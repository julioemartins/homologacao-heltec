/*
 * ============================================================================
 *  Firmware de TESTE para homologacao Anatel - Heltec WiFi LoRa 32 (V2)
 *  Radio LoRa: Semtech SX1276 (versao 863-928 MHz)
 * ============================================================================
 *
 *  OBJETIVO: colocar o radio LoRa em modos de teste exigidos pelo laboratorio
 *  (portadora continua CW e transmissao modulada continua), permitindo trocar
 *  FREQUENCIA e POTENCIA por comando serial, SEM recompilar.
 *
 *  >>> ESTE FIRMWARE COBRE APENAS O RADIO LoRa (SX1276). <<<
 *  Os ensaios de WiFi e BLE (2,4 GHz / ESP32) usam o "RF Test" da Espressif.
 *
 *  --------------------------------------------------------------------------
 *  PRE-REQUISITOS (Arduino IDE):
 *    1. Instalar suporte a placas ESP32 (Boards Manager -> "esp32" by Espressif)
 *    2. Selecionar a placa: "Heltec WiFi LoRa 32(V2)"  (ou "WiFi LoRa 32")
 *    3. Library Manager -> instalar "RadioLib" (by Jan Gromes)
 *    4. Compilar e gravar via USB. Abrir o Monitor Serial em 115200 baud.
 *
 *  --------------------------------------------------------------------------
 *  COMANDOS SERIAIS (digite e tecle Enter):
 *    F<MHz>   Define a frequencia.   Ex:  F915.2     F927.8     F902.2
 *    P<dBm>   Define a potencia.     Ex:  P20  (max)   P14   P2 (min)
 *    CW       Portadora CONTINUA nao modulada (carrier puro)
 *    MOD      Transmissao LoRa MODULADA continua (pacotes maximos em sequencia)
 *    STOP     Para a transmissao (radio em standby)
 *    ?        Mostra o estado atual
 *
 *  Procedimento tipico no laboratorio (repetir por sub-faixa):
 *    P20            -> potencia maxima do produto
 *    F915.2 / CW    -> mede no canal mais baixo da faixa
 *    F921.5 / CW    -> mede no meio
 *    F927.8 / CW    -> mede no canal mais alto
 *    depois repetir com MOD (modulado) nas mesmas frequencias.
 *
 *  --------------------------------------------------------------------------
 *  SUB-FAIXAS PERMITIDAS NO BRASIL (radiacao restrita - confirmar com OCD):
 *      902.0 - 907.5 MHz
 *      915.0 - 928.0 MHz
 *  O firmware AVISA se voce sair delas, mas NAO bloqueia (o lab pode precisar
 *  medir nas guard bands). No PRODUTO DE SERIE, trave somente as faixas acima.
 *
 *  *** SE A SUA PLACA FOR V3 (chip SX1262), ESTE CODIGO NAO SERVE: me avise
 *      que eu troco para a API do SX1262. ***
 * ============================================================================
 */

#include <RadioLib.h>
#include <SPI.h>

// ---- Pinos do SX1276 no Heltec WiFi LoRa 32 V2 ----
#define LORA_NSS   18
#define LORA_DIO0  26
#define LORA_RST   14
#define LORA_DIO1  35
#define LORA_SCK    5
#define LORA_MISO  19
#define LORA_MOSI  27

// Vext / OLED nao sao usados aqui (foco no radio)

SX1276 radio = new Module(LORA_NSS, LORA_DIO0, LORA_RST, LORA_DIO1);

// ---- Estado atual ----
float   gFreq  = 915.2;   // MHz
int8_t  gPower = 20;      // dBm (max do SX1276 com PA_BOOST = 20)
enum Mode { IDLE, CW, MODULATED };
Mode    gMode  = IDLE;

// Buffer de payload maximo para a transmissao modulada continua
uint8_t txbuf[255];

void printState() {
  Serial.println(F("------------------------------------------"));
  Serial.print(F("  Frequencia : ")); Serial.print(gFreq, 3); Serial.println(F(" MHz"));
  Serial.print(F("  Potencia   : ")); Serial.print(gPower);   Serial.println(F(" dBm"));
  Serial.print(F("  Modo       : "));
  Serial.println(gMode == CW ? F("CW (portadora continua)")
               : gMode == MODULATED ? F("MOD (LoRa modulado continuo)")
               : F("IDLE (parado)"));
  Serial.println(F("------------------------------------------"));
}

bool freqPermitidaBR(float f) {
  return (f >= 902.0 && f <= 907.5) || (f >= 915.0 && f <= 928.0);
}

void stopTx() {
  radio.standby();
  gMode = IDLE;
}

// (Re)aplica frequencia/potencia e inicia o modo escolhido
void applyMode(Mode m) {
  stopTx();
  int state;

  if (m == CW) {
    // beginFSK + transmitDirect() => portadora pura, nao modulada
    state = radio.beginFSK(gFreq);
    radio.setOutputPower(gPower);   // PA_BOOST ate +20 dBm
    if (state == RADIOLIB_ERR_NONE) {
      radio.transmitDirect();       // emite carrier ate STOP
      gMode = CW;
      Serial.println(F(">> CW ON"));
    }
  } else if (m == MODULATED) {
    // LoRa: pacotes maximos enviados em sequencia no loop() => modulado ~continuo
    state = radio.begin(gFreq);     // params LoRa default (BW125/SF9/CR4-7)
    radio.setOutputPower(gPower);
    if (state == RADIOLIB_ERR_NONE) {
      gMode = MODULATED;
      Serial.println(F(">> MOD ON"));
    }
  }

  if (m != IDLE && gMode == IDLE) {
    Serial.print(F("!! ERRO ao iniciar radio, codigo "));
    Serial.println(state);
  }
  printState();
}

void handleLine(String s) {
  s.trim();
  s.toUpperCase();
  if (s.length() == 0) return;

  if (s == "?") { printState(); return; }
  if (s == "STOP") { stopTx(); Serial.println(F(">> STOP")); printState(); return; }
  if (s == "CW")  { applyMode(CW); return; }
  if (s == "MOD") { applyMode(MODULATED); return; }

  if (s[0] == 'F') {
    float f = s.substring(1).toFloat();
    if (f < 800 || f > 1000) { Serial.println(F("!! Frequencia invalida")); return; }
    gFreq = f;
    if (!freqPermitidaBR(f))
      Serial.println(F("!! AVISO: fora das sub-faixas Anatel (902-907.5 / 915-928)"));
    Serial.print(F(">> Frequencia = ")); Serial.print(gFreq, 3); Serial.println(F(" MHz"));
    if (gMode != IDLE) applyMode(gMode);   // reaplica no modo ativo
    return;
  }

  if (s[0] == 'P') {
    int p = s.substring(1).toInt();
    if (p < 2 || p > 20) { Serial.println(F("!! Potencia 2..20 dBm")); return; }
    gPower = p;
    Serial.print(F(">> Potencia = ")); Serial.print(gPower); Serial.println(F(" dBm"));
    if (gMode != IDLE) applyMode(gMode);
    return;
  }

  Serial.println(F("!! Comando desconhecido. Use F/P/CW/MOD/STOP/?"));
}

void setup() {
  Serial.begin(115200);
  delay(300);
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_NSS);

  for (int i = 0; i < 255; i++) txbuf[i] = (uint8_t)i;

  int state = radio.begin(gFreq);
  Serial.println();
  Serial.println(F("=== Firmware de TESTE Anatel - Heltec V2 / SX1276 ==="));
  if (state == RADIOLIB_ERR_NONE)
    Serial.println(F("Radio SX1276 OK."));
  else {
    Serial.print(F("FALHA ao iniciar SX1276, codigo "));
    Serial.println(state);
    Serial.println(F("Verifique se a placa e' mesmo V2 (SX1276). V3 usa SX1262."));
  }
  radio.standby();
  Serial.println(F("Comandos: F<MHz> P<dBm> CW MOD STOP ?"));
  printState();
}

void loop() {
  // Comandos seriais
  static String line;
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n' || c == '\r') { if (line.length()) { handleLine(line); line = ""; } }
    else line += c;
  }

  // Transmissao modulada continua: envia pacotes maximos em sequencia
  if (gMode == MODULATED) {
    radio.transmit(txbuf, sizeof(txbuf));
  }
}

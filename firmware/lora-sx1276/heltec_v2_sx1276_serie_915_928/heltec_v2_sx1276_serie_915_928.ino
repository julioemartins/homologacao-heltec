/*
 * ============================================================================
 *  Firmware de SERIE (producao) - Heltec WiFi LoRa 32 (V2) / SX1276
 *  Modelo: SBR-Edge
 * ============================================================================
 *
 *  DIFERENCA para o firmware de TESTE:
 *    - O de TESTE permite qualquer frequencia (so AVISA fora da faixa), pois o
 *      laboratorio pode precisar medir guard bands.
 *    - ESTE (serie) TRAVA o radio: so opera em 915.0-928.0 MHz e potencia <= 20
 *      dBm. Qualquer tentativa fora disso e' RECUSADA por software. E' a camada
 *      de conformidade que garante o que foi homologado na Anatel.
 *
 *  O QUE ISTO E':
 *    Um ESQUELETO de producao + a CAMADA DE TRAVA (band/power guard). Integre a
 *    sua aplicacao real (LoRaWAN, P2P, etc.) CHAMANDO SEMPRE radioSetFreq()/
 *    radioSetPower() abaixo, em vez de mexer no radio direto. Assim a trava
 *    nunca e' contornada.
 *
 *  COMPORTAMENTO PADRAO (demonstravel): envia um beacon curto a cada 5 s na
 *  frequencia central declarada (921.5 MHz), 20 dBm. Serve para mostrar a placa
 *  operando "de verdade" dentro da faixa homologada.
 *
 *  PRE-REQUISITOS (iguais ao de teste): core esp32 + RadioLib. 115200 baud.
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

// ====== TRAVA DE CONFORMIDADE (NAO ALTERAR sem reavaliar a homologacao) ======
static const float   BR_FREQ_MIN_MHZ = 915.0;   // sub-faixa AU915 declarada
static const float   BR_FREQ_MAX_MHZ = 928.0;
static const int8_t  BR_POWER_MAX_DBM = 20;      // teto homologado
static const float   FREQ_DEFAULT_MHZ = 921.5;   // canal central da faixa
// ============================================================================

SX1276 radio = new Module(LORA_NSS, LORA_DIO0, LORA_RST, LORA_DIO1);

float  gFreq  = FREQ_DEFAULT_MHZ;
int8_t gPower = BR_POWER_MAX_DBM;

// Retorna true se a frequencia esta DENTRO da faixa homologada.
static bool freqAllowed(float f) {
  return (f >= BR_FREQ_MIN_MHZ && f <= BR_FREQ_MAX_MHZ);
}

// Unico ponto autorizado para mudar a frequencia. Recusa fora da faixa.
bool radioSetFreq(float f) {
  if (!freqAllowed(f)) {
    Serial.print(F("[TRAVA] Frequencia "));
    Serial.print(f, 3);
    Serial.println(F(" MHz RECUSADA (fora de 915-928). Mantida a anterior."));
    return false;
  }
  gFreq = f;
  int st = radio.setFrequency(gFreq);
  return (st == RADIOLIB_ERR_NONE);
}

// Unico ponto autorizado para mudar a potencia. Satura no teto homologado.
bool radioSetPower(int8_t dbm) {
  if (dbm > BR_POWER_MAX_DBM) {
    Serial.print(F("[TRAVA] Potencia limitada a "));
    Serial.print(BR_POWER_MAX_DBM);
    Serial.println(F(" dBm."));
    dbm = BR_POWER_MAX_DBM;
  }
  if (dbm < 2) dbm = 2;
  gPower = dbm;
  int st = radio.setOutputPower(gPower);
  return (st == RADIOLIB_ERR_NONE);
}

void setup() {
  Serial.begin(115200);
  delay(300);
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_NSS);

  Serial.println();
  Serial.println(F("=== SBR-Edge - Firmware de SERIE (LoRa travado 915-928) ==="));

  int state = radio.begin(gFreq);   // ja inicia dentro da faixa
  if (state != RADIOLIB_ERR_NONE) {
    Serial.print(F("FALHA ao iniciar SX1276, codigo "));
    Serial.println(state);
    Serial.println(F("Confirme que a placa e' V2 (SX1276)."));
    while (true) delay(1000);
  }

  radioSetFreq(gFreq);
  radioSetPower(gPower);

  Serial.print(F("Operacao travada em "));
  Serial.print(BR_FREQ_MIN_MHZ, 1); Serial.print(F("-"));
  Serial.print(BR_FREQ_MAX_MHZ, 1);
  Serial.print(F(" MHz, ate "));
  Serial.print(BR_POWER_MAX_DBM); Serial.println(F(" dBm."));
  Serial.print(F("Beacon em "));
  Serial.print(gFreq, 1); Serial.println(F(" MHz a cada 5 s."));

  // Auto-teste da trava (so loga): tenta sair da faixa e mostra a recusa.
  Serial.println(F("[auto-teste] tentando 902.2 MHz (deve ser RECUSADO):"));
  radioSetFreq(902.2);
  Serial.println(F("[auto-teste] tentando 868.0 MHz (deve ser RECUSADO):"));
  radioSetFreq(868.0);
  radioSetFreq(FREQ_DEFAULT_MHZ);   // volta ao canal valido
}

void loop() {
  // ---- SUBSTITUA por sua aplicacao real; mantenha radioSetFreq/Power ----
  static uint32_t last = 0;
  if (millis() - last >= 5000) {
    last = millis();
    const char *msg = "SBR-Edge";
    int st = radio.transmit((uint8_t*)msg, 8);
    Serial.print(F("TX beacon @ "));
    Serial.print(gFreq, 1);
    Serial.print(F(" MHz -> "));
    Serial.println(st == RADIOLIB_ERR_NONE ? F("OK") : F("ERRO"));
  }
}

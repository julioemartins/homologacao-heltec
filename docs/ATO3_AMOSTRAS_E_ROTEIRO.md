# ATO 3 — Amostras e Roteiro (testar aqui antes de despachar)

> **Propósito:** montar as amostras na configuração final e **validar na bancada**
> que cada rádio entra em modo de teste — antes de mandar ao laboratório. Só
> começa após o [Ato 2](ATO2_PERGUNTAS_OCD.md) (escopo/custo/amostras aceitos).
>
> Detalhe técnico completo: [`GUIA_COMPLETO_HOMOLOGACAO_ANATEL.md`](GUIA_COMPLETO_HOMOLOGACAO_ANATEL.md), Fases 2–4 e Seção 7.

---

## 1. Preparar as amostras

- [ ] Montar **N unidades** (N = quantidade confirmada pelo OCD no Ato 2; ~2–3).
- [ ] Todas **idênticas**: mesma placa V2, mesma **antena original**, mesmos headers.
- [ ] **Numerar** cada amostra (nº de série) e registrar.
- [ ] Reservar superfície na placa para o **selo** (arte com placeholder por ora).

---

## 2. Firmwares (já no repositório)

| Rádio | Arquivo | Pasta |
|---|---|---|
| LoRa SX1276 (teste) | `heltec_v2_sx1276_anatel_testmode.ino` | [`../firmware/lora-sx1276/`](../firmware/lora-sx1276/) |
| WiFi+BLE (RF Test) | `ESP32_RFTest_V195_*.bin` + `ESP32_Init_data_bin_*.bin` | [`../firmware/esp32-rf-test/`](../firmware/esp32-rf-test/) |
| BLE DTM (HCI) | `ESP32_BLE_DTM_HCI_*.bin` | [`../firmware/esp32-rf-test/`](../firmware/esp32-rf-test/) |

> Mesma amostra física grava um firmware de cada vez. Instruções de gravação:
> [README do esp32-rf-test](../firmware/esp32-rf-test/README.md).

---

## 3. Teste de bancada (validação antes do lab)

Não medimos conformidade aqui (isso é no lab) — só confirmamos que **cada rádio
entra em modo de teste e transmite** onde deve.

### 3.1 LoRa (firmware `.ino`)
- [ ] Compilar/gravar o `.ino` na amostra (Arduino IDE / PlatformIO).
- [ ] Abrir serial **115200**; comando `?` lista os comandos.
- [ ] `P20` → `F915.2` → `CW`: confirmar portadora (com analisador/SDR, se houver).
- [ ] Repetir em `F921.5` e `F927.8`, em `CW` e `MOD`.
- [ ] `STOP`. Confirmar que **fora de 915–928 o firmware avisa/bloqueia**.

### 3.2 WiFi + BLE (RF Test ESP32)
- [ ] Gravar `ESP32_RFTest_*.bin` (`0x1000`) + `ESP32_Init_data_*.bin` (`0x1fc000`).
- [ ] Serial **115200**; `help` lista comandos.
- [ ] WiFi: TX nos canais **1 / 6 / 11** — confirmar que transmite.
- [ ] BLE: TX nos canais **2402 / 2440 / 2480 MHz** — confirmar que transmite.
- [ ] Parar transmissão.

### 3.3 Firmware de série
- [ ] Gravar o firmware de **produção travado em 915–928** numa amostra de referência.
- [ ] Confirmar que **não** opera fora de 915–928.

---

## 4. Roteiro de ensaio (entregar ao lab)

### LoRa — sub-faixa 915–928 MHz (única declarada), sempre em `P20`
| Passo | Comando | Medição |
|---|---|---|
| Potência máx | `P20` | — |
| Canal baixo (CW) | `F915.2` → `CW` | freq, espúrios |
| Canal meio (CW) | `F921.5` → `CW` | freq, espúrios |
| Canal alto (CW) | `F927.8` → `CW` | freq, espúrios |
| Canal baixo (MOD) | `F915.2` → `MOD` | potência, OBW, OOB |
| Canal meio (MOD) | `F921.5` → `MOD` | potência, OBW, OOB |
| Canal alto (MOD) | `F927.8` → `MOD` | potência, OBW, OOB |
| Parar | `STOP` | — |

### WiFi / BLE (RF Test ESP32 — operado pela EspRFTestTool)
| Rádio | Modo | Canais |
|---|---|---|
| WiFi | TX contínuo (potência, OBW, máscara) | 1 / 6 / 11 = 2412 / 2437 / 2462 MHz |
| WiFi | Single carrier (freq, espúrios) | 1 / 6 / 11 |
| BLE | DTM TX (potência) | 0 / 19 / 39 = 2402 / 2440 / 2480 MHz |

Taxas WiFi: 11b (1/11 Mbps), 11g (54 Mbps), 11n (MCS0/MCS7) — conforme o lab.
Sempre na **potência máxima** definida no Ato 1.

---

## 5. Portão do Ato 3

- [ ] Amostras montadas, numeradas e idênticas.
- [ ] Os 3 rádios entram em modo de teste na bancada.
- [ ] Firmware de série confirma trava em 915–928.
- [ ] Roteiro conferido.

**→ OK: seguir para o Ato 4 (despachar + acompanhar).**

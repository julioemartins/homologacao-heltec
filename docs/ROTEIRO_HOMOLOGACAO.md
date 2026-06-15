# Roteiro de Homologação — 3 rádios (SBR-Edge / Heltec V2)

> **Documento para o laboratório.** Define, por rádio, os modos, canais e
> potência a ensaiar, e qual firmware usar em cada caso. Mesma amostra física
> grava um firmware de cada vez.
>
> Validação prévia na bancada da SBR: [`BANCADA_LORA.md`](BANCADA_LORA.md) e
> [`BANCADA_WIFI_BLE.md`](BANCADA_WIFI_BLE.md).

## Dados do produto

| Item | Valor |
|---|---|
| Modelo | **SBR-Edge** (módulo plugável / placa nua) |
| LoRa | SX1276 — **915–928 MHz (AU915)**, **20 dBm** |
| WiFi | ESP32 — 2,4 GHz, ~20 dBm |
| BLE | ESP32 — 2,4 GHz |
| Antena | modelo original do kit (~2–3 dBi, u.FL/IPEX) |

Medições por rádio (conforme os Atos vigentes que o OCD indicar): **potência/EIRP,
largura de banda ocupada (OBW), emissões fora de faixa (OOB), espúrios** e, no
2,4 GHz, **máscara espectral**.

---

## RÁDIO 1 — LoRa 900 MHz (SX1276)

**Firmware:** `firmware/lora-sx1276/heltec_v2_sx1276_anatel_testmode/`
**Interface:** serial 115200. **Faixa:** somente **915–928 MHz**. Sempre `P20`.

| Passo | Comando | Frequência | Medição |
|---|---|---|---|
| Potência máx | `P20` | — | — |
| Canal baixo — CW | `F915.2` → `CW` | 915,2 MHz | freq, espúrios |
| Canal meio — CW | `F921.5` → `CW` | 921,5 MHz | freq, espúrios |
| Canal alto — CW | `F927.8` → `CW` | 927,8 MHz | freq, espúrios |
| Canal baixo — MOD | `F915.2` → `MOD` | 915,2 MHz | potência, OBW, OOB |
| Canal meio — MOD | `F921.5` → `MOD` | 921,5 MHz | potência, OBW, OOB |
| Canal alto — MOD | `F927.8` → `MOD` | 927,8 MHz | potência, OBW, OOB |
| Parar | `STOP` | — | — |

> **CW** = portadora pura (frequência/espúrios). **MOD** = LoRa modulado contínuo
> (potência/OBW/máscara). 902–907,5 MHz **não** é declarada — não ensaiar.

---

## RÁDIO 2 — WiFi 2,4 GHz (ESP32)

**Firmware:** `firmware/esp32-rf-test/ESP32_RFTest_V195_*.bin` (+ `ESP32_Init_data_*.bin`).
**Operação:** EspRFTestTool / serial 115200 (`help` lista comandos).

| Modo | Canais (MHz) | Medição |
|---|---|---|
| TX contínuo modulado | 1 / 6 / 11 = 2412 / 2437 / 2462 | potência, OBW, máscara |
| Single carrier | 1 / 6 / 11 | frequência, espúrios |

Taxas representativas: 11b (1/11 Mbps), 11g (54 Mbps), 11n (MCS0/MCS7) — conforme
o lab. Sempre na **potência máxima**. Encerrar com **stop**.

---

## RÁDIO 3 — BLE 2,4 GHz (ESP32)

**Firmware:** mesmo RF Test acima (ou `ESP32_BLE_DTM_HCI_*.bin` para DTM via HCI).

| Modo | Canais (MHz) | Medição |
|---|---|---|
| DTM TX | 0 / 19 / 39 = 2402 / 2440 / 2480 | potência |

Na **potência máxima** do produto. Encerrar com **stop**.

---

## Entregas ao laboratório

- Amostras (qtde confirmada pelo OCD), idênticas e numeradas.
- Firmwares: LoRa (este repo) + RF Test ESP32 (este repo).
- Este roteiro + ficha técnica (Seção 2 do guia) + documentação (Seção 6 do guia).

## Sequência sugerida (mesma amostra)
1. Gravar firmware **LoRa** → ensaiar Rádio 1 → `STOP`.
2. Gravar **RF Test ESP32** → ensaiar Rádio 2 (WiFi) e Rádio 3 (BLE) → stop.
3. Regravar **firmware de série** (LoRa travado 915–928) na amostra de referência.

> Regra de ouro: ensaiar sempre na **potência máxima real de série (20 dBm)**.
> Nunca acima do que será comercializado.

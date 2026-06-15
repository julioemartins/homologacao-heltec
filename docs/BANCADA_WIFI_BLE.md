# Bancada — Verificar os rádios WiFi e BLE (ESP32) aqui

> Passo a passo para confirmar, na sua mesa, que o **RF Test da Espressif** entra
> em modo de transmissão no ESP32 da placa V2. Os binários são **oficiais** da
> Espressif (usados em certificação no mundo todo); aqui só confirmamos que dão
> boot e transmitem. A medição de conformidade é do laboratório.

**Ferramentas já instaladas:** `esptool`, `pyserial`, `screen`.
**Binários:** [`../firmware/esp32-rf-test/`](../firmware/esp32-rf-test/) (ver o
[README](../firmware/esp32-rf-test/README.md) de lá).

---

## 0. Porta e pasta

```bash
PORTA=/dev/cu.usbserial-0001     # <-- ajuste (ls /dev/cu.*)
cd firmware/esp32-rf-test
```

> ⚠️ Mantenha a **antena conectada** ao transmitir.

---

## 1. Gravar o firmware de RF Test

```bash
python3 -m esptool --chip esp32 --port $PORTA --baud 921600 \
  write_flash --flash_mode dio --flash_freq 40m --flash_size detect \
  0x1000   ESP32_RFTest_V195_1807fd3_20250818.bin \
  0x1fc000 ESP32_Init_data_bin_v06_20191016.bin
```

Se falhar, segure **PRG/BOOT** ao iniciar o flash. Ao final, ele reinicia.

---

## 2. Abrir o serial e ver os comandos

```bash
screen $PORTA 115200      # sair: Ctrl-A depois K
```

Digite **`help`** → o firmware lista os comandos de RF disponíveis (os nomes
variam conforme a versão; use os que aparecerem).

---

## 3. WiFi — transmitir nos canais de ensaio

Para cada canal (**1 = 2412**, **6 = 2437**, **11 = 2462 MHz**), acione:
- **TX contínuo modulado** (para potência / largura de banda / máscara), e
- **single carrier / portadora** (para frequência / espúrios).

Confirme no log que entra em transmissão. Encerre com o comando **stop**.

> A sintaxe exata está no `docs/RF_test_introduction.pdf` e no
> `EspRFTestTool_introduction.pdf` (pasta `../firmware/esp32-rf-test/docs/`).
> Na homologação, **quem opera é o laboratório** pela EspRFTestTool — aqui você
> só confirma que a placa responde.

---

## 4. BLE — transmitir nos canais de ensaio

Canais **0 / 19 / 39 = 2402 / 2440 / 2480 MHz**, na potência máxima. Acione o
modo TX/DTM e confirme a transmissão; encerre com stop.

> Alternativa por instrumento: o binário `ESP32_BLE_DTM_HCI_*.bin` faz **DTM via
> HCI** (CMW500 etc.) — instruções no `.txt` ao lado dele.

---

## 5. Confirmar o RF (opcional)

- **2,4 GHz precisa de SDR de 2,4 GHz** (HackRF ou similar) — o RTL-SDR comum
  **não** alcança 2,4 GHz. Sem isso, a confirmação de RF fica para o lab.
- Mínimo viável aqui: ver no **log serial** que cada comando entra em TX/stop.

---

## 6. Devolver a placa ao firmware de aplicação

Depois dos testes, regrave o firmware de produção (LoRa de série etc.) se for
reutilizar a mesma placa.

---

## Checklist

- [ ] RF Test gravado (boot OK).
- [ ] `help` lista os comandos.
- [ ] WiFi transmite em 1 / 6 / 11.
- [ ] BLE transmite em 2402 / 2440 / 2480.
- [ ] (Opcional) SDR 2,4 GHz confirmou emissão.

→ WiFi/BLE OK. Ver o [`ROTEIRO_HOMOLOGACAO.md`](ROTEIRO_HOMOLOGACAO.md).

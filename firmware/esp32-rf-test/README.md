# Firmware de RF Test do ESP32 (WiFi 2,4 GHz + BLE)

Firmwares oficiais da **Espressif** para colocar os rádios de 2,4 GHz do ESP32
(WiFi e BLE) em **modo de teste de RF**, exigidos nos ensaios de homologação.

> O rádio **LoRa 900 MHz (SX1276)** usa outro firmware — ver
> [`../lora-sx1276/`](../lora-sx1276/). São firmwares **separados**, gravados na
> **mesma** placa, um de cada vez.

Placa-alvo: **Heltec WiFi LoRa 32 V2** → chip **ESP32** (clássico). Os binários
deste diretório são os da família ESP32; **não** servem para ESP32-S2/S3/C3/C6 etc.

---

## Arquivos

| Arquivo | O que é | Uso |
|---|---|---|
| `ESP32_RFTest_V195_1807fd3_20250818.bin` | **Firmware principal de RF Test** (WiFi + BLE, não-signaling) | Operado pela EspRFTestTool ou por comandos seriais. É o que o laboratório usa na maioria dos ensaios. |
| `ESP32_Init_data_bin_v06_20191016.bin` | `phy_init` / init data (calibração de PHY) | Gravar junto, no endereço `0x1fc000`. |
| `ESP32_BLE_DTM_HCI_f8139fe_20250714.bin` | **BLE DTM via HCI** (signaling, p/ instrumentos tipo CMW500) | Alternativa para teste BLE DTM controlado por instrumento. Ver `.txt`. |
| `ESP32_BLE_DTM_HCI_f8139fe_20250714.txt` | Instruções do BLE DTM HCI (pinos UART1, baud, setup CMW500) | Ler antes de usar o DTM HCI. |
| `docs/EspRFTestTool_introduction.pdf` | Manual da ferramenta EspRFTestTool | Referência de comandos/uso. |
| `docs/RF_test_introduction.pdf` | Guia de RF test | Procedimento de ensaio. |
| `docs/RF_certification_introduction.pdf` | Guia de certificação RF | Contexto regulatório/certificação. |

> **Não versionado aqui:** a GUI `EspRFTestTool_v5.2_Manual.exe` (~52 MB, Windows)
> e o pacote completo (~77 MB). Baixe-os direto da Espressif (ver abaixo).

---

## De onde vieram (links oficiais Espressif)

- **Pacote completo (GUI + todos os firmwares):**
  `https://dl.espressif.com/RF/EspRFTestTool_v5.2_Manual.zip`
- **Firmware RF Test ESP32 avulso (versão anterior V191):**
  `https://dl.espressif.com/RF/ESP32_RFTest_V191_482eb73_20230724.bin`
- Documentação: https://docs.espressif.com/projects/esp-test-tools/en/latest/esp32/
- Página de certificação/test: https://www.espressif.com/en/tools-type/certification-and-test

A versão `V195_...20250818` (incluída aqui) veio de dentro do pacote `EspRFTestTool_v5.2`.

---

## Como gravar o firmware principal de RF Test

**Endereços de flash (ESP32):**

| Componente | Endereço |
|---|---|
| Firmware de RF Test (`ESP32_RFTest_*.bin`) | `0x1000` |
| `phy_init` / init data (`ESP32_Init_data_bin_*.bin`) | `0x1fc000` |

**esptool (linha de comando):**
```bash
# Descobrir a porta (macOS): ls /dev/cu.*  -> ex.: /dev/cu.usbserial-0001
esptool.py --chip esp32 --port /dev/cu.usbserial-0001 --baud 921600 \
  write_flash --flash_mode dio --flash_freq 40m --flash_size detect \
  0x1000   ESP32_RFTest_V195_1807fd3_20250818.bin \
  0x1fc000 ESP32_Init_data_bin_v06_20191016.bin
```

**GUI (EspRFTestTool / Flash Download Tool):** escolher chip **ESP32**, adicionar
os binários nos endereços acima, selecionar a porta COM, baud 921600, **START**.

> A Heltec V2 normalmente entra em modo de gravação sozinha (auto-reset). Se
> falhar, segurar **BOOT/PRG** ao iniciar o flash.

---

## Operar os modos de teste

Após gravar, conectar por **serial (UART0) a 115200 baud** (ou pela EspRFTestTool).
Digitar `help` mostra os comandos disponíveis.

- **WiFi:** TX contínuo modulado (potência/OBW/máscara) e single carrier
  (frequência/espúrios) nos canais **1 (2412), 6 (2437), 11 (2462 MHz)**.
- **BLE:** TX nos canais **0/19/39 = 2402/2440/2480 MHz**, na potência máxima.

A sintaxe exata dos comandos depende da versão do firmware — usar a tabela do
`docs/RF_test_introduction.pdf` / manual da EspRFTestTool. **Na prática, o
laboratório opera a ferramenta**; você entrega a placa já gravada + a lista de
canais/potência (Seção 7 do guia de homologação).

> Roteiro de ensaio e contexto completo: [`../../docs/GUIA_COMPLETO_HOMOLOGACAO_ANATEL.md`](../../docs/GUIA_COMPLETO_HOMOLOGACAO_ANATEL.md), Seção 2.2.

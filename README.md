# Homologação Anatel — Heltec WiFi LoRa 32 V2 (SBR-Edge)

Repositório de trabalho para a **homologação na Anatel** do módulo
**Heltec WiFi LoRa 32 V2** (ESP32 + SX1276 + WiFi + BLE), a ser comercializado
pela **SBR** como **módulo plugável** integrado em outras placas/produtos host.

## Decisões fechadas (SBR)

| Item | Decisão |
|---|---|
| Modelo comercial | **SBR-Edge** |
| Chip LoRa | **SX1276** (placa **V2**, confirmado por foto) |
| Plano de frequência LoRa | **915–928 MHz** (AU915) |
| Potência | máx. do produto de série (a definir/confirmar) |
| Antena | **modelo original** do kit Heltec *(ganho/conector a especificar)* |
| Firmware de série | **travado** em 915–928 MHz (sub-faixa BR) |
| Configuração a homologar | **placa nua** (módulo plugável, sem case) |
| Case | decisão do produto host — fora do escopo desta homologação |

## Estrutura

```
.
├── docs/                                  # documentação de homologação
│   ├── GUIA_COMPLETO_HOMOLOGACAO_ANATEL.md   (documento mestre — 8 fases)
│   └── PLANO_HOMOLOGACAO.md                   (resumo rápido)
└── firmware/                              # firmwares de teste p/ o laboratório
    ├── lora-sx1276/                          (rádio LoRa 900 MHz)
    │   └── heltec_v2_sx1276_anatel_testmode.ino
    └── esp32-rf-test/                        (WiFi + BLE 2,4 GHz — Espressif)
        ├── README.md                         (como gravar/operar)
        ├── ESP32_RFTest_V195_*.bin           (firmware principal de RF Test)
        ├── ESP32_Init_data_bin_*.bin         (phy_init, @0x1fc000)
        ├── ESP32_BLE_DTM_HCI_*.bin/.txt      (BLE DTM via HCI)
        └── docs/                             (manuais PDF da Espressif)
```

## O processo, em 4 atos

Plano de comando: **[`docs/PROCESSO.md`](docs/PROCESSO.md)** — cada ato só começa
quando o portão do anterior é aprovado.

| Ato | O quê | Documento | Estado |
|---|---|---|---|
| **1** | Confirmar o produto (interno SBR) | [`docs/ATO1_DEFINICAO_PRODUTO.md`](docs/ATO1_DEFINICAO_PRODUTO.md) | ⏳ aguarda aprovação SBR |
| **2** | Consultar OCD/lab (escopo + custo) | [`docs/ATO2_PERGUNTAS_OCD.md`](docs/ATO2_PERGUNTAS_OCD.md) | pronto p/ enviar |
| **3** | Amostras + teste de bancada | [`docs/ATO3_AMOSTRAS_E_ROTEIRO.md`](docs/ATO3_AMOSTRAS_E_ROTEIRO.md) | — |
| **4** | Despachar + acompanhar | [`docs/PROCESSO.md`](docs/PROCESSO.md) (Ato 4) | — |

## Referência técnica

- **Guia mestre (8 fases):** [`docs/GUIA_COMPLETO_HOMOLOGACAO_ANATEL.md`](docs/GUIA_COMPLETO_HOMOLOGACAO_ANATEL.md)
- **Resumo rápido:** [`docs/PLANO_HOMOLOGACAO.md`](docs/PLANO_HOMOLOGACAO.md)
- **Firmware LoRa (teste):** [`firmware/lora-sx1276/`](firmware/lora-sx1276/)
- **Firmware WiFi/BLE (RF Test ESP32):** [`firmware/esp32-rf-test/`](firmware/esp32-rf-test/)

## Próxima ação

**Ato 1** — a SBR revisa e aprova a [ficha de definição do produto](docs/ATO1_DEFINICAO_PRODUTO.md),
fechando o único item técnico em aberto (**potência máxima de série**, rec. 20 dBm)
e a **antena** (modelo original — ganho/conector). Só então segue para o Ato 2.

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
| Potência LoRa de série | **20 dBm** (100 mW) |
| Antena | **modelo original** do kit Heltec (~2–3 dBi, u.FL/IPEX) |
| WiFi / BLE | **ativos** — os 3 rádios entram no escopo |
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
    │   ├── heltec_v2_sx1276_anatel_testmode/    (firmware de TESTE — CW/MOD)
    │   ├── heltec_v2_sx1276_serie_915_928/      (firmware de SÉRIE — travado)
    │   └── teste_bancada.py                     (valida o roteiro por serial)
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
| **1** | Confirmar o produto (interno SBR) | [`docs/ATO1_DEFINICAO_PRODUTO.md`](docs/ATO1_DEFINICAO_PRODUTO.md) | ✅ confirmado (falta razão social) |
| **2** | Consultar OCD/lab (escopo + custo) | [`docs/ATO2_PERGUNTAS_OCD.md`](docs/ATO2_PERGUNTAS_OCD.md) | pronto p/ enviar |
| **3** | Amostras + teste de bancada | [`docs/ATO3_AMOSTRAS_E_ROTEIRO.md`](docs/ATO3_AMOSTRAS_E_ROTEIRO.md) | — |
| **4** | Despachar + acompanhar | [`docs/PROCESSO.md`](docs/PROCESSO.md) (Ato 4) | — |

## Verificar na bancada (antes do lab)

- **Roteiro de ensaio dos 3 rádios:** [`docs/ROTEIRO_HOMOLOGACAO.md`](docs/ROTEIRO_HOMOLOGACAO.md)
- **Passo a passo LoRa:** [`docs/BANCADA_LORA.md`](docs/BANCADA_LORA.md)
- **Passo a passo WiFi/BLE:** [`docs/BANCADA_WIFI_BLE.md`](docs/BANCADA_WIFI_BLE.md)

> Ferramentas já instaladas nesta máquina: `arduino-cli` (core esp32 + RadioLib),
> `esptool`, `pyserial`. Os dois firmwares LoRa **compilam sem erros**.

## Referência técnica

- **Guia mestre (8 fases):** [`docs/GUIA_COMPLETO_HOMOLOGACAO_ANATEL.md`](docs/GUIA_COMPLETO_HOMOLOGACAO_ANATEL.md)
- **Resumo rápido:** [`docs/PLANO_HOMOLOGACAO.md`](docs/PLANO_HOMOLOGACAO.md)
- **Firmwares LoRa (teste + série):** [`firmware/lora-sx1276/`](firmware/lora-sx1276/)
- **Firmware WiFi/BLE (RF Test ESP32):** [`firmware/esp32-rf-test/`](firmware/esp32-rf-test/)

## Próxima ação

Definições técnicas **confirmadas** (Ato 1). Pendências:
- **SBR:** informar **razão social/CNPJ** (resumo enviado por e-mail — ver [`docs/EMAIL_RESUMO_SBR.md`](docs/EMAIL_RESUMO_SBR.md)).
- **Em paralelo:** enviar o [Ato 2 — perguntas ao OCD/lab](docs/ATO2_PERGUNTAS_OCD.md).

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

## Por onde começar

- **Visão geral e fases:** [`docs/GUIA_COMPLETO_HOMOLOGACAO_ANATEL.md`](docs/GUIA_COMPLETO_HOMOLOGACAO_ANATEL.md)
- **Resumo rápido:** [`docs/PLANO_HOMOLOGACAO.md`](docs/PLANO_HOMOLOGACAO.md)
- **Firmware LoRa (teste):** [`firmware/lora-sx1276/`](firmware/lora-sx1276/)
- **Firmware WiFi/BLE (RF Test ESP32):** [`firmware/esp32-rf-test/`](firmware/esp32-rf-test/)

## Pendências [SBR]

- [ ] Confirmar **potência máxima** de série e **antena** (modelo/ganho/conector).
- [ ] Enviar **perguntas ao OCD** (Seção 10 do guia) — destaque: viabilidade do
      regime de **módulo plugável** reaproveitável.
- [ ] Reunir documentação técnica (Seção 6 do guia) e roteiro de ensaio.

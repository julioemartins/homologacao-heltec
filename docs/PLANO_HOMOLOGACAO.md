# Plano de Homologacao Anatel — Heltec WiFi LoRa 32 (V2)

> Produto: modulo Heltec WiFi LoRa 32 **V2** (SX1276 confirmado), homologado como **modulo plugavel (placa nua)** — sera integrado em outras placas/produtos host da SBR.
> Titular: SBR (fabricante/importador). OCD/laboratorio: ja contratado.
> **Confirmar TODOS os pontos marcados [OCD] com o seu Organismo de Certificacao.**
>
> **Decisoes fechadas (SBR):** modelo = **SBR-Edge** · chip = SX1276 (V2) · plano de frequencia = **915–928 MHz** · potencia de serie = **20 dBm** · antena = modelo original do kit (~2–3 dBi, u.FL/IPEX) · WiFi/BLE ativos · firmware de serie travado em 915–928 · homologar placa nua como modulo plugavel · case = decisao do produto host (premissa do time SBR, fora desta homologacao).

---

## 1. Identificacao tecnica do produto

| Item | Valor |
|---|---|
| Modelo comercial | **SBR-Edge** |
| MCU | ESP32 (WiFi 2,4 GHz + BLE) |
| Radio LoRa | Semtech **SX1276** (placa V2) — confirmado por foto |
| Faixa do hardware | 863–928 MHz (largo) |
| **Faixa declarada p/ Anatel** | **915–928 MHz** (AU915) — unica sub-faixa declarada |
| Potencia LoRa max | +20 dBm (100 mW) conduzido — limite do proprio chip |
| WiFi | 2,4 GHz (2400–2483,5), ~+20 dBm |
| BLE | 2,4 GHz, ~+9 dBm |
| Antena | **modelo original** do kit Heltec (~2–3 dBi, u.FL/IPEX — confirmar ganho na peca) |

**Travar no firmware de SERIE:** operacao SOMENTE em **915–928 MHz**.
Bloquear o restante do range que o hardware alcanca (863–915 e fora de 928) e que nao foi declarado.

---

## 2. Amostras

- **1 modelo = 1 homologacao** cobrindo LoRa + WiFi + BLE (tudo na mesma placa).
- **NAO** se manda uma amostra por radio.
- Quantidade de unidades fisicas: **[OCD]** — tipicamente **2 a 3 unidades iguais**.
- As amostras sao a **placa nua** na config final (mesma antena/headers/firmware de serie) — e' assim que o modulo sera homologado e integrado.

---

## 3. Firmwares de teste a entregar ao laboratorio

| Radio | Firmware | Status |
|---|---|---|
| LoRa SX1276 | `heltec_v2_sx1276_anatel_testmode.ino` (CW / MOD, comandavel por serial) | **PRONTO** — `../firmware/lora-sx1276/` |
| WiFi 2,4 GHz | "RF Test" da Espressif (`ESP32_RFTest_*.bin`) | **BAIXADO** — `../firmware/esp32-rf-test/` |
| BLE | DTM — `ESP32_BLE_DTM_HCI_*.bin` (ou via RF Test) | **BAIXADO** — `../firmware/esp32-rf-test/` |

Procedimento LoRa (so a sub-faixa 915–928, ver comentarios no .ino):
`P20` -> `F915.2`/`CW` -> `F921.5`/`CW` -> `F927.8`/`CW` -> repetir com `MOD`.

---

## 4. Ensaios esperados (confirmar escopo com [OCD])

- [ ] Ensaios de RF radiacao restrita — LoRa 900 MHz (potencia/EIRP, largura de banda ocupada, emissoes fora de faixa, espurios)
- [ ] Ensaios de RF — WiFi 2,4 GHz
- [ ] Ensaios de RF — BLE 2,4 GHz
- [ ] Avaliacao de exposicao a campos EM (SAR/MPE) — para baixa potencia normalmente **declaracao** simplificada **[OCD]**
- [ ] Seguranca eletrica / EMC — conforme categoria do produto **[OCD]**

---

## 5. Documentacao a montar (modelo: ver homologacao anterior do D-Link na pasta pai)

- [ ] Dados do titular (CNPJ, responsavel)
- [ ] Requerimento de homologacao (sistema Anatel — Mosaico/SCH)
- [ ] Relatorios de ensaio emitidos pelo laboratorio
- [ ] Certificado de Conformidade emitido pelo OCD
- [ ] Manual / descricao tecnica do produto
- [ ] Fotos externas e internas da placa
- [ ] Esquematico (Heltec publica) + datasheets SX1276 e ESP32
- [ ] Especificacao da antena (ganho, conector, faixa)
- [ ] Arte da etiqueta com modelo + numero de homologacao Anatel
- [ ] Declaracao de exposicao a campos EM (se aplicavel) [OCD]

---

## 6. Perguntas a fazer ao OCD (resolver de uma vez)

1. Quantas unidades de amostra voces querem?
2. Categoria do produto e lista exata de ensaios (inclui EMC/seguranca?).
3. WiFi/BLE: precisa ensaiar mesmo que o produto final use so LoRa?
4. Posso homologar como **modulo reaproveitavel** em produtos host? Quais condicoes
   (manter front-end de RF e antena, rotulagem)?
5. Avaliacao de exposicao EM: ensaio ou declaracao?
6. Eles ja tem o procedimento de RF Test do ESP32 (WiFi/BLE)?

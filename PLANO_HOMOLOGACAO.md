# Plano de Homologacao Anatel — Heltec WiFi LoRa 32 (V2)

> Produto: modulo Heltec WiFi LoRa 32 V2, em case, homologado como **produto acabado**.
> Titular: SBR (fabricante/importador). OCD/laboratorio: ja contratado.
> **Confirmar TODOS os pontos marcados [OCD] com o seu Organismo de Certificacao.**

---

## 1. Identificacao tecnica do produto

| Item | Valor |
|---|---|
| MCU | ESP32 (WiFi 2,4 GHz + BLE) |
| Radio LoRa | Semtech **SX1276** (placa V2) — *confirmar SX1276 x SX1262 olhando o chip* |
| Faixa do hardware | 863–928 MHz (largo) |
| **Faixa declarada p/ Anatel** | **902–907,5 MHz** e **915–928 MHz** (somente sub-faixas permitidas) |
| Potencia LoRa max | +20 dBm (100 mW) conduzido — limite do proprio chip |
| WiFi | 2,4 GHz (2400–2483,5), ~+20 dBm |
| BLE | 2,4 GHz, ~+9 dBm |
| Antena | externa, ~3 dBi (especificar ganho/conector) |

**Travar no firmware de SERIE:** operacao SOMENTE em 902–907,5 e 915–928 MHz.
Bloquear o restante do range 863–928 que o hardware alcanca mas a Anatel nao permite.

---

## 2. Amostras

- **1 modelo = 1 homologacao** cobrindo LoRa + WiFi + BLE (tudo na mesma placa).
- **NAO** se manda uma amostra por radio.
- Quantidade de unidades fisicas: **[OCD]** — tipicamente **2 a 3 unidades iguais**.
- As amostras devem estar no **case final** (e' assim que sera homologado/vendido).

---

## 3. Firmwares de teste a entregar ao laboratorio

| Radio | Firmware | Status |
|---|---|---|
| LoRa SX1276 | `heltec_v2_sx1276_anatel_testmode.ino` (CW / MOD, comandavel por serial) | **PRONTO neste diretorio** |
| WiFi 2,4 GHz | "RF Test" da Espressif (binario + ferramenta de PC) | baixar da Espressif |
| BLE | DTM (Direct Test Mode) — incluido no RF Test da Espressif | baixar da Espressif |

Procedimento LoRa (repetir por sub-faixa, ver comentarios no .ino):
`P20` -> `F<baixa>`/`CW` -> `F<meio>`/`CW` -> `F<alta>`/`CW` -> repetir com `MOD`.

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

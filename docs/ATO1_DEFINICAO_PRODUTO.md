# ATO 1 — Ficha de Definição do Produto (para confirmação da SBR)

> **Propósito:** congelar internamente **o que será homologado** antes de
> consultar o OCD/lab. A SBR revisa, fecha os itens em aberto e **aprova** (bloco
> no fim). Só depois seguimos para o [Ato 2](ATO2_PERGUNTAS_OCD.md).

---

## 1. O que estamos homologando

Módulo de rádio **Heltec WiFi LoRa 32 V2** (ESP32 + SX1276 + WiFi + BLE),
homologado como **placa nua / módulo plugável**, para ser integrado em
**produtos host da SBR** sem reensaiar cada produto (a confirmar regra com o OCD).

- **1 homologação** cobre os **3 rádios** (LoRa 900 MHz + WiFi + BLE).
- Não há case nesta homologação — case é decisão de cada produto host.

---

## 2. Definições já fechadas

| # | Item | Definição | Status |
|---|---|---|---|
| 1 | Modelo comercial | **SBR-Edge** | ✅ fechado |
| 2 | Placa / chip | Heltec **V2** → LoRa **SX1276** (confirmado por foto) | ✅ fechado |
| 3 | Forma de homologação | **Placa nua (módulo plugável)** | ✅ fechado |
| 4 | Plano de frequência LoRa | **915–928 MHz (AU915)** — só esta sub-faixa | ✅ fechado |
| 5 | Firmware de série | **travado em 915–928 MHz** | ✅ fechado |
| 6 | Rádios no escopo | LoRa + WiFi + BLE (todos ensaiados) | ✅ fechado |

---

## 3. Decisões confirmadas (valores recomendados aceitos)

> Valores recomendados **confirmados**. Resta apenas o dado cadastral (item C),
> que só a SBR possui — será obtido por e-mail.

| # | Item | Decisão | Status |
|---|---|---|---|
| A | **Potência máx. de série (LoRa)** | **20 dBm** (100 mW — teto do chip e valor usual) | ✅ confirmado |
| B | **Antena** | modelo **original** do kit Heltec — **~2–3 dBi**, conector **u.FL/IPEX** *(confirmar ganho exato na peça)* | ✅ confirmado |
| C | **Nome do fabricante** na homologação | **razão social/CNPJ da SBR** *(preencher: ____________)* | ⏳ aguarda dado SBR |
| D | **WiFi/BLE ativos** no produto final? | **Ativos** — ensaiar os 3 rádios | ✅ confirmado |

> **Por que a potência importa:** o ensaio é feito na **potência máxima real** de
> série. Definir agora evita reensaio. 20 dBm é o teto do chip e o usual.
>
> **Sobre a antena (item B):** ganho/conector recomendados são os típicos do kit
> Heltec V2; **confirme olhando a peça** (etiqueta/datasheet da antena) antes de
> fechar — o ganho entra no cálculo de EIRP do ensaio.
>
> **Sobre o fabricante (item C):** só a SBR tem a razão social/CNPJ exatos — este
> é o único campo que **precisa** ser digitado (não dá para recomendar).

---

## 4. Configuração física a homologar

- Placa nua com **headers** (mantém o caráter plugável).
- **Antena original** fixada (item B acima).
- Espaço reservado na placa para o **selo Anatel** (nº + QR).
- Sem alterações no circuito de RF / chips.

---

## 5. Status do portão do Ato 1

- [x] Definições técnicas (Seções 2 e 3) **confirmadas internamente**.
- [ ] **Razão social/CNPJ da SBR** (item C) — a obter por e-mail com a SBR.

> Único item pendente é cadastral (não bloqueia o Ato 2 em paralelo). Resumo
> enviado à SBR por e-mail — ver [`EMAIL_RESUMO_SBR.md`](EMAIL_RESUMO_SBR.md).

**→ Liberado para o [Ato 2 — Perguntas ao OCD](ATO2_PERGUNTAS_OCD.md).**

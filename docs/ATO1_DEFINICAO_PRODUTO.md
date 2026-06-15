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

## 3. Itens em aberto — a SBR precisa decidir

| # | Item | Opções / recomendação | Decisão SBR |
|---|---|---|---|
| A | **Potência máx. de série (LoRa)** | até +20 dBm (limite do chip). **Rec.: 20 dBm** | __________ |
| B | **Antena** | modelo **original** do kit Heltec — informar **ganho (dBi)** e **conector** | __________ |
| C | **Nome do fabricante** na homologação | razão social da SBR (qual exatamente?) | __________ |
| D | **WiFi/BLE ativos** no produto final? | ensaiar os 3 de qualquer forma (hardware transmite). **Rec.: manter** | __________ |

> **Por que a potência importa:** o ensaio é feito na **potência máxima real** de
> série. Definir agora evita reensaio. 20 dBm é o teto do chip e o usual.

---

## 4. Configuração física a homologar

- Placa nua com **headers** (mantém o caráter plugável).
- **Antena original** fixada (item B acima).
- Espaço reservado na placa para o **selo Anatel** (nº + QR).
- Sem alterações no circuito de RF / chips.

---

## 5. Aprovação SBR (portão do Ato 1)

> Ao aprovar, a SBR autoriza seguir para a consulta ao OCD/lab.

- Itens em aberto (Seção 3) preenchidos? **[ ] Sim**
- Definições (Seção 2) conferidas? **[ ] Sim**

| Campo | Valor |
|---|---|
| Aprovado por (nome) | __________________________ |
| Cargo / área | __________________________ |
| Data | _____ / _____ / __________ |
| Observações | __________________________ |

**→ Aprovado: seguir para o [Ato 2 — Perguntas ao OCD](ATO2_PERGUNTAS_OCD.md).**

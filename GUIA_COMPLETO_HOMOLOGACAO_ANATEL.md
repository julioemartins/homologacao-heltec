# Guia Completo — Homologação Anatel do Heltec WiFi LoRa 32 (V2)

> **Produto:** módulo Heltec WiFi LoRa 32 V2 (ESP32 + SX1276 + WiFi + BLE), montado em case, homologado como **produto acabado** / módulo plugável.
> **Titular:** SBR (fabricante/importador — responsável legal perante a Anatel).
> **Laboratório/OCD:** já contratado.
>
> **Como usar:** este é o documento mestre. Itens marcados **[OCD]** dependem de confirmação do seu Organismo de Certificação Designado — ele é a autoridade final sobre escopo de ensaios, categoria e formato de etiqueta. Itens **[SBR]** são ações suas.

---

## 1. Objetivo e estratégia

Tornar o módulo Heltec **legalmente comercializável no Brasil**, com **número de homologação Anatel**, de forma que ele possa ser:
- vendido/usado dentro de um **case próprio**, e
- (objetivo secundário) **reaproveitado como módulo** em produtos host futuros, sem reensaiar tudo — desde que o front-end de RF e a antena não mudem **[OCD]**.

São **3 rádios numa única placa**, todos sob o regime de **radiação restrita** da Anatel:
1. **LoRa 900 MHz** (SX1276)
2. **WiFi 2,4 GHz** (ESP32)
3. **BLE 2,4 GHz** (ESP32)

→ **1 produto = 1 homologação** cobrindo os três. Não se homologa rádio por rádio.

---

## 2. Identificação técnica do produto

| Item | Valor |
|---|---|
| Modelo comercial | *(definir nome/modelo SBR)* **[SBR]** |
| MCU | ESP32 (dual-core, WiFi 2,4 GHz + BLE) |
| Rádio LoRa | Semtech **SX1276** — *confirmar olhando o chip (V3 usa SX1262)* **[SBR]** |
| Faixa do hardware LoRa | 863–928 MHz |
| **Faixa LoRa declarada à Anatel** | **902–907,5 MHz** e **915–928 MHz** (apenas sub-faixas permitidas) |
| Potência LoRa máx. | +20 dBm (100 mW) conduzido — limite do chip |
| WiFi | 2,4 GHz (2400–2483,5 MHz), ~+20 dBm |
| BLE | 2,4 GHz, ~+9 dBm |
| Antena | externa, conectorizada, ~3 dBi *(especificar ganho/conector exatos)* **[SBR]** |
| Alimentação | USB 5 V + bateria Li-Po (gestão de carga embarcada) |
| Display | OLED 0,96" 128×64 (não-RF, irrelevante p/ ensaio de rádio) |

**Regra crítica:** o produto de série deve operar **somente** em 902–907,5 e 915–928 MHz. O trecho 863–902 MHz que o hardware alcança **não é permitido no Brasil** e precisa estar **travado por firmware**.

---

## 3. Marco regulatório aplicável

| Norma | O que trata |
|---|---|
| **Resolução nº 715/2019** | Regulamento de Avaliação da Conformidade e de Homologação de produtos. Define categorias e o fluxo OCD → Anatel. |
| **Resolução nº 680/2017** | Equipamentos de **radiação restrita** — quais faixas podem ser usadas sem licença. |
| **Ato nº 14448/2017** (e atualizações) | Requisitos técnicos de ensaio para equipamentos de radiação restrita (limites de potência/EIRP, emissões, sub-faixas). |
| **Atos de procedimento de ensaio** (LoRa/Wi-Fi/BLE) | Procedimentos específicos por tecnologia. O OCD indica os Atos vigentes. **[OCD]** |

**Categoria do produto:** equipamentos transmissores de radiação restrita costumam ser **Categoria 1 ou 2** (exigem ensaios + certificação por OCD, não apenas declaração). **Confirmar a categoria exata com o OCD [OCD]** — ela define a profundidade dos ensaios (RF, e possivelmente EMC, segurança elétrica, exposição EM).

---

## 4. Papéis e responsabilidades

| Parte | Responsabilidade |
|---|---|
| **SBR (titular)** | É a "fabricante" declarada do modelo no Brasil. Fornece amostras, firmwares de teste, documentação técnica, paga ensaios e taxas, mantém a conformidade do produto. |
| **Laboratório de ensaio** | Executa as medições de RF (e demais ensaios da categoria) e emite os **relatórios de ensaio**. |
| **OCD** | Analisa relatórios e documentação e emite o **Certificado de Conformidade**. Frequentemente também faz o pedido de homologação no sistema da Anatel. |
| **Anatel** | Emite o **número de homologação** e publica o certificado. |

---

## 5. Visão geral das fases (roadmap)

| Fase | Nome | Saída principal | Responsável |
|---|---|---|---|
| 1 | Enquadramento | categoria + escopo de ensaios definidos | SBR + OCD |
| 2 | Preparação técnica | firmwares de teste prontos (LoRa + WiFi/BLE) | SBR |
| 3 | Case + etiqueta | produto na configuração final, etiquetável | SBR |
| 4 | Amostras | 2–3 unidades iguais entregues ao lab | SBR |
| 5 | Ensaios | relatórios de ensaio | Laboratório |
| 6 | Certificação | Certificado de Conformidade | OCD |
| 7 | Homologação | nº de homologação Anatel + selo | Anatel/OCD |
| 8 | Pós-homologação | rotulagem, manutenção, importação | SBR |

```
[1 Enquadramento] -> [2 Firmware] -> [3 Case/Etiqueta] -> [4 Amostras]
        -> [5 Ensaios] -> [6 Certificado OCD] -> [7 Homologacao Anatel] -> [8 Pos]
```

---

## FASE 1 — Enquadramento e definição de escopo

**Objetivo:** travar exatamente o que será ensaiado antes de gastar com laboratório.

- [ ] **[SBR]** Definir o **modelo comercial** e o **nome do fabricante** que constará na homologação.
- [ ] **[SBR]** Definir o **plano de frequência** do produto: 915–928 (AU915), 902–907,5, ou ambos.
- [ ] **[SBR]** Definir a **potência máxima** de operação do produto de série (recomendado: 20 dBm).
- [ ] **[SBR]** Decidir se WiFi e BLE ficam **ativos** no produto final (recomendado ensaiar os três de qualquer forma, pois o hardware transmite).
- [ ] **[OCD]** Confirmar **categoria** do produto e a **lista exata de ensaios** (RF; EMC; segurança elétrica; exposição a campos EM).
- [ ] **[OCD]** Confirmar os **Atos de procedimento de ensaio** vigentes para LoRa, WiFi e BLE.
- [ ] **[OCD]** Confirmar viabilidade de **homologação como módulo reaproveitável** e suas condições.

---

## FASE 2 — Preparação técnica (firmwares de teste)

**Não existe firmware de homologação para baixar.** O laboratório precisa de firmwares que coloquem cada rádio em **modo de teste**.

### 2.1 LoRa (SX1276) — PRONTO
Arquivo: **`heltec_v2_sx1276_anatel_testmode.ino`** (neste diretório).
- Comandável por serial (115200 baud), sem recompilar.
- Modos: **CW** (portadora contínua não modulada) e **MOD** (LoRa modulado contínuo).
- Comandos: `F<MHz>` (frequência), `P<dBm>` (potência), `CW`, `MOD`, `STOP`, `?`.
- Avisa se sair das sub-faixas brasileiras.

> Se a placa for **V3 (SX1262)**, este firmware não serve — solicitar a versão SX1262.

### 2.2 WiFi 2,4 GHz e BLE — RF Test da Espressif

Para o ESP32 (WiFi + BLE) **não se escreve firmware**: a Espressif fornece um **firmware de RF Test pronto** + uma **ferramenta de PC** que comanda os modos de transmissão exigidos no ensaio. O procedimento completo está abaixo.

> **Importante:** o RF Test cobre **apenas** os rádios de 2,4 GHz (WiFi e BLE) do ESP32. O LoRa (900 MHz) usa o firmware da Seção 2.1. São firmwares **separados**, gravados na **mesma** amostra, um de cada vez.

#### 2.2.1 O que baixar (Espressif)
- [ ] **[SBR]** **Firmware de RF Test** para **ESP32** (chip clássico da placa V2). Vem como conjunto de binários: `bootloader.bin`, `partition-table.bin` e o `rf_test.bin` (app).
- [ ] **[SBR]** **RF Test Tool** (ferramenta GUI de PC, Windows) — documento de referência: **"ESP RF Test Tool and Test Guide"** da Espressif.
- [ ] **[SBR]** **Flash Download Tool** da Espressif (GUI de gravação) — opcional, alternativa ao `esptool`.

> Os pacotes de RF Test/certificação da Espressif costumam ser distribuídos pelo canal de suporte/engenharia da Espressif. Se não achar o link, **peça ao seu laboratório** — eles quase sempre já têm o firmware e a ferramenta do ESP32. **[OCD/LAB]**

#### 2.2.2 Gravar o firmware de RF Test na placa

**Opção A — Flash Download Tool (GUI, mais simples):**
1. Abrir o Flash Download Tool, escolher chip **ESP32**.
2. Adicionar os três binários nos endereços padrão:
   - `bootloader.bin` → **0x1000**
   - `partition-table.bin` → **0x8000**
   - `rf_test.bin` (app) → **0x10000**
   *(use exatamente os endereços indicados no pacote da Espressif, se diferirem).*
3. Selecionar a porta COM da placa, baud **921600**, e clicar **START**.

**Opção B — esptool (linha de comando):**
```bash
# Descobrir a porta (macOS): ls /dev/cu.*  -> algo como /dev/cu.usbserial-0001
esptool.py --chip esp32 --port /dev/cu.usbserial-0001 --baud 921600 write_flash \
  0x1000  bootloader.bin \
  0x8000  partition-table.bin \
  0x10000 rf_test.bin
```
Se o pacote vier como **imagem única combinada**, grave-a em `0x0`:
```bash
esptool.py --chip esp32 --port /dev/cu.usbserial-0001 --baud 921600 write_flash 0x0 rf_test_combined.bin
```

> A placa Heltec V2 normalmente entra em modo de gravação sozinha (auto-reset). Se falhar, segurar **BOOT/PRG** ao iniciar o flash.

#### 2.2.3 Conectar e comandar os modos de teste

Após gravar, conectar por **serial a 115200 baud** (Monitor Serial, ou a própria **RF Test Tool**). A ferramenta envia os comandos de RF; também é possível digitá-los manualmente.

**WiFi — modos exigidos pelo ensaio:**
- **TX contínuo modulado** (para potência/largura de banda/máscara) em cada canal/taxa.
- **Single carrier / portadora contínua** (para frequência e espúrios).
- Canais de borda e meio: **1 (2412), 6 (2437) e 11 (2462 MHz)**.
- Taxas representativas: **802.11b (1/11 Mbps), 11g (54 Mbps), 11n (MCS0/MCS7)** — conforme o lab.

**BLE — DTM (Direct Test Mode):**
- Modo de transmissão DTM em **canais baixo/meio/alto: 2402 / 2440 / 2480 MHz** (canais BLE 0, 19 e 39).
- Potência máxima do produto.

> **Sintaxe exata dos comandos:** os nomes (ex.: TX contínuo, single carrier, DTM start/stop) variam conforme a **versão do firmware de RF Test**. Use sempre a tabela de comandos do **"ESP RF Test Tool and Test Guide"** correspondente ao binário baixado. Na prática, **o laboratório opera a RF Test Tool** — você entrega a placa já gravada + a lista de canais/potência da Seção 9. **[OCD/LAB]**

#### 2.2.4 Sequência de ensaio WiFi/BLE (resumo)
1. Gravar o firmware de RF Test (2.2.2).
2. Definir potência máxima do produto.
3. WiFi: TX contínuo nos canais 1, 6, 11 (medir potência, OBW, máscara) + single carrier (freq/espúrios).
4. BLE: DTM nos canais 2402, 2440, 2480 MHz.
5. Parar a transmissão (comando stop) ao final.
6. **Regravar o firmware de produção** na amostra depois dos ensaios, se for reutilizá-la.

- [ ] **[OCD]** Confirmar se o laboratório já domina a RF Test Tool do ESP32 (é muito comum — geralmente sim).

### 2.3 Entrega ao laboratório
- 1 firmware LoRa (.ino/.bin) + 1 firmware RF Test do ESP32 (.bin).
- O lab grava um, ensaia, grava o outro. **Mesma amostra física para os três rádios.**

---

## FASE 3 — Do kit ao produto: case (se houver) e etiqueta

O produto é homologado **na configuração física exata em que será vendido**. Mudanças relevantes de RF (antena, circuito, potência) depois **invalidam** a homologação.

### 3.0 Do kit de desenvolvimento ao produto homologável

**O case pode NÃO ser obrigatório.** A Anatel homologa o que você vende — então a decisão não é "qual case", é **"o que será comercializado?"**:

- Vender a **placa nua como módulo plugável** (como vem hoje, com headers) → homologa-se a **placa nua**. **Sem case.**
- Vender **dentro de um case** → homologa-se **com o case definitivo**.

Ou seja, o "kit de teste" atual **pode ser o próprio produto homologado**, desde que seja assim que chega ao cliente. O case é escolha de produto, não exigência regulatória.

**O que realmente muda do "kit como vem" para "produto homologável":**

| # | Item | Ação | Físico? |
|---|---|---|---|
| 1 | **Antena** ⭐ | Fixar **UMA** antena (modelo, ganho dBi, conector). Ela passa a fazer parte do produto certificado. Ideal: **conector fixo/único**, para o usuário não trocar por antena de maior ganho e estourar o EIRP homologado. **[OCD]** confirma a exigência de conector. | **Sim** |
| 2 | **Espaço para o selo** | Garantir superfície (placa ou case) para aplicar o **selo Anatel** de forma permanente e legível. | **Sim** |
| 3 | **Firmware travado** | Travar operação só em **902–907,5 / 915–928 MHz** e na **potência máxima** declarada. | Não (SW) |
| 4 | **Case** | Só se vender com case — então ele precisa ser o **final** (ver 3.1). | Depende |

**O que NÃO precisa mexer:**
- Circuito de RF / chips → mantém como está.
- Blindagem metálica → não exigida para esta classe (radiação restrita).
- Headers/pinos → manter (é o que o torna "plugável").

> **Resumo:** o item físico que você precisa fechar de fato é a **antena** (modelo + conector fixo) e o **espaço do selo**. O case é decisão comercial.

### 3.1 Requisitos do case (caso opte por vender com case)
- [ ] **Configuração final:** ensaiar com o case definitivo (material, tampa, aberturas). Não ensaiar "placa nua" se o produto vende com case.
- [ ] **Antena:** posição e tipo de antena **fixos**; usar a antena que irá ao mercado. Documentar **ganho e conector**. Conector "único/não padronizado" facilita o enquadramento de antena dedicada **[OCD]**.
- [ ] **Material:** plástico (não blindado) é o caso típico do Heltec; se usar case metálico, isso muda a emissão e **precisa ser o mesmo do ensaio**.
- [ ] **Espaço para a etiqueta:** superfície plana, visível e acessível para aplicar o **selo de homologação Anatel** de forma **permanente e legível** (ver 3.2).
- [ ] **Acessos físicos:** aberturas para USB/carga, antena (SMA/uFL→SMA) e, se aplicável, botão/reset, sem comprometer a fixação.
- [ ] **Térmica:** ventilação adequada para operação contínua na potência máxima.
- [ ] **Bateria Li-Po:** se o case contém bateria, prever fixação segura e, dependendo da categoria, requisitos de **segurança** podem se aplicar **[OCD]**.
- [ ] **Robustez mecânica:** alívio de tração no cabo da antena e na alimentação; fixação da placa.
- [ ] **Para "módulo plugável":** o case/headers devem expor o conector mantendo o **front-end de RF e a antena inalterados** em relação ao ensaiado **[OCD]**.

### 3.2 Requisitos de etiqueta / selo de homologação
- [ ] Selo de homologação Anatel com o **número de homologação** no formato oficial.
- [ ] Versões recentes exigem o **selo com QR Code** apontando para a base da Anatel — **confirmar o formato/arte vigente com o OCD [OCD]**.
- [ ] Deve conter no mínimo: **número de homologação Anatel** e **modelo** do produto.
- [ ] **Permanente e legível** durante a vida útil; se o produto for pequeno demais, há regras para etiqueta na embalagem/manual **[OCD]**.
- [ ] Antes de ter o número, usar **arte com placeholder**; o número sai ao final da Fase 7.

---

## FASE 4 — Amostras

- [ ] **[OCD]** Confirmar **quantidade** de unidades (tipicamente **2 a 3** iguais).
- [ ] Amostras **idênticas ao produto final**: mesmo case, mesma antena, mesmo firmware de série (além dos firmwares de teste).
- [ ] Identificar cada amostra (nº de série).
- [ ] Enviar junto: firmwares de teste + roteiro de ensaio (Seção 9) + ficha técnica.

---

## FASE 5 — Ensaios em laboratório

Escopo conforme a categoria **[OCD]**. Tipicamente:
- [ ] **RF radiação restrita — LoRa 900 MHz:** potência/EIRP, largura de banda ocupada, emissões fora de faixa, espúrios — nos canais baixo/meio/alto de cada sub-faixa.
- [ ] **RF — WiFi 2,4 GHz** (via RF Test ESP32).
- [ ] **RF — BLE 2,4 GHz** (via DTM).
- [ ] **Exposição a campos EM (SAR/MPE):** baixa potência normalmente resolve com **declaração/avaliação simplificada** **[OCD]**.
- [ ] **EMC / segurança elétrica:** conforme categoria **[OCD]**.
- [ ] **Saída:** relatórios de ensaio assinados pelo laboratório.

> **Regra de ouro:** ensaiar com a **potência máxima real** do produto de série. Nunca ensaiar acima do que será vendido.

---

## FASE 6 — Certificação (OCD)

- [ ] OCD analisa relatórios + documentação técnica.
- [ ] Eventuais ajustes/reensaios se algo reprovar.
- [ ] **Saída:** **Certificado de Conformidade** emitido pelo OCD.

---

## FASE 7 — Homologação (Anatel)

- [ ] Pedido de homologação no **sistema da Anatel** (Mosaico/SCH), com login gov.br + cadastro da empresa.
- [ ] Anexar Certificado de Conformidade e documentação.
- [ ] Pagar a **taxa de homologação** (GRU).
- [ ] **Saída:** **número de homologação Anatel** publicado.
- [ ] Aplicar o **selo definitivo** (com o número/QR) no case e na arte.

> Frequentemente o **OCD conduz** esta fase em nome do titular — confirmar quem submete **[OCD]**.

---

## FASE 8 — Pós-homologação

- [ ] Aplicar o selo em **todas as unidades** comercializadas.
- [ ] Incluir o número no **manual** e na **embalagem**.
- [ ] **Importação:** o nº de homologação é exigido no desembaraço aduaneiro dos produtos.
- [ ] **Manutenção:** qualquer alteração de **hardware de RF, antena ou potência** exige reavaliação. Alterações só de software não-RF geralmente não.
- [ ] Guardar documentação técnica para fiscalização.

---

## 6. Documentos a enviar ao OCD (checklist detalhado)

### Cadastrais / administrativos
- [ ] Dados da empresa titular (CNPJ, contrato social, responsável técnico/legal).
- [ ] Procuração, se terceiro atuar pela empresa.
- [ ] Requerimento/ordem de serviço do processo (modelo do OCD).

### Técnicos do produto
- [ ] **Ficha técnica / especificação** (Seção 2 deste guia).
- [ ] **Manual do usuário** (mesmo modelo do D-Link na pasta pai serve de base).
- [ ] **Esquemático elétrico** (Heltec publica o do WiFi LoRa 32 V2).
- [ ] **Datasheets:** SX1276 (Semtech) e ESP32 (Espressif).
- [ ] **Diagrama de blocos de RF** (cadeia rádio → PA → antena).
- [ ] **Especificação da antena:** modelo, ganho (dBi), faixa, conector.
- [ ] **Fotos:** externas (case + etiqueta) e internas (placa, chips legíveis, antena).
- [ ] **Lista de frequências e potências** declaradas (plano AU915 etc.).

### De ensaio / firmware
- [ ] Firmwares de teste (LoRa `.ino`/`.bin` + RF Test ESP32 `.bin`).
- [ ] **Roteiro de ensaio** (Seção 9).

### De rotulagem
- [ ] Arte do **selo/etiqueta** (com placeholder do número até a Fase 7).

> O OCD pode pedir documentos adicionais conforme a categoria. **[OCD]**

---

## 7. Roteiro de ensaio LoRa (entregar ao laboratório)

Usar o firmware `heltec_v2_sx1276_anatel_testmode.ino`. Para **cada** sub-faixa, medir no canal **baixo, meio e alto**, em **CW** e depois em **MOD**, sempre na **potência máxima** (`P20`).

### Sub-faixa 915–928 MHz (AU915)
| Passo | Comando | Medição |
|---|---|---|
| Potência máx | `P20` | — |
| Canal baixo (CW) | `F915.2` → `CW` | freq, espúrios |
| Canal meio (CW) | `F921.5` → `CW` | freq, espúrios |
| Canal alto (CW) | `F927.8` → `CW` | freq, espúrios |
| Canal baixo (MOD) | `F915.2` → `MOD` | potência, OBW, OOB |
| Canal meio (MOD) | `F921.5` → `MOD` | potência, OBW, OOB |
| Canal alto (MOD) | `F927.8` → `MOD` | potência, OBW, OOB |
| Parar | `STOP` | — |

### Sub-faixa 902–907,5 MHz (se declarada)
| Passo | Comando |
|---|---|
| Canal baixo | `F902.2` → `CW` / `MOD` |
| Canal meio | `F904.8` → `CW` / `MOD` |
| Canal alto | `F907.3` → `CW` / `MOD` |

### WiFi/BLE (RF Test ESP32 — ver procedimento completo na Seção 2.2)
Gravar primeiro o firmware de RF Test (Seção 2.2.2) e operar pela RF Test Tool.

| Rádio | Modo | Canais / frequências |
|---|---|---|
| WiFi | TX contínuo modulado (potência, OBW, máscara) | 1 / 6 / 11 = 2412 / 2437 / 2462 MHz |
| WiFi | Single carrier (frequência, espúrios) | 1 / 6 / 11 |
| BLE | DTM TX (potência) | canais 0 / 19 / 39 = 2402 / 2440 / 2480 MHz |

Taxas WiFi representativas: 11b (1/11 Mbps), 11g (54 Mbps), 11n (MCS0/MCS7) — conforme o lab. Sempre na **potência máxima** do produto. Encerrar com o comando de **stop**.

---

## 8. Checklist mestre (visão única)

- [ ] **[OCD]** Categoria e escopo de ensaios confirmados
- [ ] **[SBR]** Modelo, plano de frequência e potência definidos
- [ ] **[SBR]** Firmware LoRa pronto ✔ (já neste diretório)
- [ ] **[SBR]** RF Test ESP32 baixado e testado
- [ ] **[SBR]** Case final + posição da etiqueta definidos
- [ ] **[SBR]** Antena especificada (ganho/conector)
- [ ] **[SBR]** Amostras montadas (qtde confirmada pelo OCD)
- [ ] **[SBR]** Documentação técnica reunida (Seção 6)
- [ ] **[SBR]** Roteiro de ensaio anexado
- [ ] **[LAB]** Ensaios concluídos e relatórios emitidos
- [ ] **[OCD]** Certificado de Conformidade emitido
- [ ] **[ANATEL]** Número de homologação obtido
- [ ] **[SBR]** Selo aplicado, manual/embalagem atualizados

---

## 9. Riscos e pontos de atenção

| Risco | Mitigação |
|---|---|
| Placa ser V3 (SX1262) e firmware não servir | Confirmar o chip antes de gastar com lab |
| Hardware transmitir fora das faixas BR (863–902) | Travar firmware de série só em 902–907,5 / 915–928 |
| Ensaiar placa nua e vender com case diferente | Ensaiar já no case final |
| Trocar antena depois da homologação | Antena é parte do ensaio; mudança = reavaliação |
| WiFi/BLE "esquecido" no escopo | Incluir os três rádios desde o início |
| Selo/etiqueta fora do formato vigente (QR) | Confirmar arte atual com o OCD |
| Reaproveitamento como módulo sem regra clara | Confirmar condições com o OCD na Fase 1 |

---

## 10. Perguntas para o OCD (resolver de uma vez)

1. Qual a **categoria** do produto e a **lista exata de ensaios** (inclui EMC/segurança)?
2. Quantas **unidades de amostra** vocês querem?
3. WiFi/BLE precisa ser ensaiado mesmo que o produto final use só LoRa?
4. Posso homologar como **módulo reaproveitável** em produtos host? Quais condições (RF/antena/rotulagem)?
5. Exposição a campos EM: **ensaio** ou **declaração**?
6. Vocês já têm o procedimento de **RF Test do ESP32** (WiFi/BLE)?
7. Qual o **formato vigente do selo** (QR Code) e quem **submete a homologação** na Anatel (vocês ou nós)?
8. Quais **Atos de procedimento** vigentes vocês usarão para LoRa, WiFi e BLE?

---

*Arquivos relacionados nesta pasta:*
- `heltec_v2_sx1276_anatel_testmode.ino` — firmware de teste do rádio LoRa
- `PLANO_HOMOLOGACAO.md` — resumo rápido (este guia é a versão detalhada)

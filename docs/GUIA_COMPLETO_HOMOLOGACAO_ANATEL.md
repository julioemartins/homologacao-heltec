# Guia Completo — Homologação Anatel do Heltec WiFi LoRa 32 (V2)

> **Produto:** módulo Heltec WiFi LoRa 32 **V2** (ESP32 + **SX1276** + WiFi + BLE), homologado como **módulo plugável (placa nua)** — será plugado em outras placas/produtos host da SBR.
> **Titular:** SBR (fabricante/importador — responsável legal perante a Anatel).
> **Laboratório/OCD:** já contratado.
>
> **Decisões já tomadas (SBR):**
> - **Modelo comercial: SBR-Edge.**
> - **Chip LoRa confirmado: SX1276** (placa V2, verificado por foto). O firmware de teste em `firmware/lora-sx1276/` serve.
> - **Plano de frequência: 915–928 MHz (AU915)** — única sub-faixa declarada.
> - **Firmware de série será travado** em **915–928 MHz** (decisão fechada).
> - **Potência LoRa de série: 20 dBm** (100 mW).
> - **Antena: modelo original** do kit Heltec (~2–3 dBi, u.FL/IPEX — confirmar ganho na peça).
> - **WiFi e BLE ativos** — os 3 rádios entram no escopo.
> - **Homologar a placa nua como módulo plugável** (sem case), pois ela será integrada em outras placas da SBR.
> - **Case:** não se aplica ao módulo; eventual case do produto host é **premissa para o time da SBR decidir** caso-a-caso.
>
> **Como usar:** este é o documento mestre. Itens marcados **[OCD]** dependem de confirmação do seu Organismo de Certificação Designado — ele é a autoridade final sobre escopo de ensaios, categoria e formato de etiqueta. Itens **[SBR]** são ações suas.

---

## 1. Objetivo e estratégia

Tornar o módulo Heltec **legalmente comercializável no Brasil**, com **número de homologação Anatel**, de forma que ele possa ser:
- **reaproveitado como módulo plugável** em produtos host da SBR (objetivo principal), sem reensaiar tudo a cada produto — desde que o front-end de RF e a antena não mudem **[OCD]**.

> **Caminho escolhido:** homologa-se a **placa nua** (com headers), não um produto com case. O case é decisão do produto host, à parte desta homologação.

São **3 rádios numa única placa**, todos sob o regime de **radiação restrita** da Anatel:
1. **LoRa 900 MHz** (SX1276)
2. **WiFi 2,4 GHz** (ESP32)
3. **BLE 2,4 GHz** (ESP32)

→ **1 produto = 1 homologação** cobrindo os três. Não se homologa rádio por rádio.

---

## 2. Identificação técnica do produto

| Item | Valor |
|---|---|
| Modelo comercial | **SBR-Edge** |
| MCU | ESP32 (dual-core, WiFi 2,4 GHz + BLE) |
| Rádio LoRa | Semtech **SX1276** — confirmado (placa V2, verificado por foto) |
| Faixa do hardware LoRa | 863–928 MHz |
| **Faixa LoRa declarada à Anatel** | **915–928 MHz** (AU915) — única sub-faixa declarada |
| Potência LoRa de série | **20 dBm** (100 mW) conduzido — teto do chip |
| WiFi | 2,4 GHz (2400–2483,5 MHz), ~+20 dBm |
| BLE | 2,4 GHz, ~+9 dBm |
| Antena | **modelo original** do kit Heltec — ~2–3 dBi, u.FL/IPEX *(confirmar ganho na peça)* |
| Alimentação | USB 5 V + bateria Li-Po (gestão de carga embarcada) |
| Display | OLED 0,96" 128×64 (não-RF, irrelevante p/ ensaio de rádio) |

**Regra crítica:** o produto de série deve operar **somente** em **915–928 MHz**. Todo o restante que o hardware alcança (863–915 MHz e fora de 928 MHz) **não está declarado / não é permitido** e precisa estar **travado por firmware**.

---

## 3. Marco regulatório aplicável

| Norma | O que trata |
|---|---|
| **Resolução nº 715/2019** | Regulamento de Avaliação da Conformidade e de Homologação de produtos. Define categorias e o fluxo OCD → Anatel. |
| **Resolução nº 680/2017** | Equipamentos de **radiação restrita** — quais faixas podem ser usadas sem licença. |
| **Ato nº 14448/2017** (e atualizações) | Requisitos técnicos de ensaio para equipamentos de radiação restrita (limites de potência/EIRP, emissões, sub-faixas). |
| **Atos de procedimento de ensaio** (LoRa/Wi-Fi/BLE) | Procedimentos específicos por tecnologia. O OCD indica os Atos vigentes. **[OCD]** |

> **Atenção (módulo plugável):** como vamos homologar a placa como módulo a ser integrado em produtos host da SBR, confirme com o OCD as **condições do regime de módulo** — tipicamente: manter o **front-end de RF e a antena inalterados**, **rotulagem** do nº de homologação visível também no produto host, e eventual menção do módulo no manual do host. Isso é o que evita reensaiar a cada novo produto. **[OCD]**

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
| 3 | Placa + etiqueta | placa nua na config final + posição do selo | SBR |
| 4 | Amostras | 2–3 unidades iguais entregues ao lab | SBR |
| 5 | Ensaios | relatórios de ensaio | Laboratório |
| 6 | Certificação | Certificado de Conformidade | OCD |
| 7 | Homologação | nº de homologação Anatel + selo | Anatel/OCD |
| 8 | Pós-homologação | rotulagem, manutenção, importação | SBR |

```
[1 Enquadramento] -> [2 Firmware] -> [3 Placa/Etiqueta] -> [4 Amostras]
        -> [5 Ensaios] -> [6 Certificado OCD] -> [7 Homologacao Anatel] -> [8 Pos]
```

---

## FASE 1 — Enquadramento e definição de escopo

**Objetivo:** travar exatamente o que será ensaiado antes de gastar com laboratório.

- [x] **[SBR]** Chip LoRa confirmado: **SX1276** (placa V2).
- [x] **[SBR]** Caminho de homologação definido: **módulo plugável (placa nua)**, sem case.
- [x] **[SBR]** Firmware de série será **travado** nas sub-faixas brasileiras.
- [x] **[SBR]** Modelo comercial definido: **SBR-Edge** (confirmar nome do fabricante que constará na homologação).
- [x] **[SBR]** Plano de frequência definido: **915–928 MHz (AU915)**.
- [x] **[SBR]** Potência máxima de série definida: **20 dBm**.
- [x] **[SBR]** WiFi e BLE **ativos** — os três rádios serão ensaiados.
- [ ] **[OCD]** Confirmar **categoria** do produto e a **lista exata de ensaios** (RF; EMC; segurança elétrica; exposição a campos EM).
- [ ] **[OCD]** Confirmar os **Atos de procedimento de ensaio** vigentes para LoRa, WiFi e BLE.
- [ ] **[OCD]** Confirmar viabilidade e **condições da homologação como módulo plugável** reaproveitável em produtos host (front-end de RF + antena inalterados, rotulagem no host). **← ponto-chave deste projeto**

---

## FASE 2 — Preparação técnica (firmwares de teste)

**Não existe firmware de homologação para baixar.** O laboratório precisa de firmwares que coloquem cada rádio em **modo de teste**.

### 2.1 LoRa (SX1276) — PRONTO
Arquivo: **`heltec_v2_sx1276_anatel_testmode.ino`** (em [`../firmware/lora-sx1276/`](../firmware/lora-sx1276/)).
- Comandável por serial (115200 baud), sem recompilar.
- Modos: **CW** (portadora contínua não modulada) e **MOD** (LoRa modulado contínuo).
- Comandos: `F<MHz>` (frequência), `P<dBm>` (potência), `CW`, `MOD`, `STOP`, `?`.
- Avisa se sair das sub-faixas brasileiras.

> Placa confirmada como **V2 (SX1276)** — este firmware é o correto.

### 2.2 WiFi 2,4 GHz e BLE — RF Test da Espressif

Para o ESP32 (WiFi + BLE) **não se escreve firmware**: a Espressif fornece um **firmware de RF Test pronto** + uma **ferramenta de PC** que comanda os modos de transmissão exigidos no ensaio. O procedimento completo está abaixo.

> **Importante:** o RF Test cobre **apenas** os rádios de 2,4 GHz (WiFi e BLE) do ESP32. O LoRa (900 MHz) usa o firmware da Seção 2.1. São firmwares **separados**, gravados na **mesma** amostra, um de cada vez.

#### 2.2.1 Firmware de RF Test (JÁ BAIXADO)

Os binários oficiais da Espressif para o **ESP32** (chip da placa V2) já estão no
repositório: [`../firmware/esp32-rf-test/`](../firmware/esp32-rf-test/). Ver o
[README](../firmware/esp32-rf-test/README.md) de lá para detalhes de gravação/comandos.

- [x] **[SBR]** **Firmware de RF Test** ESP32 — `ESP32_RFTest_V195_1807fd3_20250818.bin` (+ `ESP32_Init_data_bin_*.bin`).
- [x] **[SBR]** **BLE DTM (HCI)** — `ESP32_BLE_DTM_HCI_*.bin` (+ `.txt`), para teste BLE por instrumento.
- [x] **[SBR]** **Manuais** da EspRFTestTool (PDFs em `firmware/esp32-rf-test/docs/`).
- [ ] **[SBR]** **EspRFTestTool / Flash Download Tool** (GUI Windows, ~52 MB) — **não versionada** no repo. Baixar de `https://dl.espressif.com/RF/EspRFTestTool_v5.2_Manual.zip`.

> Origem dos binários: pacote `EspRFTestTool_v5.2_Manual.zip` da Espressif. Na prática, **o laboratório opera a ferramenta** — você entrega a placa já gravada. **[OCD/LAB]**

#### 2.2.2 Gravar o firmware de RF Test na placa

> Binários em [`../firmware/esp32-rf-test/`](../firmware/esp32-rf-test/). Endereços de flash do RF Test ESP32: **app em `0x1000`** e **`phy_init`/init data em `0x1fc000`** (ver [README](../firmware/esp32-rf-test/README.md)).

**Opção A — esptool (linha de comando):**
```bash
# Descobrir a porta (macOS): ls /dev/cu.*  -> algo como /dev/cu.usbserial-0001
esptool.py --chip esp32 --port /dev/cu.usbserial-0001 --baud 921600 \
  write_flash --flash_mode dio --flash_freq 40m --flash_size detect \
  0x1000   ESP32_RFTest_V195_1807fd3_20250818.bin \
  0x1fc000 ESP32_Init_data_bin_v06_20191016.bin
```

**Opção B — Flash Download Tool / EspRFTestTool (GUI Windows):** escolher chip
**ESP32**, adicionar os dois binários nos endereços acima, porta COM, baud **921600**, **START**.

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

> **Sintaxe exata dos comandos:** os nomes (ex.: TX contínuo, single carrier, DTM start/stop) variam conforme a **versão do firmware de RF Test**. Use sempre a tabela de comandos do **"ESP RF Test Tool and Test Guide"** correspondente ao binário baixado. Na prática, **o laboratório opera a RF Test Tool** — você entrega a placa já gravada + a lista de canais/potência da Seção 7. **[OCD/LAB]**

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

## FASE 3 — Placa na configuração final e etiqueta

O módulo é homologado **na configuração física exata em que será integrado**. Mudanças relevantes de RF (antena, circuito, potência) depois **invalidam** a homologação.

### 3.0 Configuração do módulo a homologar (decisão: placa nua)

**Caminho escolhido pela SBR: homologar a placa nua como módulo plugável** (com headers, sem case), pois ela será integrada em outras placas/produtos host da SBR.

> O case é **decisão do produto host** — premissa para o time da SBR avaliar caso-a-caso quando definir cada produto final. **Não faz parte desta homologação do módulo.**

**O que precisa estar fechado na placa para homologar:**

| # | Item | Ação | Físico? |
|---|---|---|---|
| 1 | **Antena** ⭐ | Fixar **UMA** antena (modelo, ganho dBi, conector). Ela passa a fazer parte do módulo certificado. Ideal: **conector fixo/único**, para não trocar por antena de maior ganho e estourar o EIRP homologado. **[OCD]** confirma a exigência de conector. | **Sim** |
| 2 | **Espaço para o selo** | Garantir superfície na **placa** para aplicar o **selo Anatel** de forma permanente e legível (e replicá-lo/referenciá-lo no produto host). | **Sim** |
| 3 | **Firmware travado** | Travar operação só em **915–928 MHz** e na **potência máxima** declarada (decisão fechada). | Não (SW) |

**O que NÃO precisa mexer:**
- Circuito de RF / chips → mantém como está.
- Blindagem metálica → não exigida para esta classe (radiação restrita).
- Headers/pinos → manter (é o que o torna "plugável").

> **Resumo:** o item físico a fechar de fato é a **antena** (modelo + conector fixo) e o **espaço do selo** na placa. Case fica fora do escopo.

### 3.1 Requisitos do módulo (placa) para ensaio
- [ ] **Configuração final:** ensaiar a **placa nua** exatamente como será integrada (mesma antena, mesmos headers, mesmo firmware de série).
- [ ] **Antena:** posição e tipo de antena **fixos**; usar a antena que irá ao mercado. Documentar **ganho e conector**. Conector "único/não padronizado" facilita o enquadramento de antena dedicada **[OCD]**.
- [ ] **Espaço para a etiqueta:** superfície na placa, visível e acessível, para aplicar o **selo de homologação Anatel** de forma **permanente e legível** (ver 3.2).
- [ ] **Robustez mecânica:** alívio de tração no cabo da antena; fixação adequada quando plugada no host.
- [ ] **Condição de módulo plugável:** o produto host deve **manter o front-end de RF e a antena inalterados** em relação ao ensaiado, sob pena de reavaliação **[OCD]**.
- [ ] **Bateria Li-Po:** se a placa do módulo integra gestão de carga/bateria, dependendo da categoria podem se aplicar requisitos de **segurança** **[OCD]**.

### 3.2 Requisitos de etiqueta / selo de homologação
- [ ] Selo de homologação Anatel com o **número de homologação** no formato oficial.
- [ ] Versões recentes exigem o **selo com QR Code** apontando para a base da Anatel — **confirmar o formato/arte vigente com o OCD [OCD]**.
- [ ] Deve conter no mínimo: **número de homologação Anatel** e **modelo** do produto.
- [ ] **Permanente e legível** durante a vida útil; se o produto for pequeno demais, há regras para etiqueta na embalagem/manual **[OCD]**.
- [ ] Antes de ter o número, usar **arte com placeholder**; o número sai ao final da Fase 7.

---

## FASE 4 — Amostras

- [ ] **[OCD]** Confirmar **quantidade** de unidades (tipicamente **2 a 3** iguais).
- [ ] Amostras **idênticas ao módulo a homologar**: mesma placa, mesma antena, mesmo firmware de série (além dos firmwares de teste).
- [ ] Identificar cada amostra (nº de série).
- [ ] Enviar junto: firmwares de teste + roteiro de ensaio (Seção 7) + ficha técnica.

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
- [ ] Aplicar o **selo definitivo** (com o número/QR) na placa e na arte.

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
- [ ] **Fotos:** da placa (frente/verso, chips legíveis), da antena e da posição do selo/etiqueta.
- [ ] **Lista de frequências e potências** declaradas (plano AU915 etc.).

### De ensaio / firmware
- [ ] Firmwares de teste (LoRa `.ino`/`.bin` + RF Test ESP32 `.bin`).
- [ ] **Roteiro de ensaio** (Seção 7).

### De rotulagem
- [ ] Arte do **selo/etiqueta** (com placeholder do número até a Fase 7).

> O OCD pode pedir documentos adicionais conforme a categoria. **[OCD]**

---

## 7. Roteiro de ensaio LoRa (entregar ao laboratório)

Usar o firmware `heltec_v2_sx1276_anatel_testmode.ino` ([`../firmware/lora-sx1276/`](../firmware/lora-sx1276/)). Plano declarado: **somente 915–928 MHz**. Medir no canal **baixo, meio e alto**, em **CW** e depois em **MOD**, sempre na **potência máxima** (`P20`).

### Sub-faixa 915–928 MHz (AU915) — única declarada
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

> **Sub-faixa 902–907,5 MHz: NÃO declarada** (decisão SBR — fora do escopo deste ensaio). O firmware de série bloqueia essa faixa.

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
- [x] **[SBR]** Modelo (**SBR-Edge**) e plano de frequência (**915–928**) definidos — falta **potência**
- [x] **[SBR]** Firmware LoRa pronto ✔ (`firmware/lora-sx1276/`)
- [x] **[SBR]** RF Test ESP32 **baixado** (`firmware/esp32-rf-test/`) — falta **testar/gravar**
- [x] **[SBR]** Caminho definido: placa nua (módulo plugável) — sem case
- [ ] **[SBR]** Posição da etiqueta/selo na placa definida
- [x] **[SBR]** Antena: **modelo original** do kit (~2–3 dBi, u.FL/IPEX) — confirmar ganho exato na peça
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
| Hardware transmitir fora da faixa declarada (863–915 / >928) | Travar firmware de série **só em 915–928 MHz** |
| Host alterar front-end de RF/antena do módulo | Manter RF e antena inalterados; mudança = reavaliação [OCD] |
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

*Arquivos relacionados no repositório:*
- [`../firmware/lora-sx1276/heltec_v2_sx1276_anatel_testmode.ino`](../firmware/lora-sx1276/heltec_v2_sx1276_anatel_testmode.ino) — firmware de teste do rádio LoRa
- [`../firmware/esp32-rf-test/`](../firmware/esp32-rf-test/) — firmwares de RF Test do ESP32 (WiFi/BLE) + manuais
- [`PLANO_HOMOLOGACAO.md`](PLANO_HOMOLOGACAO.md) — resumo rápido (este guia é a versão detalhada)
- [`../README.md`](../README.md) — índice do repositório

# Processo de Homologação SBR-Edge — em 4 Atos

> Plano **operacional** (quem faz o quê, em que ordem). Para o detalhe técnico
> de cada etapa, ver o documento mestre
> [`GUIA_COMPLETO_HOMOLOGACAO_ANATEL.md`](GUIA_COMPLETO_HOMOLOGACAO_ANATEL.md).
>
> **Regra de ouro:** cada Ato só começa quando o **portão (gate)** do anterior
> for aprovado. Isso evita gastar com o lab antes de a SBR ter fechado o que vai
> ser homologado.

```
[ATO 1] Definir + confirmar      → portão: SBR aprova a ficha do produto
   │
[ATO 2] Consultar OCD/lab        → portão: escopo, custo e prazo aceitos
   │
[ATO 3] Amostras + teste interno → portão: bancada OK, roteiro validado
   │
[ATO 4] Despachar + acompanhar   → portão: nº de homologação Anatel emitido
```

---

## ATO 1 — Confirmar o que estamos homologando (interno SBR)

**Objetivo:** travar internamente a definição do produto **antes** de falar com
o lab. Nada vai para fora sem este aceite.

- **Responsável:** SBR (com apoio técnico).
- **Documento:** [`ATO1_DEFINICAO_PRODUTO.md`](ATO1_DEFINICAO_PRODUTO.md) — ficha
  com tudo já definido + os poucos itens em aberto (ex.: **potência de série**).
- **Ações:**
  - [ ] Revisar a ficha de definição do produto.
  - [ ] Fechar o item pendente: **potência máxima de série** (rec. 20 dBm).
  - [ ] Confirmar **antena** (modelo original — ganho/conector).
  - [ ] Confirmar **nome do fabricante** que constará na homologação.
- **🚪 PORTÃO 1:** SBR **assina/aprova** a ficha. → libera o Ato 2.

---

## ATO 2 — Enviar intenção ao OCD/lab e pedir projeto + custos

**Objetivo:** com a definição aprovada, consultar o OCD/lab (já contratado) para
**confirmar escopo, custo e prazo** — e atualizar o projeto se algo mudar.

- **Responsável:** SBR → OCD/lab.
- **Documento:** [`ATO2_PERGUNTAS_OCD.md`](ATO2_PERGUNTAS_OCD.md) — contexto já
  definido + perguntas que só eles respondem.
- **Ações:**
  - [ ] Enviar o documento ao contato do OCD/lab.
  - [ ] Receber: **categoria**, **lista de ensaios**, **Atos vigentes**,
        **nº de amostras**, **custo/prazo**, **regra de módulo plugável**.
  - [ ] Ajustar o projeto/orçamento conforme a resposta.
- **🚪 PORTÃO 2:** SBR **aceita** escopo + custo + prazo. → libera o Ato 3.

---

## ATO 3 — Preparar amostras e roteiro; testar aqui antes de despachar

**Objetivo:** montar as amostras na configuração final e **validar na bancada**
(gravar firmwares, confirmar que cada rádio entra em modo de teste) — para não
descobrir problema só no laboratório.

- **Responsável:** SBR (técnico).
- **Documento:** [`ATO3_AMOSTRAS_E_ROTEIRO.md`](ATO3_AMOSTRAS_E_ROTEIRO.md) —
  preparo das amostras + checklist de teste de bancada + roteiro de ensaio.
- **Ações:**
  - [ ] Montar **N amostras** (qtde confirmada no Ato 2), idênticas, numeradas.
  - [ ] Gravar e validar **firmware LoRa** (CW/MOD em 915–928).
  - [ ] Gravar e validar **RF Test ESP32** (WiFi/BLE entra em modo de teste).
  - [ ] Gravar **firmware de série travado** (915–928) na config final.
  - [ ] Conferir o **roteiro de ensaio** (canais/potência) com a bancada.
- **🚪 PORTÃO 3:** bancada OK e roteiro validado. → libera o Ato 4.

---

## ATO 4 — Despachar para o lab e acompanhar a homologação

**Objetivo:** entregar amostras + documentação ao lab e conduzir até o
**número de homologação** da Anatel.

- **Responsável:** Lab → OCD → Anatel (SBR acompanha).
- **Ações:**
  - [ ] Despachar amostras + firmwares de teste + roteiro + documentação técnica.
  - [ ] Lab executa ensaios → emite **relatórios**.
  - [ ] OCD analisa → emite **Certificado de Conformidade**.
  - [ ] Pedido de homologação na Anatel (definir no Ato 2 **quem submete**).
  - [ ] Pagar **taxa (GRU)** → sai o **número de homologação**.
  - [ ] Aplicar **selo definitivo** (nº + QR) e atualizar manual/embalagem.
- **🚪 PORTÃO 4:** **número de homologação Anatel emitido** e publicado. ✅

---

## Onde cada coisa está

| Ato | Documento | Mapeia para (GUIA) |
|---|---|---|
| 1 | `ATO1_DEFINICAO_PRODUTO.md` | Fase 1 (enquadramento) |
| 2 | `ATO2_PERGUNTAS_OCD.md` | Fase 1 (escopo/OCD) |
| 3 | `ATO3_AMOSTRAS_E_ROTEIRO.md` | Fases 2–4 + Seção 7 (roteiro) |
| 4 | (este doc, seção Ato 4) | Fases 5–8 |

# Perguntas ao OCD / Laboratório — Homologação SBR-Edge (Heltec WiFi LoRa 32 V2)

> **Como usar:** envie ao OCD/laboratório já contratado. O objetivo é fechar
> **escopo, custo e logística** numa única rodada. O bloco "Contexto já
> definido" dá a eles tudo para responder de uma vez — peça que respondam item
> a item.
>
> *Destinatário:* **[nome do contato / empresa do OCD]**
> *Remetente:* SBR — **[seu nome / cargo]**

---

## Contexto já definido (não é pergunta — é informação)

| Item | Definição SBR |
|---|---|
| Produto | Módulo **Heltec WiFi LoRa 32 V2** (ESP32 + SX1276 + WiFi + BLE) |
| Modelo comercial | **SBR-Edge** |
| Forma de homologação | **Placa nua (módulo plugável)** — será integrada em produtos host da SBR |
| Rádios | LoRa 900 MHz (SX1276) + WiFi 2,4 GHz + BLE 2,4 GHz (1 homologação cobrindo os 3) |
| Plano de frequência LoRa | **915–928 MHz (AU915)** — apenas esta sub-faixa; 902–907,5 não será declarada |
| Potência LoRa | **20 dBm** (100 mW) de série |
| Antena | modelo **original** do kit Heltec (~2–3 dBi, u.FL/IPEX) |
| Firmware de série | travado em 915–928 MHz |
| Firmwares de teste | LoRa (CW/MOD por serial) **pronto** + RF Test ESP32 (WiFi/BLE) **já baixado** |
| Titular | SBR (fabricante/importador declarado) |

---

## Perguntas (o que precisamos que vocês definam)

### A. Escopo e custo
1. Qual a **categoria** do produto e a **lista exata de ensaios**? Inclui apenas
   RF, ou também **EMC** e **segurança elétrica**?
2. Quais **Atos de procedimento de ensaio** vigentes vocês usarão para **LoRa,
   WiFi e BLE**?
3. **Exposição a campos EM (SAR/MPE):** será exigido **ensaio** ou basta
   **declaração/avaliação simplificada** (dada a baixa potência)?
4. Qual o **prazo** estimado e o **custo total** (ensaios + certificação + taxas)?

### B. Módulo plugável (ponto-chave do projeto)
5. Podemos homologar a **placa nua como módulo** e **reaproveitá-la em vários
   produtos host** da SBR **sem reensaiar** cada produto? Quais as **condições**?
6. O reaproveitamento exige manter **front-end de RF e antena inalterados**?
   Há alguma outra restrição (categoria do host, blindagem, etc.)?
7. Como fica a **rotulagem no produto host** — basta o nº de homologação
   visível? Precisa constar no manual do host?

### C. Amostras e firmwares
8. Quantas **unidades de amostra** vocês precisam, e em qual configuração
   (com firmware de série travado + firmwares de teste)?
9. Vocês já operam a **RF Test Tool do ESP32** (WiFi/BLE)? Se preferirem,
   **enviamos os firmwares oficiais** que já baixamos.

### D. Rotulagem e submissão
10. Qual o **formato vigente do selo** Anatel (com **QR Code**) e a arte exigida?
11. Sendo **placa pequena**, há regra específica de **onde aplicar o selo**
    (na placa, na embalagem, ou no produto host)?
12. **Quem submete** o pedido de homologação na Anatel — vocês (OCD) ou a SBR?

### E. Documentação
13. Qual a **lista completa de documentos** que vocês exigem de nós? (Temos:
    ficha técnica, esquemático Heltec, datasheets SX1276/ESP32, fotos da placa,
    especificação de antena, lista de frequências/potências. Falta algo?)

---

*Confirmações rápidas (esperamos "sim", mas vale registrar):*
- 14. **915–928 MHz** está OK como única faixa LoRa declarada? Há limite de
  potência/EIRP específico nessa sub-faixa?
- 15. Os **três rádios** (LoRa/WiFi/BLE) serão ensaiados mesmo que um host
  específico use só LoRa — correto?

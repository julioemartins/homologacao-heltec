# E-mail de status para o time da SBR

> Rascunho pronto para enviar. Ajuste saudação/assinatura e cole no e-mail.

---

**Assunto:** Homologação Anatel do SBR-Edge — escopo confirmado e status (firmwares prontos)

---

Olá, time SBR,

Compartilho onde estamos no processo de homologação do nosso módulo **SBR-Edge**
(baseado no Heltec WiFi LoRa 32 V2) junto à Anatel.

## 1. Escopo confirmado

Vamos homologar a **placa como módulo plugável**, para que possa ser integrada
em vários produtos da SBR **sem precisar reensaiar cada produto** (condição a
ser formalizada com o organismo de certificação). Uma única homologação cobre os
**três rádios** da placa.

| Item | Definição |
|---|---|
| Modelo comercial | **SBR-Edge** |
| Forma de homologação | **Módulo plugável (placa nua)** — sem case |
| Rádios no escopo | **LoRa 900 MHz + WiFi 2,4 GHz + BLE** |
| Faixa LoRa | **915–928 MHz** (padrão AU915) |
| Potência | **20 dBm** (100 mW) |
| Antena | modelo original do kit (~2–3 dBi) |
| Firmware de série | **travado** na faixa homologada (915–928 MHz) |

*(Pendente apenas o dado cadastral — razão social/CNPJ — para o registro de
fabricante.)*

## 2. Status atual

**Os dois firmwares necessários já estão prontos.** Falta somente a **validação
de bancada**, que farei **entre hoje e amanhã** (gravar nas placas e confirmar
que cada rádio entra corretamente em modo de teste). Em paralelo, podemos acionar
o laboratório/OCD para fechar escopo de ensaios, custo e prazo.

## 3. Um ponto que merece destaque — engenharia de firmware

A homologação exige firmwares que coloquem cada rádio em **modo de transmissão
controlada** para as medições do laboratório. Aqui está a diferença importante do
nosso caso:

- Por usarmos o **Heltec** (e não um módulo "puro" da Espressif), a placa tem um
  rádio **LoRa SX1276 (Semtech)** que **não é coberto** pelo ferramental de
  certificação da Espressif — ou seja, **não existe firmware pronto** para ele.
- Foi necessário **desenvolver esses firmwares do zero, exclusivamente para a
  homologação**:
  1. um **firmware de teste** do LoRa (portadora contínua e transmissão modulada,
     comandável por serial nos canais e potência exigidos pelo ensaio); e
  2. o **firmware de série** com a **trava regulatória** que impede o produto de
     operar fora de 915–928 MHz — requisito para manter a conformidade.
- Para o WiFi/BLE (ESP32) aproveitamos o firmware oficial da Espressif, mas a
  parte de LoRa — que é justamente o diferencial do produto — **só foi viabilizada
  por desenvolvimento nosso**.

Em resumo: sem esse trabalho de engenharia, a homologação do rádio LoRa **não
seria possível** com firmware de prateleira. Ele está concluído e documentado.

## 4. Próximos passos

1. **Validação de bancada** dos firmwares (hoje/amanhã) — eu conduzo.
2. **Enviar uma amostra do Heltec** ao laboratório, acompanhada do **roteiro de
   ensaio dos 3 rádios** que preparei (define modos, canais e potência por rádio).
3. **Execução dos ensaios** pelo laboratório → relatórios → certificação (OCD) →
   número de homologação (Anatel).

Precisamos de vocês apenas para: **(a)** confirmar a razão social/CNPJ para o
registro e **(b)** validar que **20 dBm** atende ao uso pretendido.

Qualquer dúvida, fico à disposição.

Abraços,
[seu nome]
[cargo / contato]

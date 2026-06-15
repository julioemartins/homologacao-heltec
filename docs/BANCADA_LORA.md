# Bancada — Verificar o rádio LoRa (SX1276) aqui

> Passo a passo para **você confirmar, na sua mesa**, que o firmware LoRa está se
> comportando bem **antes** de mandar ao laboratório. Não mede conformidade de RF
> (isso é no lab) — confirma que o rádio inicia, entra em CW/MOD e respeita a faixa.

**Ferramentas já instaladas nesta máquina:** `arduino-cli` (core esp32 + RadioLib),
`esptool`, `pyserial`. Não precisa instalar nada.

---

## 0. Conectar a placa

1. Ligue a Heltec V2 no USB.
2. Descubra a porta:
   ```bash
   ls /dev/cu.*
   # ou:
   python3 firmware/lora-sx1276/teste_bancada.py --list
   ```
   Anote algo como `/dev/cu.usbserial-0001` ou `/dev/cu.SLAB_USBtoUART`.

> Rode os comandos a partir da raiz do repositório
> (`.../Homologacao - Anatel/lora`).

---

## 1. Gravar o firmware de TESTE

```bash
PORTA=/dev/cu.usbserial-0001     # <-- ajuste para a sua porta
FQBN=esp32:esp32:heltec_wifi_lora_32_V2

arduino-cli compile --fqbn $FQBN firmware/lora-sx1276/heltec_v2_sx1276_anatel_testmode
arduino-cli upload  --fqbn $FQBN -p $PORTA firmware/lora-sx1276/heltec_v2_sx1276_anatel_testmode
```

> Já confirmamos aqui que **compila sem erros** (usa ~11% da flash). Se o upload
> falhar, segure **PRG/BOOT** ao iniciar e tente de novo.

---

## 2. Teste automático (valida o roteiro por serial)

```bash
python3 firmware/lora-sx1276/teste_bancada.py $PORTA
```

O script envia `P20 → F915.2/CW → F921.5 → F927.8 → STOP → …/MOD…` e confere as
respostas. **Esperado:** no fim, `PASS` em todas as linhas e:

```
✔ Firmware LoRa respondeu a todo o roteiro como esperado.
```

Inclui um passo que manda `F902.2` e espera o **aviso de fora-de-faixa** — ou
seja, também confirma que o firmware "sabe" os limites brasileiros.

### Conferência manual (opcional)
Abra o serial e digite à mão:
```bash
screen $PORTA 115200      # sair: Ctrl-A depois K
```
Comandos: `?`  `P20`  `F915.2`  `CW`  `MOD`  `STOP`. Deve responder `>> CW ON`,
`>> MOD ON`, e imprimir o estado.

---

## 3. Confirmar o RF de verdade (opcional, recomendado)

O teste acima prova a **lógica**. Para ver o **sinal saindo**:

- **Com SDR (RTL-SDR ~R$150):** abra um app de waterfall (CubicSDR, SDR++),
  sintonize **915,2 MHz**, mande `F915.2` + `CW` e veja a **portadora** aparecer.
  Repita em 921,5 e 927,8. Em `MOD`, vê-se o sinal mais largo (modulado).
- **Sem SDR:** fica para o laboratório (analisador calibrado).

> ⚠️ Mantenha a **antena conectada** sempre que transmitir (CW/MOD), para não
> danificar o PA do SX1276.

---

## 4. Verificar a TRAVA do firmware de SÉRIE

O firmware de série só pode operar em 915–928. Para confirmar:

```bash
arduino-cli compile --fqbn $FQBN firmware/lora-sx1276/heltec_v2_sx1276_serie_915_928
arduino-cli upload  --fqbn $FQBN -p $PORTA firmware/lora-sx1276/heltec_v2_sx1276_serie_915_928
screen $PORTA 115200
```

No boot ele roda um **auto-teste** e você deve ver:
```
[auto-teste] tentando 902.2 MHz (deve ser RECUSADO):
[TRAVA] Frequencia 902.200 MHz RECUSADA (fora de 915-928). Mantida a anterior.
[auto-teste] tentando 868.0 MHz (deve ser RECUSADO):
[TRAVA] Frequencia 868.000 MHz RECUSADA ...
TX beacon @ 921.5 MHz -> OK
```
Isso comprova que o produto de série **não transmite fora da faixa homologada**.

---

## Checklist

- [ ] Porta serial identificada.
- [ ] Firmware de teste gravado.
- [ ] `teste_bancada.py` → tudo **PASS**.
- [ ] (Opcional) SDR mostrou portadora em 915,2 / 921,5 / 927,8.
- [ ] Firmware de série: auto-teste **recusa** 902/868 e faz beacon em 921,5.

→ LoRa OK. Ver também [`BANCADA_WIFI_BLE.md`](BANCADA_WIFI_BLE.md) e o
[`ROTEIRO_HOMOLOGACAO.md`](ROTEIRO_HOMOLOGACAO.md).

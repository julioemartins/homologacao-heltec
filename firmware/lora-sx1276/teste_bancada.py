#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Teste de bancada do firmware LoRa de TESTE (heltec_v2_sx1276_anatel_testmode.ino).

O que faz: conecta na placa por serial, roda o roteiro de homologacao LoRa
(915-928 MHz, CW e MOD nos canais baixo/meio/alto a 20 dBm) e VALIDA as respostas
esperadas do firmware. Gera um log com PASS/FAIL.

NAO mede RF (isso e' no lab / com SDR). Confirma que o radio inicia e entra
em cada modo corretamente, e que a trava de faixa do firmware avisa fora dela.

Uso:
    python3 teste_bancada.py                # auto-detecta a porta
    python3 teste_bancada.py /dev/cu.usbserial-0001
    python3 teste_bancada.py --list         # so lista as portas

Requer: pyserial  (ja instalado:  python3 -m pip install --user pyserial)
"""
import sys
import time

try:
    import serial
    from serial.tools import list_ports
except ImportError:
    sys.exit("Falta pyserial. Rode: python3 -m pip install --user pyserial")

BAUD = 115200

# (comando, substring que DEVE aparecer na resposta)  -- None = so envia
ROTEIRO = [
    ("?",       "Modo"),
    ("P20",     "Potencia = 20"),
    ("F915.2",  "915.2"),
    ("CW",      "CW ON"),
    ("F921.5",  "921.5"),
    ("F927.8",  "927.8"),
    ("STOP",    "STOP"),
    ("F915.2",  "915.2"),
    ("MOD",     "MOD ON"),
    ("F921.5",  "921.5"),
    ("F927.8",  "927.8"),
    ("STOP",    "STOP"),
    # Verifica a TRAVA/aviso de faixa (fora de 915-928 deve avisar):
    ("F902.2",  "AVISO"),
    ("STOP",    "STOP"),
]


def achar_porta():
    cands = [p.device for p in list_ports.comports()
             if any(k in p.device.lower() for k in
                    ("usbserial", "slab", "wch", "usbmodem", "uart"))]
    return cands[0] if cands else None


def ler_resposta(ser, espera=1.2):
    """Le tudo que chegar dentro de 'espera' segundos."""
    fim = time.time() + espera
    buf = b""
    while time.time() < fim:
        n = ser.in_waiting
        if n:
            buf += ser.read(n)
            fim = time.time() + 0.3   # estende um pouco apos receber
        else:
            time.sleep(0.02)
    return buf.decode(errors="replace")


def main():
    args = [a for a in sys.argv[1:]]
    if "--list" in args:
        ports = list(list_ports.comports())
        if not ports:
            print("Nenhuma porta serial encontrada.")
        for p in ports:
            print(f"  {p.device}   {p.description}")
        return

    porta = next((a for a in args if not a.startswith("-")), None) or achar_porta()
    if not porta:
        sys.exit("Nenhuma placa detectada. Conecte via USB ou passe a porta:\n"
                 "  python3 teste_bancada.py /dev/cu.usbserial-XXXX\n"
                 "  (use --list para ver as portas)")

    print(f">> Abrindo {porta} @ {BAUD} ...")
    ser = serial.Serial(porta, BAUD, timeout=1)
    time.sleep(2.0)              # aguarda reset/boot do ESP32
    boot = ler_resposta(ser, 2.0)
    print("---- boot ----")
    print(boot.strip() or "(sem saida de boot)")
    if "SX1276" in boot and "OK" in boot:
        print(">> Radio reportou SX1276 OK no boot.")
    elif "FALHA" in boot:
        print("!! Boot reportou FALHA ao iniciar o SX1276 — confira a placa (V2?).")
    print("--------------\n")

    passes, fails = 0, 0
    for cmd, esperado in ROTEIRO:
        ser.reset_input_buffer()
        ser.write((cmd + "\n").encode())
        resp = ler_resposta(ser)
        ok = (esperado is None) or (esperado.upper() in resp.upper())
        tag = "PASS" if ok else "FAIL"
        if ok:
            passes += 1
        else:
            fails += 1
        primeira = " | ".join(l.strip() for l in resp.splitlines() if l.strip())[:90]
        print(f"[{tag}] {cmd:<8} (espera '{esperado}')  ->  {primeira}")

    ser.write(b"STOP\n")
    ler_resposta(ser, 0.5)
    ser.close()

    print("\n==================  RESUMO  ==================")
    print(f"  PASS: {passes}   FAIL: {fails}")
    if fails == 0:
        print("  ✔ Firmware LoRa respondeu a todo o roteiro como esperado.")
        print("    (RF de verdade: confirmar com SDR/analisador — ver BANCADA_LORA.md)")
    else:
        print("  ✗ Houve falhas — ver linhas FAIL acima.")
    print("=============================================")
    sys.exit(1 if fails else 0)


if __name__ == "__main__":
    main()

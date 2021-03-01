# Register im Allgemeinen

Hier eine kleine Zusammenfassung der Entwicklung der x86-er Register:

- [intel 8080](intel8080.md) 8 Bit Register und Flags
- [intel 8086](intel8086.md) 16 Bit Register und Flags
- [intel 80386](intel80386.md) 32 Bit Register und Flags

## Erweiterung der Register

Die Register wurden mit der Zeit schrittweise erweitert von 8 Bit auf 16, 32 und 64 Bit. Die Benennung Der Register durch die Erweiterung ergibt zum Beispiel von AX wie folgt

- 64 Bit: RAX (R für Register)
- 32 Bit: EAX (E für Extended)
- 16 Bit: AX  (Hier könne X auf den He*X*adezimal hinweisen?!)

Somit wurden die Register EAX, ECX, EDX, EBX, ESP, EBP, ESI EDI zu RAX, RCX, RDX, RBX, RSP, RBP, RSI RDI.
Zusätzlich sind noch acht neue register hinzugekommen. R8, R9, R10, R11, R12, R13, R14 und R15.

Der Register EIP hat ebenfall einen großen Bruder bekommen RIP.

Der Zusammenhang zwischen den 64, 32 und 16 Bit Registern als Bild für den Register RAX.

```
   8     7     6     5     4     3     2     1 
+-----+-----+-----+-----+-----+-----+-----+-----+
|                      RAX                      |
+-----+-----+-----+-----+-----+-----+-----+-----+
|                       |          EAX          |
+-----+-----+-----+-----+-----+-----+-----+-----+
|                                   |    AX     |
+-----+-----+-----+-----+-----+-----+-----+-----+
|                                   | AH  | AL  |
+-----+-----+-----+-----+-----+-----+-----+-----+

```
- Der Register RAX belegt 64 Bit = 8 Byte.
- Der Register EAX belegt 32 Bit = 4 Byte.
- Der Register AX belegt 16 Bit = 2 Byte.
- Die Register AH und AL belegen 8 Bit = 1 Byte. Somit zerfällt der Register AX in AH und AL. AH steht für den  High-Byte und AL für den Low-Byte des Registers AX.

Diese Aufteilung gilt nur für die Register AX, BX, CX, DX (GPR). Bei den Registern SP, BP, SI und DI kann nur auf den Low-Byte zugegriffen werden. Aso zum Beispie für den SP Register

```
   8     7     6     5     4     3     2     1 
+-----+-----+-----+-----+-----+-----+-----+-----+
|                      RSP                      |
+-----+-----+-----+-----+-----+-----+-----+-----+
|                       |          ESP          |
+-----+-----+-----+-----+-----+-----+-----+-----+
|                                   |    SP     |
+-----+-----+-----+-----+-----+-----+-----+-----+
|                                         | SPL |
+-----+-----+-----+-----+-----+-----+-----+-----+

```
und hier als Beisiel für den Register R1
```
   8     7     6     5     4     3     2     1 
+-----+-----+-----+-----+-----+-----+-----+-----+
|                      R1                       |
+-----+-----+-----+-----+-----+-----+-----+-----+
|                       |          R1D          |
+-----+-----+-----+-----+-----+-----+-----+-----+
|                                   |    R1W    |
+-----+-----+-----+-----+-----+-----+-----+-----+
|                                         | R1B |
+-----+-----+-----+-----+-----+-----+-----+-----+

```


```
      Register
Bit   16 Bit  8 Bit
------------------
 0     AX      AL
 1     CX      CL
 2     DX      DL
 3     BX      BL
 4     SP      AH
 5     BP      CH
 6     SI      DH
 7     DI      BH
```

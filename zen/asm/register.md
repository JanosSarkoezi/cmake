# Register im Allgemeinen

Es gibt acht Register für allgemeinen Zweck (General Purpose Register) auf 16 Bit ebene

```
Register  Name   
---------------------------
AX        Accumulator
CX        Counter
DX        Data 
BX        Base
SP        Stack Pointer
BP        Stack Base Pointer
SI        Source
DI        Destination
---------------------------
```

Benutzung der Register

- *AX* Wird für arithmetische Operationen benutzt.
- *CX* Wird in shift/rotation Anweisungen benutzt.
- *DX* Wird für aritmethische und I/O Operationen benutzt.
- *BX* Wird als Zeiger auf Daten benutzt (wenn im segmentierten Modus arbeiten, dann im Segment Register DS).
- *SP* Wird als Zeiger auf den Stack benutzt. Zeigt auf das Ende des Stacks.
- *BP* Wird als Zeiger auf den Stack benutzt. Zeigt auf den Beginn des Stacks.
- *SI* Wird als Zeiger auf eine Quellen (Source) in Stream Operationen benutzt.
- *DI* Wird als Zeiger auf einen Ziel (Destination) in Stream Operationen benutzt.

## Erweiterung der Register

Die Register wurden mit der Zeit schrittweise erweitert von 8 Bit auf 16, 32 und 64 Bit. Die Benennung Der Register durch die Erweiterung ergibt zum Beispiel von AX wie folgt

- 64 Bit: RAX (R für Register)
- 32 Bit: EAX (E für Extended oder Enhanced)
- 16 Bit: AX  (Hier könne X auf den He*X*adezimal hinweisen?!)

Der Zusammenhang zwischen den 64, 32 und 16 Bit Registern als Bild

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
- Die Register AH und AL belegen 8 Bit = 1 Byte. Somit zerfällt der Register AX in AH und AL.

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

# Register im Allgemeinen

## 8 Bit Register (Intel 8080)

### Register

- Bei Intel 8080 gab es 10 Register A, B, C, D, E, H, L. SP, PC und ein Status Register.

Benutzung der Register

Der Register A war der Akkumulator. Die anderen sechs Register konnten individuell als 8 Bit oder als drei 16 Bit Register genutzt werden. Die Paarung der Register war BC, DE und HL.
- Die zwei 16 Bit Register
-- SP (Stack Pointer). Dieser Register referenzierte Speicheradressen auf dem Stack.
-- PC (Program Count) oder IP (Instruction Pointer).
- Status Register. Dieser Register wurde interne Flag-Bits benutzt.

### Flags
```
  7   6   5   4   3   2   1   0
+---+---+---+---+---+---+---+---+
| S | Z | 0 |AC | 0 | P | 0 | C |
+---+---+---+---+---+---+---+---+
```
- *C* Carry. Wird gesetzt, wenn nach einer arithmetischen Operation ein Übertrag entstanden ist.
- *P* Parity. Wird gesetzt, wenn die Anzahl der 1-er Bits in einem Ergebnis gerade war.
- *AC* Auxiliary Carry. Wird gesetzt, wenn ein Übertrag vom Bit 3 zum Bit 4 entstanden ist.
- *Z* Zero. Wird gesetzt, wenn das Resultat des ausgeführten Befehls eine Null ergeben hat.
- *S* Sign. Wird gesetzt, wenn das Resultat des ausgeführten Befehls eine negative Zahl ergeben hat.

## 16 Bit Register (Intel 8086)

### Register
Die Register für allgemeinen Zweck (General Purpose Register).

- *AX* Wird für arithmetische Operationen benutzt. (Accumulator)
- *CX* Wird in shift/rotation Anweisungen benutzt. (Counter)
- *DX* Wird für aritmethische und I/O Operationen benutzt. (Data)
- *BX* Wird als Zeiger auf die Daten benutzt (lokal in den Segment Register DS). (Base)
- *SP* Wird als Zeiger auf das Ende des Stack benutzt. (Stack Pointer)
- *BP* Wird als Zeiger auf den Angang des Stacks benutzt. (Stack Base Pointer)
- *SI* Wird als Zeiger auf die Quelle einer Stream-Operation benutzt. (Source Index Register)
- *DI* Wird als Zeiger auf das Zeil einer Stream-Operation benutzt. (Destination Index Register)

Die Segment Register 

- *SS* Zeiger für den Stack. (Stack Segment)
- *CS* Zeiger für den Code. (Code Segment)
- *DS* Zeiger für die Daten. (Data Segment)
- *ES* Zeiger für den Extra Daten. (Extra Segment)
- *FS* Zeiger für den mehr Extra Daten. (F kommt hinter E)
- *GS* Zeiger für den noch mehr Extra Daten. (G kommt hinter F)

### Flags
EFlags Register

```
 31  30  29  28  27  26  25  24  23  22  21  20  19  18  17  16
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |ID |VIP|VIF|AC |VM |RF |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+

 15  14  13  12  11   10  9   8   7   6   5   4   3   2   1   0
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| 0 |NT | IOPL  |OF |DF |IF |TF |SF |ZF | 0 |AF | 0 |PF | 1 |CF |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
```

- *CF* Carry Flag. Wird gesetzt, wenn wenn nach einer arithmetischen Operation (Addition, Subtraktion) ein Übertrag entstanden ist.
Dies wird dann überprüft, wenn auf die Operation ein Add-with-Carry oder Subtrahieren-mit-Borrow folgt, um mit Werten umzugehen,
die zu groß sind, als dass nur ein Register sie enthalten könnte.
- *PF* Parity Flag. Wird gesetzt, wenn die Anzahl der gesetzten Bits in der niedrigstwertigen Byte ein Vielfaches von 2 ist.
- *AF* Adjust Flag. Wird gesetzt, beim Übertragen von BCD-Zahlen (Binary Code Decimal) arithmetische Operationen.
- *ZF* Zero Flag. Wird gesetzt, wenn das Resultat des ausgeführten Befehls eine Null ergeben hat.
- *SF* Sign Flag. Wird gesetzt, wenn das Resultat des ausgeführten Befehls eine negative Zahl ergeben hat.
- *TF* Trap Flag. Wird gesetzt bei schrittweise Debuggen.
- *IF* Interruption Flag. Wird gesetzt, wenn eine Unterbrechung (interrupt) eingeschaltet ist.
- *DF* Direction Flag. Richtung eines Streams. Wenn gesetzt ist, dann wird der Zeiger der String-Operationen rückwerts abgearbeitet. Der Speicher wird rückwerts gelesen.
- *OF* Overflow Flag. Wird gesetzt, wenn eine arithmetische Operation zu groß für Register ist, der dieses Ergebnis aufnehmen sollte.
- *IOPL* I/O Privilege Level field (2 bits). I/O Privileg Stufe des Prozesses.
- *NT* Nested Task flag. Kontrolliert das Verketten der Unterbrechungen (interrupts). Wird gesetzt, wenn der aktuelle Prozess mit dem nächsten Prozess verbunden ist.
- *RF* Resume Flag. Antwort zu dem Fehler eines Debuggens.
- *VM* Virtual-8086 Mode. Ist im 8086 Kombatibilitäts modus gesetzt.
- *AC* Alignment Check. Wird gesetzt, wenn die Ausrichtungsprüfung der Speicherreferenzen durchgeführt ist.
- *VIF* Virtual Interrupt Flag. Virtuelles Bild des IF.
- *VIP* Virtual Interrupt Pending flag. Wird gesetzt, wenn eine Unterbrechung aussteht.
- *ID* Identification Flag. Unterstützung für CPUID-Anweisungen, falls eingestellt werden kann.

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

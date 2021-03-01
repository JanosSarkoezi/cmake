# 16 Bit Register (Intel 8086)

## Register
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
- *ES* Zeiger für die Extra Daten. (Extra Segment)

Programm Zähler

- *IP* Beinhaltet die Adresse des aktuell auszufürenden Assemblerbefehls. (Instruction Pointer)

## Flags
Flags Register

```
 15  14  13  12  11   10  9   8   7   6   5   4   3   2   1   0
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| 0 | 0 | 0 | 0 | O | D | I | T | S | Z | 0 | A | 0 | P | 1 | C |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
```

- *C* Carry Flag. Wird gesetzt, wenn wenn nach einer arithmetischen Operation (Addition, Subtraktion) ein Übertrag entstanden ist.
Dies wird dann überprüft, wenn auf die Operation ein Add-with-Carry oder Subtrahieren-mit-Borrow folgt, um mit Werten umzugehen,
die zu groß sind, als dass nur ein Register sie enthalten könnte.
- *P* Parity Flag. Wird gesetzt, wenn die Anzahl der gesetzten Bits in der niedrigstwertigen Byte ein Vielfaches von 2 ist.
- *A* Adjust Flag. Wird gesetzt, beim Übertragen von BCD-Zahlen (Binary Code Decimal) arithmetische Operationen.
- *Z* Zero Flag. Wird gesetzt, wenn das Resultat des ausgeführten Befehls eine Null ergeben hat.
- *S* Sign Flag. Wird gesetzt, wenn das Resultat des ausgeführten Befehls eine negative Zahl ergeben hat.
- *T* Trap Flag. Wird gesetzt bei schrittweise Debuggen.
- *I* Interruption Flag. Wird gesetzt, wenn eine Unterbrechung (interrupt) eingeschaltet ist.
- *D* Direction Flag. Richtung eines Streams. Wenn gesetzt ist, dann wird der Zeiger der String-Operationen rückwerts abgearbeitet. Der Speicher wird rückwerts gelesen.
- *O* Overflow Flag. Wird gesetzt, wenn eine arithmetische Operation zu groß für Register ist, der dieses Ergebnis aufnehmen sollte.

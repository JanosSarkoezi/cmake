# 8 Bit Register (Intel 8080)

## Register

- Bei Intel 8080 gab es 10 Register A, B, C, D, E, H, L. SP, PC und ein Status Register.

Benutzung der Register

Der Register A war der Akkumulator. Die anderen sechs Register konnten individuell als 8 Bit oder als drei 16 Bit Register genutzt werden. Die Paarung der Register war BC, DE und HL.
- Die zwei 16 Bit Register
    - SP (Stack Pointer). Dieser Register referenzierte Speicheradressen auf dem Stack.
    - PC (Program Count) oder IP (Instruction Pointer).

## Flags
```
  7   6   5   4   3   2   1   0
+---+---+---+---+---+---+---+---+
| S | Z | 0 | A | 0 | P | 0 | C |
+---+---+---+---+---+---+---+---+
```
- *C* Carry. Wird gesetzt, wenn nach einer arithmetischen Operation ein Übertrag entstanden ist.
- *P* Parity. Wird gesetzt, wenn die Anzahl der 1-er Bits in einem Ergebnis gerade war.
- *A* Auxiliary Carry. Wird gesetzt, wenn ein Übertrag vom Bit 3 zum Bit 4 entstanden ist.
- *Z* Zero. Wird gesetzt, wenn das Resultat des ausgeführten Befehls eine Null ergeben hat.
- *S* Sign. Wird gesetzt, wenn das Resultat des ausgeführten Befehls eine negative Zahl ergeben hat.

# x86 Meditations

Erstellen ein mini C Programm im Verzeichnis /tmp. Der Name der Date sei t.c
```C
float getFloat() {
    return 1.1f;
}

int main(int argc, char ** argv) {
    float f = getFloat();
    return 0;
}
```
und lassen es mit
```
gcc t.c
```
compilieren, wenn wir im Verzeichnis /tmp sind. Jetzt können wir ein hexdump mit
```
hexdump -C /tmp/a.out -n 128 -s $((0))
```
ausfüren und bekommen den Anfang der Date, genauer 128 Byte zu sehen. Bei mir sieht das so aus:
```
00000000  7f 45 4c 46 02 01 01 00  00 00 00 00 00 00 00 00  |.ELF............|
00000010  03 00 3e 00 01 00 00 00  f0 04 00 00 00 00 00 00  |..>.............|
00000020  40 00 00 00 00 00 00 00  00 19 00 00 00 00 00 00  |@...............|
00000030  00 00 00 00 40 00 38 00  09 00 40 00 1c 00 1b 00  |....@.8...@.....|
00000040  06 00 00 00 04 00 00 00  40 00 00 00 00 00 00 00  |........@.......|
00000050  40 00 00 00 00 00 00 00  40 00 00 00 00 00 00 00  |@.......@.......|
00000060  f8 01 00 00 00 00 00 00  f8 01 00 00 00 00 00 00  |................|
00000070  08 00 00 00 00 00 00 00  03 00 00 00 04 00 00 00  |................|
00000080
```
Wenn wir nun Die Struktur dieser Datei mit der Beschreibung des [Headers](ELF-64.md) verstehen, so interessieren wir uns für die zweite Zeile der hexdump ausgabe
```
00000010  03 00 3e 00 01 00 00 00  f0 04 00 00 00 00 00 00  |..>.............|
                                   ^^^^^^^^^^^^^^^^^^^^^^^
```
speziell die mit `^` gekennzeichneten. Diese Bytes lesen wie dann von **rechs** nach **links** und erhalten so in der Kurzform `0x04f0`. Ach ja voher weiß man das, dass diese Bytes von rechts nach links zu lesen sind? Das steht auch im Header. Genauer in der 

## Operator Code (Opcode) Oktal
```
00o - AND
01o - OR
02o - ADC
03o - SBB
04o - AND
05o - SUB
06o - XOR
07o - CMP
```

## ModR/M

Mod
```
00 - Memory
01 - Memory [disp8]
10 - Memory [disp16]
11 - General Purpose Register
```

## Beispiele

Betrachte die Hexadezimale Darstellung der folgenden Anweisung:
```
23 0F
```
Umwandeln in binäre Darstellung ergibt
```
       23h        0Fh
0010 0011b  00001111b
```
Zu betrachten sind nun die Tabellen

- Table A-2. One-Byte opcode Map: (00H-F7H)
- Table 2-1. 16-Bit Addressing Forms with the ModR/M Bype

aus dem Dokument

- Interl 64 and IA-32 Architectures Software Developer's Manual Voume 2 (2A, 2B, 2C $ 2D): Instruction Set Reference, A-Z


```
+-------- Zeile  in der Tabelle (Table A-2.)
|+------- Spalte in der Tabelle (Table A-2.)
||
vv
23h          0Fh <-- Eintrag in der Tabelle (Table 2-1.)
     00 001 111b
     ^   ^   ^
     |   |   |
     |   |   +-- R/M      (Table 2-1.)
     |   +------ Register (Table 2-1.)
     +---------- Mod      (Table 2-1.)
```

Die Kreuzung der 2. Zeile mit der 3. Spalte in der Tabelle (Table A-2.) führt zu:
```
AND Gv,Ev
```

Dabei Steht Gv für (G)PR mit (V)ariable länge. Ev signaliziert das Folgen eines ModR/M Bytes, sodass der Operand ein word, double word GPR oder eine Memoryaddresse ist. In umserem Beispiel ist das foge Byte also ein ModR/M Byte.

Zerlegt man das Byte in Bites wie oben, so kann aus der Tabelle (Table 2-1.) zu den Werten
```
Mod      =  00
Register = 001
R/M      = 111
```
die Addresse des Registers [BX] und den Register CX finden.


Damit ergeben die Hexadezimalzahlen `23 0F` die Anweisung
```
AND CX, [BX]
```

Möchte man den Befel
```
AND [BX], CX
```
Kodieren. so kann die mit der Hilfe der Tabelle (Table 2-1.) vorgenommen werden und erhält
```
21 0F
```

Wenden wir uns dem Konvertieren einer Anweisung in 80386 (32-Bit) zu. Betrachten wir die Bytes
```
23 0C 8B
```
so sehen wir `23` an der erstenn Stellel. Dies Bedeutet ein One-Byte OpCode. Und Lesen aus der Tabelle (Table A-2) wie schon vorher
```
AND Gv,Ev
```
Gehen in die Tabelle (Table 2-2. 32-Bit Addressing Froms with the ModR/M Byte) und lesen zu `0C` was spezielles aus. Unter der Effektieve Address ist `[--][--]` zu sehen. Die Bedeutung dieser Zeichen ist, das nach dem ModR/M Byte ein SIB Byte folgt.
```
(S)cale = Der Multiplikator des Registers, der mit dem Index beschrieben wird.
(I)ndex = Der Register, der zu dem Index passt.
(B)ase  = Der Register, der zu dem Basis passt.
```
Die Informatioen zu den SIB können aus der Tabelle (Table 2-3.)
- Table 2-3 32-Bit Addressing Forms with the SIB Byte

entnommen weden. Das Byte `0C` beschreibt aber auch den Gv als `ECX`. Nur der Ev muss aus der SIB Byte ermittelt werden. Bei uns ist der SIB Byte `8B`. Zerlegen wir den SIB wie den ModR/M Byte:
```
        8Bh <--- Direkt ablesen aus (Table 2-3.)
10 001 011b
^   ^   ^
|   |   |
|   |   +-- B  (Table 2-3.)
|   +------ I  (Table 2-3.)
+---------- S  (Table 2-3.)

```
Oder Spass haben mit der Zerlegung von `8B` in `10 001 011`. Bedeutung der S-Bits.
```
0 =  1 * Register, der zu dem Index passt.
1 =  2 * Register, der zu dem Index passt.
2 =  4 * Register, der zu dem Index passt.
3 =  8 * Register, der zu dem Index passt.
```
Somit erhalten wir aus der Anaylse des SIB Byes
```
4 * ECX + EBX
```
Hier nochmal die Register zur Erinnerung von Oben.
```
0 - AX / AL
1 - CX / CL
2 - DX / CL
3 - BX / BL
4 - SP / AH
5 - BP / CH
6 - SI / DH
7 - DI / BH
```
Ein E musste vor den Registern, da wir in 32-Bit Modus sind.

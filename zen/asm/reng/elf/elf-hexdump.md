# Hexdump Beispiel

Wir erstellen eine C-Datei mit dem Namen `t.c` im `/tmp ` Verzeichnis. Hier der Inhalt der Datei:

```
int add(int x, int y) {
    return x + y;
}

int main(int argc, char **argv) {
    int z = add(2, 3);
    return 0;
}
```

Erstellt wir die ausführbaire Datei mit

```
gcc t.c
```

## Hexdump des ELF Headers

```
hexdump -n $((0x40)) -s $((0x0)) -C /tmp/a.out

00000000  7f 45 4c 46 02 01 01 00  00 00 00 00 00 00 00 00  |.ELF............|
00000010  03 00 3e 00 01 00 00 00  f0 04 00 00 00 00 00 00  |..>.............|
00000020  40 00 00 00 00 00 00 00  00 19 00 00 00 00 00 00  |@...............|
00000030  00 00 00 00 40 00 38 00  09 00 40 00 1c 00 1b 00  |....@.8...@.....|
00000040
```

Die Struktur des [ELF Haders](elf-header.md) in kurzer Form:

```
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|              e_i                |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|e_t|e_m|  e_v  |      e_e        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|      e_p      |      e_s        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  e_f  |e_h|eph|epn|esh|esn|esidx|
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

## Informationen

## e_indent

```
grep "define EI_" /usr/include/elf.h

#define EI_NIDENT (16)
#define EI_MAG0         0               /* File identification byte 0 index */
#define EI_MAG1         1               /* File identification byte 1 index */
#define EI_MAG2         2               /* File identification byte 2 index */
#define EI_MAG3         3               /* File identification byte 3 index */
#define EI_CLASS        4               /* File class byte index */
#define EI_DATA         5               /* Data encoding byte index */
#define EI_VERSION      6               /* File version byte index */
#define EI_OSABI        7               /* OS ABI identification */
#define EI_ABIVERSION   8               /* ABI version */
#define EI_PAD          9               /* Byte index of padding bytes */
```

### e_indent[EI_CLASS]

```
grep "ELFCLASS" /usr/include/elf.h | grep -w $((0x02))

#define ELFCLASS64      2               /* 64-bit objects */
```

### e_indent[EI_DATA]

```
grep "ELFDATA" /usr/include/elf.h | grep -w $((0x01))

#define ELFDATA2LSB     1               /* 2's complement, little endian */
```

### e_indent[EI_VERSION]

Ist immer `e_indetn[EI_VERSION] = 0x01` 

### e_indent[EI_OSABI]

```
grep "ELFOSABI" /usr/include/elf.h | grep -w $((0x00))

#define ELFOSABI_NONE           0       /* UNIX System V ABI */
#define ELFOSABI_SYSV           0       /* Alias.  */
```

### e_indent[EI_ABIVERSION]

Nix gefunden?! Ist `0x00` der Standard?

### e_indent[EI_PAD]

Nix gefunden?! Ist `0x00` der Standard?

## e_type

In `e_type` steht `03 00`, also wegen little endian `0x0003`.

```
grep "ET_" /usr/include/elf.h | grep -w $((0x0003))

#define ET_DYN          3               /* Shared object file */
```

## e_machine

In `e_machine` steht `3e 00`, also wegen little endian `0x003e`.

```
grep "EM_" /usr/include/elf.h | grep -w $((0x003e))

#define EM_X86_64       62      /* AMD x86-64 architecture */
```

## e_version

In `e_version` steht `01 00 00 00`, also wegen little endian `0x01` (die nullen weg gelassen).

```
grep "EV_" /usr/include/elf.h | grep -w $((0x01))

#define EV_CURRENT      1               /* Current version */
```

## e_entry

In `e_entry` steht `f0 04 00 00 00 00 00 00`, also wegen little endian `0x04f0` (die nullen weg gelassen).
Hier beginnt das Programm. Sehen wir mit hexdump die ersten `64 (0x40)` Bytes nach:

```
hexdump -n $((0x40)) -s $((0x04f0)) -C /tmp/a.out

000004f0  31 ed 49 89 d1 5e 48 89  e2 48 83 e4 f0 50 54 4c  |1.I..^H..H...PTL|
00000500  8d 05 8a 01 00 00 48 8d  0d 13 01 00 00 48 8d 3d  |......H......H.=|
00000510  d5 00 00 00 ff 15 c6 0a  20 00 f4 0f 1f 44 00 00  |........ ....D..|
00000520  48 8d 3d e9 0a 20 00 48  8d 05 e2 0a 20 00 48 39  |H.=.. .H.... .H9|
00000530
```

Hier kann man ein neues Kapitel aufmachen ... Assembler oder tools wie radare2.

## e_phoff, e_phentsize und e_phnum

Zur Erinnerung ... wir sind in der dritten Zeile unseres hexdump gekommen:

```
hexdump -n $((0x40)) -s $((0x0)) -C /tmp/a.out

00000000  7f 45 4c 46 02 01 01 00  00 00 00 00 00 00 00 00  |.ELF............|
00000010  03 00 3e 00 01 00 00 00  f0 04 00 00 00 00 00 00  |..>.............|
00000020  40 00 00 00 00 00 00 00  00 19 00 00 00 00 00 00  |@...............|
00000030  00 00 00 00 40 00 38 00  09 00 40 00 1c 00 1b 00  |....@.8...@.....|
00000040
```

Hier ist der Offset zu finden, ab der in dieser Datei (`a.out`), die Programm Header Tabellen (PHT) sich befinden. Der Offset bezieht sich auf den
Anfang der Datei. Die Länge der Bytes des PHT befinden sich in `e_phentsize`. Die Anzahl der PHTs aus dem Eintrag `e_phnum` zu entnehmen.

Hier öffnen wir ein neues Kapitel: [Program Header Table](elf-hexdump-pht.md)

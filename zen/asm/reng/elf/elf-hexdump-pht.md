# Program Header Tabelle (PHT)

Schauen wir uns mit `hexdump` die ersten beiden PHTs an,

```
Anzahl  ----------------------------------+
Eintrag ----------------------------+     |
Offset  --------------------+       |     |
Anzahl  --------+           |       |     |
                |           |       |     |
                v           v       v     V
hexdump -n $((0x38)) -s $((0x40 + 0x00 * 0x38)) -C /tmp/a.out

00000040  06 00 00 00 04 00 00 00  40 00 00 00 00 00 00 00  |........@.......|
00000050  40 00 00 00 00 00 00 00  40 00 00 00 00 00 00 00  |@.......@.......|
00000060  f8 01 00 00 00 00 00 00  f8 01 00 00 00 00 00 00  |................|
00000070  08 00 00 00 00 00 00 00                           |........|
00000078

hexdump -n $((0x38)) -s $((0x40 + 0x01 * 0x38)) -C /tmp/a.out

00000078  03 00 00 00 04 00 00 00  38 02 00 00 00 00 00 00  |........8.......|
00000088  38 02 00 00 00 00 00 00  38 02 00 00 00 00 00 00  |8.......8.......|
00000098  1c 00 00 00 00 00 00 00  1c 00 00 00 00 00 00 00  |................|
000000a8  01 00 00 00 00 00 00 00                           |........|
000000b0
```

Die Struktur des [ELF PHTs](elf-program-header-table.md) in kurzer Form:

```
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  p_t  |  p_f  |      p_o        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|      p_v      |      p_p        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|      p_f      |      p_m        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|      p_a      |
+-+-+-+-+-+-+-+-+
```

# p_type

Was für ein Typ ist das?

```
grep "define PT_" /usr/include/elf.h | grep -w $((0x06))

#define PT_PHDR         6               /* Entry for header table itself */
```

Welche Typen haben wir?

```
grep "define PT_" /usr/include/elf.h
```

Ok ... jede Menge, die ich hier nicht aufzähle, aber das mit

```
#define PT_LOAD         1               /* Loadable program segment */
#define PT_DYNAMIC      2               /* Dynamic linking information */
```

könnte interessant sein. Also suchen wir mit:

```
immer um eins erhöhen -------------+
                                   |
                                   v
hexdump -n $((0x38)) -s $((0x40 + xxx * 0x38)) -C /tmp/a.out
```

bis wir das Maximum - 1  erreicht haben,  das wir in der ELF Header gefunden haben. In unserem Falle also `0x09 - 0x01 = 0x08`.
Wir haben alle durch und finden bei den Indizes 2,3 und 4 die Einträge:

```
hexdump -n $((0x38)) -s $((0x40 + 0x02 * 0x38)) -C /tmp/a.out

000000b0  01 00 00 00 05 00 00 00  00 00 00 00 00 00 00 00  |................|
000000c0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
000000d0  10 08 00 00 00 00 00 00  10 08 00 00 00 00 00 00  |................|
000000e0  00 00 20 00 00 00 00 00                           |.. .....|
000000e8

hexdump -n $((0x38)) -s $((0x40 + 0x03 * 0x38)) -C /tmp/a.out

000000e8  01 00 00 00 06 00 00 00  f0 0d 00 00 00 00 00 00  |................|
000000f8  f0 0d 20 00 00 00 00 00  f0 0d 20 00 00 00 00 00  |.. ....... .....|
00000108  20 02 00 00 00 00 00 00  28 02 00 00 00 00 00 00  | .......(.......|
00000118  00 00 20 00 00 00 00 00                           |.. .....|
00000120

hexdump -n $((0x38)) -s $((0x40 + 0x04 * 0x38)) -C /tmp/a.out

00000120  02 00 00 00 06 00 00 00  00 0e 00 00 00 00 00 00  |................|
00000130  00 0e 20 00 00 00 00 00  00 0e 20 00 00 00 00 00  |.. ....... .....|
00000140  c0 01 00 00 00 00 00 00  c0 01 00 00 00 00 00 00  |................|
00000150  08 00 00 00 00 00 00 00                           |........|
00000158
```


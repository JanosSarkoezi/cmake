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
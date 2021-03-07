# ELF

- [ELF Header](elf-header.md)
- [Program Header Table](elf-program-header.md)
- [Segment](elf-segment.md)
- [Section](elf-section.md)
- [Section Header Table](elf-section-header.md)
- [Hexdump example](elf-hexdump.md)

## Visualisation of the relationship between Program Header Table and Segments

```
+----------------------+
| ELF header           |
+----------------------+
| Program header table |--+++
+----------------------+  |||
| Segment 1            |<-+||
+----------------------+   ||
| Segment 2            |<--+|
+----------------------+    |
| Segment 3            |<---+
+----------------------+
|      ...             |
+----------------------+
| Section header table |
+----------------------+

```

## Visualisation of the relationship between Section Header Table and Sections

```
+----------------------+
| ELF header           |
+----------------------+
| Program header table |
+----------------------+
| Section 1            |<---+
+----------------------+    |
| Section 2            |<--+|
+----------------------+   ||
| Section 3            |<-+||
+----------------------+  |||
|      ...             |  |||
+----------------------+  |||
| Section header table |--+++
+----------------------+

```

## Segments and Sections

A segmetn can contan several sections. As an exapmle, a Code segmetn contains a .text and a .rodata section.

```
+----------------------+\
| .text                | |
+----------------------+ > Code segment
| .rodata              | |
+----------------------+/
```

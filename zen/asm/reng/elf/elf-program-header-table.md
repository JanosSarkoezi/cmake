# Program Header Table (PHT)

C-Structure of program header:

```
typedef struct
{
  Elf64_Word   p_type;   /* Type of segment */
  Elf64_Word   p_flags;  /* Segment attributes */
  Elf64_Off    p_offset; /* Offset in file */
  Elf64_Addr   p_vaddr;  /* Virtual address in memory */
  Elf64_Addr   p_paddr;  /* Reserved */
  Elf64_Xword  p_filesz; /* Size of segment in file */
  Elf64_Xword  p_memsz;  /* Size of segment in memory */
  Elf64_Xword  p_align;  /* Alignment of segment */
} Elf64_Phdr;
```

## Visulaisation of program header

### Short

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

### Long

```
    1       2       3       4       5       6      7       8       9      10      11      12      13      14      15      16
+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
|             p_type            |             p_flags           |                            p_offset                           |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
|                            p_vaddr                            |                            p_paddr                            |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
|                            p_filesz                           |                            p_memsz                            |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
|                            p_align                            | 
+-------+-------+-------+-------+-------+-------+-------+-------+
```

- `p_type` identifies the type of segment. The processor-independent segment types.
- `p_flags` contains the segment attributes. The processor-independent flags.
- `p_offset` contains the offset, in bytes, of the segment from the beginning of the file. 
- `p_vaddr` contains the virtual address of the segment in memory. 
- `p_paddr` is reserved for systems with physical addressing
- `p_filesz` contains the size, in bytes, of the file image of the segment.
- `p_memsz` contains the size, in bytes, of the memory image of the segment.
- `p_align` specifies the alignment constraint for the segment. Must be a
power of two. The values of `p_offset` and `p_vaddr` must be congruent modulo
the alignment.

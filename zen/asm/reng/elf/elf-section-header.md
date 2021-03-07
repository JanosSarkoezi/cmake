# Section header

C-Structure of section header:

```
typedef struct
{
  Elf64_Word   sh_name;      /* Section name */
  Elf64_Word   sh_type;      /* Section type */
  Elf64_Xword  sh_flags;     /* Section attributes */
  Elf64_Addr   sh_addr;      /* Virtual address in memory */
  Elf64_Off    sh_offset;    /* Offset in file */
  Elf64_Xword  sh_size;      /* Size of section */
  Elf64_Word   sh_link;      /* Link to other section */
  Elf64_Word   sh_info;      /* Miscellaneous information */
  Elf64_Xword  sh_addralign; /* Address alignment boundary */
  Elf64_Xword  sh_entsize;   /* Size of entries, if section has table */
} Elf64_Shdr;
```

## Visulaisation of section header

### Short

```
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  s_n  |  s_t  |      s_f        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|      s_a      |      s_o        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|      s_s      |  s_l  |  s_i    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|      s_aa     |      s_es       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

### Long


```
    1       2       3       4       5       6      7       8       9      10      11      12      13      14      15      16
+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
|            sh_name            |            sh_type            |                            sh_flags                           |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
|                            sh_addr                            |                            sh_off                             |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
|                            sh_size                            |           sh_link             |            sh_info            |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
|                          sh_addraling                         |                          sh_entsize                           |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
```

- `sh_name` contains the offset, in bytes, to the section name, relative to the start of the section name string table.
- `sh_type` identifies the section type. Table 8 lists the processor-independent values for this field.
- `sh_flags` identifies the attributes of the section. Table 9 lists the processorindependent values for these flags.
- `sh_addr` contains the virtual address of the beginning of the section in memory. If the section is not allocated to the memory image of the
program, this field should be zero. 
- `sh_offset` contains the offset, in bytes, of the beginning of the section contents in the file. 
- `sh_size` contains the size, in bytes, of the section. Except for SHT_NOBITS sections, this is the amount of space occupied in the file. 
- `sh_link` contains the section index of an associated section. This field is used for several purposes, depending on the type of section.
- `sh_info` contains extra information about the section. This field is used for several purposes, depending on the type of section.
- `sh_addralign` contains the required alignment of the section. This field must be a power of two. 
- `sh_entsize` contains the size, in bytes, of each entry, for sections that contain fixed-size entries. Otherwise, this field contains zero. 


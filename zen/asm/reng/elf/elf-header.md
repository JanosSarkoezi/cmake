# File Header

C-Structure of file header:

```
typedef struct
{
  unsigned char e_ident[16]; /* ELF identification */
  Elf64_Half    e_type;      /* Object file type */
  Elf64_Half    e_machine;   /* Machine type */
  Elf64_Word    e_version;   /* Object file version */
  Elf64_Addr    e_entry;     /* Entry point address */
  Elf64_Off     e_phoff;     /* Program header offset */
  Elf64_Off     e_shoff;     /* Section header offset */
  Elf64_Word    e_flags;     /* Processor-specific flags */
  Elf64_Half    e_ehsize;    /* ELF header size */
  Elf64_Half    e_phentsize; /* Size of program header entry */
  Elf64_Half    e_phnum;     /* Number of program header entries */
  Elf64_Half    e_shentsize; /* Size of section header entry */
  Elf64_Half    e_shnum;     /* Number of section header entries */
  Elf64_Half    e_shstrndx;  /* Section name string table index */
} Elf64_Ehdr;
```

more information of [datatypes](elf-datatypes.md).

## Visulaisation of file header

### Short

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

### Long

```
    1       2       3       4       5       6      7       8       9      10      11      12      13      14      15      16
+-------+-------+-------+-------+------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
|                                                         e_ident[16]                                                          |
+-------+-------+-------+-------+------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
|    e_type     |   e_machine   |           e_version          |                            e_entry                            |
+-------+-------+-------+-------+------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
|                            e_phoff                           |                            e_shoff                            |
+-------+-------+-------+-------+------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
|            e_flags            |   e_ehsize   | e_phentsize   |    e_phnum    |  e_shentsize  |    e_shnum    |  e_shstrndx   |
+-------+-------+-------+-------+------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
```


## Description

- `e_ident` identify the file as an ELF object file, and provide information about the data representation of the object file structures. [More Information](tables/e_ident.md)
- `e_type` identifies the object file type. [More Information](tables/e_type.md)
- `e_machine` identifies the target architecture. [More Information](tables/e_machine.md)
- `e_version` identifies the version of the object file format. Currently, this field has the value EV_CURRENT, which is defined with the value 1.
- `e_entry` contains the virtual address of the program entry point. If there is no entry point, this field contains zero.
- `e_phoff` contains the file offset, in bytes, of the program header table.
- `e_shoff` contains the file offset, in bytes, of the section header table.
- `e_flags` contains processor-specific flags.
- `e_ehsize` contains the size, in bytes, of the ELF header.
- `e_phentsize` contains the size, in bytes, of a program header table entry.
- `e_phnum` contains the number of entries in the program header table.
- `e_shentsize` contains the size, in bytes, of a section header table entry.
- `e_shnum` contains the number of entries in the section header table.
- `e_shstrndx` contains the section header table index of the section containing the section name string table. If there is no section name string
table, this field has the value SHN_UNDEF. 

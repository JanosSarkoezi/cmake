# ELF-64 Data Types

```
 Type         Size
------------------
Elf64_Addr     8
Elf64_Off      8
Elf64_Half     2
Elf64_Word     4
Elf64_Sword    4
Elf64_Xword    8
Elf64_Sxword   8
unsigned char  1
------------------
```

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

Visulaisation of file header:

```
    1        2        3        4        5        6        7        8        9        10       11       12       13       14       15       16
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
|                                                                  e_ident[16]                                                                  |
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
|     e_type      |    e_machine    |             e_version             |                                e_entry                                |
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
|                                e_phoff                                |                                e_shoff                                |
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
|              e_flags              |    e_ehsize     |  e_phentsize    |     e_phnum     |   e_shentsize   |     e_shnum     |   e_shstrndx    |
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
```

- `e_ident` identify the file as an ELF object file, and provide information about the data representation of the object file structures. [More Information](tables/e_ident.md)
- `e_type` identifies the object file type.
- `e_machine` identifies the target architecture.
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

Visulaisation of section header:


```
    1        2        3        4        5        6        7        8        9        10       11       12       13       14       15       16
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
|              sh_name              |              sh_type              |                                sh_flags                               |
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
|                                sh_addr                                |                                sh_off                                 |
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
|                                sh_size                                |               sh_link             |              sh_info              |
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
|                              sh_addraling                             |                              sh_entsize                               |
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
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

# Program header

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

Visulaisation of program header:

```
    1        2        3        4        5        6        7        8        9        10       11       12       13       14       15       16
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
|               p_type              |               p_flags             |                                p_offset                               |
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
|                                p_vaddr                                |                                p_paddr                                |
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
|                                p_filesz                               |                                p_memsz                                |
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
|                                p_align                                | 
+--------+--------+--------+--------+--------+--------+--------+--------+
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

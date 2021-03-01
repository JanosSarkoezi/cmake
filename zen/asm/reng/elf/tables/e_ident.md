# Table e_ident

|  Name        | Value | Purpose                 |
|--------------|-------|-------------------------|
|EI_MAG0       |   0   | File identification     |
|EI_MAG1       |   1   |                         |
|EI_MAG2       |   2   |                         |
|EI_MAG3       |   3   |                         |
|EI_CLASS      |   4   | File class              |
|EI_DATA       |   5   | Data encoding           |
|EI_VERSION    |   6   | File version            |
|EI_OSABI      |   7   | OS/ABI identification   |
|EI_ABIVERSION |   8   | ABI version             |
|EI_PAD        |   9   | Start of padding bytes  |
|EI_NIDENT     |  16   | Size of e_ident[]       |

- e_ident[EI_MAG0] through e_ident[EI_MAG3] contain a “magic number,”
identifying the file as an ELF object file. They contain the characters ‘ \x7f ’,
‘ E ’, ‘ L ’, and ‘ F ’, respectively.
- e_ident[EI_CLASS] identifies the class of the object file, or its capacity.
Lists of possible values.

    |  Name        | Value | Meaning       |
    |--------------|-------|---------------|
    |ELFCLASS32    |   1   | 32-bit object |
    |ELFCLASS64    |   2   | 64-bit object |

    This document describes the structures for ELFCLASS64 .
    The class of the ELF file is independent of the data model assumed by the
    object code. The EI_CLASS field identifies the file format; a processor-
    specific flag in the e_flags field, described below, may be used to identify
    the application’s data model if the processory supports multiple models.
- e_ident[EI_DATA] specifies the data encoding of the object file data
structures. Table 4 lists the encodings defined for ELF-64.
For the convenience of code that examines ELF object files at run time
(e.g., the dynamic loader), it is intended that the data encoding of the
object file will match that of the running program. For environments that
support both byte orders, a processor-specific flag in the e_flags field,
described below, may be used to identify the application’s operating mode.
- e_ident[EI_VERSION ] identifies the version of the object file format.
Currently, this field has the value EV_CURRENT , which is defined with the
value 1 .
- e_ident[EI_ABIVERSION] identifies the version of the ABI for which the object
is prepared. This field is used to distinguish among incompatible versions
of an ABI. The interpretation of this version number is dependent on the
ABI identified by the EI_OSABI field.
For applications conforming to the System V ABI, third edition, this field
should contain 0.

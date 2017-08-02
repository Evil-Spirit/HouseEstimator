# ---------------------------------------------------------------------------
!if !$d(BCB)
BCB = $(MAKEDIR)\..
!endif

# ---------------------------------------------------------------------------
# IDE SECTION
# ---------------------------------------------------------------------------
# The following section of the project makefile is managed by the BCB IDE.
# It is recommended to use the IDE to change any of the values in this
# section.
# ---------------------------------------------------------------------------

VERSION = BCB.06.00
# ---------------------------------------------------------------------------
PROJECT = ..\..\LIB\Bind.lib
OBJFILES = ..\..\OBJ\z_List_int.obj ..\..\OBJ\z_All.obj ..\..\OBJ\z_Attributes.obj \
    ..\..\OBJ\z_VisIt.obj ..\..\OBJ\z_Pointer.obj ..\..\OBJ\z_List.obj \
    ..\..\OBJ\z_GO.obj ..\..\OBJ\z_VCL.obj
RESFILES = 
MAINSOURCE = Bind.bpf
RESDEPEN = $(RESFILES)
LIBFILES = 
IDLFILES = 
IDLGENFILES = 
LIBRARIES = 
PACKAGES = 
SPARELIBS = 
DEFFILE = 
OTHERFILES = 
# ---------------------------------------------------------------------------
LINKER = TLib
DEBUGLIBPATH = 
RELEASELIBPATH = 
USERDEFINES = _DEBUG
SYSDEFINES = NO_STRICT
INCLUDEPATH = $(BCB)\include;$(BCB)\include\vcl;..\COMMON;..\iup_include;..\lexer_include;..\lua_include;..\MAIN;..\ROOF;..\tolua_include;..\Compose;..\VisIt;..\KERNEL;..\GeomObject;..\BaseTool;..\LuaEnv;..\MainTools;..\DialogEditor;..\Math;..\ObjectInspector;C:\Development\Suiskin2\Include\BCB6;C:\development\components\suiskin2\Include\BCB6
LIBPATH = $(BCB)\lib\obj;$(BCB)\lib;..\..\LIB;C:\Development\Suiskin2\Source
WARNINGS = -w-par
LISTFILE = 
PATHCPP = .;
PATHASM = .;
PATHPAS = .;
PATHRC = .;
PATHOBJ = .;$(LIBPATH)
# ---------------------------------------------------------------------------
CFLAG1 = -Od -Vx -Ve -X- -r- -a8 -b- -k -y -v -vi- -c -tW -tWM
IDLCFLAGS = -I$(BCB)\include -I$(BCB)\include\vcl -I..\COMMON -I..\iup_include \
    -I..\lexer_include -I..\lua_include -I..\MAIN -I..\ROOF -I..\tolua_include \
    -I..\Compose -I..\VisIt -I..\KERNEL -I..\GeomObject -I..\BaseTool \
    -I..\LuaEnv -I..\MainTools -I..\DialogEditor -I..\Math \
    -I..\ObjectInspector -IC:\Development\Suiskin2\Include\BCB6 \
    -IC:\development\components\suiskin2\Include\BCB6 -src_suffix cpp -D_DEBUG \
    -boa
PFLAGS = -N2..\..\OBJ -N0..\..\OBJ -$YD -$W -$O- -$A8 -v -JPHNE -M
RFLAGS = 
AFLAGS = /mx /w2 /zd
LFLAGS = /P256
# ---------------------------------------------------------------------------
ALLOBJ = $(OBJFILES)
ALLRES = 
ALLLIB = 
# ---------------------------------------------------------------------------
!ifdef IDEOPTIONS

[Version Info]
IncludeVerInfo=0
AutoIncBuild=0
MajorVer=1
MinorVer=0
Release=0
Build=0
Debug=0
PreRelease=0
Special=0
Private=0
DLL=0

[Version Info Keys]
CompanyName=
FileDescription=
FileVersion=1.0.0.0
InternalName=
LegalCopyright=
LegalTrademarks=
OriginalFilename=
ProductName=
ProductVersion=1.0.0.0
Comments=

[Debugging]
DebugSourceDirs=$(BCB)\source\vcl

!endif





# ---------------------------------------------------------------------------
# MAKE SECTION
# ---------------------------------------------------------------------------
# This section of the project file is not used by the BCB IDE.  It is for
# the benefit of building from the command-line using the MAKE utility.
# ---------------------------------------------------------------------------

.autodepend
# ---------------------------------------------------------------------------
!if "$(USERDEFINES)" != ""
AUSERDEFINES = -d$(USERDEFINES:;= -d)
!else
AUSERDEFINES =
!endif

!if !$d(BCC32)
BCC32 = bcc32
!endif

!if !$d(CPP32)
CPP32 = cpp32
!endif

!if !$d(DCC32)
DCC32 = dcc32
!endif

!if !$d(TASM32)
TASM32 = tasm32
!endif

!if !$d(LINKER)
LINKER = TLib
!endif

!if !$d(BRCC32)
BRCC32 = brcc32
!endif


# ---------------------------------------------------------------------------
!if $d(PATHCPP)
.PATH.CPP = $(PATHCPP)
.PATH.C   = $(PATHCPP)
!endif

!if $d(PATHPAS)
.PATH.PAS = $(PATHPAS)
!endif

!if $d(PATHASM)
.PATH.ASM = $(PATHASM)
!endif

!if $d(PATHRC)
.PATH.RC  = $(PATHRC)
!endif
# ---------------------------------------------------------------------------
!if "$(LISTFILE)" ==  ""
COMMA =
!else
COMMA = ,
!endif

$(PROJECT):  $(OTHERFILES) $(IDLGENFILES) $(OBJFILES) $(RESDEPEN) $(DEFFILE)
    $(BCB)\BIN\$(LINKER) /u $@ @&&!
    $(LFLAGS) $? $(COMMA) $(LISTFILE)

!
# ---------------------------------------------------------------------------
.pas.hpp:
    $(BCB)\BIN\$(DCC32) $(PFLAGS) -U$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -O$(INCLUDEPATH) --BCB {$< }

.pas.obj:
    $(BCB)\BIN\$(DCC32) $(PFLAGS) -U$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -O$(INCLUDEPATH) --BCB {$< }

.cpp.obj:
    $(BCB)\BIN\$(BCC32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -n$(@D) {$< }

.c.obj:
    $(BCB)\BIN\$(BCC32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -n$(@D) {$< }

.c.i:
    $(BCB)\BIN\$(CPP32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -n. {$< }

.cpp.i:
    $(BCB)\BIN\$(CPP32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -n. {$< }

.asm.obj:
    $(BCB)\BIN\$(TASM32) $(AFLAGS) -i$(INCLUDEPATH:;= -i) $(AUSERDEFINES) -d$(SYSDEFINES:;= -d) $<, $@

.rc.res:
    $(BCB)\BIN\$(BRCC32) $(RFLAGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -fo$@ $<



# ---------------------------------------------------------------------------





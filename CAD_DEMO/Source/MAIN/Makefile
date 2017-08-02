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
PROJECT = ..\..\BIN\pConfig.exe
OBJFILES = ..\..\OBJ\pConfig.obj ..\..\OBJ\about.obj ..\..\OBJ\CounterBaseV.obj \
    ..\..\OBJ\DynamicCast.obj ..\..\OBJ\ExcelExchangeV.obj ..\..\OBJ\LOGOV.obj \
    ..\..\OBJ\MDIConfigV.obj ..\..\OBJ\MDICountReportV.obj \
    ..\..\OBJ\MDICubeV.obj ..\..\OBJ\MDIMetaActionListV.obj \
    ..\..\OBJ\MDIMetaActionV.obj ..\..\OBJ\MDIMetaMenuItemV.obj \
    ..\..\OBJ\MDIMetaPlatformV.obj ..\..\OBJ\MDIMetaRoomV.obj \
    ..\..\OBJ\MDIMetaUIV.obj ..\..\OBJ\MDINomenclatureV.obj \
    ..\..\OBJ\MDIVisibleSelectFloorV.obj ..\..\OBJ\MetaInterface.obj \
    ..\..\OBJ\UI.obj ..\..\OBJ\ArchitectElementV.obj ..\..\OBJ\PlatformV.obj \
    ..\..\OBJ\WallV.obj ..\..\OBJ\RoomV.obj ..\..\OBJ\NomenclatureV.obj \
    ..\..\OBJ\RegisterArchitectureV.obj ..\..\OBJ\ArchitectureSupportV.obj \
    ..\..\OBJ\MDITriggerBlockEditV.obj ..\..\OBJ\ClassExplorerV.obj \
    ..\..\OBJ\Main.obj ..\..\OBJ\RoofV.obj ..\..\OBJ\RoofEditV.obj
RESFILES = pConfig.res
MAINSOURCE = pConfig.cpp
RESDEPEN = $(RESFILES) about.dfm ExcelExchangeV.dfm LOGOV.dfm MDIConfigV.dfm \
    MDICountReportV.dfm MDIMetaUIV.dfm MDINomenclatureV.dfm \
    MDIVisibleSelectFloorV.dfm ..\KERNEL\MDITriggerBlockEditV.dfm \
    ClassExplorerV.dfm Main.dfm RoofEditV.dfm
LIBFILES = ..\..\LIB\Roof.lib ..\..\LIB\memmgr.lib ..\..\LIB\pCompose.lib \
    ..\..\LIB\tolua_103.lib ..\..\LIB\Bind.lib ..\..\LIB\lua5_omf.lib \
    ..\..\LIB\lualib5_omf.lib
IDLFILES = 
IDLGENFILES = 
LIBRARIES = 
PACKAGES = CommonAL.bpi IMGLIB.bpi KERNEL.bpi BaseTool.bpi GeomObject.bpi vcl.bpi \
    rtl.bpi vis30p5c.bpi vclx.bpi MathAL.bpi SUISkinC6.bpi
SPARELIBS = vcl.lib rtl.lib CommonAL.lib vis30p5c.lib vclx.lib SUISkinC6.lib
DEFFILE = 
OTHERFILES = 
# ---------------------------------------------------------------------------
DEBUGLIBPATH = $(BCB)\lib\debug
RELEASELIBPATH = $(BCB)\lib\release
USERDEFINES = _DEBUG
SYSDEFINES = NO_STRICT;_RTLDLL;USEPACKAGES
INCLUDEPATH = "C:\Program Files\Borland\CBuilder6\Projects";$(BCB)\include;$(BCB)\include\vcl;..\Math;..\VisIt;..\iup_include;..\lexer_include;..\lua_include;..\tolua_include;..\ROOF;..\Compose;..\KERNEL;..\COMMON;..\IMGLIB;..\BaseTool;..\MainTools;..\LuaEnv;..\GeomObject;C:\development\components\suiskin2\Include\BCB6
LIBPATH = $(BCB)\Projects\Lib;c:\config\lib;..\Roof;"c:\development\components\mwa jpeg";"C:\Program Files\Borland\CBuilder6\Projects";..\KERNEL;$(BCB)\lib\obj;$(BCB)\lib;..\..\LIB;..\COMMON;..\LuaEnv;..\BaseTool;..\MainTools;..\VisIt;..\ImgLib
WARNINGS= -w-par
PATHCPP = .;..\KERNEL;..\Roof
PATHASM = .;
PATHPAS = .;
PATHRC = .;
PATHOBJ = .;$(LIBPATH)
# ---------------------------------------------------------------------------
CFLAG1 = -Od -Vx -Ve -X- -r- -a8 -b- -k -y -v -vi- -c -tW -tWM
IDLCFLAGS = -I"C:\Program Files\Borland\CBuilder6\Projects" -I$(BCB)\include \
    -I$(BCB)\include\vcl -I..\Math -I..\VisIt -I..\iup_include \
    -I..\lexer_include -I..\lua_include -I..\tolua_include -I..\ROOF \
    -I..\Compose -I..\KERNEL -I..\COMMON -I..\IMGLIB -I..\BaseTool \
    -I..\MainTools -I..\LuaEnv -I..\GeomObject \
    -IC:\development\components\suiskin2\Include\BCB6 -src_suffix cpp -D_DEBUG \
    -boa
PFLAGS = -N2..\..\OBJ -N0..\..\OBJ -$YD -$W -$O- -$A8 -v -JPHNE -M
RFLAGS = 
AFLAGS = /mx /w2 /zi
LFLAGS = -l..\..\LIB -I..\..\OBJ -D"" -aa -Tpe -x -Gn -v
# ---------------------------------------------------------------------------
ALLOBJ = c0w32.obj $(PACKAGES) Memmgr.Lib sysinit.obj $(OBJFILES)
ALLRES = $(RESFILES)
ALLLIB = $(LIBFILES) $(LIBRARIES) import32.lib cp32mti.lib
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
LINKER = ilink32
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

!if $d(PATHOBJ)
.PATH.OBJ  = $(PATHOBJ)
!endif
# ---------------------------------------------------------------------------
$(PROJECT): $(OTHERFILES) $(IDLGENFILES) $(OBJFILES) $(RESDEPEN) $(DEFFILE)
    $(BCB)\BIN\$(LINKER) @&&!
    $(LFLAGS) -L$(LIBPATH) +
    $(ALLOBJ), +
    $(PROJECT),, +
    $(ALLLIB), +
    $(DEFFILE), +
    $(ALLRES)
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





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
PROJECT = ..\..\BIN\KERNEL.bpl
OBJFILES = ..\..\OBJ\KERNEL.obj ..\..\OBJ\Driver.obj ..\..\OBJ\ElementV.obj \
    ..\..\OBJ\GenImageV.obj ..\..\OBJ\CameraEngineV.obj \
    ..\..\OBJ\LinkGeometry.obj ..\..\OBJ\LogicNode.obj \
    ..\..\OBJ\ElementViewerV.obj ..\..\OBJ\LuaVarsEditV.obj \
    ..\..\OBJ\MDI3DUserV.obj ..\..\OBJ\MDI3DV.obj \
    ..\..\OBJ\MDIActionsEditV.obj ..\..\OBJ\MDIBMPSetEditV.obj \
    ..\..\OBJ\MDIBMPSetV.obj ..\..\OBJ\MDICanExistsCheckEditV.obj \
    ..\..\OBJ\MDIColorsV.obj ..\..\OBJ\MDIConnectV.obj \
    ..\..\OBJ\MDIDynamicLinkEditV.obj ..\..\OBJ\MDIElementSelectV.obj \
    ..\..\OBJ\MDIElementV.obj ..\..\OBJ\MDIEpsEditV.obj \
    ..\..\OBJ\MDIHasAngleV.obj ..\..\OBJ\MDIHasPositionV.obj \
    ..\..\OBJ\MDIHasSizeV.obj ..\..\OBJ\MDIHasStepV.obj \
    ..\..\OBJ\MDIMetaMaterialV.obj ..\..\OBJ\MDIMetaNodeV.obj \
    ..\..\OBJ\MDIMetaTextureV.obj ..\..\OBJ\MDIMetaVisParamV.obj \
    ..\..\OBJ\MDIMyModeSettingListEditV.obj \
    ..\..\OBJ\MDIMyModeSettingsEditV.obj ..\..\OBJ\MDIMyTextureFlagsEditV.obj \
    ..\..\OBJ\MDIMyTextureModesListV.obj ..\..\OBJ\MDIMyTextureModesV.obj \
    ..\..\OBJ\MDIPointerEditV.obj ..\..\OBJ\MDIPointerListEditV.obj \
    ..\..\OBJ\MDITextureV.obj ..\..\OBJ\MDITriggerBlockEditV.obj \
    ..\..\OBJ\MDITVV.obj ..\..\OBJ\MDIViewSettingsV.obj \
    ..\..\OBJ\TasksQueueV.obj ..\..\OBJ\MetaClasses.obj ..\..\OBJ\ProgBarV.obj \
    ..\..\OBJ\RenderParamV.obj ..\..\OBJ\Select.obj ..\..\OBJ\SelectBMPV.obj \
    ..\..\OBJ\UNDO.obj ..\..\OBJ\IntExplorerV.obj ..\..\OBJ\CatalogUnitV.obj \
    ..\..\OBJ\MDIMetaCatalogUnitV.obj ..\..\OBJ\MYIMPORTV.obj \
    ..\..\OBJ\MDIMetaMyModeV.obj ..\..\OBJ\MetaNodeCollectionV.obj \
    ..\..\OBJ\MySupportV.obj ..\..\OBJ\MDIKernelSupportEditV.obj \
    ..\..\OBJ\RegisterKernelV.obj ..\..\OBJ\World.obj \
    ..\..\OBJ\MultiElementV.obj ..\..\OBJ\MDIMultiElementV.obj \
    ..\..\OBJ\MDISelectClassV.obj ..\..\OBJ\AUIV.obj ..\..\OBJ\AddLuaVarV.obj \
    ..\..\OBJ\QueueRoutineV.obj ..\..\OBJ\TriggerBlockV.obj \
    ..\..\OBJ\MetaToolV.obj ..\..\OBJ\MDIMetaToolEditV.obj \
    ..\..\OBJ\Label3DV.obj ..\..\OBJ\CustomElementV.obj \
    ..\..\OBJ\MDICustomElementV.obj ..\..\OBJ\ToolFormV.obj \
    ..\..\OBJ\BindedBaseToolEditV.obj ..\..\OBJ\BindedBlockEditV.obj \
    ..\..\OBJ\BindedGoEditV.obj ..\..\OBJ\MainToolsV.obj \
    ..\..\OBJ\LuaUniFormV.obj ..\..\OBJ\LinearList.obj \
    ..\..\OBJ\Wizard3DSImport.obj
RESFILES = KERNEL.res
MAINSOURCE = KERNEL.cpp
RESDEPEN = $(RESFILES) GenImageV.dfm ElementViewerV.dfm LuaVarsEditV.dfm MDI3DV.dfm \
    MDIColorsV.dfm MDIElementSelectV.dfm MDIMetaNodeV.dfm MDIMetaTextureV.dfm \
    MDIMetaVisParamV.dfm MDIPointerEditV.dfm MDIPointerListEditV.dfm \
    MDITextureV.dfm MDITriggerBlockEditV.dfm MDITVV.dfm MDIViewSettingsV.dfm \
    ProgBarV.dfm SelectBMPV.dfm IntExplorerV.dfm MDIMetaCatalogUnitV.dfm \
    MDIMetaMyModeV.dfm MDIKernelSupportEditV.dfm MDISelectClassV.dfm \
    AddLuaVarV.dfm MDIMetaToolEditV.dfm ToolFormV.dfm BindedBaseToolEditV.dfm \
    BindedBlockEditV.dfm BindedGoEditV.dfm LuaUniFormV.dfm Wizard3DSImport.dfm
LIBFILES = ..\..\LIB\lualib5_omf.lib ..\..\LIB\lua5_omf.lib
IDLFILES = 
IDLGENFILES = 
LIBRARIES = 
PACKAGES = vcl.bpi rtl.bpi vclx.bpi CommonAL.bpi vis30p5c.bpi IMGLIB.bpi BaseTool.bpi \
    LuaEnv.bpi GeomObject.bpi MathAL.bpi
SPARELIBS = rtl.lib vis30p5c.lib vcl.lib CommonAL.lib vclx.lib
DEFFILE = 
OTHERFILES = 
# ---------------------------------------------------------------------------
DEBUGLIBPATH = $(BCB)\lib\debug
RELEASELIBPATH = $(BCB)\lib\release
USERDEFINES = _DEBUG
SYSDEFINES = _RTLDLL;NO_STRICT;USEPACKAGES
INCLUDEPATH = $(BCB)\include;$(BCB)\include\vcl;..\Math;..\Visit;..\lexer_include;..\lua_include;..\iup_include;..\IMGLIB;..\COMMON;..\BaseTool;..\LuaEnv;..\MainTools;..\GeomObject
LIBPATH = ..\GeomObject;"c:\development\components\mwa jpeg";$(BCB)\lib\obj;$(BCB)\lib;..\..\LIB;..\MainTools
WARNINGS= -w-par
PATHCPP = .;..\GeomObject
PATHASM = .;
PATHPAS = .;
PATHRC = .;
PATHOBJ = .;$(LIBPATH)
# ---------------------------------------------------------------------------
CFLAG1 = -Od -Vx -Ve -X- -r- -a8 -b- -k -y -v -vi- -c -tWM
IDLCFLAGS = -I$(BCB)\include -I$(BCB)\include\vcl -I..\Math -I..\Visit \
    -I..\lexer_include -I..\lua_include -I..\iup_include -I..\IMGLIB \
    -I..\COMMON -I..\BaseTool -I..\LuaEnv -I..\MainTools -I..\GeomObject \
    -src_suffix cpp -D_DEBUG -boa
PFLAGS = -N2..\..\OBJ -N0..\..\OBJ -$YD -$W -$O- -$A8 -v -JPHNE -M
RFLAGS = 
AFLAGS = /mx /w2 /zi
LFLAGS = -l..\..\LIB -I..\..\OBJ -D"Kernel Library" -aa -Tpp -Gpr -x -Gn -Gl -Gi -v
# ---------------------------------------------------------------------------
ALLOBJ = c0pkg32.obj $(PACKAGES) Memmgr.Lib sysinit.obj $(OBJFILES)
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





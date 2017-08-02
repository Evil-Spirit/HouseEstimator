unit ObjectInspectorU;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, StdCtrls, ExtCtrls, Grids, ValEdit, TypInfo, Types,
  PictureEditorU, StringListEditorU, PropDataU;

const
//  MaxPropLen = 255;
  cStrEdge = '    ';
  OpenRectWidth = 10;

type
  EditorType = (etMethod, etProperty);
//  PropIdent = (piSet, piSetElement, piClass, piEnumeration, piPointer, piNone);
//  TPropObject = class;

{----------------------------------------------------------------------------}
{ Header }
{----------------------------------------------------------------------------}
{ TProp }
{  TProp = class
    FPropertyName   : string;
    FPropertyInfo   : TPropInfo;
    FPropertyType   : TTypeInfo;
    FPPropertyType  : PTypeInfo;
    FPropertyKind   : TTypeKind;
    FPropertyValue  : Variant;
    FDefaultValue   : Variant;
    FObject         : TPropObject;
    FParent         : TPropObject;
    FData           : String;
  private
    procedure SetProperty(const Value: PPropInfo);
    function GetProperty(): PPropInfo;
  public
    SawFlag         : Boolean;
    constructor Create;
    property Data           : String read FData write FData;
    property PropertyInfo   : PPropInfo read GetProperty write SetProperty;
    property PropertyType   : TTypeInfo read FPropertyType write FPropertyType;
    property PPropertyType  : PTypeInfo read FPPropertyType write FPPropertyType;
    property PropertyValue  : Variant read FPropertyValue write FPropertyValue;
    property DefaultValue   : Variant read FDefaultValue write FDefaultValue;
    property PropertyKind   : TTypeKind read FPropertyKind write FPropertyKind;
    property PropertyName   : string read FPropertyName write FPropertyName;
    property ThisObject     : TPropObject read FObject write FObject;
    property Parent         : TPropObject read FParent write FParent;
  end;

{----------------------------------------------------------------------------}
{ TPropObject }
{  TPropObject = class(TObject)
    FPropId          : PropIdent;
    FOpenFlag        : Boolean;
    FRefresh         : Boolean;
    FName            : string;
    FObject          : TObject;
    ChildList        : array of TPropObject;
    FParent          : TPropObject;
    PropertyList     : array of TProp;
    MethodList       : array of TProp;
    FSetValue        : string;
    FSetLength       : Integer;
  private
    function NextWord(var Value: PChar): string;
  public
    constructor Create;
    destructor Destroy; override;
    procedure SetObject(_Name: string; const Value, Default: TObject; _Copy: Boolean = True; _Parent: TPropObject = nil);
    function GetPropertyValue(Name: string)                       : variant; overload;
    function IsAnyType(Index: integer; const PropType: TTypeKinds): boolean;
    function GetChild(_Name: string)                              : TPropObject;
    property OpenFlag                                             : Boolean read FOpenFlag write FOpenFlag;
    property Name                                                 : string read FName write FName;
    property Refresh                                              : Boolean read FRefresh write FRefresh;
    property Parent                                               : TPropObject read FParent write FParent;
    property ThisObject                                           : TObject read FObject write FObject;
  end;

{----------------------------------------------------------------------------}
{ TObjectIspector }
  TObjectInspectorF = class(TForm)
    OIPanel                 : TPanel;
    OIComboBox              : TComboBox;
    OIStatusBar             : TStatusBar;
    OIPageControl           : TPageControl;
    OIProperties            : TTabSheet;
    OIMethods               : TTabSheet;
    MethodValueListEditor   : TValueListEditor;
    PropertyValueListEditor : TValueListEditor;
    procedure OIComboBoxChange(Sender: TObject);
    procedure MethodValueListEditorStringsChange(Sender: TObject);
    procedure PropertyValueListEditorStringsChange(Sender: TObject);
    procedure PropertyValueListEditorEditButtonClick(Sender: TObject);
    procedure PropertyValueListEditorMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure PropertyValueListEditorDrawCell(Sender: TObject; ACol, ARow: Integer; Rect: TRect; State: TGridDrawState);
    procedure FormShow(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure PropertyValueListEditorKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure MethodValueListEditorKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure PropertyValueListEditorSelectCell(Sender: TObject; ACol, ARow: Integer; var CanSelect: Boolean);
    procedure PropertyValueListEditorDblClick(Sender: TObject);
    procedure PropertyValueListEditorMouseMove(Sender: TObject;
      Shift: TShiftState; X, Y: Integer);
    procedure PropertyValueListEditorMouseUp(Sender: TObject;
      Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure MethodValueListEditorDblClick(Sender: TObject);
    procedure MethodValueListEditorMouseUp(Sender: TObject;
      Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure MethodValueListEditorMouseMove(Sender: TObject;
      Shift: TShiftState; X, Y: Integer);
  private
    FDrawFlag              : Integer;
    Resizeable             : Boolean;
    NeedRefresh            : Boolean;
    procedure OIStringsChange(_Type: EditorType);
    function RecursiveFind(Root: TComponent; ActiveWindow: HWND) : Integer;
    function FindActiveEditor() : Integer;
  public
    Items                  : array of TPropObject;
    SelectedObjects        : array of TPropObject;
    AbstractObject         : TPropObject;
    ObjectChanged          : TNotifyEvent;
    RefreshSelectionBorder : Boolean;
    destructor Destroy; override;
    property DrawFlag   : Integer read FDrawFlag write FDrawFlag;
    procedure ClearOI();
    procedure ReAct(_Object: TObject; ReDraw: Boolean = False);
    procedure RefreshOI(var Line: Integer; Edge: Integer; _Object: TPropObject);
    procedure AddObject(const Value: TObject; _Name: string);
    procedure ObjectToSelect(_Object: TPropObject;  NeedDraw: Boolean = False; Add: Boolean = False); overload;
    procedure ObjectToSelect(_Object: TObject;  NeedDraw: Boolean = False; Add: Boolean = False); overload;
    procedure ObjectFromSelect(_Object: TPropObject); overload;
    procedure ObjectFromSelect(_Object: TObject); overload;
    procedure ClearSelect();
    procedure DeleteObject(_Object: TPropObject; NeedDraw: Boolean = True); overload;
    procedure DeleteObject(_Object: TObject; NeedDraw: Boolean = True); overload;
    procedure ReReadProperty(_Object: TPropObject);
    procedure MakeTmpList(_Objects: array of TPropObject);
    procedure DrawOpenRect(MPoint: TPoint; _Object: TPropObject);
    function OnOpenRect(MPoint: TPoint; Prop: TProp): Boolean;
    function FindEdgeByParent(Prop: TProp): Integer;
    function ChildIsIn(_Name: string; List: array of TPropObject) : Integer;
    function GetPropByRaw(_Index: Integer; _Object: TPropObject): TProp;
    function GetMethodByRaw(_Index: Integer; _Object: TPropObject): TProp;
    function OpenChildValue(_Object: TPropObject): Integer;
    function FindByObject(_Object: TObject) : Integer; overload;
    function FindByObject(_Object: TPropObject) : Integer; overload;
    function GetColor ( Color: string ) : TColor;
  end;

//function DefaultObject(const Value: TObject; Owner: TComponent) : TObject;
function PropIsIn(_Name: string; List: array of TProp) : Integer;
procedure InitPropByObject(_MyObject: TObject; var _Object: TPropObject);
procedure SetPropByKind (Data: String; Kind: TTypeKind; _Object: TObject; PropName: String; PropValue: Variant; PropObject: TObject = nil);
function PropertyCount(_Object: TObject; var PropCount, MethodCount: Integer ) : Integer;

var
  ObjInspector: TObjectInspectorF;

implementation

{$R *.dfm}

{----------------------------------------------------------------------------}
{ TProp }
{----------------------------------------------------------------------------}
{constructor TProp.Create;
begin
  inherited Create;
  FObject := nil;
  FParent := nil;
  Data := '';
  SawFlag := True;
end;

{----------------------------------------------------------------------------}
{function TProp.GetProperty(): PPropInfo;
begin
  Result := @FPropertyInfo;
end;

{----------------------------------------------------------------------------}
{procedure TProp.SetProperty(const Value: PPropInfo);
begin
  FPPropertyType               := Value^.PropType^;
  FPropertyType.Kind           := Value^.PropType^^.Kind;
  FPropertyType.Name           := Value^.PropType^^.Name;
  FPropertyKind                := FPropertyType.Kind;
  FPropertyInfo.GetProc        := Value^.GetProc;
  FPropertyInfo.SetProc        := Value^.SetProc;
  FPropertyInfo.StoredProc     := Value^.StoredProc;
  FPropertyInfo.Index          := Value^.Index;
  FPropertyInfo.Default        := Value^.Default;
  FPropertyInfo.NameIndex      := Value^.NameIndex;
  FPropertyInfo.Name           := Value^.Name;
  FPropertyName                := FPropertyInfo.Name;
end;

{----------------------------------------------------------------------------}
{ TPropObject }
{----------------------------------------------------------------------------}
function PropertyCount(_Object: TObject; var PropCount, MethodCount: Integer ) : Integer;
var
  i          : Integer;
  Value      : Integer;
  Properties : PPropList;
begin
  if _Object <> nil then
    Value := GetTypeData(_Object.ClassInfo).PropCount;
  GetMem(Properties, sizeof (PPropInfo) * Result);
  PropCount := 0;
  MethodCount := 0;
  try
    Value := GetPropList (_Object.ClassInfo, [tkUnknown, tkInteger, tkChar,
    tkEnumeration, tkFloat, tkString, tkSet, tkClass, tkMethod, tkWChar, tkLString,
    tkWString, tkVariant, tkArray, tkRecord, tkInterface, tkInt64, tkDynArray], Properties);
    for i := 0 to Value - 1 do
      if IsPublishedProp(_Object,Properties[i]^.Name) then
        if Properties[i]^.PropType^^.Kind = tkMethod then
          Inc(MethodCount)
        else
          Inc(PropCount);
  finally
    FreeMem(Properties);
    Result := Value;
  end;
end;

{----------------------------------------------------------------------------}
{constructor TPropObject.Create;
begin
  inherited Create;
  FRefresh := False;
  FOpenFlag := False;
  FSetLength := 0;
  FSetValue := '';
  FPropId := piNone;
end;

{----------------------------------------------------------------------------}
{destructor TPropObject.Destroy;
var
  i: integer;
begin
  for i := 0 to Length(PropertyList) - 1 do PropertyList[i].Free;
  for i := 0 to Length(MethodList) - 1 do MethodList[i].Free;
  for i := 0 to Length(ChildList) - 1 do ChildList[i].Free;
  SetLength(PropertyList,0);
  SetLength(MethodList,0);
  SetLength(ChildList,0);
  inherited;
end;

{----------------------------------------------------------------------------}
{function TPropObject.GetChild(_Name: string): TPropObject;
var
  i     : Integer;
begin
  Result := nil;
  for i := 0 to Length(ChildList) - 1 do
    if _Name = ChildList[i].Name then Result := ChildList[i];
end;

{----------------------------------------------------------------------------}
{function TPropObject.IsAnyType(Index: integer; const PropType: TTypeKinds): boolean;
begin
  Result := PropertyList[Index].PropertyKind in PropType;
end;

{----------------------------------------------------------------------------}
{procedure TPropObject.SetObject(_Name: string; const Value, Default: TObject; _Copy: Boolean; _Parent: TPropObject);
var
  i, j                                     : Integer;
  PropValue                                : Integer;
  PropIndex                                : Integer;
  MethodIndex                              : Integer;
  DefValue                                 : TObject;
  TempObject                               : TObject;
  Properties                               : PPropList;
  NewObject                                : TPropObject;
  NewSetObject                             : TPropObject;
  ThisInfo                                 : PTypeInfo;
  _Value                                   : PChar;
  EnumName                                 : string;
begin
  FObject := Value;
  Name := _Name;
  Parent := _Parent;
  if FObject <> nil then
    PropValue := GetTypeData(FObject.ClassInfo).PropCount;
  GetMem(Properties, sizeof (PPropInfo) * PropValue);
  try
    PropValue := GetPropList (FObject.ClassInfo, [tkUnknown, tkInteger, tkChar,
    tkEnumeration, tkFloat, tkString, tkSet, tkClass, tkMethod, tkWChar, tkLString,
    tkWString, tkVariant, tkArray, tkRecord, tkInterface, tkInt64, tkDynArray],Properties);
    PropIndex := 0;
    MethodIndex := 0;
    for i := 0 to PropValue - 1 do
      if IsPublishedProp(FObject,Properties[i]^.Name) then
        if Properties[i]^.PropType^^.Kind = tkMethod then
          //Methods:
          begin
            SetLength(MethodList,MethodIndex + 1);
            MethodList[MethodIndex] := TProp.Create;
            MethodList[MethodIndex].PropertyInfo := Properties[i];
            if _Copy then
              begin
                MethodList[MethodIndex].FPropertyValue := '';
                MethodList[MethodIndex].FDefaultValue := '';
              end;
            MethodList[MethodIndex].FParent := nil;
            Inc(MethodIndex);
          end
        else
          //Properties:
          begin
            SetLength(PropertyList,PropIndex + 1);
            PropertyList[PropIndex] := TProp.Create;
            PropertyList[PropIndex].PropertyInfo := Properties[i];
            case PropertyList[PropIndex].PropertyKind of
              tkClass:
                begin
                  TempObject := GetObjectProp(FObject,PropertyList[PropIndex].PropertyName);
                  if TempObject <> nil then
                    begin
                      if _Copy then
                        begin
                          PropertyList[PropIndex].PropertyValue := '(' + TempObject.ClassName + ')';
                          PropertyList[PropIndex].DefaultValue := '(' + TempObject.ClassName + ')';
                        end;
                      NewObject := TPropObject.Create;
                      NewObject.FPropId := piClass;
                      DefValue := DefaultObject(TempObject, (TComponent(TempObject)).Owner);
                      NewObject.SetObject(PropertyList[PropIndex].PropertyName, TempObject, DefValue, _Copy, Self);
                      SetLength(Self.ChildList, Length(Self.ChildList) + 1);
                      ChildList[Length(Self.ChildList) - 1] := NewObject;
                      PropertyList[PropIndex].ThisObject := NewObject;
                    end;
                end;
              tkSet:
                begin
                  if _Copy then
                    begin
                      PropertyList[PropIndex].PropertyValue := GetSetProp(FObject, PropertyList[PropIndex].PropertyName, True);
                      PropertyList[PropIndex].DefaultValue := '[]';
                    end;
                  NewObject := TPropObject.Create;
                  NewObject.FSetValue := PropertyList[PropIndex].PropertyValue;
                  NewObject.FPropId := piSet;
                  NewObject.Name := PropertyList[PropIndex].PropertyName;
                  NewObject.Parent := Self;
                  SetLength(Self.ChildList, Length(Self.ChildList) + 1);
                  ThisInfo := GetTypeData(PropertyList[PropIndex].PPropertyType)^.CompType^;
                  NewObject.FSetLength := GetTypeData(ThisInfo)^.MaxValue;
                  for j := 0 to NewObject.FSetLength do
                    begin
                      SetLength(NewObject.PropertyList, Length(NewObject.PropertyList) + 1);
                      NewObject.PropertyList[j] := TProp.Create;
                      NewObject.PropertyList[j].PropertyName := GetEnumName(ThisInfo, j);
                      if _Copy then
                        begin
                          NewObject.PropertyList[j].PropertyValue := False;
                          NewObject.PropertyList[j].DefaultValue := False;
                        end;
                      NewSetObject := TPropObject.Create;
                      NewSetObject.FPropId := piSetElement;
                      NewSetObject.Name := NewObject.PropertyList[j].PropertyName;
                      NewSetObject.Parent := NewObject;
                      NewObject.PropertyList[j].ThisObject := NewSetObject;
                    end;
                  if PropertyList[PropIndex].PropertyValue <> '' then
                    begin
                      EnumName := PropertyList[PropIndex].PropertyValue;
                      _Value := PChar(EnumName);
                      while _Value^ in ['[',' '] do
                        Inc(_Value);
                      EnumName := NextWord(_Value);
                      while EnumName <> '' do
                        begin
                          for j := 0 to NewObject.FSetLength do
                            if NewObject.PropertyList[j].PropertyName = EnumName then
                                NewObject.PropertyList[j].PropertyValue := True;
                          EnumName := NextWord(_Value);
                        end;
                      EnumName := PropertyList[PropIndex].DefaultValue;
                      _Value := PChar(EnumName);
                      while _Value^ in ['[',' '] do
                        Inc(_Value);
                      EnumName := NextWord(_Value);
                      while EnumName <> '' do
                        begin
                          for j := 0 to NewObject.FSetLength do
                            if NewObject.PropertyList[j].PropertyName = EnumName then
                                NewObject.PropertyList[j].DefaultValue := True;
                          EnumName := NextWord(_Value);
                        end;
                     end;
                  PropertyList[PropIndex].ThisObject := NewObject;
                  ChildList[Length(Self.ChildList) - 1] := NewObject;
                end;
              tkInterface: ;
              else
                if _Copy then
                  begin
                    PropertyList[PropIndex].PropertyValue := GetPropValue(FObject, PropertyList[PropIndex].PropertyName);
                    if Default <> nil then
                      begin
                        (TControl(Default)).Parent := TWinControl(FObject);
                        PropertyList[PropIndex].DefaultValue := GetPropValue(Default, PropertyList[PropIndex].PropertyName);
                      end
                    else
                        PropertyList[PropIndex].DefaultValue := '';
                  end;
            end;
            if _Parent <> nil then
                PropertyList[PropIndex].Parent := Self
            else
                PropertyList[PropIndex].Parent := nil;
            Inc(PropIndex);
          end;
  finally
    FreeMem(Properties);
  end;
end;

{----------------------------------------------------------------------------}
{function TPropObject.NextWord(var Value: PChar): string;
var
  i             : Integer;
begin
  i := 0;
  while not (Value[i] in [',', ' ', #0,']']) do
    Inc(i);
  SetString(Result, Value, i);
  while Value[i] in [',', ' ',']'] do
    Inc(i);
  Inc(Value, i);
end;

{----------------------------------------------------------------------------}
{function TPropObject.GetPropertyValue(Name: string): variant;
var
  i     : integer;
begin
  Result := '';
  for i:=0 to Length(PropertyList)-1 do
    if PropertyList[i].PropertyName = Name then
      begin
        Result := PropertyList[i].PropertyValue;
      end;
end;

{----------------------------------------------------------------------------}
{ TObjectIspector }
{----------------------------------------------------------------------------}
procedure TObjectInspectorF.FormShow(Sender: TObject);
begin
  OIComboBoxChange(AbstractObject);
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.FormCreate(Sender: TObject);

begin
//  ObjInspector := Self;
  ClearOI;
  Show;
end;

{----------------------------------------------------------------------------}
destructor TObjectInspectorF.Destroy;
var
    i   : Integer;
begin
  SetLength(AbstractObject.PropertyList,0);
  SetLength(AbstractObject.MethodList,0);
   for i :=0 to Length(Items)-1 do
    Items[i].Free;
  SetLength(Items, 0);
  SetLength(SelectedObjects, 0);
  inherited;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.MethodValueListEditorStringsChange(Sender: TObject);
begin
  OIStringsChange(etMethod);
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.PropertyValueListEditorStringsChange(Sender: TObject);
var
  Index     : Integer;
  TempProp  : TProp;
begin
  Index := PropertyValueListEditor.Selection.Top;
  TempProp := GetPropByRaw(Index, AbstractObject);
  if ( (TempProp.PropertyName = 'Name')  and (TempProp.Parent.Name = 'Font') ) or (TempProp.PropertyType.Name = 'TColor') or (TempProp.PropertyName = 'Caption') or (TempProp.PropertyType.Kind = tkEnumeration) or (TempProp.PropertyType.Kind = tkSet) or (TempProp.PropertyType.Kind = tkClass) then
    OIStringsChange(etProperty);
end;

{----------------------------------------------------------------------------}
procedure SetPropByKind (Data: String; Kind: TTypeKind; _Object: TObject; PropName: String; PropValue: Variant; PropObject: TObject);
begin
  case Kind of
    tkInt64                  : SetInt64Prop(_Object, PropName, Int64(Integer(PropValue)));
    tkWString                : SetWideStrProp(_Object, PropName, WideString(PropValue));
    tkFloat                  : SetFloatProp(_Object, PropName, Extended(PropValue));
    tkVariant                : SetVariantProp(_Object, PropName, Integer(PropValue));
    tkInterface              : SetInterfaceProp(_Object, PropName, IInterface(PropValue));
    tkClass                  : SetObjectProp(_Object, PropName, PropObject);
    tkInteger                : SetOrdProp(_Object, PropName, LongInt(PropValue));
    tkLString, tkString      : SetStrProp(_Object, PropName , String(PropValue));
  else
    SetPropValue(_Object, PropName, PropValue);
  end;
  TPropObject(ObjInspector.OIComboBox.Items.Objects[ObjInspector.FindByObject(_Object)]).PropertyList[PropIsIn(PropName, TPropObject(ObjInspector.OIComboBox.Items.Objects[ObjInspector.FindByObject(_Object)]).PropertyList)].Data := Data;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.OIStringsChange(_Type: EditorType);
var
  i, j, k       : Integer;
  Index         : Integer;
  PointCount    : Integer;
  SetValue      : string;
  TempObject    : TPropObject;
  TempProp      : TProp;
  TempParent    : TPropObject;
  TempValue     : string;
begin
  if FDrawFlag = 0 then
    begin
      if _Type = etMethod then
        begin
          Index := MethodValueListEditor.Selection.Top;
          TempProp := GetMethodByRaw(Index, AbstractObject);
          TempValue := MethodValueListEditor.Values[MethodValueListEditor.Keys[Index]];
          TempProp.FPropertyValue := TempValue;
          for i := 0 to Length(SelectedObjects) - 1 do
            begin
              j := PropIsIn(TempProp.PropertyName, SelectedObjects[i].PropertyList);
              if j <> -1 then
                begin
                  SelectedObjects[i].MethodList[j] := TempProp;
                end;
            end;
          end
        else
          begin
            Index := PropertyValueListEditor.Selection.Top;
            TempProp := GetPropByRaw(Index, AbstractObject);
            if (TempProp.PropertyName = 'Name') and (TempProp.Parent = nil) then
              begin
                TPropObject(OIComboBox.Items.Objects[OIComboBox.ItemIndex]).Name := AnsiString(TempProp.PropertyValue);
                OIComboBox.Items.Strings[OIComboBox.ItemIndex] := AnsiString(TempProp.PropertyValue);
              end;
            TempValue := PropertyValueListEditor.Values[PropertyValueListEditor.Keys[Index]];
            //For Color...
            if TempProp.PropertyType.Name = 'TColor' then
              begin
                TempProp.PropertyValue := GetColor( TempValue );
                PropertyValueListEditorDrawCell(Self, 1, Index, TRect(PropertyValueListEditor.Selection), [gdSelected]);
              end
            else
              begin
                TempProp.PropertyValue := TempValue;
                RefreshSelectionBorder := True;
                //posylat' soobshenie FindActiveEditor;
              end;

            //POCHEMU-TO NE zAHODIT MYSH'U - GLUK????
            if ( (TempProp.ThisObject <> nil) and (TPropObject(TempProp.ThisObject).FPropId = piSetElement) ) then
              begin
                TempObject := TPropObject(TempProp.ThisObject);
                Index := Index - PropIsIn(TempProp.FPropertyName, TPropObject(TempProp.ThisObject).Parent.PropertyList) - 1;
                TempProp := TempObject.Parent.Parent.PropertyList[PropIsIn(TempObject.Parent.Name, TempObject.Parent.Parent.PropertyList)];
                TempObject := TPropObject(TempProp.ThisObject);
                for i := 0 to TempObject.FSetLength do
                  begin
                    if PropertyValueListEditor.Values[PropertyValueListEditor.Keys[Index + i + 1]] = 'True' then
                      TempObject.PropertyList[i].PropertyValue := True
                    else
                      TempObject.PropertyList[i].PropertyValue := False;
                  end;
                TempObject :=  TPropObject((GetPropByRaw(Index, AbstractObject)).ThisObject);
                SetValue := '[';
                PointCount := 0;
                for i := 0 to TempObject.FSetLength do
                  if TempObject.PropertyList[i].PropertyValue = True then
                    Inc(PointCount);
                for i := 0 to TempObject.FSetLength do
                  if TempObject.PropertyList[i].PropertyValue = True then
                    begin
                      SetValue := SetValue + TempObject.PropertyList[i].PropertyName ;
                      Dec(PointCount);
                      if PointCount > 0 then
                        SetValue := SetValue + ',';
                    end;
                SetValue := SetValue + ']';
                TempProp.PropertyValue := SetValue;
                try
                  Inc(FDrawFlag);
                  PropertyValueListEditor.Values[PropertyValueListEditor.Keys[Index]] := SetValue;
                  PropertyValueListEditor.Invalidate();
                finally
                  Dec(FDrawFlag);
                end;
              end;
              for i := 0 to Length(SelectedObjects) - 1 do
                begin
                  j := PropIsIn(TempProp.PropertyName, SelectedObjects[i].PropertyList);
                  if (j <> -1) and (TempProp.Parent = nil) then
                    begin
                      SelectedObjects[i].PropertyList[j] := TempProp;
                      if TempValue <> '' then
                        if SelectedObjects[i].PropertyList[j].ThisObject <> nil then
                          SetPropByKind(SelectedObjects[i].PropertyList[j].Data, TempProp.FPropertyKind, SelectedObjects[i].FObject, SelectedObjects[i].PropertyList[j].FPropertyName, SelectedObjects[i].PropertyList[j].FPropertyValue, TPropObject(SelectedObjects[i].PropertyList[j].ThisObject).FObject)
                        else
                          SetPropByKind(SelectedObjects[i].PropertyList[j].Data,TempProp.FPropertyKind, SelectedObjects[i].FObject, SelectedObjects[i].PropertyList[j].FPropertyName, SelectedObjects[i].PropertyList[j].FPropertyValue);
                    end
                  else
                    begin
                      j := PropIsIn(TempProp.PropertyName, TempProp.Parent.PropertyList);
                      if j <> -1 then
                        begin
                          k := PropIsIn(TempProp.Parent.Name, SelectedObjects[i].PropertyList);
                          if k <> -1 then
                            begin
                              TempParent := TPropObject(SelectedObjects[i].PropertyList[k].ThisObject);
                              if TempValue <> '' then
                                if TempProp.ThisObject <> nil then
                                  SetPropByKind(SelectedObjects[i].PropertyList[j].Data, TempProp.FPropertyKind, TempParent.FObject, TempParent.PropertyList[j].FPropertyName, TempParent.PropertyList[j].FPropertyValue, TPropObject(TempParent.PropertyList[j].ThisObject).FObject)
                                else
                                  SetPropByKind(SelectedObjects[i].PropertyList[j].Data, TempProp.FPropertyKind, TempParent.FObject, TempParent.PropertyList[j].FPropertyName, TempParent.PropertyList[j].FPropertyValue);
                            end;
                        end;
                    end;
                  if Assigned(ObjectChanged) then
                    ObjectChanged( SelectedObjects[i].FObject );
                end;
        end;
    end;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.PropertyValueListEditorEditButtonClick(Sender: TObject);
begin
  PropertyValueListEditorDblClick(Sender);
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.PropertyValueListEditorMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  i              : Integer;
  Index          : Integer;
  ItemIndex      : Integer;
  Edge           : Integer;
  Col            : Integer;
  Line           : Integer;
  StrEdge        : string;
  TempProp       : TProp;
  TempObject     : TPropObject;
begin
  try
    Inc(FDrawFlag);
    PropertyValueListEditor.MouseToCell(X, Y, Col, Index);
//V Funkciyu perehvata mdown dlya dropdownlist, libo ubrat' READONLY:
//    if Col = 1 then
//      begin
//       TempProp := GetPropByRaw(Index, AbstractObject);
//       Line := Index + 1;
        {tkEnumeration}
//        if TempProp.PropertyKind = tkEnumeration then
//          begin
//            ItemIndex := PropertyValueListEditor.ItemProps[Line - 1].PickList.IndexOf(PropertyValueListEditor.Values[PropertyValueListEditor.ItemProps[Line - 1].KeyDesc]);
//            if ItemIndex < PropertyValueListEditor.ItemProps[Line - 1].PickList.Count - 1 then
//              Inc ( ItemIndex )
//            else
//              ItemIndex := 0;
//            PropertyValueListEditor.Values[PropertyValueListEditor.ItemProps[Line - 1].KeyDesc] := PropertyValueListEditor.ItemProps[Line - 1].PickList[ItemIndex];
//          end;
//      end;
    if Col = 0 then
      begin
        TempProp := GetPropByRaw(Index, AbstractObject);
        Line := Index + 1;
        StrEdge := '';
        Edge := FindEdgeByParent(TempProp);
       {tkSet}
        if TempProp.PropertyKind = tkSet then
          begin
            for i := 0 to Edge do
              StrEdge := StrEdge + ' ';
            TempObject := TPropObject(TempProp.ThisObject);
            if TempObject.OpenFlag = False then
              begin
                TempObject.OpenFlag := True;
                PropertyValueListEditor.Strings.BeginUpdate;
                PropertyValueListEditor.ItemProps[Line - 1].KeyDesc := StrEdge + cStrEdge + TempProp.PropertyName;
                for i := 0 to TempObject.FSetLength do
                  begin
                    if TempObject.PropertyList[i].PropertyValue = True then
                      PropertyValueListEditor.Strings.Insert(Line + i, StrEdge + cStrEdge + '   ' + string(TempObject.PropertyList[i].PropertyName) + '=True' )
                    else
                      PropertyValueListEditor.Strings.Insert(Line + i, StrEdge + cStrEdge + '   ' + string(TempObject.PropertyList[i].PropertyName) + '=False' );
                    PropertyValueListEditor.ItemProps[Line + i].ReadOnly := True;
                    PropertyValueListEditor.ItemProps[Line + i].EditStyle := esPickList;
                    PropertyValueListEditor.ItemProps[Line + i].PickList.Clear;
                    PropertyValueListEditor.ItemProps[Line + i].PickList.Add('False');
                    PropertyValueListEditor.ItemProps[Line + i].PickList.Add('True');
                  end;
                PropertyValueListEditor.Strings.EndUpdate;
              end
            else
              begin
                PropertyValueListEditor.ItemProps[Line - 1].KeyDesc := StrEdge + cStrEdge + TempProp.PropertyName;
                TempObject.OpenFlag := False;
                for i := TempObject.FSetLength downto 0 do
                  begin
                    PropertyValueListEditor.Strings.BeginUpdate;
                    PropertyValueListEditor.Strings.Delete(Line + i);
                    PropertyValueListEditor.Strings.EndUpdate;
                  end;
              end;
          end;
        {tkClass}
        if (TempProp.PropertyKind = tkClass) and (TPropObject((GetPropByRaw(Index,AbstractObject)).ThisObject) <> nil) then {tkClass}
          begin
            for i := 0 to Edge do
              StrEdge := StrEdge + ' ';
            TempObject := TPropObject(TempProp.ThisObject);
            if TempObject.OpenFlag = False then
              begin
                TempObject.OpenFlag := True;
                RefreshOI(Line, 4 * Edge, TempObject);
                PropertyValueListEditor.ItemProps[Index].KeyDesc := StrEdge + cStrEdge + TempObject.Name;
              end
            else
              begin
                TempObject.OpenFlag := False;
                PropertyValueListEditor.ItemProps[Index].KeyDesc := StrEdge + cStrEdge + TempObject.Name;
                for i := 0 to OpenChildValue(TempObject) - 1 do
                  begin
                    PropertyValueListEditor.Strings.BeginUpdate;
                    PropertyValueListEditor.Strings.Delete(Line);
                    PropertyValueListEditor.Strings.EndUpdate;
                  end;
              end;
          end;
      end;
  finally
    Dec(FDrawFlag);
  end;
end;

{----------------------------------------------------------------------------}
function TObjectInspectorF.OpenChildValue(_Object: TPropObject): Integer;
var
  i     : Integer;
begin
  Result := 0;
  for i := 0 to Length(_Object.PropertyList) - 1 do
    Inc(Result);
  for i := 0 to Length(_Object.ChildList) - 1 do
    if ( _Object.ChildList[i].OpenFlag ) then
      Result := Result + OpenChildValue(_Object.ChildList[i]);
end;

{----------------------------------------------------------------------------}
function TObjectInspectorF.GetMethodByRaw(_Index: Integer; _Object: TPropObject): TProp;
var
  i         : Integer;
begin
  i := 0;
  Result := nil;
  while (i <= _Index) and (i < Length(_Object.MethodList)) do
    begin
      if (i = _Index) then
        begin
          Result := _Object.MethodList[i];
          Exit;
        end;
      Inc(i);
    end;
end;

{----------------------------------------------------------------------------}
function TObjectInspectorF.GetPropByRaw(_Index: Integer; _Object: TPropObject): TProp;
var
  i, j         : Integer;
begin
  i := 0;
  j := 0;
  Result := nil;
  while (i <= _Index) and (j < Length(_Object.PropertyList)) do
    begin
      if (i = _Index) then
        begin
          Result := _Object.PropertyList[j];
          Exit;
        end;
      if _Object.PropertyList[j].ThisObject <> nil then
        begin
          if TPropObject(_Object.PropertyList[j].ThisObject).OpenFlag then
            begin
              Result := GetPropByRaw(_Index - i - 1, _Object.PropertyList[j].ThisObject);
              if Result = nil then
                i := i + Length(TPropObject(_Object.PropertyList[j].ThisObject).PropertyList)
              else
                Exit;
            end;
        end;
      Inc(i);
      Inc(j);
    end;
end;

{----------------------------------------------------------------------------}
function PropIsIn(_Name: string; List: array of TProp) : Integer;
var
  i     : Integer;
begin
  Result := -1;
  for i := 0 to Length(List) - 1 do
    if List[i].PropertyName = _Name then
      begin
        Result := i;
        Exit;
      end;
end;

{---------------------------------------------------------------------------}
procedure InitPropByObject(_MyObject: TObject; var _Object: TPropObject);
var
  DefValue    : TObject;
begin
  DefValue := DefaultObject(_MyObject, (TComponent(_MyObject)).Owner);
  _Object.SetObject(TComponent(_MyObject).Name, _MyObject, DefValue, False);
  _Object.Name := TComponent(_MyObject).Name;
  DefValue.Free;
end;

{----------------------------------------------------------------------------}
function TObjectInspectorF.ChildIsIn(_Name: string; List: array of TPropObject) : Integer;
var
  i     : Integer;
begin
  Result := -1;
  for i := 0 to Length(List) - 1 do
    if List[i].Name = _Name then
      begin
        Result := i;
        Exit;
      end;
end;

{----------------------------------------------------------------------------}
function TObjectInspectorF.FindByObject(_Object: TPropObject) : Integer;
var
  i     : Integer;
begin
  Result := -1;
  for i := 0 to OIComboBox.Items.Count - 1 do
    if OIComboBox.Items.Objects[i] = _Object then
      begin
        Result := i;
        Break;
      end;
end;

{----------------------------------------------------------------------------}
function TObjectInspectorF.FindByObject(_Object: TObject) : Integer;
var
  i     : Integer;
begin
  Result := -1;
  for i := 0 to OIComboBox.Items.Count - 1 do
    if TPropObject(OIComboBox.Items.Objects[i]).Name = TComponent(_Object).Name then
      begin
        Result := i;
        Break;
      end;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.OIComboBoxChange(Sender: TObject);
var
  Line  : Integer;
begin
  if FDrawFlag = 0 then
    if OIComboBox.Items.Count <> 0 then
      begin
        SetLength(SelectedObjects, 1);
        SelectedObjects[0] := TPropObject(OIComboBox.Items.Objects[OIComboBox.ItemIndex]);
        Line := 0;
        MakeTmpList(SelectedObjects);
        if (AbstractObject <> nil ) then
          RefreshOI(Line, 0, AbstractObject);
        if SelectedObjects[0].ThisObject is TTabSheet then
          (TTabSheet(SelectedObjects[0].ThisObject)).PageControl.ActivePage := TTabSheet(SelectedObjects[0].ThisObject);
        RefreshSelectionBorder := True;
        //posylat' soobshenie FindActiveEditor;        
      end;
end;

{----------------------------------------------------------------------------}
function TObjectInspectorF.GetColor ( Color : string ) : TColor;
begin
  Result := StrToIntDef(Color, 0);
  if Color = 'clScrollBar'  then Result := clScrollBar;
  if Color = 'clBackground'  then Result := clBackground;
  if Color = 'clActiveCaption'  then Result := clActiveCaption;
  if Color = 'clInactiveCaption'  then Result := clInactiveCaption;
  if Color = 'clMenu'  then Result := clMenu;
  if Color = 'clWindow'  then Result := clWindow;
  if Color = 'clMenuText'  then Result := clMenuText;
  if Color = 'clWindowFrame'  then Result := clWindowFrame;
  if Color = 'clCaptionText'  then Result := clCaptionText;
  if Color = 'clActiveBorder'  then Result := clActiveBorder;
  if Color = 'clInactiveBorder'  then Result := clInactiveBorder;
  if Color = 'clAppWorkSpace'  then Result := clAppWorkSpace;
  if Color = 'clHighlight'  then Result := clHighlight;
  if Color = 'clHighlightText'  then Result := clHighlightText;
  if Color = 'clBtnFace'  then Result := clBtnFace;
  if Color = 'clBtnShadow'  then Result := clBtnShadow;
  if Color = 'clGrayText'  then Result := clGrayText;
  if Color = 'clBtnText'  then Result := clBtnText;
  if Color = 'clBtnHighlight'  then Result := clBtnHighlight;
  if Color = 'cl3DDkShadow'  then Result := cl3DDkShadow;
  if Color = 'cl3DLight'  then Result := cl3DLight;
  if Color = 'clInfoText'  then Result := clInfoText;
  if Color = 'clInfoBk'  then Result := clInfoBk;
  if Color = 'clHotLight'  then Result := clHotLight;
  if Color = 'clGradientActiveCaption'  then Result := clGradientActiveCaption;
  if Color = 'clGradientInactiveCaption'  then Result := clGradientInactiveCaption;
  if Color = 'clMenuHighlight'  then Result := clMenuHighlight;
  if Color = 'clMenuBar'  then Result := clMenuBar;
  if Color = 'clBlack'  then Result := clBlack;
  if Color = 'clMaroon'  then Result := clMaroon;
  if Color = 'clGreen'  then Result := clGreen;
  if Color = 'clOlive'  then Result := clOlive;
  if Color = 'clNavy'  then Result := clNavy;
  if Color = 'clPurple'  then Result := clPurple;
  if Color = 'clTeal'  then Result := clTeal;
  if Color = 'clGray'  then Result := clGray;
  if Color = 'clSilver'  then Result := clSilver;
  if Color = 'clRed'  then Result := clRed;
  if Color = 'clLime'  then Result := clLime;
  if Color = 'clYellow'  then Result := clYellow;
  if Color = 'clBlue'  then Result := clBlue;
  if Color = 'clFuchsia'  then Result := clFuchsia;
  if Color = 'clAqua'  then Result := clAqua;
  if Color = 'clLtGray'  then Result := clLtGray;
  if Color = 'clDkGray'  then Result := clDkGray;
  if Color = 'clWhite'  then Result := clWhite;
  if Color = 'clMoneyGreen'  then Result := clMoneyGreen;
  if Color = 'clSkyBlue'  then Result := clSkyBlue;
  if Color = 'clCream'  then Result := clCream;
  if Color = 'clMedGray'  then Result := clMedGray;
  if Color = 'clNone'  then Result := clNone;
  if Color = 'clDefault'  then Result := clDefault;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.PropertyValueListEditorDrawCell(Sender: TObject; ACol, ARow: Integer; Rect: TRect; State: TGridDrawState);
var
  i              : Integer;
  Col            : Integer;
  Row            : Integer;
  BeginIndex     : Integer;
  Index          : Integer;
  TempProp       : TProp;
  ColorBox       : TRect;
begin
  PropertyValueListEditor.MouseToCell(0, 0, Col, Row);
  BeginIndex := Row;
  for i := 0 to PropertyValueListEditor.Height div (PropertyValueListEditor.RowHeights[0] + 1) + 1 do
    if Length(AbstractObject.PropertyList) > i + BeginIndex then
      begin
        TempProp := GetPropByRaw(BeginIndex + i, AbstractObject);
        if TempProp.PropertyType.Name = 'TColor' then
          begin
            Index := Row;
            ColorBox.Left := 1;
            ColorBox.Right := 10;
            ColorBox.Top := 3 + i * (PropertyValueListEditor.RowHeights[0] + 1) + 1  ;
            ColorBox.Bottom := 3 + i * (PropertyValueListEditor.RowHeights[0] + 1) + 10 ;
            PropertyValueListEditor.Canvas.Brush.Color := GetColor( TempProp.PropertyValue );
            PropertyValueListEditor.Canvas.FillRect(ColorBox);
            PropertyValueListEditor.Canvas.Brush.Color := clBlack;
            PropertyValueListEditor.Canvas.FrameRect(ColorBox);
          end;
        if ( (TempProp.ThisObject <> nil) and (TPropObject(TempProp.ThisObject).FPropId <> piSetElement) ) then
          DrawOpenRect(Point(0, i * (PropertyValueListEditor.RowHeights[0] + 1)), TPropObject(TempProp.ThisObject));
      end;
end;

{----------------------------------------------------------------------------}
function TObjectInspectorF.OnOpenRect(MPoint: TPoint; Prop: TProp): Boolean;
var
  OpenRect   : TRect;
  Edge       : Integer;
  Index      : Integer;
begin
  Edge := FindEdgeByParent(Prop) - 1;
  Index := MPoint.Y div (PropertyValueListEditor.RowHeights[0] + 1);
  OpenRect.Left := 1 + Edge * OpenRectWidth;
  OpenRect.Right := 10 + Edge * OpenRectWidth;
  OpenRect.Top := 1 + Index * (PropertyValueListEditor.RowHeights[0] + 1) + (PropertyValueListEditor.RowHeights[0] + 1) div 2 - 5;
  OpenRect.Bottom := 10 + Index * (PropertyValueListEditor.RowHeights[0] + 1) + (PropertyValueListEditor.RowHeights[0] + 1) div 2 - 5;
  if ( ( MPoint.X < OpenRect.Right ) and ( MPoint.X > OpenRect.Left ) and ( MPoint.Y > OpenRect.Top ) and ( MPoint.Y < OpenRect.Bottom ) ) then
    Result := True
  else
    Result := False;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.DrawOpenRect(MPoint: TPoint; _Object: TPropObject);
var
  OpenRect   : TRect;
  Edge       : Integer;
  Index      : Integer;
begin
  Edge := FindEdgeByParent( _Object.Parent.PropertyList[PropIsIn(_Object.Name, _Object.Parent.PropertyList)] ) - 1;
  Index := MPoint.Y div (PropertyValueListEditor.RowHeights[0] + 1);
  OpenRect.Left := 1 + Edge * OpenRectWidth;
  OpenRect.Right := 10 + Edge * OpenRectWidth;
  OpenRect.Top := 1 + Index * (PropertyValueListEditor.RowHeights[0] + 1) + (PropertyValueListEditor.RowHeights[0] + 1) div 2 - 5;
  OpenRect.Bottom := 10 + Index * (PropertyValueListEditor.RowHeights[0] + 1) + (PropertyValueListEditor.RowHeights[0] + 1) div 2 - 5;
  PropertyValueListEditor.Canvas.Brush.Color := clWhite;
  PropertyValueListEditor.Canvas.FillRect(OpenRect);
  PropertyValueListEditor.Canvas.Brush.Color := clBlack;
  PropertyValueListEditor.Canvas.Pen.Color := clBlack;
  PropertyValueListEditor.Canvas.FrameRect(OpenRect);
  PropertyValueListEditor.Canvas.MoveTo(3 + Edge * OpenRectWidth, 5 + Index * (PropertyValueListEditor.RowHeights[0] + 1) + (PropertyValueListEditor.RowHeights[0] + 1) div 2 - 5);
  PropertyValueListEditor.Canvas.LineTo(8 + Edge * OpenRectWidth, 5 + Index * (PropertyValueListEditor.RowHeights[0] + 1) + (PropertyValueListEditor.RowHeights[0] + 1) div 2 - 5);
  if _Object.FOpenFlag = False then
     begin
       PropertyValueListEditor.Canvas.MoveTo(5 + Edge * OpenRectWidth, 3 + Index * (PropertyValueListEditor.RowHeights[0] + 1) + (PropertyValueListEditor.RowHeights[0] + 1) div 2 - 5);
       PropertyValueListEditor.Canvas.LineTo(5 + Edge * OpenRectWidth, 8 + Index * (PropertyValueListEditor.RowHeights[0] + 1) + (PropertyValueListEditor.RowHeights[0] + 1) div 2 - 5);
     end;
end;

{----------------------------------------------------------------------------}
function TObjectInspectorF.FindEdgeByParent(Prop: TProp): Integer;
var
  TempObject     : TPropObject;
begin
  Result := 0;
  TempObject := Prop.ThisObject;
  if Prop.ThisObject <> nil then
    while TempObject.FParent <> nil do
      begin
        TempObject := TempObject.Parent;
        Inc(Result);
      end;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.RefreshOI(var Line: Integer; Edge: Integer; _Object: TPropObject);
var
  i, j        : Integer;
  ThisType    : PTypeData;
  StrEdge     : String;
  TempObjects : TPropObject;
  OldColor    : TColor;
  MyRect      : TGridRect;
begin
  try
    Inc(FDrawFlag);
    StrEdge := '';
    OldColor := PropertyValueListEditor.Font.Color;
    If Edge <> 0 then
      for i := 0 to Edge do
        StrEdge := StrEdge + ' ';
    if(Line = 0) then
      begin
        PropertyValueListEditor.Strings.Clear();
        MethodValueListEditor.Strings.Clear();
        if Length(SelectedObjects) = 1 then
          OIComboBox.Text := AbstractObject.Name
        else
          OIComboBox.Text := IntToStr(Length(SelectedObjects)) + ' Items';
        //MethodList:
        PropertyValueListEditor.Font.Color := OldColor;
        for i := 0 to Length(_Object.MethodList) - 1 do
          begin
            MethodValueListEditor.InsertRow(AbstractObject.MethodList[i].PropertyName,AbstractObject.MethodList[i].PropertyValue, true);
            MethodValueListEditor.ItemProps[i].EditStyle := esPickList;
            MethodValueListEditor.ItemProps[i].PickList.Clear;
            MethodValueListEditor.ItemProps[i].PickList.Add('');
          end;
      end;
      //PropertyList:
      for i := 0 to Length(_Object.PropertyList) - 1 do
      begin
        PropertyValueListEditor.Font.Color := OldColor;
        PropertyValueListEditor.Strings.BeginUpdate;
        if _Object.PropertyList[i].SawFlag = True then
          PropertyValueListEditor.Strings.Insert(Line, StrEdge + cStrEdge + string(_Object.PropertyList[i].PropertyName) + '=' + string(_Object.PropertyList[i].PropertyValue))
        else
          PropertyValueListEditor.Strings.Insert(Line, StrEdge + cStrEdge + string(_Object.PropertyList[i].PropertyName) + '=');
        PropertyValueListEditor.Strings.EndUpdate;
        ThisType := GetTypeData(_Object.PropertyList[i].PPropertyType);
        //Font
        if ( _Object.PropertyList[i].PropertyName = 'Name' ) and ( _Object.Name = 'Font' ) then
          begin
            PropertyValueListEditor.ItemProps[Line].EditStyle := esPickList;
            PropertyValueListEditor.ItemProps[Line].PickList.Clear;
            for j := 0 to Screen.Fonts.Count - 1 do
              PropertyValueListEditor.ItemProps[Line].PickList.Add(Screen.Fonts.Strings[j]);
          end;
        //Color
        if _Object.PropertyList[i].PropertyType.Name = 'TColor' then
          begin
            PropertyValueListEditor.ItemProps[Line].EditStyle := esPickList;
            PropertyValueListEditor.ItemProps[Line].PickList.Clear;
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clScrollBar');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clBackground');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clActiveCaption');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clInactiveCaption');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clMenu');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clWindow');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clWindowFrame');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clMenuText');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clWindowText');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clCaptionText');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clActiveBorder');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clInactiveBorder');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clAppWorkSpace');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clHighlight');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clHighlightText');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clBtnFace');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clBtnShadow');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clGrayText');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clBtnText');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clInactiveCaptionText');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clBtnHighlight');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('cl3DDkShadow');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('cl3DLight');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clInfoText');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clInfoBk');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clHotLight');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clGradientActiveCaption');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clGradientInactiveCaption');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clMenuHighlight');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clMenuBar');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clBlack');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clMaroon');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clGreen');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clOlive');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clNavy');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clPurple');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clTeal');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clGray');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clSilver');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clRed');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clLime');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clYellow');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clBlue');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clFuchsia');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clAqua');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clLtGray');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clDkGray');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clWhite');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clMoneyGreen');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clSkyBlue');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clCream');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clMedGray');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clNone');
            PropertyValueListEditor.ItemProps[Line].PickList.Add('clDefault');
          end;
        case _Object.PropertyList[i].PropertyKind of
          tkEnumeration:
            begin
              PropertyValueListEditor.ItemProps[Line].ReadOnly := True;
              PropertyValueListEditor.ItemProps[Line].EditStyle := esPickList;
              PropertyValueListEditor.ItemProps[Line].PickList.Clear;
              for j := 0 to ThisType^.MaxValue do
                PropertyValueListEditor.ItemProps[Line].PickList.Add(GetEnumName(_Object.PropertyList[i].PPropertyType, j));
            end;
          tkSet:
            begin
              PropertyValueListEditor.ItemProps[Line].ReadOnly := True;
              if TPropObject(_Object.PropertyList[i].ThisObject).OpenFlag = False then
                PropertyValueListEditor.ItemProps[Line].KeyDesc := StrEdge + cStrEdge + _Object.PropertyList[i].PropertyName
              else
                begin
                  PropertyValueListEditor.ItemProps[Line].KeyDesc := StrEdge + cStrEdge + _Object.PropertyList[i].PropertyName;
                  PropertyValueListEditor.Strings.BeginUpdate;
                  for j := 0 to TPropObject(_Object.PropertyList[i].ThisObject).FSetLength do
                    begin
                      if TPropObject(_Object.PropertyList[i].ThisObject).PropertyList[j].PropertyValue = True then
                        PropertyValueListEditor.Strings.Insert(Line + j + 1, StrEdge + cStrEdge + '   ' + string(TPropObject(_Object.PropertyList[i].ThisObject).PropertyList[j].PropertyName) + '=True')
                      else
                        PropertyValueListEditor.Strings.Insert(Line + j + 1, StrEdge + cStrEdge + '   ' + string(TPropObject(_Object.PropertyList[i].ThisObject).PropertyList[j].PropertyName) + '=False');
                      PropertyValueListEditor.ItemProps[Line + j + 1].ReadOnly := True;
                      PropertyValueListEditor.ItemProps[Line + j + 1].EditStyle := esPickList;
                      PropertyValueListEditor.ItemProps[Line + j + 1].PickList.Clear;
                      PropertyValueListEditor.ItemProps[Line + j + 1].PickList.Add('False');
                      PropertyValueListEditor.ItemProps[Line + j + 1].PickList.Add('True');
                    end;
                  Line := Line + TPropObject(_Object.PropertyList[i].ThisObject).FSetLength + 1;
                  PropertyValueListEditor.Strings.EndUpdate;
                end;
            end;
          tkClass:
            begin
              PropertyValueListEditor.ItemProps[Line].EditStyle := esEllipsis;
              PropertyValueListEditor.ItemProps[Line].ReadOnly := True;
              if _Object.PropertyList[i].ThisObject <> nil then
                begin
                  if TPropObject(_Object.PropertyList[i].ThisObject).OpenFlag = True then
                    PropertyValueListEditor.ItemProps[Line].KeyDesc := StrEdge + cStrEdge + _Object.PropertyList[i].PropertyName
                  else
                    PropertyValueListEditor.ItemProps[Line].KeyDesc := StrEdge + cStrEdge + _Object.PropertyList[i].PropertyName;
                  if TPropObject(_Object.PropertyList[i].ThisObject).OpenFlag = True then
                    begin
                      Line := Line + 1;
                      TempObjects := _Object.GetChild(_Object.PropertyList[i].PropertyName);
                      RefreshOI(Line, Edge + 4, TempObjects);
                      Line := Line - 1;
                    end;
                end
              else
                PropertyValueListEditor.ItemProps[Line].ReadOnly := False;
            end;
          end;
        Line := Line + 1;
      end;
  finally
    Dec(FDrawFlag);
  end;
  if ( Edge = 0 ) and ( NeedRefresh ) then
    begin
      MyRect.Left := 1;
      MyRect.Right := 1;
      MyRect.Top := 0;
      MyRect.Bottom := 0;
      PropertyValueListEditor.Selection := MyRect;
      MethodValueListEditor.Selection := MyRect;
    end;
end;

{----------------------------------------------------------------------------}
{function DefaultObject(const Value: TObject; Owner: TComponent) : TObject;
begin
  Result := nil;
  if Value is TButton then
    Result := TButton.Create(Owner);
  if Value is TPanel then
    Result := TPanel.Create(Owner);
  if Value is TForm then
    Result := TForm.Create(Owner);
  if Value is TRadioButton then
    Result := TRadioButton.Create(Owner);
  if Value is TRadioGroup then
    Result := TRadioGroup.Create(Owner);
  if Value is TStaticText then
    Result := TStaticText.Create(Owner);
  if Value is TEdit then
    Result := TEdit.Create(Owner);
  if Value is TMemo then
    Result := TMemo.Create(Owner);
  if Value is TCheckBox then
    Result := TCheckBox.Create(Owner);
  if Value is TListBox then
    Result := TListBox.Create(Owner);
  if Value is TComboBox then
    Result := TComboBox.Create(Owner);
  if Value is TGroupBox then
    Result := TGroupBox.Create(Owner);
  if Value is TScrollBar then
    Result := TScrollBar.Create(Owner);
  if Value is TPageControl then
    Result := TPageControl.Create(Owner);
  if Value is TTabSheet then
    Result := TTabSheet.Create(Owner);
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.AddObject(const Value: TObject; _Name: string);
var
  DefValue      : TObject;
  TempObject    : TPropObject;
  TempName      : string;
begin
  DefValue := DefaultObject(Value, (TComponent(Value)).Owner);
  TempObject := TPropObject.Create;
  if _Name='' then
    TempName := TempObject.GetPropertyValue('Name')
  else
    TempName := _Name;
  TempObject.SetObject(TempName, Value, DefValue);
  OIComboBox.Items.AddObject(TempName, TempObject);
  OIComboBox.ItemIndex := OIComboBox.Items.Count - 1;
  SetLength(SelectedObjects, 1);
  SetLength(Items, Length(Items) + 1);
  SelectedObjects[0] := TempObject;
  Items[OIComboBox.ItemIndex] := TempObject;
  FDrawFlag := 0;
  OIComboBoxChange(Self);
  DefValue.Free;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.ObjectToSelect(_Object: TPropObject; NeedDraw: Boolean; Add: Boolean);
var
  Line      : Integer;
begin
  if Add then
    begin
      SetLength(SelectedObjects, Length(SelectedObjects) + 1);
      SelectedObjects[Length(SelectedObjects) - 1] := _Object;
    end
  else
    begin
      OIComboBox.ItemIndex := FindByObject(_Object);
      SetLength(SelectedObjects, 1);
      SelectedObjects[0] := TPropObject(OIComboBox.Items.Objects[OIComboBox.ItemIndex]);
     end;
  if NeedDraw then
    begin
      MakeTmpList(SelectedObjects);
      ReReadProperty(AbstractObject);
      Line := 0;
      RefreshOI(Line, 0, AbstractObject);
    end;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.ObjectToSelect(_Object: TObject;  NeedDraw: Boolean; Add: Boolean);
begin
  ObjectToSelect(Items[FindByObject(_Object)], NeedDraw, Add);
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.ObjectFromSelect(_Object: TPropObject);
var
  i     : Integer;
  Index : Integer;
  Line  : Integer;
begin
  for i := 0 to Length(SelectedObjects) - 1 do
    if _Object = SelectedObjects[i] then
      Index := i;
  for i := Index + 1 to Length(SelectedObjects) - 1 do
    SelectedObjects[i - 1] := SelectedObjects[i];
  SetLength(SelectedObjects, Length(SelectedObjects) - 1);
  if Length(SelectedObjects) = 0 then
    ClearSelect()
  else
    begin
      if Length(SelectedObjects) = 1 then
        OIComboBox.ItemIndex := FindByObject(SelectedObjects[0]);
      MakeTmpList(SelectedObjects);
      ReReadProperty(AbstractObject);
      Line := 0;
      RefreshOI(Line, 0, AbstractObject);
    end;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.ObjectFromSelect(_Object: TObject);
begin
  ObjectFromSelect(Items[FindByObject(_Object)]);
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.ClearSelect();
begin
  SetLength(SelectedObjects, 0);
  OIComboBox.ItemIndex := -1;
  PropertyValueListEditor.Strings.Clear();
  MethodValueListEditor.Strings.Clear();
  OIComboBox.Text := '';
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.DeleteObject(_Object: TPropObject; NeedDraw: Boolean);
var
  i     : Integer;
  Index : Integer;
begin
  Index := FindByObject(_Object);
  OIComboBox.ItemIndex := Index;
  OIComboBox.DeleteSelected;
  OIComboBox.ItemIndex := Index - 1;
  for i := Index + 1 to Length(Items) - 1 do
    Items[i - 1] := Items[i];
  SetLength(Items, Length(Items) - 1);
  if NeedDraw then
    OIComboBoxChange(Self);
  if Length(Items) = 0 then
    ClearSelect();
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.DeleteObject(_Object: TObject; NeedDraw: Boolean);
var
  i            : Integer;
begin
 for i := 0 to (TWinControl(_Object)).ControlCount - 1 do
   DeleteObject((TWinControl(_Object)).Controls[i], NeedDraw);
 DeleteObject(Items[FindByObject(_Object)], NeedDraw);
end;
{----------------------------------------------------------------------------}
procedure TObjectInspectorF.ReAct(_Object: TObject; ReDraw: Boolean);
var
  Index         : Integer;
  Temp          : Integer;
  TempString    : String;
begin
  if _Object is TComponent then
    begin
      try
        Inc(FDrawFlag);
        Index := FindByObject( _Object );
        if (Index <> -1) then
          begin
            Temp := PropIsIn( 'Left', Items[Index].PropertyList );
            if Temp <> -1 then
              begin
                Items[Index].PropertyList[Temp].PropertyValue := TControl(_Object).Left;
                Str(TControl(_Object).Left, TempString);
                Temp := PropIsIn( 'Left', AbstractObject.PropertyList );
                if (Temp <> -1)  and (ReDraw) then
                  PropertyValueListEditor.Values[PropertyValueListEditor.Keys[Temp]] := TempString;
              end;
            Temp := PropIsIn( 'Top', Items[Index].PropertyList );
            if Temp <> -1 then
              begin
                Items[Index].PropertyList[Temp].PropertyValue := TControl(_Object).Top;
                Str(TControl(_Object).Top, TempString);
                Temp := PropIsIn( 'Top', AbstractObject.PropertyList );
                if (Temp <> -1)  and (ReDraw) then
                  PropertyValueListEditor.Values[PropertyValueListEditor.Keys[Temp]] := TempString;
              end;
            Temp := PropIsIn( 'Width', Items[Index].PropertyList );
            if Temp <> -1 then
              begin
                Items[Index].PropertyList[Temp].PropertyValue := TControl(_Object).Width;
                Str(TControl(_Object).Width, TempString);
                Temp := PropIsIn( 'Width', AbstractObject.PropertyList );
                if (Temp <> -1)  and (ReDraw) then
                  PropertyValueListEditor.Values[PropertyValueListEditor.Keys[Temp]] := TempString;
              end;
            Temp := PropIsIn( 'Height', Items[Index].PropertyList );
            if Temp <> -1 then
              begin
                Items[Index].PropertyList[Temp].PropertyValue := TControl(_Object).Height;
                Str(TControl(_Object).Height, TempString);
                Temp := PropIsIn( 'Height', AbstractObject.PropertyList );
                if (Temp <> -1)  and (ReDraw) then
                  PropertyValueListEditor.Values[PropertyValueListEditor.Keys[Temp]] := TempString;
              end;
            PropertyValueListEditor.Refresh();
          end;
      finally
        Dec(FDrawFlag);
      end;
    end;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.ReReadProperty(_Object: TPropObject);
var
  i             : Integer;
  Line          : Integer;
  StringValue   : string;
  VariantValue  : Variant;
  TempObject    : TObject;
begin
  if (_Object = nil) or (_Object.Refresh = False) then Exit;
  for i := 0 to Length(AbstractObject.PropertyList) - 1 do
    begin
      case _Object.PropertyList[i].PropertyKind of
        tkSet:
          begin
            VariantValue := GetSetProp(_Object.FObject, _Object.PropertyList[i].PropertyName, True);
            _Object.Refresh := _Object.PropertyList[i].PropertyValue <> VariantValue;
            _Object.PropertyList[i].PropertyValue := VariantValue;
          end;
        tkClass:
          begin
            TempObject := GetObjectProp(_Object.FObject, _Object.PropertyList[i].PropertyName);
            if TempObject <> nil then
              begin
                StringValue := '(' + TempObject.ClassName + ')';
                _Object.Refresh := _Object.PropertyList[i].PropertyValue <> StringValue;
                _Object.PropertyList[i].PropertyValue := StringValue;
                ReReadProperty(_Object.PropertyList[i].ThisObject);
              end;
          end;
        tkInterface: ;
      else
        begin
          VariantValue := GetPropValue(_Object.FObject, _Object.PropertyList[i].PropertyName);
          _Object.Refresh := _Object.PropertyList[i].PropertyValue <> VariantValue;
          _Object.PropertyList[i].PropertyValue := VariantValue;
        end;
      end;
    end;
  Line := 0;
  if _Object.Refresh then
    begin
      RefreshOI(Line, 0, AbstractObject);
    end;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.MakeTmpList(_Objects: array of TPropObject);
var
  i, j          : Integer;
  MinVal        : Integer;
  Index         : Integer;
  Flag          : array [0..MaxPropLen] of Boolean;
  SimpleProp    : array [0..MaxPropLen] of Boolean;
begin
  SetLength(AbstractObject.ChildList, 0);
  SetLength(AbstractObject.PropertyList, 0);
  SetLength(AbstractObject.MethodList, 0);
  if Length(SelectedObjects) = 1 then
    AbstractObject.Name := SelectedObjects[0].Name
  else
    AbstractObject.Name := '';
  MinVal := 2147483647;
  Index  := -1;
  for i := 0 to Length(_Objects) - 1 do
    if MinVal > Length(_Objects[i].PropertyList) - 1 then
      begin
        MinVal := Length(_Objects[i].PropertyList) - 1;
        Index := i;
      end;
  for i := 0 to MaxPropLen do
    begin
      Flag[i] := True;
      SimpleProp[i] := True;
    end;
  for i := 0 to MinVal do
    for j := 0 to Length(_Objects) - 1  do
      begin
        if PropIsIn(_Objects[Index].PropertyList[i].PropertyName, _Objects[j].PropertyList) = -1 then
          Flag[i] := False;
        if (_Objects[Index].PropertyList[i].PropertyName = _Objects[j].PropertyList[i].PropertyName) and (_Objects[Index].PropertyList[i].PropertyValue <> _Objects[j].PropertyList[i].PropertyValue) then
          SimpleProp[i] := False;
      end;
  j := 0;
  for i := 0 to MinVal do
    begin
      if Flag[i] = True then
        begin
          SetLength(AbstractObject.PropertyList, Length(AbstractObject.PropertyList) + 1);
          AbstractObject.PropertyList[j] := _Objects[Index].PropertyList[i];
          if SimpleProp[j] = False then
            AbstractObject.PropertyList[j].SawFlag := False
          else
            AbstractObject.PropertyList[j].SawFlag := True;
          Inc(j);
        end;
    end;
  MinVal := 2147483647;
  Index  := -1;
  for i := 0 to Length(_Objects) - 1 do
    if MinVal > Length(_Objects[i].MethodList) - 1 then
      begin
        MinVal := Length(_Objects[i].MethodList) - 1;
        Index := i;
      end;
  for i := 0 to MaxPropLen do
   begin
    Flag[i] := True;
    SimpleProp[i] := False;
   end;
  for i := 0 to MinVal do
    for j := 0 to Length(_Objects) - 1  do
      begin
        if PropIsIn(_Objects[Index].MethodList[i].PropertyName, _Objects[j].MethodList) = -1 then
          Flag[i] := False;
        if (_Objects[Index].MethodList[i].PropertyName = _Objects[j].MethodList[i].PropertyName) and (_Objects[Index].MethodList[i].PropertyValue <> _Objects[j].MethodList[i].PropertyValue) then
          SimpleProp[i] := False;
      end;
  j := 0;
  for i := 0 to MinVal do
    begin
       if Flag[i] = True then
         begin
           SetLength(AbstractObject.MethodList, Length(AbstractObject.MethodList) + 1);
           AbstractObject.MethodList[j] := _Objects[Index].MethodList[i];
           if SimpleProp[j] = False then
             AbstractObject.MethodList[j].SawFlag := False
           else
             AbstractObject.MethodList[j].SawFlag := True;
           Inc(j);
         end;
    end;
  MinVal := 2147483647;
  Index  := -1;
  for i := 0 to Length(_Objects) - 1 do
    if MinVal > Length(_Objects[i].ChildList) - 1 then
      begin
        MinVal := Length(_Objects[i].ChildList) - 1;
        Index := i;
      end;
  for i := 0 to MaxPropLen do
   Flag[i] := True;
  for i := 0 to MinVal do
    for j := 0 to Length(_Objects) - 1  do
      if ChildIsIn(_Objects[Index].ChildList[i].Name, _Objects[j].ChildList) = -1 then
        Flag[i] := False;
  j := 0;
  for i := 0 to MinVal do
    if Flag[i] = True then
      begin
        SetLength(AbstractObject.ChildList, Length(AbstractObject.ChildList) + 1);
        AbstractObject.ChildList[j] := _Objects[Index].ChildList[i];
        Inc(j);
      end;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.PropertyValueListEditorKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
 if Key = VK_RETURN then
   OIStringsChange(etProperty);
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.MethodValueListEditorKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
 if Key = VK_RETURN then
   OIStringsChange(etMethod);
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.PropertyValueListEditorSelectCell(Sender: TObject; ACol, ARow: Integer; var CanSelect: Boolean);
begin
 OIStringsChange(etProperty);
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.PropertyValueListEditorDblClick( Sender: TObject );
var
  i, j             : Integer;
  Line             : Integer;
  Index            : Integer;
  TempProp         : TProp;
  FontDlg          : TFontDialog;
  ColorDlg         : TColorDialog;
  SetString        : string;
  SetProp          : TPropObject;
  FontStyle        : Set of TFontStyle;
  MySelection      : TGridRect;
  PictureEditor    : TPictureEditorF;
  StringListEditor : TStringListEditorF;
begin
  Line := 0;
  Index := PropertyValueListEditor.Selection.Top;
  TempProp := GetPropByRaw(Index, AbstractObject);
  if ( PropertyValueListEditor.Selection.Left = 1 ) and ( TempProp.PropertyName = 'Font' ) then
    begin
      FontDlg := TFontDialog.Create( PropertyValueListEditor );
      FontDlg.Font.Name := TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Name', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue;
      FontDlg.Font.Charset := Byte(StrToIntDef(TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Charset', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue,0));
      FontDlg.Font.Color := TColor(StrToIntDef(TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Color', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue, 0));
      FontDlg.Font.Height := StrToIntDef(TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Height', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue, 0);
      FontDlg.Font.Pitch := TFontPitch(StrToIntDef(TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Pitch', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue, 0));
      FontDlg.Font.Size := StrToIntDef(TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Size', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue, 0);
      SetProp := TPropObject(TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Style', TPropObject(TempProp.ThisObject).PropertyList)].ThisObject);
      if SetProp.PropertyList[PropIsIn('fsBold', SetProp.PropertyList)].PropertyValue = 'true' then
        FontStyle := FontStyle + [fsBold];
      if SetProp.PropertyList[PropIsIn('fsItalic', SetProp.PropertyList)].PropertyValue = 'true' then
        FontStyle := FontStyle + [fsItalic];
      if SetProp.PropertyList[PropIsIn('fsUnderline', SetProp.PropertyList)].PropertyValue = 'true' then
        FontStyle := FontStyle + [fsUnderline];
      if SetProp.PropertyList[PropIsIn('fsStrikeOut', SetProp.PropertyList)].PropertyValue = 'true' then
        FontStyle := FontStyle + [fsStrikeOut];
      FontDlg.Font.Style := FontStyle;
      FontDlg.Execute;
      TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Name', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue := FontDlg.Font.Name;
      TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Charset', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue := FontDlg.Font.Charset;
      TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Color', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue := FontDlg.Font.Color;
      TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Height', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue := FontDlg.Font.Height;
      case FontDlg.Font.Pitch of
        fpDefault  : TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Pitch', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue := 'fpDefault';
        fpFixed    : TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Pitch', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue := 'fpFixed';
        fpVariable : TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Pitch', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue := 'fpVariable';
      end;
      TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Size', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue := FontDlg.Font.Size;
      SetString := '';
      if fsBold in FontDlg.Font.Style then
        begin
          if SetString <> '' then
            SetString := SetString + ',';
          SetString := SetString + 'fsBold';
        end;
      if fsItalic in FontDlg.Font.Style then
        begin
          if SetString <> '' then
            SetString := SetString + ',';
          SetString := SetString + 'fsItalic';
        end;
      if fsUnderline in FontDlg.Font.Style then
        begin
          if SetString <> '' then
            SetString := SetString + ',';
          SetString := SetString + 'fsUnderline';
        end;
      if fsStrikeOut in FontDlg.Font.Style then
        begin
          if SetString <> '' then
            SetString := SetString + ',';
          SetString := SetString + 'fsStrikeOut';
        end;
      SetString := '[' + SetString + ']';
      TPropObject(TempProp.ThisObject).PropertyList[PropIsIn('Style', TPropObject(TempProp.ThisObject).PropertyList)].PropertyValue := SetString;
      MySelection := PropertyValueListEditor.Selection;
      TPropObject(TempProp.ThisObject).OpenFlag := True;
      RefreshOI(Line, 0, AbstractObject);
      PropertyValueListEditor.Selection := MySelection;
      for i := 1 to 7 do
        begin
          Inc(MySelection.Bottom);
          Inc(MySelection.Top);
          PropertyValueListEditor.Selection := MySelection;
          OIStringsChange(etProperty);
        end;
      PropertyValueListEditor.Row := MySelection.Top - 7;
      NeedRefresh := False;
      Exit;
    end;
  if ( PropertyValueListEditor.Selection.Left = 1 ) and ( TempProp.PropertyType.Name = 'TColor' ) then
    begin
      ColorDlg := TColorDialog.Create( PropertyValueListEditor );
      ColorDlg.Execute;
      TempProp.PropertyValue := ColorDlg.Color;
      MySelection := PropertyValueListEditor.Selection;
      RefreshOI(Line, 0, AbstractObject);
      PropertyValueListEditor.Row := MySelection.Top;
      NeedRefresh := False;
      OIStringsChange(etProperty);
      Exit;
    end;
  if ( PropertyValueListEditor.Selection.Left = 1 ) and ( TempProp.PropertyType.Name = 'TPicture' ) then
    begin
      PictureEditor := TPictureEditorF.Create ( PropertyValueListEditor );
      PictureEditor.Show;
      Exit;
    end;
  if ( PropertyValueListEditor.Selection.Left = 1 ) and ( TempProp.PropertyType.Name = 'TStrings' ) then
    begin
      StringListEditor := TStringListEditorF.Create ( PropertyValueListEditor );
      StringListEditor.Prop := TempProp;
      StringListEditor.ThisObject := TPropObject(OIComboBox.Items.Objects[OIComboBox.ItemIndex]).ThisObject;
      StringListEditor.Show;
      Exit;
    end;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.PropertyValueListEditorMouseMove( Sender: TObject; Shift: TShiftState; X, Y: Integer);
begin
  if ( Resizeable ) and ( ssLeft in Shift ) then
    PropertyValueListEditor.DefaultColWidth := X;
  if ( X > PropertyValueListEditor.DefaultColWidth - 1 ) and ( X < PropertyValueListEditor.DefaultColWidth + 1 ) then
    begin
      Screen.Cursor := crHSplit;
      Resizeable := True;
    end
  else
    begin
      Screen.Cursor := crDefault;
      Resizeable := False;
    end;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.PropertyValueListEditorMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  if Resizeable then
    PropertyValueListEditor.DefaultColWidth := X;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.MethodValueListEditorDblClick(Sender: TObject);
var
  X         : Integer;
  Y         : Integer;
  Col       : Integer;
  Index     : Integer;
begin
  X := MethodValueListEditor.ScreenToClient(Mouse.CursorPos).X;
  Y := MethodValueListEditor.ScreenToClient(Mouse.CursorPos).Y;
  if X > MethodValueListEditor.DefaultColWidth then
    begin
      MethodValueListEditor.MouseToCell(X, Y, Col, Index);
      MethodValueListEditor.Values[MethodValueListEditor.Keys[Index]] := MethodValueListEditor.Keys[Index];
      MethodValueListEditor.ItemProps[Index].PickList.Clear;
      MethodValueListEditor.ItemProps[Index].PickList.Add(MethodValueListEditor.Keys[Index]);
    end;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.MethodValueListEditorMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  if Resizeable then
    MethodValueListEditor.DefaultColWidth := X;
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.MethodValueListEditorMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
begin
  if Resizeable and ( ssLeft in Shift ) then
    MethodValueListEditor.DefaultColWidth := X;
  if ( X > MethodValueListEditor.DefaultColWidth - 1 ) and ( X < MethodValueListEditor.DefaultColWidth + 1 ) then
    begin
      Screen.Cursor := crHSplit;
      Resizeable := True;
    end
  else
    begin
      Screen.Cursor := crDefault;
      Resizeable := False;
    end;
end;

{----------------------------------------------------------------------------}
function TObjectInspectorF.RecursiveFind(Root: TComponent; ActiveWindow: HWND) : Integer;
var
  i   : Integer;
  Res : Integer;
begin
  Result := 0;
  if ( Root.ClassName = 'TMyDialogEdit' ) and ( TForm(Root).Handle = ActiveWindow ) then
    Result := Integer(Root)
  else
    begin
      for i := 0 to Root.ComponentCount - 1 do
        begin
          Res := RecursiveFind(Root.Components[i], ActiveWindow);
          if Res <> 0 then
            Result := Res;
        end;
    end;
end;

{----------------------------------------------------------------------------}
function TObjectInspectorF.FindActiveEditor() : Integer;
begin
  Result := RecursiveFind(Application, GetActiveWindow());
end;

{----------------------------------------------------------------------------}
procedure TObjectInspectorF.ClearOI();
begin
  NeedRefresh := True;
  RefreshSelectionBorder := False;
  FDrawFlag := 0;
  Resizeable := False;
  ObjectChanged := nil;
  if AbstractObject <> nil then
    begin
      SetLength(AbstractObject.PropertyList,0);
      SetLength(AbstractObject.MethodList,0);
    end;
  AbstractObject := TPropObject.Create;
  SetLength(Items, 0);
  SetLength(SelectedObjects, 0);
  OIComboBoxChange(AbstractObject);
end;

end.
{----------------------------------------------------------------------------}


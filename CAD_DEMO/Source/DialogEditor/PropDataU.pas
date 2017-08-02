unit PropDataU;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, StdCtrls, ExtCtrls, Grids, ValEdit, TypInfo, Types;

const
  MaxPropLen = 255;

type
  PropIdent = (piSet, piSetElement, piClass, piEnumeration, piPointer, piNone);
  TPropObject = class;

{----------------------------------------------------------------------------}
{ TProp }
  TProp = class
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
  TPropObject = class(TObject)
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

function DefaultObject(const Value: TObject; Owner: TComponent) : TObject;

implementation

{----------------------------------------------------------------------------}
function DefaultObject(const Value: TObject; Owner: TComponent) : TObject;
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
{ TProp }
{----------------------------------------------------------------------------}
constructor TProp.Create;
begin
  inherited Create;
  FObject := nil;
  FParent := nil;
  Data := '';
  SawFlag := True;
end;

{----------------------------------------------------------------------------}
function TProp.GetProperty(): PPropInfo;
begin
  Result := @FPropertyInfo;
end;

{----------------------------------------------------------------------------}
procedure TProp.SetProperty(const Value: PPropInfo);
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
constructor TPropObject.Create;
begin
  inherited Create;
  FRefresh := False;
  FOpenFlag := False;
  FSetLength := 0;
  FSetValue := '';
  FPropId := piNone;
end;

{----------------------------------------------------------------------------}
destructor TPropObject.Destroy;
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
function TPropObject.GetChild(_Name: string): TPropObject;
var
  i     : Integer;
begin
  Result := nil;
  for i := 0 to Length(ChildList) - 1 do
    if _Name = ChildList[i].Name then Result := ChildList[i];
end;

{----------------------------------------------------------------------------}
function TPropObject.IsAnyType(Index: integer; const PropType: TTypeKinds): boolean;
begin
  Result := PropertyList[Index].PropertyKind in PropType;
end;

{----------------------------------------------------------------------------}
procedure TPropObject.SetObject(_Name: string; const Value, Default: TObject; _Copy: Boolean; _Parent: TPropObject);
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
function TPropObject.NextWord(var Value: PChar): string;
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
function TPropObject.GetPropertyValue(Name: string): variant;
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

end.
{----------------------------------------------------------------------------}

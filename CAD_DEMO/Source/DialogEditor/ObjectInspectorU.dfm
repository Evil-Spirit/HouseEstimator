object ObjectInspectorF: TObjectInspectorF
  Left = 0
  Top = 358
  Width = 180
  Height = 380
  BorderStyle = bsSizeToolWin
  Caption = 'Object Inspector'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object OIPanel: TPanel
    Left = 0
    Top = 0
    Width = 172
    Height = 25
    Align = alTop
    TabOrder = 0
    DesignSize = (
      172
      25)
    object OIComboBox: TComboBox
      Left = 0
      Top = 0
      Width = 172
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      ItemHeight = 13
      ParentColor = True
      TabOrder = 0
      OnChange = OIComboBoxChange
    end
  end
  object OIStatusBar: TStatusBar
    Left = 0
    Top = 334
    Width = 172
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object OIPageControl: TPageControl
    Left = 0
    Top = 25
    Width = 172
    Height = 309
    ActivePage = OIProperties
    Align = alClient
    TabIndex = 0
    TabOrder = 2
    object OIProperties: TTabSheet
      Caption = 'Properties'
      object PropertyValueListEditor: TValueListEditor
        Left = 0
        Top = 0
        Width = 164
        Height = 281
        Align = alClient
        BiDiMode = bdLeftToRight
        Color = clBtnFace
        DefaultColWidth = 85
        DefaultRowHeight = 16
        DisplayOptions = [doAutoColResize, doKeyColFixed]
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goColSizing, goEditing, goTabs, goAlwaysShowEditor, goThumbTracking]
        ParentBiDiMode = False
        ScrollBars = ssVertical
        Strings.Strings = (
          '=')
        TabOrder = 0
        OnDblClick = PropertyValueListEditorDblClick
        OnDrawCell = PropertyValueListEditorDrawCell
        OnEditButtonClick = PropertyValueListEditorEditButtonClick
        OnKeyDown = PropertyValueListEditorKeyDown
        OnMouseDown = PropertyValueListEditorMouseDown
        OnMouseMove = PropertyValueListEditorMouseMove
        OnMouseUp = PropertyValueListEditorMouseUp
        OnSelectCell = PropertyValueListEditorSelectCell
        OnStringsChange = PropertyValueListEditorStringsChange
        ColWidths = (
          85
          73)
      end
    end
    object OIMethods: TTabSheet
      Caption = 'Events'
      ImageIndex = 1
      object MethodValueListEditor: TValueListEditor
        Left = 0
        Top = 0
        Width = 176
        Height = 281
        Align = alClient
        Color = clBtnFace
        DefaultColWidth = 85
        DefaultRowHeight = 16
        DisplayOptions = [doAutoColResize, doKeyColFixed]
        FixedColor = clWindow
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goColSizing, goEditing, goTabs, goAlwaysShowEditor, goThumbTracking]
        ScrollBars = ssVertical
        TabOrder = 0
        OnDblClick = MethodValueListEditorDblClick
        OnKeyDown = MethodValueListEditorKeyDown
        OnMouseMove = MethodValueListEditorMouseMove
        OnMouseUp = MethodValueListEditorMouseUp
        OnStringsChange = MethodValueListEditorStringsChange
        ColWidths = (
          85
          85)
      end
    end
  end
end

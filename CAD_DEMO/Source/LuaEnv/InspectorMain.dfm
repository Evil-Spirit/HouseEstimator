object DbgInspector: TDbgInspector
  Left = 258
  Top = 115
  Width = 284
  Height = 154
  Anchors = [akLeft, akTop, akRight, akBottom]
  BorderStyle = bsSizeToolWin
  Caption = 'Debug Inspector'
  Color = clBtnFace
  Constraints.MinHeight = 50
  Constraints.MinWidth = 80
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnClose = FormClose
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Sheets: TPageControl
    Left = 0
    Top = 24
    Width = 273
    Height = 81
    ActivePage = Sheet1
    TabIndex = 0
    TabOrder = 0
    object Sheet1: TTabSheet
      Caption = 'Data'
      ImageIndex = 1
      object DataWatch1: TStringGrid
        Left = 0
        Top = 0
        Width = 265
        Height = 53
        Align = alClient
        ColCount = 3
        DefaultColWidth = 100
        DefaultRowHeight = 15
        FixedCols = 0
        RowCount = 2
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
        ScrollBars = ssVertical
        TabOrder = 0
        OnDblClick = DataWatch1DblClick
        ColWidths = (
          80
          79
          100)
      end
    end
    object Sheet2: TTabSheet
      Caption = 'Methods'
      ImageIndex = 1
      TabVisible = False
      object DataWatch2: TStringGrid
        Left = 0
        Top = 0
        Width = 265
        Height = 329
        Align = alClient
        ColCount = 3
        DefaultColWidth = 100
        DefaultRowHeight = 15
        FixedCols = 0
        RowCount = 2
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSizing, goColSizing, goRowSelect]
        ScrollBars = ssVertical
        TabOrder = 0
        ColWidths = (
          80
          74
          100)
      end
    end
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 108
    Width = 276
    Height = 19
    AutoHint = True
    Panels = <>
    SimplePanel = False
  end
  object VariableName: TComboBoxEx
    Left = 0
    Top = 0
    Width = 273
    Height = 22
    ItemsEx.CaseSensitive = False
    ItemsEx.SortType = stNone
    ItemsEx = <>
    StyleEx = []
    ItemHeight = 16
    TabOrder = 1
    OnKeyDown = VariableNameKeyDown
    DropDownCount = 8
  end
end

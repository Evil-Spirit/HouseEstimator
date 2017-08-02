object SelectBorder: TSelectBorder
  Left = 328
  Top = 125
  BorderStyle = bsNone
  Caption = 'SelectBorder'
  ClientHeight = 86
  ClientWidth = 115
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnDeactivate = FormDeactivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 115
    Height = 86
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object ToolBar1: TToolBar
      Left = 12
      Top = 8
      Width = 95
      Height = 70
      Align = alNone
      Caption = 'ToolBar1'
      EdgeBorders = []
      Flat = True
      Images = CGIL.ilBorders
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Caption = 'ToolButton1'
        ImageIndex = 0
        OnClick = ToolButton1Click
      end
      object ToolButton2: TToolButton
        Left = 23
        Top = 0
        Caption = 'ToolButton2'
        ImageIndex = 1
        OnClick = ToolButton2Click
      end
      object ToolButton4: TToolButton
        Left = 46
        Top = 0
        Caption = 'ToolButton4'
        ImageIndex = 2
        OnClick = ToolButton4Click
      end
      object ToolButton5: TToolButton
        Left = 69
        Top = 0
        Caption = 'ToolButton5'
        ImageIndex = 3
        Wrap = True
        OnClick = ToolButton5Click
      end
      object ToolButton6: TToolButton
        Left = 0
        Top = 22
        Caption = 'ToolButton6'
        ImageIndex = 4
        OnClick = ToolButton6Click
      end
      object ToolButton7: TToolButton
        Left = 23
        Top = 22
        Caption = 'ToolButton7'
        ImageIndex = 5
        OnClick = ToolButton7Click
      end
      object ToolButton8: TToolButton
        Left = 46
        Top = 22
        Caption = 'ToolButton8'
        ImageIndex = 6
        OnClick = ToolButton8Click
      end
      object ToolButton9: TToolButton
        Left = 69
        Top = 22
        Caption = 'ToolButton9'
        ImageIndex = 7
        Wrap = True
        OnClick = ToolButton9Click
      end
      object ToolButton10: TToolButton
        Left = 0
        Top = 44
        Caption = 'ToolButton10'
        ImageIndex = 8
        OnClick = ToolButton10Click
      end
      object ToolButton11: TToolButton
        Left = 23
        Top = 44
        Caption = 'ToolButton11'
        ImageIndex = 9
        OnClick = ToolButton11Click
      end
      object ToolButton12: TToolButton
        Left = 46
        Top = 44
        Caption = 'ToolButton12'
        ImageIndex = 10
        OnClick = ToolButton12Click
      end
      object ToolButton13: TToolButton
        Left = 69
        Top = 44
        Caption = 'ToolButton13'
        ImageIndex = 11
        OnClick = ToolButton13Click
      end
    end
  end
end

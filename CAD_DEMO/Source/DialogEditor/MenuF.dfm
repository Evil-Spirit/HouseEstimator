object MainMenuF: TMainMenuF
  Left = 192
  Top = 106
  Width = 126
  Height = 41
  BorderStyle = bsSizeToolWin
  Caption = 'Menu'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu: TMainMenu
    object mmView: TMenuItem
      Caption = 'View'
      object mmObjectInspector: TMenuItem
        Caption = 'Object Inspector'
        OnClick = mmObjectInspectorClick
      end
      object mmObjectTreeView: TMenuItem
        Caption = 'Object TreeView'
        OnClick = mmObjectTreeViewClick
      end
      object mmToolBar: TMenuItem
        Caption = 'ToolBar'
        OnClick = mmToolBarClick
      end
    end
  end
end

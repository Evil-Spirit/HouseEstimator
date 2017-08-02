object CheckForm: TCheckForm
  Left = 868
  Top = 5
  HelpType = htKeyword
  AutoScroll = False
  AutoSize = True
  BorderIcons = []
  Caption = 'CheckForm'
  ClientHeight = 185
  ClientWidth = 145
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object EditB: TButton
    Left = 0
    Top = 96
    Width = 145
    Height = 25
    Caption = 'Edit'
    TabOrder = 0
    OnClick = EditBClick
  end
  object LoadB: TButton
    Left = 0
    Top = 64
    Width = 145
    Height = 25
    Caption = 'Load'
    TabOrder = 1
    OnClick = LoadBClick
  end
  object SaveB: TButton
    Left = 0
    Top = 32
    Width = 145
    Height = 25
    Caption = 'Save'
    TabOrder = 2
    OnClick = SaveBClick
  end
  object CreateB: TButton
    Left = 0
    Top = 128
    Width = 145
    Height = 25
    Caption = 'Create'
    TabOrder = 3
    OnClick = CreateBClick
  end
  object NewB: TButton
    Left = 0
    Top = 0
    Width = 145
    Height = 25
    Caption = 'New'
    TabOrder = 4
    OnClick = NewBClick
  end
  object ExitB: TButton
    Left = 0
    Top = 160
    Width = 145
    Height = 25
    Caption = 'Exit'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = ExitBClick
  end
end

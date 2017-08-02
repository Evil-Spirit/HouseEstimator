object ProgramProperty: TProgramProperty
  Left = 328
  Top = 182
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'ProgramProperty'
  ClientHeight = 382
  ClientWidth = 328
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PC: TPageControl
    Left = 0
    Top = 8
    Width = 329
    Height = 337
    ActivePage = pGrid
    TabIndex = 1
    TabOrder = 0
    object pSnap: TTabSheet
      Caption = #1059#1083#1072#1074#1083#1080#1074#1072#1085#1080#1077
      object Label1: TLabel
        Left = 16
        Top = 112
        Width = 133
        Height = 13
        Caption = #1054#1073#1083#1072#1089#1090#1100' '#1091#1083#1072#1074#1083#1080#1074#1072#1085#1080#1103' (pix)'
      end
      object lSnapStep: TLabel
        Left = 16
        Top = 144
        Width = 174
        Height = 13
        Caption = #1050#1088#1072#1090#1085#1086#1089#1090#1100' '#1089#1077#1090#1082#1080' '#1076#1083#1103' '#1091#1083#1072#1074#1083#1080#1074#1072#1085#1080#1103
      end
      object cbSnapOn: TCheckBox
        Left = 16
        Top = 16
        Width = 89
        Height = 17
        Caption = #1059#1083#1072#1074#1083#1080#1074#1072#1090#1100
        Checked = True
        State = cbChecked
        TabOrder = 0
      end
      object cbAdditionalSnapOn: TCheckBox
        Left = 16
        Top = 40
        Width = 241
        Height = 17
        Caption = #1059#1083#1072#1074#1083#1080#1074#1072#1090#1100' '#1087#1086' '#1074#1089#1087#1086#1084#1086#1075#1072#1090#1077#1083#1100#1085#1099#1084' '#1083#1080#1085#1103#1084
        Checked = True
        State = cbChecked
        TabOrder = 1
      end
      object cbMyFigureSnapOn: TCheckBox
        Left = 16
        Top = 64
        Width = 233
        Height = 17
        Caption = #1059#1083#1072#1074#1083#1080#1074#1072#1090#1100' '#1087#1086' '#1082#1086#1085#1090#1091#1088#1091
        Checked = True
        State = cbChecked
        TabOrder = 2
      end
      object eSnapValue: TEdit
        Left = 264
        Top = 112
        Width = 41
        Height = 21
        TabOrder = 3
        Text = '10'
      end
      object eSnapStep: TEdit
        Left = 264
        Top = 144
        Width = 41
        Height = 21
        TabOrder = 4
        Text = '2'
      end
    end
    object pGrid: TTabSheet
      Caption = #1057#1077#1090#1082#1072
      ImageIndex = 1
      object lGridStep: TLabel
        Left = 8
        Top = 40
        Width = 69
        Height = 13
        Caption = #1064#1072#1075' '#1089#1077#1090#1082#1080' ('#1084')'
      end
      object lMultiplier: TLabel
        Left = 8
        Top = 72
        Width = 154
        Height = 13
        Caption = #1050#1088#1072#1090#1085#1086#1089#1090#1100' '#1073#1086#1083#1100#1096#1077#1081' '#1089#1077#1090#1082#1080' (pix)'
      end
      object lSwitchEpsilon: TLabel
        Left = 8
        Top = 104
        Width = 163
        Height = 13
        Caption = #1052#1080#1085#1080#1084#1072#1083#1100#1085#1072#1103' '#1103#1095#1077#1081#1082#1072' '#1089#1077#1090#1082#1080' (pix)'
      end
      object lZoomLimit: TLabel
        Left = 8
        Top = 136
        Width = 116
        Height = 13
        Caption = #1055#1088#1077#1076#1077#1083' '#1091#1074#1077#1083#1080#1095#1077#1085#1080#1103' ('#1084')'
      end
      object eStep: TEdit
        Left = 256
        Top = 40
        Width = 41
        Height = 21
        TabOrder = 0
        Text = '0,1'
      end
      object eMultiplier: TEdit
        Left = 256
        Top = 72
        Width = 41
        Height = 21
        TabOrder = 1
        Text = '10'
      end
      object cbGridOn: TCheckBox
        Left = 8
        Top = 8
        Width = 81
        Height = 17
        Caption = #1057#1077#1090#1082#1072' '#1074#1082#1083
        Checked = True
        State = cbChecked
        TabOrder = 2
      end
      object eSwitchEpsilon: TEdit
        Left = 256
        Top = 104
        Width = 41
        Height = 21
        TabOrder = 3
        Text = '10'
      end
      object eZoomLimit: TEdit
        Left = 256
        Top = 136
        Width = 41
        Height = 21
        TabOrder = 4
        Text = '9999'
      end
    end
    object pColors: TTabSheet
      Caption = #1062#1074#1077#1090#1072
      ImageIndex = 2
      object lGridMINColor: TLabel
        Left = 8
        Top = 16
        Width = 79
        Height = 13
        Caption = #1052#1077#1085#1100#1096#1072#1103' '#1089#1077#1090#1082#1072
      end
      object lGridMAXColor: TLabel
        Left = 8
        Top = 48
        Width = 77
        Height = 13
        Caption = #1041#1086#1083#1100#1096#1072#1103' '#1089#1077#1090#1082#1072
      end
      object lGridOSIColor: TLabel
        Left = 8
        Top = 80
        Width = 76
        Height = 13
        Caption = #1054#1089#1080' '#1082#1086#1086#1088#1076#1080#1085#1072#1090
      end
      object lAdditionalColor: TLabel
        Left = 8
        Top = 112
        Width = 126
        Height = 13
        Caption = #1042#1089#1087#1086#1084#1086#1075#1072#1090#1077#1083#1100#1085#1099#1077' '#1083#1080#1085#1080#1080
      end
      object lMyFiguresColor: TLabel
        Left = 8
        Top = 144
        Width = 75
        Height = 13
        Caption = #1051#1080#1085#1080#1080' '#1082#1086#1085#1090#1091#1088#1072
      end
      object lSelectedColor: TLabel
        Left = 8
        Top = 176
        Width = 98
        Height = 13
        Caption = #1042#1099#1076#1077#1083#1077#1085#1085#1099#1077' '#1083#1080#1085#1080#1080
      end
      object lBackGroundColor: TLabel
        Left = 8
        Top = 240
        Width = 23
        Height = 13
        Caption = #1060#1086#1085
      end
      object lCursor: TLabel
        Left = 8
        Top = 272
        Width = 36
        Height = 13
        Caption = #1050#1091#1088#1089#1086#1088
      end
      object lLinesFixid: TLabel
        Left = 8
        Top = 208
        Width = 118
        Height = 13
        Caption = #1060#1080#1082#1089#1080#1088#1086#1074#1072#1085#1085#1099#1077' '#1083#1080#1085#1080#1080
      end
      object cbGridMIN: TColorBox
        Left = 160
        Top = 16
        Width = 145
        Height = 22
        AutoComplete = False
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        Ctl3D = True
        ItemHeight = 16
        ParentCtl3D = False
        TabOrder = 0
      end
      object cbGridMAX: TColorBox
        Left = 160
        Top = 48
        Width = 145
        Height = 22
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        ItemHeight = 16
        TabOrder = 1
      end
      object cbGridOSI: TColorBox
        Left = 160
        Top = 80
        Width = 145
        Height = 22
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        ItemHeight = 16
        TabOrder = 2
      end
      object cbAdditional: TColorBox
        Left = 160
        Top = 112
        Width = 145
        Height = 22
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        ItemHeight = 16
        TabOrder = 3
      end
      object cbMyFigures: TColorBox
        Left = 160
        Top = 144
        Width = 145
        Height = 22
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        ItemHeight = 16
        TabOrder = 4
      end
      object cbSelected: TColorBox
        Left = 160
        Top = 176
        Width = 145
        Height = 22
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbIncludeDefault, cbCustomColor]
        ItemHeight = 16
        TabOrder = 5
      end
      object cbBackGround: TColorBox
        Left = 160
        Top = 240
        Width = 145
        Height = 22
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        ItemHeight = 16
        TabOrder = 6
      end
      object cbCursor: TColorBox
        Left = 160
        Top = 272
        Width = 145
        Height = 22
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        ItemHeight = 16
        TabOrder = 7
      end
      object cbFixid: TColorBox
        Left = 160
        Top = 208
        Width = 145
        Height = 22
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        ItemHeight = 16
        TabOrder = 8
      end
    end
  end
  object bOk: TButton
    Left = 48
    Top = 352
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = bOkClick
  end
  object bCancel: TButton
    Left = 200
    Top = 352
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 2
    OnClick = bCancelClick
  end
end

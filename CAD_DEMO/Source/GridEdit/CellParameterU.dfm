object CellParameter: TCellParameter
  Left = 355
  Top = 186
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #1060#1086#1088#1084#1072#1090' '#1103#1095#1077#1077#1082
  ClientHeight = 314
  ClientWidth = 481
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object OK: TButton
    Left = 296
    Top = 280
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = OKClick
  end
  object Cansel: TButton
    Left = 384
    Top = 280
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = CanselClick
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 481
    Height = 265
    ActivePage = TabSheet2
    Align = alTop
    TabIndex = 1
    TabOrder = 2
    object TabSheet1: TTabSheet
      Caption = #1058#1077#1082#1089#1090
      object GroupBox2: TGroupBox
        Left = 0
        Top = 4
        Width = 185
        Height = 221
        Caption = ' '#1058#1080#1087' '
        TabOrder = 0
        object Label2: TLabel
          Left = 8
          Top = 16
          Width = 132
          Height = 13
          Caption = #1058#1080#1087' '#1089#1086#1076#1077#1088#1078#1080#1084#1086#1075#1086' '#1103#1095#1077#1081#1082#1080':'
        end
        object cbValueType: TComboBox
          Left = 8
          Top = 32
          Width = 169
          Height = 105
          Style = csSimple
          ItemHeight = 0
          TabOrder = 0
          OnChange = cbValueTypeChange
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1042#1099#1088#1072#1074#1085#1080#1074#1072#1085#1080#1077
      ImageIndex = 1
      object GroupBox1: TGroupBox
        Left = 0
        Top = 0
        Width = 185
        Height = 129
        Caption = ' '#1042#1099#1088#1072#1074#1085#1080#1074#1072#1085#1080#1077' '#1090#1077#1082#1089#1090#1072' '
        TabOrder = 0
        object Label1: TLabel
          Left = 8
          Top = 24
          Width = 84
          Height = 13
          Caption = #1055#1086' '#1075#1086#1088#1080#1079#1086#1085#1090#1072#1083#1080':'
        end
        object Label3: TLabel
          Left = 8
          Top = 80
          Width = 73
          Height = 13
          Caption = #1055#1086' '#1074#1077#1088#1090#1080#1082#1072#1083#1080':'
        end
        object cbTextHAlign: TComboBox
          Left = 8
          Top = 40
          Width = 169
          Height = 21
          Style = csDropDownList
          ItemHeight = 13
          TabOrder = 0
          OnChange = cbTextHAlignChange
        end
        object cbTextVAlign: TComboBox
          Left = 8
          Top = 96
          Width = 169
          Height = 21
          Style = csDropDownList
          ItemHeight = 13
          TabOrder = 1
          OnChange = cbTextVAlignChange
        end
      end
      object GroupBox3: TGroupBox
        Left = 0
        Top = 136
        Width = 185
        Height = 57
        Caption = ' '#1054#1090#1086#1073#1088#1072#1078#1077#1085#1080#1077' '#1090#1077#1082#1089#1090#1072' '
        TabOrder = 1
        object chbTextWordBreak: TCheckBox
          Left = 8
          Top = 16
          Width = 145
          Height = 17
          Caption = #1055#1077#1088#1077#1085#1086#1089#1080#1090#1100' '#1087#1086' '#1089#1083#1086#1074#1072#1084
          Color = clBtnFace
          ParentColor = False
          TabOrder = 0
          OnClick = chbTextWordBreakClick
        end
        object chbTypeAutoSize: TCheckBox
          Left = 8
          Top = 32
          Width = 97
          Height = 17
          Caption = #1040#1074#1090#1086' '#1088#1072#1079#1084#1077#1088
          TabOrder = 1
          OnClick = chbTypeAutoSizeClick
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1064#1088#1080#1092#1090
      ImageIndex = 2
      object Label4: TLabel
        Left = 8
        Top = 0
        Width = 37
        Height = 13
        Caption = #1064#1088#1080#1092#1090':'
      end
      object Label5: TLabel
        Left = 160
        Top = 0
        Width = 63
        Height = 13
        Caption = #1053#1072#1095#1077#1088#1090#1072#1085#1080#1077':'
      end
      object Label6: TLabel
        Left = 312
        Top = 0
        Width = 42
        Height = 13
        Caption = #1056#1072#1079#1084#1077#1088':'
      end
      object Label7: TLabel
        Left = 160
        Top = 112
        Width = 70
        Height = 13
        Caption = #1062#1074#1077#1090' '#1096#1088#1080#1092#1090#1072':'
      end
      object cbFontName: TComboBox
        Left = 8
        Top = 16
        Width = 145
        Height = 137
        Style = csSimple
        ItemHeight = 0
        TabOrder = 0
        OnChange = cbFontNameChange
      end
      object cbFontStyle: TComboBox
        Left = 160
        Top = 16
        Width = 145
        Height = 97
        Style = csSimple
        ItemHeight = 0
        TabOrder = 1
        OnChange = cbFontStyleChange
      end
      object cbFontSize: TComboBox
        Left = 312
        Top = 16
        Width = 57
        Height = 97
        Style = csSimple
        ItemHeight = 0
        TabOrder = 2
        OnChange = cbFontSizeChange
      end
      object GroupBox4: TGroupBox
        Left = 8
        Top = 152
        Width = 145
        Height = 57
        Caption = #1069#1092#1092#1077#1082#1090#1099' '#1096#1088#1080#1092#1090#1072
        TabOrder = 3
        object chbFontUnderline: TCheckBox
          Left = 8
          Top = 16
          Width = 97
          Height = 17
          Caption = #1055#1086#1076#1095#1077#1088#1082#1085#1091#1090#1099#1081
          TabOrder = 0
          OnClick = chbFontUnderlineClick
        end
        object chbFontStrikeOut: TCheckBox
          Left = 8
          Top = 32
          Width = 97
          Height = 17
          Caption = #1047#1072#1095#1077#1088#1082#1085#1091#1090#1099#1081
          TabOrder = 1
          OnClick = chbFontStrikeOutClick
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = #1041#1086#1088#1076#1102#1088
      ImageIndex = 3
      object GroupBox5: TGroupBox
        Left = 0
        Top = 0
        Width = 185
        Height = 57
        Caption = ' '#1042#1089#1077' '#1075#1088#1072#1085#1080#1094#1099' '
        TabOrder = 0
        object btLineFlood: TSpeedButton
          Left = 8
          Top = 16
          Width = 32
          Height = 32
          Glyph.Data = {
            96010000424D9601000000000000760000002800000018000000180000000100
            0400000000002001000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000FFF0FF
            FFFFFFF0FFFFFFFFF0FFF0FFFFFFFFF0FFFFFFFFF0FFF0FFFFFFFFF0FFFFFFFF
            F0FFF0FFFFFFFFF0FFFFFFFFF0FFF0FFFFFFFFF0FFFFFFFFF0FFF0FFFFFFFFF0
            FFFFFFFFF0FFF0FFFFFFFFF0FFFFFFFFF0FFF0FFFFFFFFF0FFFFFFFFF0FFF0FF
            FFFFFFF0FFFFFFFFF0FFF000000000000000000000FFF0FFFFFFFFF0FFFFFFFF
            F0FFF0FFFFFFFFF0FFFFFFFFF0FFF0FFFFFFFFF0FFFFFFFFF0FFF0FFFFFFFFF0
            FFFFFFFFF0FFF0FFFFFFFFF0FFFFFFFFF0FFF0FFFFFFFFF0FFFFFFFFF0FFF0FF
            FFFFFFF0FFFFFFFFF0FFF0FFFFFFFFF0FFFFFFFFF0FFF0FFFFFFFFF0FFFFFFFF
            F0FFF000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFF}
          OnClick = btLineFloodClick
        end
        object btLine: TSpeedButton
          Left = 48
          Top = 16
          Width = 32
          Height = 32
          Glyph.Data = {
            96010000424D9601000000000000760000002800000018000000180000000100
            0400000000002001000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000FFF0FF
            FFFFFFFFFFFFFFFFF0FFF0FFFFFFFFF8FFFFFFFFF0FFF0FFFFFFFFFFFFFFFFFF
            F0FFF0FFFFFFFFF8FFFFFFFFF0FFF0FFFFFFFFFFFFFFFFFFF0FFF0FFFFFFFFF8
            FFFFFFFFF0FFF0FFFFFFFFFFFFFFFFFFF0FFF0FFFFFFFFF8FFFFFFFFF0FFF0FF
            FFFFFFFFFFFFFFFFF0FFF0F8F8F8F8F8F8F8F8F8F0FFF0FFFFFFFFFFFFFFFFFF
            F0FFF0FFFFFFFFF8FFFFFFFFF0FFF0FFFFFFFFFFFFFFFFFFF0FFF0FFFFFFFFF8
            FFFFFFFFF0FFF0FFFFFFFFFFFFFFFFFFF0FFF0FFFFFFFFF8FFFFFFFFF0FFF0FF
            FFFFFFFFFFFFFFFFF0FFF0FFFFFFFFF8FFFFFFFFF0FFF0FFFFFFFFFFFFFFFFFF
            F0FFF000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFF}
          OnClick = btLineClick
        end
        object btLineFloodClear: TSpeedButton
          Left = 88
          Top = 16
          Width = 32
          Height = 32
          Glyph.Data = {
            96010000424D9601000000000000760000002800000018000000180000000100
            0400000000002001000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8F8F8F8F8F8F8F8F8F8F8FFFFFF
            FFFFFFFFFFFFFFFFFFFFF8FFFFFFFFF8FFFFFFFFF8FFFFFFFFFFFFFFFFFFFFFF
            FFFFF8FFFFFFFFF8FFFFFFFFF8FFFFFFFFFFFFFFFFFFFFFFFFFFF8FFFFFFFFF8
            FFFFFFFFF8FFFFFFFFFFFFFFFFFFFFFFFFFFF8FFFFFFFFF8FFFFFFFFF8FFFFFF
            FFFFFFFFFFFFFFFFFFFFF8F8F8F8F8F8F8F8F8F8F8FFFFFFFFFFFFFFFFFFFFFF
            FFFFF8FFFFFFFFF8FFFFFFFFF8FFFFFFFFFFFFFFFFFFFFFFFFFFF8FFFFFFFFF8
            FFFFFFFFF8FFFFFFFFFFFFFFFFFFFFFFFFFFF8FFFFFFFFF8FFFFFFFFF8FFFFFF
            FFFFFFFFFFFFFFFFFFFFF8FFFFFFFFF8FFFFFFFFF8FFFFFFFFFFFFFFFFFFFFFF
            FFFFF8F8F8F8F8F8F8F8F8F8F8FFFFFFFFFFFFFFFFFFFFFFFFFF}
          OnClick = btLineFloodClearClick
        end
      end
      object GroupBox6: TGroupBox
        Left = 0
        Top = 64
        Width = 265
        Height = 169
        Caption = ' '#1054#1090#1076#1077#1083#1100#1085#1099#1077' '#1075#1088#1072#1085#1080#1094#1099' '
        TabOrder = 1
        object btLineOne_Top: TSpeedButton
          Left = 40
          Top = 24
          Width = 22
          Height = 23
          AllowAllUp = True
          GroupIndex = -1
          Glyph.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            0400000000008000000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFF8F8F8F8F8F8F8FFFFFFFFFFFFFFFFFFF8FFFFF8FFFF
            F8FFFFFFFFFFFFFFFFFFF8FFFFF8FFFFF8FFFFFFFFFFFFFFFFFFF8F8F8F8F8F8
            F8FFFFFFFFFFFFFFFFFFF8FFFFF8FFFFF8FFFFFFFFFFFFFFFFFFF8FFFFF8FFFF
            F8FFFFFFFFFFFFFFFFFFF0000000000000FFFFFFFFFFFFFFFFFF}
          OnClick = btLineOne_TopClick
        end
        object btLineOne_Left: TSpeedButton
          Left = 64
          Top = 128
          Width = 22
          Height = 23
          AllowAllUp = True
          GroupIndex = -4
          Glyph.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            0400000000008000000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFF0F8F8F8F8F8F8FFF0FFFFFFFFFFFFFFF0FFFFF8FFFF
            F8FFF0FFFFFFFFFFFFFFF0FFFFF8FFFFF8FFF0FFFFFFFFFFFFFFF0F8F8F8F8F8
            F8FFF0FFFFFFFFFFFFFFF0FFFFF8FFFFF8FFF0FFFFFFFFFFFFFFF0FFFFF8FFFF
            F8FFF0FFFFFFFFFFFFFFF0F8F8F8F8F8F8FFFFFFFFFFFFFFFFFF}
          OnClick = btLineOne_LeftClick
        end
        object btLineOne_Right: TSpeedButton
          Left = 216
          Top = 128
          Width = 22
          Height = 23
          AllowAllUp = True
          GroupIndex = -6
          Glyph.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            0400000000008000000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFF8F8F8F8F8F8F0FFFFFFFFFFFFFFF0FFF8FFFFF8FFFF
            F0FFFFFFFFFFFFFFF0FFF8FFFFF8FFFFF0FFFFFFFFFFFFFFF0FFF8F8F8F8F8F8
            F0FFFFFFFFFFFFFFF0FFF8FFFFF8FFFFF0FFFFFFFFFFFFFFF0FFF8FFFFF8FFFF
            F0FFFFFFFFFFFFFFF0FFF8F8F8F8F8F8F0FFFFFFFFFFFFFFFFFF}
          OnClick = btLineOne_RightClick
        end
        object btLineOne_Bottom: TSpeedButton
          Left = 40
          Top = 96
          Width = 22
          Height = 23
          AllowAllUp = True
          GroupIndex = -3
          Glyph.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            0400000000008000000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFF0000000000000FFFFFFFFFFFFFFFFFFF8FFFFF8FFFF
            F8FFFFFFFFFFFFFFFFFFF8FFFFF8FFFFF8FFFFFFFFFFFFFFFFFFF8F8F8F8F8F8
            F8FFFFFFFFFFFFFFFFFFF8FFFFF8FFFFF8FFFFFFFFFFFFFFFFFFF8FFFFF8FFFF
            F8FFFFFFFFFFFFFFFFFFF8F8F8F8F8F8F8FFFFFFFFFFFFFFFFFF}
          OnClick = btLineOne_BottomClick
        end
        object imExampleBorder: TPaintBox
          Left = 64
          Top = 24
          Width = 177
          Height = 97
          Color = clWhite
          ParentColor = False
          OnPaint = imExampleBorderPaint
        end
        object btLineOne_CenterH: TSpeedButton
          Left = 40
          Top = 56
          Width = 22
          Height = 23
          AllowAllUp = True
          GroupIndex = -2
          Glyph.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            0400000000008000000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFF8F8F8F8F8F8F8FFFFFFFFFFFFFFFFFFF8FFFFF8FFFF
            F8FFFFFFFFFFFFFFFFFFF8FFFFF8FFFFF8FFFFFFFFFFFFFFFFFFF00000000000
            00FFFFFFFFFFFFFFFFFFF8FFFFF8FFFFF8FFFFFFFFFFFFFFFFFFF8FFFFF8FFFF
            F8FFFFFFFFFFFFFFFFFFF8F8F8F8F8F8F8FFFFFFFFFFFFFFFFFF}
          OnClick = btLineOne_CenterHClick
        end
        object btLineOne_CenterV: TSpeedButton
          Left = 136
          Top = 128
          Width = 22
          Height = 23
          AllowAllUp = True
          GroupIndex = -5
          Glyph.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            0400000000008000000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFF8F8F8F0F8F8F8FFFFFFFFF0FFFFFFFFF8FFFFF0FFFF
            F8FFFFFFFFF0FFFFFFFFF8FFFFF0FFFFF8FFFFFFFFF0FFFFFFFFF8F8F8F0F8F8
            F8FFFFFFFFF0FFFFFFFFF8FFFFF0FFFFF8FFFFFFFFF0FFFFFFFFF8FFFFF0FFFF
            F8FFFFFFFFF0FFFFFFFFF8F8F8F0F8F8F8FFFFFFFFFFFFFFFFFF}
          OnClick = btLineOne_CenterVClick
        end
      end
      object GroupBox7: TGroupBox
        Left = 192
        Top = 0
        Width = 137
        Height = 41
        Caption = #1058#1080#1087' '#1083#1080#1085#1080#1080
        TabOrder = 2
        object btLine0: TSpeedButton
          Left = 8
          Top = 17
          Width = 32
          Height = 16
          GroupIndex = 1
          Down = True
          Flat = True
          Glyph.Data = {
            96010000424D9601000000000000760000002800000018000000180000000100
            0400000000002001000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFF8F8F8F8F8F8F8F8F8F8F8FFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          OnClick = btLine0Click
        end
        object btLine1: TSpeedButton
          Left = 48
          Top = 17
          Width = 32
          Height = 16
          GroupIndex = 1
          Flat = True
          Glyph.Data = {
            96010000424D9601000000000000760000002800000018000000180000000100
            0400000000002001000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFF0000000000000000000000FFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          OnClick = btLine0Click
        end
        object btLine2: TSpeedButton
          Left = 88
          Top = 17
          Width = 32
          Height = 16
          GroupIndex = 1
          Flat = True
          Glyph.Data = {
            96010000424D9601000000000000760000002800000018000000180000000100
            0400000000002001000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFF0000000000000000000000FF0000000000000000000
            000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          OnClick = btLine0Click
        end
      end
    end
    object TabSheet5: TTabSheet
      Caption = #1060#1086#1085
      ImageIndex = 4
      object Label8: TLabel
        Left = 8
        Top = 8
        Width = 57
        Height = 13
        Caption = #1062#1074#1077#1090' '#1092#1086#1085#1072':'
      end
      object btBkColorNot: TButton
        Left = 8
        Top = 24
        Width = 145
        Height = 20
        Caption = #1053#1077#1090' '#1094#1074#1077#1090#1072
        TabOrder = 0
        OnClick = btBkColorNotClick
      end
      object GroupBox8: TGroupBox
        Left = 176
        Top = 8
        Width = 257
        Height = 65
        Caption = ' '#1054#1073#1088#1072#1079#1077#1094' '#1094#1074#1077#1090#1072' '
        TabOrder = 1
        object pbBkColor: TPaintBox
          Left = 8
          Top = 16
          Width = 241
          Height = 40
          Color = clBtnFace
          ParentColor = False
          OnPaint = pbBkColorPaint
        end
      end
    end
  end
end

inherited MDIConnect: TMDIConnect
  Left = 290
  Top = 135
  Width = 451
  Height = 371
  Caption = 'MDIConnect'
  Position = poDefaultSizeOnly
  PixelsPerInch = 96
  TextHeight = 13
  inherited PCNode: TPageControl
    Width = 443
    Height = 303
    ActivePage = tsExtended
    TabIndex = 4
    inherited tsMain: TTabSheet
      object lMetaLinkType: TLabel [2]
        Left = 74
        Top = 124
        Width = 35
        Height = 13
        Caption = #1056#1077#1078#1080#1084
      end
      inherited mnDescription: TEdit
        TabOrder = 5
      end
      object cbMetaLinkType: TComboBox
        Left = 120
        Top = 120
        Width = 201
        Height = 19
        Style = csOwnerDrawFixed
        ItemHeight = 13
        TabOrder = 3
        Items.Strings = (
          #1054#1073#1083#1072#1089#1090#1100' (1) - '#1058#1086#1095#1082#1072' (2)'
          #1058#1086#1095#1082#1072' (1) -'#1058#1086#1095#1082#1072' (2)'
          #1051#1080#1085#1080#1103' (1) - '#1051#1080#1085#1080#1103' (2)'
          #1057#1090#1077#1085#1072'(1) - '#1057#1090#1077#1085#1072'(2)')
      end
    end
    inherited tsAttributes: TTabSheet
      inherited Splitter2: TSplitter
        Width = 435
      end
      inherited Attributes: TPanel
        Width = 435
      end
      inherited TB: TPanel
        Width = 435
        Height = 143
      end
    end
    object tsAngle: TTabSheet
      Caption = 'Angle'
      ImageIndex = 3
      object Angle: TPanel
        Left = 0
        Top = 8
        Width = 329
        Height = 217
        BevelOuter = bvNone
        Caption = 'ANGLE'
        TabOrder = 0
      end
    end
    object tsExtended: TTabSheet
      Caption = 'Additional'
      ImageIndex = 4
      object cbHoleCreated: TCheckBox
        Left = 16
        Top = 88
        Width = 113
        Height = 17
        Caption = 'Aperture-Link'
        TabOrder = 0
      end
      object gblcm: TGroupBox
        Left = 16
        Top = 8
        Width = 409
        Height = 49
        Caption = 'LinkChangeMode'
        TabOrder = 1
        object cblcmX: TComboBox
          Left = 16
          Top = 16
          Width = 89
          Height = 21
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 0
          Text = 'Auto'
          Items.Strings = (
            'Auto'
            'Minus'
            'Zero'
            'Plus')
        end
        object cblcmY: TComboBox
          Left = 160
          Top = 16
          Width = 89
          Height = 21
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 1
          Text = 'Auto'
          Items.Strings = (
            'Auto'
            'Minus'
            'Zero'
            'Plus')
        end
        object cblcmZ: TComboBox
          Left = 304
          Top = 16
          Width = 89
          Height = 21
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 2
          Text = 'Auto'
          Items.Strings = (
            'Auto'
            'Minus'
            'Zero'
            'Plus')
        end
      end
      object cbClient: TCheckBox
        Left = 16
        Top = 112
        Width = 97
        Height = 17
        Caption = 'Target-Link'
        TabOrder = 2
      end
      object GroupBox1: TGroupBox
        Left = 16
        Top = 192
        Width = 409
        Height = 65
        Caption = 'Target'
        TabOrder = 3
        object Label2: TLabel
          Left = 16
          Top = 16
          Width = 31
          Height = 13
          Caption = 'Object'
        end
        object Label3: TLabel
          Left = 248
          Top = 16
          Width = 31
          Height = 13
          Caption = 'Target'
        end
        object cbNormal0: TComboBox
          Left = 16
          Top = 36
          Width = 145
          Height = 21
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 0
          Text = 'Normal vector X'
          Items.Strings = (
            'Normal vector X'
            'Normal vector Y'
            'Normal vector Z')
        end
        object cbNormal1: TComboBox
          Left = 248
          Top = 36
          Width = 145
          Height = 21
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 1
          Text = 'Normal vector X'
          Items.Strings = (
            'Normal vector X'
            'Normal vector Y'
            'Normal vector Z')
        end
      end
      object GroupBox2: TGroupBox
        Left = 328
        Top = 64
        Width = 97
        Height = 129
        Caption = 'Priority'
        TabOrder = 4
        object UpDown1: TUpDown
          Left = 49
          Top = 24
          Width = 15
          Height = 21
          Associate = ePriority
          Min = 0
          Position = 0
          TabOrder = 0
          Wrap = False
        end
        object ePriority: TEdit
          Left = 16
          Top = 24
          Width = 33
          Height = 21
          ReadOnly = True
          TabOrder = 1
          Text = '0'
        end
      end
      object cbControl: TCheckBox
        Left = 16
        Top = 64
        Width = 113
        Height = 17
        Caption = #1057'ontrol'
        TabOrder = 5
      end
      object cbWallLink: TCheckBox
        Left = 16
        Top = 136
        Width = 113
        Height = 17
        Caption = 'Wall link'
        TabOrder = 6
      end
      object rgTransMode: TRadioGroup
        Left = 176
        Top = 64
        Width = 145
        Height = 121
        Caption = 'Transformation mode'
        ItemIndex = 0
        Items.Strings = (
          'Position'
          'Size'
          'Size And Position')
        TabOrder = 7
      end
      object cbRunOnStop: TCheckBox
        Left = 16
        Top = 160
        Width = 121
        Height = 17
        Caption = 'Not snap'
        TabOrder = 8
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Snap'
      ImageIndex = 5
      object EPS: TPanel
        Left = 0
        Top = 48
        Width = 313
        Height = 217
        BevelOuter = bvNone
        Caption = 'EPS'
        TabOrder = 0
      end
    end
    object tsNew: TTabSheet
      Caption = 'Step'
      ImageIndex = 7
      object STEP: TPanel
        Left = 0
        Top = 0
        Width = 435
        Height = 113
        Align = alTop
        BevelOuter = bvNone
        Caption = 'STEP'
        TabOrder = 0
      end
    end
  end
  inherited Panel1: TPanel
    Top = 303
    Width = 443
  end
end

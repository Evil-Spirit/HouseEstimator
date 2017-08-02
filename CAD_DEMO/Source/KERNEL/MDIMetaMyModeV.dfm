inherited MDIMetaMyMode: TMDIMetaMyMode
  Left = 270
  Top = 246
  Caption = 'MDIMetaMyMode'
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  inherited PCNode: TPageControl
    inherited tsMain: TTabSheet
      inherited Label1: TLabel
        Left = 87
      end
      inherited indLabel: TLabel
        Left = 105
      end
      inherited LabelDescription: TLabel
        Left = 45
      end
      inherited lGUID: TLabel
        Left = 89
      end
    end
    object tsMode: TTabSheet
      Caption = 'Mode'
      ImageIndex = 2
      object lCAM: TLabel
        Left = 32
        Top = 24
        Width = 36
        Height = 13
        Caption = 'Camera'
      end
      object cbCAM: TComboBox
        Left = 80
        Top = 20
        Width = 145
        Height = 19
        Style = csOwnerDrawFixed
        ItemHeight = 13
        ItemIndex = 0
        TabOrder = 0
        Text = 'Orthographic'
        Items.Strings = (
          'Orthographic'
          'Perspective')
      end
    end
  end
end

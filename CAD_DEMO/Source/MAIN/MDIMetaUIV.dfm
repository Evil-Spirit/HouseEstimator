inherited MDIMetaUI: TMDIMetaUI
  Left = 297
  Top = 254
  Caption = 'MDIMetaUI'
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  inherited PCNode: TPageControl
    object tsMetaUI: TTabSheet
      Caption = 'Element of interface'
      ImageIndex = 2
      object cbEnabled: TCheckBox
        Left = 24
        Top = 16
        Width = 97
        Height = 17
        Caption = 'Enabled'
        TabOrder = 0
      end
      object cbVisible: TCheckBox
        Left = 24
        Top = 40
        Width = 97
        Height = 17
        Caption = 'Visible'
        TabOrder = 1
      end
    end
  end
end

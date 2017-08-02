inherited MDIBMPSet: TMDIBMPSet
  Caption = 'MDIBMPSet'
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  inherited PCNode: TPageControl
    object tsBMPSet: TTabSheet
      Caption = 'Picture List'
      ImageIndex = 2
      object BMPSet: TPanel
        Left = 0
        Top = 0
        Width = 645
        Height = 273
        Align = alClient
        BevelOuter = bvNone
        Caption = 'BMPSet'
        TabOrder = 0
      end
    end
  end
end

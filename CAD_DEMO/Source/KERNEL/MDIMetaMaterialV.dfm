inherited MDIMetaMaterial: TMDIMetaMaterial
  Left = 362
  Top = 214
  Width = 638
  Height = 322
  Caption = 'MDIMetaMaterial'
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter [0]
    Left = 358
    Top = 0
    Width = 3
    Height = 254
    Cursor = crHSplit
    Align = alRight
  end
  inherited PCNode: TPageControl
    Width = 358
    Height = 254
    inherited tsAttributes: TTabSheet
      inherited Splitter2: TSplitter
        Top = 219
        Width = 350
      end
      inherited Attributes: TPanel
        Width = 350
        Height = 219
      end
      inherited TB: TPanel
        Top = 222
        Width = 350
        Height = 4
      end
    end
    object tsMaterial: TTabSheet
      Caption = 'Material'
      ImageIndex = 2
      object P3: TPanel
        Left = 0
        Top = 0
        Width = 350
        Height = 226
        Align = alClient
        BevelOuter = bvNone
        Constraints.MinHeight = 200
        TabOrder = 0
      end
    end
  end
  inherited Panel1: TPanel
    Top = 254
    Width = 630
  end
  object Panel2: TPanel
    Left = 361
    Top = 0
    Width = 269
    Height = 254
    Align = alRight
    Caption = 'Panel2'
    TabOrder = 2
  end
end

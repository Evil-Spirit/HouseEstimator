inherited MDIDynamicLinkEdit: TMDIDynamicLinkEdit
  Left = 242
  Top = 156
  Width = 508
  Height = 396
  Caption = 'MDIDynamicLinkEdit'
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  inherited PCNode: TPageControl
    Width = 500
    Height = 328
    inherited tsAttributes: TTabSheet
      inherited Splitter2: TSplitter
        Top = 121
        Width = 492
      end
      inherited Attributes: TPanel
        Width = 492
        Height = 121
      end
      inherited TB: TPanel
        Top = 124
        Width = 492
        Height = 176
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Link'
      ImageIndex = 1
      object GroupBox9: TGroupBox
        Left = 8
        Top = 104
        Width = 281
        Height = 65
        Caption = 'Object'
        TabOrder = 0
        object cbeElements: TComboBoxEx
          Left = 8
          Top = 24
          Width = 265
          Height = 22
          ItemsEx.CaseSensitive = False
          ItemsEx.SortType = stNone
          ItemsEx = <>
          StyleEx = []
          ItemHeight = 16
          TabOrder = 0
          Text = 'cbeElements'
          DropDownCount = 8
        end
      end
      object GroupBox10: TGroupBox
        Left = 8
        Top = 32
        Width = 281
        Height = 65
        Caption = 'Link'
        TabOrder = 1
        object cbeLinks: TComboBoxEx
          Left = 8
          Top = 24
          Width = 265
          Height = 22
          ItemsEx.CaseSensitive = False
          ItemsEx.SortType = stNone
          ItemsEx = <>
          StyleEx = []
          ItemHeight = 16
          TabOrder = 0
          Text = 'ComboBoxEx1'
          DropDownCount = 8
        end
      end
      object cbNeeded: TCheckBox
        Left = 16
        Top = 8
        Width = 145
        Height = 17
        Caption = 'Mandatory link'
        TabOrder = 2
      end
    end
  end
  inherited Panel1: TPanel
    Top = 328
    Width = 500
  end
end

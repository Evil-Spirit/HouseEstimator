inherited MDINomenclature: TMDINomenclature
  Left = 318
  Top = 220
  Width = 635
  Height = 402
  Caption = 'MDINomenclature'
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  inherited PCNode: TPageControl
    Width = 627
    Height = 334
    inherited tsMain: TTabSheet
      inherited Label1: TLabel
        Left = 82
      end
      inherited indLabel: TLabel
        Left = 99
      end
      inherited LabelDescription: TLabel
        Left = 39
      end
      object lStrCode: TLabel [3]
        Left = 52
        Top = 156
        Width = 55
        Height = 13
        Caption = 'Code-String'
      end
      inherited lGUID: TLabel
        Left = 83
      end
      inherited eGUID: TEdit
        TabOrder = 5
      end
      object eStrCode: TEdit
        Left = 120
        Top = 152
        Width = 233
        Height = 21
        Ctl3D = True
        ParentCtl3D = False
        TabOrder = 4
      end
    end
    object TabSheet1: TTabSheet [1]
      Caption = 'Nomenclature'
      ImageIndex = 2
      DesignSize = (
        619
        306)
      object GroupBox1: TGroupBox
        Left = 450
        Top = 0
        Width = 169
        Height = 306
        Align = alRight
        TabOrder = 0
        object lPrice: TLabel
          Left = 15
          Top = 12
          Width = 24
          Height = 13
          Caption = 'Price'
        end
        object lWeight: TLabel
          Left = 15
          Top = 80
          Width = 54
          Height = 13
          Caption = 'Weight ('#1082#1075')'
        end
        object Label2: TLabel
          Left = 15
          Top = 188
          Width = 47
          Height = 13
          Caption = 'Meter unit'
        end
        object ePrice: TEdit
          Left = 15
          Top = 32
          Width = 82
          Height = 21
          Ctl3D = True
          ParentCtl3D = False
          TabOrder = 0
        end
        object ComboBoxEx1: TComboBoxEx
          Left = 15
          Top = 208
          Width = 81
          Height = 22
          ItemsEx.CaseSensitive = False
          ItemsEx.SortType = stNone
          ItemsEx = <>
          StyleEx = []
          Ctl3D = True
          ItemHeight = 16
          ParentCtl3D = False
          TabOrder = 1
          DropDownCount = 8
        end
        object eWeight: TEdit
          Left = 15
          Top = 96
          Width = 82
          Height = 21
          Ctl3D = True
          ParentCtl3D = False
          TabOrder = 2
        end
        object ecurPrice: TEdit
          Left = 111
          Top = 32
          Width = 42
          Height = 21
          Ctl3D = True
          ParentCtl3D = False
          ReadOnly = True
          TabOrder = 3
        end
        object ecurWeight: TEdit
          Left = 111
          Top = 96
          Width = 42
          Height = 21
          Ctl3D = True
          ParentCtl3D = False
          ReadOnly = True
          TabOrder = 4
        end
      end
      object GroupBox2: TGroupBox
        Left = 0
        Top = 0
        Width = 442
        Height = 121
        Anchors = [akLeft, akTop, akRight]
        Caption = 'Size and dimensions'
        TabOrder = 1
        object Size: TPanel
          Left = 7
          Top = 16
          Width = 290
          Height = 45
          BevelOuter = bvNone
          Caption = 'Size'
          TabOrder = 0
        end
        object Dimensions: TPanel
          Left = 7
          Top = 60
          Width = 290
          Height = 45
          BevelOuter = bvNone
          Caption = 'Dimensions'
          TabOrder = 1
        end
      end
      object GroupBox3: TGroupBox
        Left = 0
        Top = 127
        Width = 443
        Height = 173
        Anchors = [akLeft, akTop, akRight, akBottom]
        Caption = 'Memo'
        TabOrder = 2
        object mMemo: TMemo
          Left = 2
          Top = 15
          Width = 439
          Height = 156
          Align = alClient
          TabOrder = 0
        end
      end
    end
    inherited tsAttributes: TTabSheet
      inherited Splitter2: TSplitter
        Top = 113
        Width = 619
        Height = 8
      end
      inherited Attributes: TPanel
        Width = 619
        Height = 113
      end
      inherited TB: TPanel
        Top = 121
        Width = 619
        Height = 185
      end
    end
    inherited tsAdvancedSuper: TTabSheet
      object Label4: TLabel [1]
        Left = 8
        Top = 8
        Width = 108
        Height = 13
        Caption = 'Corresponding element'
      end
      inherited Image1: TImage
        Top = 80
        AutoSize = True
        Center = True
      end
      object PME: TPanel
        Left = 8
        Top = 24
        Width = 193
        Height = 33
        BevelOuter = bvNone
        Caption = 'PME'
        TabOrder = 0
      end
    end
  end
  inherited Panel1: TPanel
    Top = 334
    Width = 627
  end
end

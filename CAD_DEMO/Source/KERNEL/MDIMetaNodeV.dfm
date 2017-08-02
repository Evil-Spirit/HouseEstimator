inherited MDIMetaNode: TMDIMetaNode
  Left = 227
  Top = 242
  Width = 661
  Height = 369
  ActiveControl = btOK
  Caption = 'MDIMetaNode'
  OldCreateOrder = True
  Position = poDesigned
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object PCNode: TPageControl
    Left = 0
    Top = 0
    Width = 653
    Height = 301
    ActivePage = tsMain
    Align = alClient
    MultiLine = True
    TabIndex = 0
    TabOrder = 0
    object tsMain: TTabSheet
      Caption = 'Main'
      Constraints.MinHeight = 150
      Constraints.MinWidth = 350
      object Label1: TLabel
        Left = 89
        Top = 91
        Width = 28
        Height = 13
        Caption = 'Name'
      end
      object indLabel: TLabel
        Left = 106
        Top = 28
        Width = 11
        Height = 13
        Caption = 'ID'
      end
      object LabelDescription: TLabel
        Left = 46
        Top = 123
        Width = 71
        Height = 13
        Caption = 'End user name'
      end
      object lGUID: TLabel
        Left = 90
        Top = 60
        Width = 27
        Height = 13
        Caption = 'GUID'
      end
      object mnName: TEdit
        Left = 120
        Top = 88
        Width = 233
        Height = 21
        Ctl3D = True
        ParentCtl3D = False
        TabOrder = 0
      end
      object METAID: TEdit
        Left = 120
        Top = 24
        Width = 113
        Height = 21
        Ctl3D = True
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 1
      end
      object cbeImageSelect: TComboBoxEx
        Left = 240
        Top = 24
        Width = 113
        Height = 22
        ItemsEx.CaseSensitive = False
        ItemsEx.SortType = stNone
        ItemsEx = <>
        StyleEx = []
        Ctl3D = True
        Enabled = False
        ItemHeight = 16
        ParentColor = True
        ParentCtl3D = False
        TabOrder = 2
        Images = ImageLibrary.TreeImages
        DropDownCount = 8
      end
      object mnDescription: TEdit
        Left = 120
        Top = 120
        Width = 233
        Height = 21
        Ctl3D = True
        ParentCtl3D = False
        TabOrder = 3
      end
      object eGUID: TEdit
        Left = 120
        Top = 56
        Width = 233
        Height = 21
        Ctl3D = True
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 4
      end
    end
    object tsAttributes: TTabSheet
      Caption = 'Attributes'
      ImageIndex = 1
      object Splitter2: TSplitter
        Left = 0
        Top = 129
        Width = 645
        Height = 3
        Cursor = crVSplit
        Align = alTop
      end
      object Attributes: TPanel
        Left = 0
        Top = 0
        Width = 645
        Height = 129
        Align = alTop
        BevelOuter = bvNone
        Caption = 'Attributes'
        TabOrder = 0
      end
      object TB: TPanel
        Left = 0
        Top = 132
        Width = 645
        Height = 141
        Align = alClient
        BevelOuter = bvNone
        Caption = 'TB'
        TabOrder = 1
      end
    end
    object tsAdvancedSuper: TTabSheet
      Caption = 'Advanced'
      ImageIndex = 2
      object Bevel1: TBevel
        Left = 8
        Top = 32
        Width = 130
        Height = 130
      end
      object Image1: TImage
        Left = 9
        Top = 33
        Width = 128
        Height = 128
        Proportional = True
        Stretch = True
        OnDblClick = Image2Click
      end
      object Bevel2: TBevel
        Left = 152
        Top = 32
        Width = 34
        Height = 34
      end
      object Image2: TImage
        Left = 153
        Top = 33
        Width = 32
        Height = 32
        Proportional = True
        Stretch = True
        OnDblClick = Image2DblClick
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 301
    Width = 653
    Height = 41
    Align = alBottom
    TabOrder = 1
    object btOK: TButton
      Left = 16
      Top = 8
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 0
      OnClick = btOKClick
    end
    object btCancel: TButton
      Left = 104
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Cancel'
      TabOrder = 1
      OnClick = btCancelClick
    end
  end
end

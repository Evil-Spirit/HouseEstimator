inherited MDIBMPSetEdit: TMDIBMPSetEdit
  Left = 419
  Top = 160
  Caption = 'MDIBMPSetEdit'
  ClientHeight = 196
  ClientWidth = 280
  Constraints.MinHeight = 223
  Constraints.MinWidth = 199
  OldCreateOrder = True
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object ColorBox: TShape [0]
    Left = 240
    Top = 166
    Width = 33
    Height = 21
    Anchors = [akTop, akRight]
    Brush.Color = clTeal
    OnMouseDown = ColorBoxMouseDown
  end
  object Label1: TLabel [1]
    Left = 223
    Top = 140
    Width = 7
    Height = 13
    Anchors = [akTop, akRight]
    Caption = 'Y'
  end
  object lX: TLabel [2]
    Left = 223
    Top = 112
    Width = 7
    Height = 13
    Anchors = [akTop, akRight]
    Caption = 'X'
  end
  object cbTrans: TCheckBox
    Left = 160
    Top = 168
    Width = 74
    Height = 17
    Alignment = taLeftJustify
    Anchors = [akTop, akRight]
    Caption = 'Background'
    TabOrder = 1
  end
  object eX: TEdit
    Left = 240
    Top = 108
    Width = 33
    Height = 21
    Anchors = [akTop, akRight]
    TabOrder = 2
    Text = '0'
    OnChange = eXChange
  end
  object eY: TEdit
    Left = 240
    Top = 136
    Width = 33
    Height = 21
    Anchors = [akTop, akRight]
    TabOrder = 4
    Text = '0'
    OnChange = eXChange
  end
  object LV: TListView
    Left = 0
    Top = 0
    Width = 156
    Height = 196
    Align = alLeft
    Anchors = [akLeft, akTop, akRight, akBottom]
    Columns = <
      item
        AutoSize = True
      end>
    Constraints.MinHeight = 100
    Constraints.MinWidth = 100
    FlatScrollBars = True
    FullDrag = True
    IconOptions.AutoArrange = True
    IconOptions.WrapText = False
    ReadOnly = True
    RowSelect = True
    ParentShowHint = False
    ShowColumnHeaders = False
    ShowHint = False
    SmallImages = IL
    TabOrder = 0
    ViewStyle = vsReport
  end
  object ToolBar1: TToolBar
    Left = 162
    Top = 16
    Width = 79
    Height = 88
    Align = alNone
    Anchors = [akTop, akRight]
    AutoSize = True
    ButtonWidth = 79
    Caption = 'ToolBar1'
    EdgeBorders = []
    Flat = True
    Images = ImageLibrary.ActionImages
    List = True
    ShowCaptions = True
    TabOrder = 3
    object tbtAdd: TToolButton
      Left = 0
      Top = 0
      Caption = 'Add'
      ImageIndex = 0
      Wrap = True
      OnClick = tbtAddClick
    end
    object tbtDel: TToolButton
      Left = 0
      Top = 22
      Caption = 'Delete'
      ImageIndex = 2
      Wrap = True
      OnClick = tbtDelClick
    end
    object tbtUp: TToolButton
      Left = 0
      Top = 44
      Caption = 'Shift Ups'
      ImageIndex = 4
      Wrap = True
      OnClick = tbtUpClick
    end
    object tbtDown: TToolButton
      Left = 0
      Top = 66
      Caption = 'Shift Down'
      ImageIndex = 5
      OnClick = tbtDownClick
    end
  end
  object OpenDialog: TOpenDialog
    DefaultExt = '0'
    Filter = 'Bitmap (*.bmp)|*.bmp'
    Left = 40
    Top = 160
  end
  object IL: TImageList
    Left = 8
    Top = 160
  end
  object ColorDialog: TColorDialog
    Ctl3D = True
    Left = 8
    Top = 128
  end
end

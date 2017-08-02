inherited MDIMetaTexture: TMDIMetaTexture
  Left = 240
  Top = 189
  Width = 758
  Height = 468
  Caption = 'MDIMetaTexture'
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter [0]
    Left = 453
    Top = 0
    Width = 3
    Height = 400
    Cursor = crHSplit
    Align = alRight
  end
  inherited PCNode: TPageControl
    Width = 453
    Height = 400
    inherited tsAttributes: TTabSheet
      inherited Splitter2: TSplitter
        Top = 271
        Width = 445
      end
      inherited Attributes: TPanel
        Width = 445
        Height = 271
      end
      inherited TB: TPanel
        Top = 274
        Width = 445
        Height = 98
      end
    end
    object tsTexture: TTabSheet
      Caption = #1058#1077#1082#1089#1090#1091#1088#1072
      ImageIndex = 2
      object P3: TPanel
        Left = 0
        Top = 71
        Width = 445
        Height = 301
        Align = alBottom
        Anchors = [akLeft, akTop, akRight, akBottom]
        BevelOuter = bvNone
        Constraints.MinHeight = 150
        ParentColor = True
        TabOrder = 0
      end
      object BitBtn1: TBitBtn
        Left = 8
        Top = 8
        Width = 113
        Height = 25
        Caption = 'Select Bitmap'
        TabOrder = 1
        OnClick = BitBtn1Click
      end
      object Button1: TButton
        Left = 8
        Top = 32
        Width = 113
        Height = 25
        Caption = 'Select Bitmap List'
        TabOrder = 2
        OnClick = Button1Click
      end
      object GroupBox1: TGroupBox
        Left = 128
        Top = 0
        Width = 313
        Height = 57
        Caption = 'Real texture size'
        TabOrder = 3
        object Label2: TLabel
          Left = 12
          Top = 27
          Width = 10
          Height = 13
          Caption = 'X:'
        end
        object Label3: TLabel
          Left = 100
          Top = 27
          Width = 11
          Height = 13
          Caption = #1084'.'
        end
        object Label4: TLabel
          Left = 172
          Top = 27
          Width = 10
          Height = 13
          Caption = 'Y:'
        end
        object Label5: TLabel
          Left = 260
          Top = 27
          Width = 11
          Height = 13
          Caption = #1084'.'
        end
        object edRealSizeX: TEdit
          Left = 24
          Top = 24
          Width = 73
          Height = 21
          TabOrder = 0
          Text = '1'
        end
        object edRealSizeY: TEdit
          Left = 184
          Top = 24
          Width = 73
          Height = 21
          TabOrder = 1
          Text = '1'
        end
      end
    end
  end
  inherited Panel1: TPanel
    Top = 400
    Width = 750
  end
  object Panel2: TPanel
    Left = 456
    Top = 0
    Width = 294
    Height = 400
    Align = alRight
    Caption = 'Panel2'
    TabOrder = 2
  end
end

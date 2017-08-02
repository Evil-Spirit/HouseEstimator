object ConverterForm: TConverterForm
  Left = 294
  Top = 197
  Width = 695
  Height = 397
  Caption = 'ConverterForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 153
    Width = 687
    Height = 8
    Cursor = crVSplit
    Align = alTop
  end
  object RichEdit1: TRichEdit
    Left = 0
    Top = 0
    Width = 687
    Height = 153
    Align = alTop
    TabOrder = 0
  end
  object RichEdit2: TRichEdit
    Left = 0
    Top = 161
    Width = 687
    Height = 168
    Align = alClient
    TabOrder = 1
  end
  object Panel1: TPanel
    Left = 0
    Top = 329
    Width = 687
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object Button1: TButton
      Left = 8
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Convert'
      TabOrder = 0
      OnClick = Button1Click
    end
  end
end

object ParamEntering: TParamEntering
  Left = 407
  Top = 301
  BorderStyle = bsDialog
  Caption = 'ParamEntering'
  ClientHeight = 40
  ClientWidth = 268
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lX: TLabel
    Left = 8
    Top = 13
    Width = 10
    Height = 13
    Alignment = taCenter
    Caption = 'X:'
    Layout = tlCenter
  end
  object Label1: TLabel
    Left = 96
    Top = 12
    Width = 10
    Height = 13
    Alignment = taCenter
    Caption = 'Y:'
    Layout = tlCenter
  end
  object E1: TEdit
    Left = 24
    Top = 8
    Width = 65
    Height = 19
    BevelInner = bvNone
    BevelOuter = bvNone
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 0
    Text = '0,00'
  end
  object E2: TEdit
    Left = 112
    Top = 8
    Width = 65
    Height = 19
    BevelInner = bvNone
    BevelOuter = bvNone
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 1
    Text = '0,111'
  end
  object OK: TButton
    Left = 192
    Top = 8
    Width = 71
    Height = 19
    Caption = 'OK'
    Default = True
    TabOrder = 2
    OnClick = sbOKClick
  end
end

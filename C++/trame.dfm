object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 300
  ClientWidth = 617
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Zoom: TLabel
    Left = 40
    Top = 165
    Width = 26
    Height = 13
    Caption = 'Zoom'
  end
  object Deplacement: TLabel
    Left = 400
    Top = 13
    Width = 56
    Height = 13
    Alignment = taCenter
    Caption = 'Mouvement'
  end
  object Droite: TButton
    Left = 481
    Top = 63
    Width = 75
    Height = 25
    Caption = '-->'
    TabOrder = 0
    OnClick = DroiteClick
  end
  object Gauche: TButton
    Left = 319
    Top = 63
    Width = 75
    Height = 25
    Caption = '<--'
    TabOrder = 1
    OnClick = GaucheClick
  end
  object Bas: TButton
    Left = 400
    Top = 94
    Width = 75
    Height = 25
    Caption = 'Bas'
    TabOrder = 2
    OnClick = BasClick
  end
  object Haut: TButton
    Left = 400
    Top = 32
    Width = 75
    Height = 25
    Caption = 'Haut'
    TabOrder = 3
    OnClick = HautClick
  end
  object Mode_automatique: TButton
    Left = 8
    Top = 94
    Width = 113
    Height = 37
    Caption = 'Mode automatique'
    TabOrder = 4
    OnClick = Mode_automatiqueClick
  end
  object ON: TButton
    Left = 8
    Top = 32
    Width = 75
    Height = 25
    Caption = 'ON'
    TabOrder = 5
    OnClick = ONClick
  end
  object OFF: TButton
    Left = 8
    Top = 63
    Width = 75
    Height = 25
    Caption = 'OFF'
    TabOrder = 6
    OnClick = OFFClick
  end
  object Stop: TButton
    Left = 400
    Top = 63
    Width = 75
    Height = 25
    Caption = 'Stop'
    TabOrder = 7
    OnClick = StopClick
  end
  object ZoomPlus: TButton
    Left = 16
    Top = 187
    Width = 75
    Height = 25
    Caption = '+'
    TabOrder = 8
    OnClick = ZoomPlusClick
  end
  object ZoomStop: TButton
    Left = 16
    Top = 249
    Width = 75
    Height = 25
    Caption = 'Stop'
    TabOrder = 9
    OnClick = ZoomStopClick
  end
  object ZoomMoins: TButton
    Left = 16
    Top = 218
    Width = 75
    Height = 25
    Caption = '-'
    TabOrder = 10
    OnClick = ZoomMoinsClick
  end
  object ScrollBar1: TScrollBar
    Left = 387
    Top = 249
    Width = 169
    Height = 25
    Max = 1023
    PageSize = 0
    TabOrder = 11
    OnChange = ScrollBar1Change
  end
  object Memo1: TMemo
    Left = 417
    Top = 200
    Width = 128
    Height = 43
    Lines.Strings = (
      'Valeur entre 0 et 1023')
    TabOrder = 12
  end
end

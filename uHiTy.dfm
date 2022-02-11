object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'Hi Typing !'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  KeyPreview = True
  OnKeyDown = FormKeyDown
  OnKeyPress = FormKeyPress
  OnKeyUp = FormKeyUp
  PixelsPerInch = 96
  TextHeight = 15
  object OutField: TImage
    Left = 0
    Top = 0
    Width = 624
    Height = 137
    Align = alTop
  end
  object btnOptnFile: TButton
    Left = 32
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Optn File'
    TabOrder = 0
    OnClick = btnOptnFileClick
  end
  object Memo: TMemo
    Left = 248
    Top = 240
    Width = 353
    Height = 161
    TabOrder = 1
  end
  object Button1: TButton
    Left = 32
    Top = 376
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 32
    Top = 312
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 3
    OnClick = Button2Click
  end
  object OpenDialog: TOpenDialog
    Left = 56
    Top = 304
  end
end

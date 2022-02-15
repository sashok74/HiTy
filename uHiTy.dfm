object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'Hi Typing !'
  ClientHeight = 441
  ClientWidth = 684
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  KeyPreview = True
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 15
  object OutField: TImage
    Left = 0
    Top = 416
    Width = 684
    Height = 25
    Align = alBottom
  end
  object Label1: TLabel
    Left = 24
    Top = 143
    Width = 22
    Height = 54
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object btnOptnFile: TButton
    Left = 32
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Optn File'
    TabOrder = 0
    TabStop = False
    OnClick = btnOptnFileClick
  end
  object Memo: TMemo
    Left = 304
    Top = 259
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
    TabStop = False
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 32
    Top = 312
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 3
    TabStop = False
    OnClick = Button2Click
  end
  object OpenDialog: TOpenDialog
    Left = 176
    Top = 352
  end
end

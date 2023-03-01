object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 809
  ClientWidth = 1094
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 8
    Width = 913
    Height = 769
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
  end
  object Button1: TButton
    Left = 927
    Top = 8
    Width = 159
    Height = 49
    Caption = #1042#1089#1090#1072#1074#1080#1090#1100' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 927
    Top = 63
    Width = 159
    Height = 21
    ReadOnly = True
    TabOrder = 1
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 790
    Width = 1094
    Height = 19
    Panels = <>
    SimplePanel = True
    ExplicitLeft = 552
    ExplicitTop = 416
    ExplicitWidth = 0
  end
  object Button2: TButton
    Left = 927
    Top = 106
    Width = 159
    Height = 25
    Caption = #1047#1072#1082#1086#1085#1095#1080#1090#1100
    TabOrder = 3
    OnClick = Button2Click
  end
  object FileOpenDialog1: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 544
    Top = 400
  end
end

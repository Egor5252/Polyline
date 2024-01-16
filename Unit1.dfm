object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 653
  ClientWidth = 1085
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 8
    Width = 889
    Height = 621
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 634
    Width = 1085
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object Button1: TButton
    Left = 903
    Top = 8
    Width = 178
    Height = 41
    Caption = #1055#1086#1083#1080#1083#1080#1085#1080#1103
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 903
    Top = 120
    Width = 178
    Height = 41
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 903
    Top = 64
    Width = 178
    Height = 41
    Caption = #1059#1073#1088#1072#1090#1100' '#1091#1082#1072#1079#1072#1090#1077#1083#1080
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 903
    Top = 176
    Width = 178
    Height = 41
    Caption = #1051#1080#1085#1080#1072#1083#1080#1079#1072#1094#1080#1103
    TabOrder = 4
    OnClick = Button4Click
  end
  object Edit1: TEdit
    Left = 936
    Top = 223
    Width = 121
    Height = 21
    TabOrder = 5
    Text = '50'
  end
end

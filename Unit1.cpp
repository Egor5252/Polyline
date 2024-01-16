//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Form1->StatusBar1->SimpleText = "X = " + IntToStr(X) + " Y = " + IntToStr(Y);
}
//---------------------------------------------------------------------------
int i = 0;
void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if(Shift.Contains(ssLeft)){
		if(i%2 == 0){
		Image1->Canvas->Pen->Color = clRed;
		Image1->Canvas->Brush->Color = clRed;
		Image1->Canvas->Ellipse(X-5,Y-5,X+5,Y+5);
		Image1->Canvas->MoveTo(X,Y);
		} else {
		Image1->Canvas->Pen->Color = clBlue;
		Image1->Canvas->Brush->Color = clBlue;
		Image1->Canvas->Ellipse(X-5,Y-5,X+5,Y+5);
		Image1->Canvas->LineTo(X,Y);
		}
        i++;

		d.x = X;
		d.y = Y;
		S.push_back(d);
	}

	if(Shift.Contains(ssRight)){
		Krivaya(S);
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Krivaya(S);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Form1->Image1->Canvas->Brush->Color = clWhite;
	Form1->Image1->Canvas->FillRect(Rect(0, 0, Form1->Image1->Width, Form1->Image1->Height));
    S.clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Form1->Image1->Canvas->Brush->Color = clWhite;
	Form1->Image1->Canvas->FillRect(Rect(0, 0, Form1->Image1->Width, Form1->Image1->Height));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    Form1->Image1->Canvas->Brush->Color = clWhite;
	Form1->Image1->Canvas->FillRect(Rect(0, 0, Form1->Image1->Width, Form1->Image1->Height));
    Krivaya(S);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
	XT = S[0].x; YT = S[0].y;
	Form1->Image1->Canvas->MoveTo(S[0].x,S[0].y);

	for (int ds = 0; ds < 50; ++ds) {
		linial(S,XT,YT,S[2].x,S[2].y);
	};                                          //не работает, c for работало


}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TStatusBar *StatusBar1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TEdit *Edit1;
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
struct Dots{
	int x;
	int y;
};
Dots d;
std::vector<Dots> S;

int factorial(int i)
{
  if (i==0) return 1;
  else return i*factorial(i-1);
}

void Krivaya (std::vector<Dots> S)
{
	float C = 0;
	int m = S.size(), i = 0, h = 0, Xtt = 0, Ytt = 0;
	float Xt = 0, Yt = 0;

	do {
		for(float t = 0; t <= 1; t += 0.001) {
			Xt = (1-t)*(1-t)*(1-t)*S[i].x + 3*(1-t)*(1-t)*t*S[i+1].x +
			3*(1-t)*t*t*(S[i+3].x+(S[i+2].x-S[i+3].x)*2) + t*t*t*S[i+2].x;  // 4 точки

			Yt = (1-t)*(1-t)*(1-t)*S[i].y + 3*(1-t)*(1-t)*t*S[i+1].y +
			3*(1-t)*t*t*(S[i+3].y+(S[i+2].y-S[i+3].y)*2) + t*t*t*S[i+2].y;

			            /*
				if(h >= 0 and h < 12) */
							Form1->Image1->Canvas->Pixels[Xt][Yt] = clBlack;

						/*	h++;
							if(h == 17) h = 0;
			*/
		}

		i += 2;
	} while(i < m - 2);

	h = 0;

  /*	for(float t = 0; t <= 1; t += 0.001) {
		Xt = (1-t)*(1-t)*(1-t)*S[m-2].x + 3*(1-t)*(1-t)*t*S[m-1].x + 3*(1-t)*t*t*(S[1].x+(S[0].x-S[1].x)*2) + t*t*t*S[0].x;  // 4 точки
		Yt = (1-t)*(1-t)*(1-t)*S[m-2].y + 3*(1-t)*(1-t)*t*S[m-1].y + 3*(1-t)*t*t*(S[1].y+(S[0].y-S[1].y)*2) + t*t*t*S[0].y;


			if(h >= 0 and h < 12)
					Form1->Image1->Canvas->Pixels[Xt][Yt] = clBlack;

					h++;
					if(h == 17) h = 0;

	}      */
}
int XT, YT;
void linial (std::vector<Dots> S, const double x1, const double y1, const double x2, const double y2)
{
	//double x1 = S[0].x, y1 = S[0].y;
	//double x2 = S[2].x, y2 = S[2].y;
	const double dx = x2 - x1, dy = y2 - y1;
	double t1, t2;
	double Xt, Yt;
	double f = 0;

	t1 = (-(6*S[0].y*dx - 12*S[1].y*dx + 12*S[2].y*dx - 6*S[3].y*dx -
	6*S[0].x*dy + 12*S[1].x*dy - 12*S[2].x*dy + 6*S[3].x*dy) +
	sqrt(std::pow(6*S[0].y*dx - 12*S[1].y*dx + 12*S[2].y*dx - 6*S[3].y*dx -
	6*S[0].x*dy + 12*S[1].x*dy - 12*S[2].x*dy + 6*S[3].x*dy, 2) -
	4*(-3*S[0].y*dx + 9*S[1].y*dx - 15*S[2].y*dx + 9*S[3].y*dx +
	3*S[0].x*dy - 9*S[1].x*dy + 15*S[2].x*dy - 9*S[3].x*dy)*
	(3*S[1].y*dx - 3*S[0].y*dx - 3*S[1].x*dy + 3*S[0].x*dy)))/
	(2*(-3*S[0].y*dx + 9*S[1].y*dx - 15*S[2].y*dx + 9*S[3].y*dx +
	3*S[0].x*dy - 9*S[1].x*dy + 15*S[2].x*dy - 9*S[3].x*dy));

	t2 = (-(6*S[0].y*dx - 12*S[1].y*dx + 12*S[2].y*dx - 6*S[3].y*dx -
	6*S[0].x*dy + 12*S[1].x*dy - 12*S[2].x*dy + 6*S[3].x*dy) -
	sqrt(std::pow(6*S[0].y*dx - 12*S[1].y*dx + 12*S[2].y*dx - 6*S[3].y*dx -
	6*S[0].x*dy + 12*S[1].x*dy - 12*S[2].x*dy + 6*S[3].x*dy, 2) -
	4*(-3*S[0].y*dx + 9*S[1].y*dx - 15*S[2].y*dx + 9*S[3].y*dx +
	3*S[0].x*dy - 9*S[1].x*dy + 15*S[2].x*dy - 9*S[3].x*dy)*
	(3*S[1].y*dx - 3*S[0].y*dx - 3*S[1].x*dy + 3*S[0].x*dy)))/
	(2*(-3*S[0].y*dx + 9*S[1].y*dx - 15*S[2].y*dx + 9*S[3].y*dx +
	3*S[0].x*dy - 9*S[1].x*dy + 15*S[2].x*dy - 9*S[3].x*dy));

	 if (t1 < 1 && t1 > 0 && t2 < 1 && t2 > 0) {
		if (t1 <= t2) {

			Xt = (1-t1)*(1-t1)*(1-t1)*S[0].x + 3*(1-t1)*(1-t1)*t1*S[1].x
			+ 3*(1-t1)*t1*t1*(S[3].x+(S[2].x-S[3].x)*2) + t1*t1*t1*S[2].x;

			Yt = (1-t1)*(1-t1)*(1-t1)*S[0].y + 3*(1-t1)*(1-t1)*t1*S[1].y
			+ 3*(1-t1)*t1*t1*(S[3].y+(S[2].y-S[3].y)*2) + t1*t1*t1*S[2].y;

			//Form1->Image1->Canvas->Pen->Color = clBlue;
			//Form1->Image1->Canvas->Brush->Color = clBlue;
			//Form1->Image1->Canvas->Ellipse(Xt-5,Yt-5,Xt+5,Yt+5);

			//Form1->Memo1->Text = FloatToStr(t1);

		}

		if (t2 < t1) {
			Xt = (1-t2)*(1-t2)*(1-t2)*S[0].x + 3*(1-t2)*(1-t2)*t2*S[1].x
			+ 3*(1-t2)*t2*t2*(S[3].x+(S[2].x-S[3].x)*2) + t2*t2*t2*S[2].x;

			Yt = (1-t2)*(1-t2)*(1-t2)*S[0].y + 3*(1-t2)*(1-t2)*t2*S[1].y
			+ 3*(1-t2)*t2*t2*(S[3].y+(S[2].y-S[3].y)*2) + t2*t2*t2*S[2].y;

			//Form1->Image1->Canvas->Pen->Color = clBlue;
			//Form1->Image1->Canvas->Brush->Color = clBlue;
			//Form1->Image1->Canvas->Ellipse(Xt-5,Yt-5,Xt+5,Yt+5);

			//Form1->Memo1->Text = FloatToStr(t2);
		}

	 } else if (t1 < 0 || t1 > 1) {

		Xt = (1-t2)*(1-t2)*(1-t2)*S[0].x + 3*(1-t2)*(1-t2)*t2*S[1].x
		+ 3*(1-t2)*t2*t2*(S[3].x+(S[2].x-S[3].x)*2) + t2*t2*t2*S[2].x;

		Yt = (1-t2)*(1-t2)*(1-t2)*S[0].y + 3*(1-t2)*(1-t2)*t2*S[1].y
		+ 3*(1-t2)*t2*t2*(S[3].y+(S[2].y-S[3].y)*2) + t2*t2*t2*S[2].y;

		//Form1->Image1->Canvas->Pen->Color = clBlue;
		//Form1->Image1->Canvas->Brush->Color = clBlue;
		//Form1->Image1->Canvas->Ellipse(Xt-5,Yt-5,Xt+5,Yt+5);

		//Form1->Memo1->Text = FloatToStr(t2);

	 } else if (t2 < 0 || t2 > 1) {

		Xt = (1-t1)*(1-t1)*(1-t1)*S[0].x + 3*(1-t1)*(1-t1)*t1*S[1].x
		+ 3*(1-t1)*t1*t1*(S[3].x+(S[2].x-S[3].x)*2) + t1*t1*t1*S[2].x;

		Yt = (1-t1)*(1-t1)*(1-t1)*S[0].y + 3*(1-t1)*(1-t1)*t1*S[1].y
		+ 3*(1-t1)*t1*t1*(S[3].y+(S[2].y-S[3].y)*2) + t1*t1*t1*S[2].y;

		//Form1->Image1->Canvas->Pen->Color = clBlue;
		//Form1->Image1->Canvas->Brush->Color = clBlue;
		//Form1->Image1->Canvas->Ellipse(Xt-5,Yt-5,Xt+5,Yt+5);

		//Form1->Memo1->Text = FloatToStr(t1);

	 }

	 f = (abs((y2-y1)*Xt + (x1-x2)*Yt + (y1-y2)*x1 + (x2-x1)*y1))/
	 sqrt(std::pow((y2-y1),2) + std::pow((x1-x2),2));

	 //Form1->Memo1->Lines->Add(FloatToStr(f));



	 if (f > StrToFloat(Form1->Edit1->Text)) {
		linial(S,x1,y1,Xt,Yt);
	 } else {
		//Form1->Image1->Canvas->Pen->Color = clBlue;
		//Form1->Image1->Canvas->Brush->Color = clBlue;
		//Form1->Image1->Canvas->Ellipse(Xt-5,Yt-5,Xt+5,Yt+5);
		Form1->Image1->Canvas->LineTo(Xt,Yt);
		XT = Xt; YT = Yt;
	 }

}

#endif
/**/

	/*t1 = (-(6*y1*dx - 12*S[1].y*dx + 12*y2*dx - 6*S[3].y*dx -
	6*x1*dy + 12*S[1].x*dy - 12*x2*dy + 6*S[3].x*dy) +
	sqrt(std::pow(6*y1*dx - 12*S[1].y*dx + 12*y2*dx - 6*S[3].y*dx -
	6*x1*dy + 12*S[1].x*dy - 12*x2*dy + 6*S[3].x*dy, 2) -
	4*(-3*y1*dx + 9*S[1].y*dx - 15*y2*dx + 9*S[3].y*dx +
	3*x1*dy - 9*S[1].x*dy + 15*x2*dy - 9*S[3].x*dy)*
	(3*S[1].y*dx - 3*y1*dx - 3*S[1].x*dy + 3*x1*dy)))/
	(2*(-3*y1*dx + 9*S[1].y*dx - 15*y2*dx + 9*S[3].y*dx +
	3*x1*dy - 9*S[1].x*dy + 15*x2*dy - 9*S[3].x*dy));

	t2 = (-(6*y1*dx - 12*S[1].y*dx + 12*y2*dx - 6*S[3].y*dx -
	6*x1*dy + 12*S[1].x*dy - 12*x2*dy + 6*S[3].x*dy) -
	sqrt(std::pow(6*y1*dx - 12*S[1].y*dx + 12*y2*dx - 6*S[3].y*dx -
	6*x1*dy + 12*S[1].x*dy - 12*x2*dy + 6*S[3].x*dy, 2) -
	4*(-3*y1*dx + 9*S[1].y*dx - 15*y2*dx + 9*S[3].y*dx +
	3*x1*dy - 9*S[1].x*dy + 15*x2*dy - 9*S[3].x*dy)*
	(3*S[1].y*dx - 3*y1*dx - 3*S[1].x*dy + 3*x1*dy)))/
	(2*(-3*y1*dx + 9*S[1].y*dx - 15*y2*dx + 9*S[3].y*dx +
	3*x1*dy - 9*S[1].x*dy + 15*x2*dy - 9*S[3].x*dy));*/

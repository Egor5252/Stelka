//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <vector>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Graphics::TBitmap*  GG = new Graphics::TBitmap,*GGbuffer = new Graphics::TBitmap;
bool d=0;
int x2=0,y2=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(Form1->FileOpenDialog1->Execute()) {
		GG->LoadFromFile(FileOpenDialog1->FileName);
		Image1->Canvas->Draw(0,0,GG);
		GGbuffer->Assign(GG);
		DoubleBuffered=1;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
    Form1->StatusBar1->SimpleText = "X = " + IntToStr(X) + "   Y = " + IntToStr(Y);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	dot A;
	A.x = X; A.y = Y;
	Dots.push_back(A);

    Form1->Image1->Canvas->Ellipse(X+5,Y+5,X-5,Y-5);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Form1->Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);

	Form1->Image1->Canvas->MoveTo(Dots[0].x, Dots[0].y);

	for(int i = 1; i < Dots.size(); ++i) {
		Form1->Image1->Canvas->LineTo(Dots[i].x,Dots[i].y);
	}

	Form1->Image1->Canvas->LineTo(Dots[0].x,Dots[0].y);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Form1->Image1->Canvas->Ellipse(0,0,0,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	GG->Height=GG->Height-GG->Height/50;
	GG->Width=GG->Width-GG->Width/50;
	GG->Canvas->StretchDraw(GG->Canvas->ClipRect,GGbuffer);
	Image1->Canvas->FillRect(Image1->Canvas->ClipRect);
	Image1->Canvas->Draw(x2,y2,GG);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	GG->Height=GG->Height+GG->Height/50;
	GG->Width=GG->Width+GG->Width/50;
	GG->Canvas->StretchDraw(GG->Canvas->ClipRect,GGbuffer);
	Image1->Canvas->FillRect(Image1->Canvas->ClipRect);
	Image1->Canvas->Draw(x2,y2,GG);
}
//---------------------------------------------------------------------------


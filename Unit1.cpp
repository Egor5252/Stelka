//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <vector>
#include <jpeg.hpp>
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Graphics::TBitmap* GG = new Graphics::TBitmap,*GGbuffer = new Graphics::TBitmap;
bool d = 0;
int x2 = 0,y2 = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(Form1->FileSaveDialog1->Execute()) {
		GG->LoadFromFile(FileSaveDialog1->FileName);
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

	if(d)
	{
		x2=X;
		y2=Y;
		Image1->Canvas->FillRect(Image1->Canvas->ClipRect);
		Image1->Canvas->Draw(x2,y2,GG);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if(Button == mbLeft){
		dot A;
		A.x = X; A.y = Y;
		Dots.push_back(A);
		Form1->Image1->Canvas->Ellipse(X+5,Y+5,X-5,Y-5);
	}

	if( Button == mbMiddle){
		d=1;
	}
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



void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if( Button == mbMiddle){
		d=0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
	GG->Height=GG->Height-GG->Height/50;
	GG->Width=GG->Width-GG->Width/50;
	GG->Canvas->StretchDraw(GG->Canvas->ClipRect,GGbuffer);
	Image1->Canvas->FillRect(Image1->Canvas->ClipRect);
	Image1->Canvas->Draw(x2,y2,GG);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
	GG->Height=GG->Height+GG->Height/50;
	GG->Width=GG->Width+GG->Width/50;
	GG->Canvas->StretchDraw(GG->Canvas->ClipRect,GGbuffer);
	Image1->Canvas->FillRect(Image1->Canvas->ClipRect);
	Image1->Canvas->Draw(x2,y2,GG);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if(Form1->FileSaveDialog1->Execute()) {
		std::ofstream Data_of_dots(Form1->FileSaveDialog1->FileName.w_str(), std::ios::binary);
		int size_of_vector = Dots.size();
		Data_of_dots.write((char*)&size_of_vector,sizeof(int));
		for(int i = 0; i < size_of_vector; ++i) {
			dot timed_dot = Dots[i];
			Data_of_dots.write((char*)&timed_dot,sizeof(dot));
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	if(Form1->FileSaveDialog1->Execute()) {
		std::ifstream Data_of_dots(Form1->FileSaveDialog1->FileName.w_str(), std::ios::binary);
		int size_of_vector;
		Dots.clear();
		Data_of_dots.read((char*)&size_of_vector,sizeof(int));
		Edit1->Text = IntToStr(size_of_vector);
		for(int i = 0; i < size_of_vector; ++i) {
			dot timed_dot;
			Data_of_dots.read((char*)&timed_dot,sizeof(dot));
			Dots.push_back(timed_dot);
		}

		Form1->Button2->Click();
	}
}
//---------------------------------------------------------------------------


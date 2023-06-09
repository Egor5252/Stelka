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
bool d = 0, p = 0;
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

        Dots.clear();
		Vertical.clear();
		Pychki.clear();
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

	if(p)
	{
		if(Form1->RadioGroup1->ItemIndex == 1) {
		Form1->Image1->Canvas->Pen->Color = clBlack;
			dot A;
			A.x = X; A.y = Y;
			Dots.push_back(A);
			Form1->Image1->Canvas->Ellipse(X+5,Y+5,X-5,Y-5);
			count_of_dots++;
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if(Button == mbLeft){

		if(Form1->RadioGroup1->ItemIndex == 0) {
			Form1->Image1->Canvas->Pen->Color = clBlue;
			dot A;
			A.x = X; A.y = Y;
			Vertical.push_back(A);
			Form1->Image1->Canvas->Ellipse(X+5,Y+5,X-5,Y-5);
			count_of_dots++;
			if(count_of_dots == 2) Form1->RadioGroup1->ItemIndex++;
		}
	}

	if( Button == mbMiddle){
		d=1;
	}

	if( Button == mbLeft){
		p=1;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	dot zero_point;
	zero_point.x = Vertical[1].x;
	zero_point.y = Vertical[1].y;

	Vertical[1].x -= zero_point.x;
	Vertical[1].y -= zero_point.y;

	Vertical[0].x -= zero_point.x;
	Vertical[0].y -= zero_point.y;

	for(int i = 0; i < Dots.size(); ++i)
	{
		Dots[i].x -= zero_point.x;
		Dots[i].y -= zero_point.y;
	}

	double dlina = sqrt(pow(Vertical[0].x - Vertical[1].x, 2) + pow(Vertical[0].y - Vertical[1].y, 2));
	double MSin = (Vertical[0].x) / dlina;
	double MCos = (Vertical[0].y) / dlina;

	coefficient = dlina / StrToInt(Form1->LabeledEdit1->Text);

	 for(int i = 0; i < Dots.size(); ++i)
	{
		double timed_1 = MCos * Dots[i].x - MSin * Dots[i].y;
		double timed_2 = MSin * Dots[i].x + MCos * Dots[i].y;

		Dots[i].x = timed_1;
		Dots[i].y = timed_2;
	}

	double timed1 = MCos * Vertical[0].x - MSin * Vertical[0].y;
	double timed2 = MSin * Vertical[0].x + MCos * Vertical[0].y;
	Vertical[0].x = timed1;
	Vertical[0].y = timed2;

	Vertical[1].x += zero_point.x;
	Vertical[1].y += zero_point.y;

	Vertical[0].x += zero_point.x;
	Vertical[0].y += zero_point.y;

	for(int i = 0; i < Dots.size(); ++i)
	{
		Dots[i].x += zero_point.x;
		Dots[i].y += zero_point.y;
	}

	Form1->Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);

	Form1->Image1->Canvas->Ellipse(Vertical[0].x+5,Vertical[0].y+5,Vertical[0].x-5,Vertical[0].y-5);
	Form1->Image1->Canvas->Ellipse(Vertical[1].x+5,Vertical[1].y+5,Vertical[1].x-5,Vertical[1].y-5);
	Form1->Image1->Canvas->MoveTo(Vertical[0].x, Vertical[0].y);
	Form1->Image1->Canvas->LineTo(Vertical[1].x, Vertical[1].y);

	Form1->Image1->Canvas->MoveTo(Dots[0].x, Dots[0].y);

	for(int i = 1; i < Dots.size(); ++i)
	{
		Form1->Image1->Canvas->LineTo(Dots[i].x,Dots[i].y);
	}

	Form1->Image1->Canvas->LineTo(Dots[0].x,Dots[0].y);

	//�����

	double y_for_puchki = Vertical[0].y - dlina * 0.68;
	double x_for_puchki = Vertical[0].x;

	for (int i = 0; i < 2; ++i)
	{
		dot temporary;
		temporary.x = x_for_puchki;
		temporary.y = y_for_puchki;
		Pychki.push_back(temporary);
	}

	Pychki[0].x--;
	while (Form1->Image1->Canvas->Pixels[Pychki[0].x][Pychki[0].y] != clBlack)
	{
		Form1->Image1->Canvas->Pixels[Pychki[0].x][Pychki[0].y] = clBlack;
		Pychki[0].x--;
	}
	Pychki[0].x--;

	Pychki[1].x++;
	while (Form1->Image1->Canvas->Pixels[Pychki[1].x][Pychki[1].y] != clBlack)
	{
		Form1->Image1->Canvas->Pixels[Pychki[1].x][Pychki[1].y] = clBlack;
		Pychki[1].x++;
	}
	Pychki[1].x++;

	Form1->Image1->Canvas->Ellipse(Pychki[0].x+5,Pychki[0].y+5,Pychki[0].x-5,Pychki[0].y-5);
	Form1->Image1->Canvas->Ellipse(Pychki[1].x+5,Pychki[1].y+5,Pychki[1].x-5,Pychki[1].y-5);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Form1->Image1->Canvas->Ellipse(0,0,0,0);
	count_of_dots = 0;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if( Button == mbMiddle){
		d=0;
	}

	if( Button == mbLeft){
		p=0;
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

		Data_of_dots.write((char*)&coefficient,sizeof(int));

		polnota = StrToInt(Form1->LabeledEdit2->Text);
		Data_of_dots.write((char*)&polnota,sizeof(int));

		razmer = StrToInt(Form1->LabeledEdit3->Text);
		Data_of_dots.write((char*)&razmer,sizeof(int));

		int size_of_vector = Vertical.size();
		Data_of_dots.write((char*)&size_of_vector,sizeof(int));
		for(int i = 0; i < size_of_vector; ++i) {
			dot timed_dot = Vertical[i];
			Data_of_dots.write((char*)&timed_dot,sizeof(dot));
		}

		size_of_vector = Dots.size();
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
	if(Form1->FileOpenDialog1->Execute()) {
		std::ifstream Data_of_dots(Form1->FileOpenDialog1->FileName.w_str(), std::ios::binary);
		int size_of_vector;
		Dots.clear();
		Vertical.clear();
		Pychki.clear();

		Data_of_dots.read((char*)&size_of_vector,sizeof(int));
		for(int i = 0; i < size_of_vector; ++i) {
			dot timed_dot;
			Data_of_dots.read((char*)&timed_dot,sizeof(dot));
			Vertical.push_back(timed_dot);
		}

        Data_of_dots.read((char*)&size_of_vector,sizeof(int));
		for(int i = 0; i < size_of_vector; ++i) {
			dot timed_dot;
			Data_of_dots.read((char*)&timed_dot,sizeof(dot));
			Dots.push_back(timed_dot);
		}

		Form1->Button2->Click();
	}
}
//---------------------------------------------------------------------------



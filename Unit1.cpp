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

//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(Form1->FileOpenDialog1->Execute()) {
		Form1->Edit1->Text = Form1->FileOpenDialog1->FileName;
	}

   	Form1->Image1->Picture->LoadFromFile(Edit1->Text);
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
	V.push_back(A);

    Form1->Image1->Canvas->Ellipse(X+5,Y+5,X-5,Y-5);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Form1->Image1->Canvas->MoveTo(V[0].x, V[0].y);

	for(int i = 1; i < V.size(); ++i) {
		Form1->Image1->Canvas->LineTo(V[i].x,V[i].y);
	}
    Form1->Image1->Canvas->LineTo(V[0].x,V[0].y);

}
//---------------------------------------------------------------------------


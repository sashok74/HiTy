//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uHiTy.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
  Stor = std::make_shared<TStor> ();
  Can = OutField->Canvas;
  Disp = std::make_shared<TDisplayText> (Can);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnOptnFileClick(TObject *Sender)
{
   char w[150];
   int pos = 0;
   int i = 0;
   char s[10000];
   term = {',', ' ', ':', '/' , '\\' , '.', '=', '{', '}', '\'', '"', '>', '<', '(', ')', '+', '&' , '%', ';' ,'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9', '_', '-', '#', '"'};

   if (OpenDialog->Execute())
   {
	  file.open(OpenDialog->FileName.c_str(), std::fstream::in|std::fstream::out);
	  if (file.is_open())
	  {
		 file.seekg (0, std::fstream::beg);
		 while (!file.eof())
		 {
			file.getline(s,10000);
			pos = 0;
			i= 0;

			//if(s[pos] == ' ') pos++;
			while (s[pos] != '\0' && pos < 1000)
			{
				if (term.find(s[pos]) == term.end())
				{
				  w[i++] = s[pos];
				}
				else
				{
				   if (i > 0)
				   {
					 w[i] = '\0';
					 m[String(w)] = m[String(w)] + 1;
					 i = 0;
				   }
				}
                pos++;
			}
			if (i > 0)
			{
			   w[i] = '\0';
			   m[String(w)] = m[String(w)] + 1;
			   i = 0;
			}
		 }
	  }
	  file.clear();
   }
}

void TfrmMain::print_map(const std::map<String, int>& m)
{
	// iterate using C++17 facilities
	for (const auto& [key, value] : m) {
		Memo->Lines->Add(key + " " + value);
	}
	std::cout << '\n';
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
  print_map(m);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Button2Click(TObject *Sender)
{
  Stor->ClearWords();
  Stor->AddWord("слово");
  Stor->AddSpace();
  Stor->AddWord("дело");
  Stor->AddSpace();
  Stor->AddWord("тест");
  //PrintText ();
  Disp->Start(Stor);
}
//---------------------------------------------------------------------------

void TfrmMain::PrintText ()
{
  String text = "";
  int x = 10;
  Can->Font->Size  = 30;
  String w;
  int pos;
  bool space = false;
  //Can->FillRect(Can->ClipRect);

  for (int i = 0; i < Stor->GetWordCount() ; i++) {
	  w = Stor->GetWord(i)->GetText();
	  pos = Stor->GetWord(i)->GetPos() ;
	  switch (Stor->GetWord(i)->GetStatus()) {
		case wsPrinted :
			 PrintWord (space, clGray, w, x); break;
		case wsReady :
			 PrintWord (space, clBlack, w, x); break;
		case wsPrinting :
			 PrintWord (space, clTeal,  w.SubString(1,pos - 1), x);
			 PrintWord (false, clBlack, w.SubString(pos,1), x);
			 PrintWord (false, clTeal,  w.SubString(pos + 1, w.Length() - pos), x);
			 break;
		case wsError :
			 PrintWord (space, clTeal,  w.SubString(1,pos - 1), x);
			 PrintWord (false, clRed,   w.SubString(pos,1), x);
			 PrintWord (false, clTeal,  w.SubString(pos + 1, w.Length() - pos), x);
			 break;
	  default:
            PrintWord (space, clBlack, w, x); break;
		  ;
	  }
      space = true;
  }

}

void TfrmMain::PrintWord (bool space, TColor Color, const String w, int &x)
{
   if (space) {
	 Can->TextOut(x,10," ");
	 x += Can->TextWidth(" ");
   }
   Can->Font->Color = Color;
   Can->TextOut(x,10, w);
   x += Can->TextWidth(w);
}

void __fastcall TfrmMain::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	int a = 1;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
  int i = Stor->TypeChar (WideChar(Key));
  PrintText ();
  Label1->Caption = IntToStr(i);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	int a = 1;
}
//---------------------------------------------------------------------------

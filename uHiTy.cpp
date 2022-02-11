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
  Can = OutField->Canvas;
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
  TRect Rect = OutField->ClientRect;
  Can->Font->Height = 25;
  Can->Font->Color = clBlack;
  Can->TextRect(Rect, 10,10, "������ �����");
  int shift = Can->TextWidth("������ ����� ");
  text = "";

  Stor.AddWord("�����");
  Stor.AddWord("����");
  Stor.AddWord("����");
  TWord w;
  int x = 0;

  for (int i = 0; i < Stor.GetWordCount() ; i++) {
	w = Stor.GetWord(i);
	Can->TextOut(x,10, w.GetText());
	x += Can->TextWidth(w.GetText() + " ");
  }

}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	int a = 1;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
  text = text + WideChar(Key);
  Can->TextOut(10,10, text);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	int a = 1;
}
//---------------------------------------------------------------------------

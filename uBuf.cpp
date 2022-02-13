//---------------------------------------------------------------------------

#pragma hdrstop

#include "uBuf.h"

/*
	int StartInd;
	int NextInd;
	TFont CurFont;
	TCanvas* Can;
	std::shared_ptr<TStor> Stor;
	std::map<int,TWordInfo> Words;
*/

void TDisplayText::DisplayBuf() {
  bool stop = false;
  int x = 10;
  Can->Font->Size  = 30;
  String w;
  int pos;
  bool space = false;


  for (int i = StartInd; i < Stor->GetWordCount() ; i++) {
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
};

void TDisplayText::PrintWord (bool space, TColor Color, const String w, int &x)
{
   if (space) {
	 Can->TextOut(x,10," ");
	 x += Can->TextWidth(" ");
   }
   Can->Font->Color = Color;
   Can->TextOut(x,10, w);
   x += Can->TextWidth(w);
}

//---------------------------------------------------------------------------
#pragma package(smart_init)

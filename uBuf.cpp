//---------------------------------------------------------------------------

#pragma hdrstop

#include "uBuf.h"


void TWordInfo::DisplayWord() {
  TCanvas* Can = Disp->GetCanvas();
  TColor saveColor = Can->Font->Color;
  Can->Font->Color = Color;
  Can->TextOut(Left, Top, w);
  Can->Font->Color = saveColor;
}

int TWordInfo::GetWidth() {
  return Disp->GetCanvas()->TextWidth(w);
}

void TDisplayText::AddBuf(String newWord){

}

void TDisplayText::LoadBuf() {
  bool stop = false;
  int x = 10;
  int y = 10;
  Can->Font->Size = 30;
  String w;
  int pos;
  bool space = false;
  Words.clear();
  int ind = 0;
  int TexWidth = 0;

  for (int i = StartInd; i < Stor->GetWordCount() ; i++) {
	  w   = Stor->GetWord(i)->GetText();
	  pos = Stor->GetWord(i)->GetPos() ;

	  Words[ind] = new TWordInfo(this, w);
	  TexWidth = Words[ind]->GetWidth();
	  /* проверка вмещается ли.. */
	  Words[ind]->SetPos(x, y);
	  Words[ind]->DisplayWord();
	  x += TexWidth;

	  ind++;


  }
};


//---------------------------------------------------------------------------
#pragma package(smart_init)

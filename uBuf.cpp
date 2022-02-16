//---------------------------------------------------------------------------

#pragma hdrstop

#include "uBuf.h"
#include "uTxtStor.h"


void TWordInfo::DisplayWord() {
  TCanvas* Can = Disp->GetCanvas();
  TColor saveColor = Can->Font->Color;
  Can->Font->Color = Color;
  Can->TextOut(Left, Top, w);
  Can->Font->Color = saveColor;
}

void TWordInfo::SetIdetntPos( int i) {
  int PrenIdentPos = IdentPos == 0 ? 1:IdentPos;
  IdentPos = i;
  String wb = w.SubString(1,IdentPos-1);
  String wi = w.SubString(IdentPos,1);
  TCanvas* Can = Disp->GetCanvas();
  TColor saveColor = Can->Font->Color;
  Can->Font->Color = Color;
  Can->TextOut(Left, Top, wb);
  Can->Font->Color = clRed;
  Can->TextOut(Left + Can->TextWidth(wb), Top, wi);
  Can->Font->Color = saveColor;

};


int TWordInfo::GetWidth() {
  return Disp->GetCanvas()->TextWidth(w);
}

void TDisplayText::AddBuf(String newWord){

}

void TDisplayText::LoadBuf() {
  bool stop = false;
  int x = 10;
  int y = 10;
  int l = 0;
  Can->Font->Size = 30;
  int LineHeigth = Can->TextHeight("T");;
  String w;
  bool space = false;
  Words.clear();
  int ind = 0;
  int TexWidth = 0;

  Can->FillRect(Can->ClipRect);
  for (int i = StartInd; i < Stor->GetWordCount() ; i++) {
	  using std::placeholders::_1;
	  w   = Stor->GetWord(i)->GetText();
	  Words[ind] = new TWordInfo(this, w);
	  TexWidth = Words[ind]->GetWidth();
	  /* проверка вмещается ли.. */
	  if ( (x + TexWidth) > FildWidth()) {
		x = 10;
		l++;
		y += LineHeigth + 10;
	  }
	  Words[ind]->SetPos(x, y, l);
	  /* добавит Колбэк для каждого слово происходит на печать символа */
	  Stor->GetWord(i)->AddCallback(std::bind(&TWordInfo::SetIdetntPos, Words[ind], _1));
	  Words[ind]->DisplayWord();
	  x += TexWidth;
	  ind++;
  }
};

//Foo::someCallbackName callBack = std::bind(&Bar::someOtherFunction, &bar, std::placeholders::_1);

//---------------------------------------------------------------------------
#pragma package(smart_init)

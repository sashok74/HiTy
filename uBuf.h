//---------------------------------------------------------------------------

#ifndef uBufH
#define uBufH

#include <Vcl.Graphics.hpp>
#include <memory>
#include <map>
#include "uTxtStor.h"

#define NO_UDENT -1
class TDisplayText;
typedef std::shared_ptr<TDisplayText> PDisplayText;

class TWordInfo {
 private:
	String w;
	int Line;
	int Left;
	TColor Color;
	int IdentPos;
	PDisplayText Disp;
	void ShowWord();
  public:
	  TWordInfo(PDisplayText pDisp) : Disp{pDisp}, w{' '}, Line{0}, Left{0}, Color{clBlack}, IdentPos{NO_UDENT}
		   {ShowWord()} ;
	  void Init(const String newWord);
	  void SetColor (TColor newColor);
	  void SetIdentPos (int newPos) {
		IdentPos = (newPos > 0 && newPos < w.Length() ? newPos : NO_UDENT);
	  };
};

class TDisplayText {
  private:
	int curX;
	int curY;
	int curLine;
	int StartInd;
	int NextInd;
//	TFont CurFont;
	TCanvas* Can;
	std::shared_ptr<TStor> Stor;
	std::map<int,TWordInfo> Words;
	void DisplayBuf();
	void PrintWord (bool space, TColor Color, const String w, int &x);
	void AddBuf();
  public:
	TDisplayText (TCanvas* Canvas) : Can{Canvas}, StartInd{0}, NextInd{0} curX{10} cueY{10}, curLine{0};
	void Start (std::shared_ptr<TStor> newStor) {Stor = newStor; DisplayBuf();};
};


//---------------------------------------------------------------------------
#endif

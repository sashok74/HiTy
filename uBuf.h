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
	int Top;
	TColor Color;
	int IdentPos;
	TDisplayText *Disp;
  public:
	  TWordInfo(TDisplayText* pDisp, String newW = ' ') : Disp{pDisp}, w{newW}, Line{0}, Left{0}, Top{0}, Color{clBlack}, IdentPos{NO_UDENT}
		   {};
	  void SetText(const String newWord);
	  void SetColor (TColor newColor);
	  void SetIdentPos (int newPos) {
		IdentPos = (newPos > 0 && newPos < w.Length() ? newPos : NO_UDENT);
	  };
	  int GetWidth();
	  void DisplayWord();
	  void SetPos (const int X, const int Y, const int newLine) {Left = X; Top = Y; Line = newLine;};
};
typedef std::shared_ptr<TWordInfo> PWordInfo;


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
	std::map<int,TWordInfo*> Words;
	void LoadBuf();
	void AddBuf(String newWord);
   public:
	TDisplayText (TCanvas* Canvas) : Can{Canvas}, StartInd{0}, NextInd{0}, curX{10}, curY{10}, curLine{0} {};
	void Start (std::shared_ptr<TStor> newStor) {Stor = newStor; LoadBuf();};
	TCanvas* GetCanvas() {return Can;};
	int FildWidth () { return Can->ClipRect.Width(); };
	int FildHeight () { return Can->ClipRect.Height(); };
};


//---------------------------------------------------------------------------
#endif

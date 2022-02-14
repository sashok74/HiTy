//---------------------------------------------------------------------------

#ifndef uHiTyH
#define uHiTyH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include <set>

#include "uTxtStor.h"
#include "uBuf.h"

//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TButton *btnOptnFile;
	TOpenDialog *OpenDialog;
	TMemo *Memo;
	TButton *Button1;
	TButton *Button2;
	TImage *OutField;
	TLabel *Label1;
	void __fastcall btnOptnFileClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
  std::fstream file;
  char str[1000];
  std::map<String, int> m;
  void print_map(const std::map<String, int>& m);
  std::set<char> term;
  TCanvas *Can;
  std::shared_ptr<TStor> Stor;
  std::shared_ptr<TDisplayText> Disp;
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif

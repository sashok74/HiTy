//---------------------------------------------------------------------------

#ifndef uTxtStorH
#define uTxtStorH
#include <map>
#include <set>

#define TAB  '-tab-'
#define VK '-vk-'

enum TWordStaus {wsPrinted = 1, wsPrinting = 2, wsReady = 0, wsError = 3};

class TWord
{
	String w;
	bool isVk;
	bool isTab;
	TWordStaus Status;
	int Pos;
	int Len;
	public:
	  TWord();
	  void Init(const String NewWord);
	  TWordStaus TypeChar(wchar_t c);
	  int GetPos() {return Pos;};
	  String GetText() {return w;};
};

class TStor
{
	private:
		int WordCount;
		int Pos;
		std::map<int,TWord> Words;
	public:
		TStor();
		void AddWord(String s);
		void AddTab() {AddWord(TAB);};
		void AddVk() {AddWord(VK);};
		void ClearWords();
		TWord GetWord(int Pos);
		int TypeChar(wchar_t c);
		int GetWordCount() {return WordCount;};
};


//---------------------------------------------------------------------------
#endif

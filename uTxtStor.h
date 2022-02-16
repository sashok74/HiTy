//---------------------------------------------------------------------------

#ifndef uTxtStorH
#define uTxtStorH
#include <memory>
#include <functional>
#include <map>
#include <set>

#define TAB  "-tab-"
#define VK "-vk-"
#define SPACE " "
#define WORDS_EMPTY -1

enum TWordStaus {wsPrinted = 1, wsPrinting = 2, wsReady = 0, wsError = 3};


class TWord
{
  using TCallback = std::function<void(int)>;
  private:
	String w;
	bool isVk;
	bool isTab;
	TWordStaus Status;
	int ChPos;
	int Len;
	TCallback callBack;
  public:
	TWord() :
		Status { wsReady }, ChPos { 1 }, Len { 0 }, isVk { false }, isTab {
			false
		} {};
	void Init(const String NewWord);
	void AddCallback(TCallback);

	TWordStaus TypeChar(wchar_t in);
	int GetPos()
	{
        return ChPos;
    };
    String GetText()
    {
        return w;
    };
    TWordStaus GetStatus()
    {
        return Status;
    };
};
using PWords = std::shared_ptr<TWord>;

class TStor
{

	private:
		int WordCount;
		int Pos;
		std::map<int,PWords> Words;
	public:
		TStor() : WordCount{0}, Pos{0}
			 {};
		void AddWord(String s);
		void AddTab() {AddWord(TAB);};
		void AddVk() {AddWord(VK);};
		void AddSpace() {AddWord(SPACE);};
		void ClearWords();
		PWords GetWord(int ind);
		int TypeChar(wchar_t c);
		int GetWordCount() {return WordCount;};
		int GetCurrentWordNum() {return Pos;};
};


//---------------------------------------------------------------------------
#endif


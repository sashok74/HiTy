//---------------------------------------------------------------------------

#pragma hdrstop

#include "uTxtStor.h"
//---------------------------------------------------------------------------

void TWord::Init(const String NewWord)
{
	isVk  = NewWord == TAB;
	isTab = NewWord == VK;
	Status = wsReady;
	if (!isVk & !isVk) {
	  w = NewWord;
	} else 	{
	  w = "";
	}

   //	ChPos = 1;
	Len = w.Length();
}

void TWord::AddCallback(TCallback cb) {callBack = cb;};

/*
https://www.stackfinder.ru/questions/57904835/using-stdbind-and-stdfunction-to-use-a-class-member-function-as-callback-for
*/

TWordStaus TWord::TypeChar(wchar_t in)
{
   bool res = (w[ChPos] == in);

   Status =  res ? wsPrinting : wsError;

	/*
	   если по ошибке хотим ехать дадьше то res = true
	   записываем ошибки и время нажатия здесь.
	*/

   if (res) ChPos++;
   if (ChPos > Len) Status = wsPrinted;
   callBack(ChPos);
   return Status;
}


void TStor::AddWord(String s)
{
  Words[WordCount] = std::make_shared<TWord>();
  Words[WordCount]->Init(s);
  WordCount++;
}

void TStor::ClearWords() {
	WordCount = 0;
	Pos = 0;
	if (!Words.empty())  Words.clear();
}

PWords TStor::GetWord(int ind) {
  if (ind >= WordCount)  ind = WordCount - 1;
  /*  проверка на пустой */
  return Words[ind];
}

int  TStor::TypeChar(wchar_t c) {
   // Вче пробелы заметяем одним.
   if (Words.size == 0)
	   return WORDS_EMPTY;

   if ((String(c) == SPACE) && (Pos == 0 || ( Pos > 0 && Words[Pos-1]->GetText() == SPACE)))
   return Pos;

   if (Words[Pos]->TypeChar(c) == wsPrinted) {
	 Pos++;
   }
   return Pos;
}




#pragma package(smart_init)

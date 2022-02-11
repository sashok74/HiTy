//---------------------------------------------------------------------------

#pragma hdrstop

#include "uTxtStor.h"
//---------------------------------------------------------------------------


TWord::TWord()
{
	Status = wsReady;
	Pos = 0;
}

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

	Pos = 0;
	Len = w.Length();
}

TWordStaus TWord::TypeChar(wchar_t c)
{
	bool res = w[Pos] == c;
	if (!res) Status = wsError;
	/*
	   если по ошибке хотим ехать дадьше то res = true
	   записываем ошибки и время нажатия здесь.
	*/
	if (res) Pos++;
	if (Pos == Len) Status = wsPrinted;
	return Status;
}

TStor::TStor(){
	WordCount = 0;
	Pos = 0;
}


void TStor::AddWord(String s)
{
  Words[WordCount++].Init(s);
}

void TStor::ClearWords() {
	WordCount = 0;
	Pos = 0;
	Words.clear();
}

TWord TStor::GetWord(int Pos) {
  if (Pos >= WordCount)  Pos = WordCount - 1;
  /*  проверка на пустой */
  return Words[Pos];
}

int  TStor::TypeChar(wchar_t c) {
   if (Words[Pos].TypeChar(c) == wsPrinted) {
	 Pos++;
   }
   return Pos;
}


#pragma package(smart_init)

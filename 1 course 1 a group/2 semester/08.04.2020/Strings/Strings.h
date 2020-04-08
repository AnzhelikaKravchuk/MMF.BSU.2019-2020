#pragma once
namespace StringExtension
{
	char** ObtainWords(char*, int&);
	char** ObtainWordsAgain(char*, int&);
	void SortingWords(char**, int);
	void DisplayWords(char**, int);
	void Swap(char*&, char*&);
	void FreeHeap(char**, int);
	void ReplaceSubString(char*, char*, char*);
}
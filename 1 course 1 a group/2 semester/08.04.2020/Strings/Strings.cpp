#define _CRT_SECURE_NO_WARNINGS
#include "Strings.h"
#include <ostream>
#include <iostream>

char** StringExtension::ObtainWords(char* source, int& n)
{
	char* copy = new char[strlen(source) + 1];
	strcpy(copy, source);

	char** words = new char* [strlen(copy) / 2];
	n = 0;
	const char* symbols = "	1234567890-=!@#$%^&*()_+{}|][:;'<>?/., \x22";
	char* pword = strtok(copy, symbols);
	words[n] = new char[strlen(pword) + 1];
	strcpy(words[n], pword);

	n++;
	while (pword)
	{
		pword = strtok(nullptr, symbols);
		if (pword)
		{
			words[n] = new char[strlen(pword) + 1];
			strcpy(words[n], pword);
			n++;
		}
	}

	delete[] copy;
	return words;
}

char** StringExtension::ObtainWordsAgain(char* source, int& n)
{
	const char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char** words = new char* [strlen(source) / 2];

	n = 0;
	char* pword = strpbrk(source, symbols);
	while (pword)
	{
		int length = strspn(pword, symbols);
		words[n] = new char[length + 1];
		strncpy(words[n], pword, length);
		words[n][length] = '\0';
		pword += length;
		pword = strpbrk(pword, symbols);
		n++;
	}

	return words;
}

void StringExtension::DisplayWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << (i + 1) << ". " << words[i] << std::endl;
	}
}

void StringExtension::FreeHeap(char** words, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] words[i];
	}
	
	delete[] words;
}

void StringExtension::SortingWords(char** words, int n)
{
	for (int i = 0; i < n; i++)//!!!!Optimization!!!!!
	{
		for (int j = n - 1; j > i; j--)
		{
			if (strcmp(words[j], words[j - 1]) < 0)
			{
				StringExtension::Swap(words[j], words[j - 1]);
			}
		}
	}
}

void StringExtension::Swap(char*& x, char*& y)
{
	char* temp = x;
	x = y;
	y = temp;
}

void StringExtension::ReplaceSubString(char* string, char* subString, char* replaceString)
{
	int lenSubString = strlen(subString), lenReplaceString = strlen(replaceString);

	char* pString = strstr(string, subString);

	char* help = new char[strlen(string) + 1];

	while (pString)
	{
		strcpy(help, pString + lenSubString);
		strcpy(pString, replaceString);
		strcat(pString, help);
		pString += lenReplaceString;
		pString = strstr(pString, subString);
	}

	delete[] help;
}

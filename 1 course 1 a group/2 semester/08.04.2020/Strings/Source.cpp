#include "Strings.h"
#include <iostream>

using namespace std;
using namespace StringExtension;

auto main() -> int
{
	const int LENGTH = 256;
	//char str[LENGTH] = "6354264The   ???  usual form of input, 098 -1  =+"
	//"For most statistical functions is a list is of data... 89 Form. ";
	////cout << "Enter the string: ";
	////cin.getline(str, LENGTH, '\n');
	//system("cls");
	//cout << endl << "\tSTRING IS:" << endl;
	//cout << str;
	//int n = 0;
	//char** arrayWords = ObtainWordsAgain(str, n);
	//cout << endl << "\tARRAY OF WORDS" << endl;
	//DisplayWords(arrayWords, n);
	//SortingWords(arrayWords, n);
	//cout << endl << "\tNEW ARRAY OF WORDS" << endl;
	//DisplayWords(arrayWords, n);
	//FreeHeap(arrayWords, n);
	//cout << endl;

	char string[LENGTH] = "6354264The   ???  usual form of  is input, 098 -1  =+"
		"For most statistical functions is a list is of data... 89 Form. ",
	subString[LENGTH] = "is", replaceString[LENGTH] = " are ";

	//cout << "Enter the source string, please:";
	//cin.getline(string, LENGTH, '\n');

	//cout << "Enter the  substring , please:";
	//cin.getline(subString, LENGTH, '\n');

	//cout << "Enter the  substring for the replacement, please:";
	//cin.getline(replaceString, LENGTH, '\n');
	//system("cls");


	cout << "The source string    - " << string << endl;

	cout << "The source string    - " << string + 12 << endl;
	
	//cout << "The source substring            - " << subString << endl;
	//cout << "The substring for replacement   - " << replaceString << endl << endl;
	//cout << "The source string    - " << string << endl << endl;

	//ReplaceSubString(string, subString, replaceString);

	//cout << "The obtained string  - " << string << endl;

	system("pause");
	return 0;
}

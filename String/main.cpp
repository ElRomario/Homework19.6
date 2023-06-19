#include "String.h"
#include <iostream>
using namespace std;
int main()
{
	const char* chacha = "Hello";
	int size = strlen(chacha);

	String<char> str(chacha, size);
	cout << "str0: " << &str<<" ";
	cout << str << endl;

	cout << endl;

	str[1] = 'p';
	cout << "After replacing the second letter in str0:" << endl;
	cout << str;
	cout << endl;

	cout << endl;

	String<char>str1(str);
	cout << "str1: " << &str1<<" ";
	cout << str1 << endl;

	cout << endl;

	

	/*wchar_t* wtext = new wchar_t[strlen("Hello0000") + 1];
	int wsize = strlen("Hello0000" + 1);*/


	//wchar_t* wtext = new wchar_t[strlen("Nigger" + 1)];
	//String<wchar_t> wstr(wtext, wsize);
	//cout << "wstr: " << wstr;

	/*String<char> str2 = move(str1);
	cout << "str1 after using as argument in mover:" << endl;
	cout << str1<<endl;
	cout << "str2: " << str2;*/
	
	const wchar_t* wChar = L"Hello everynyan";
	int wSize = wcslen(wChar + 1);
	String<wchar_t>wStr(L"Hello everynyan", wSize);
	cout << "Wide string: " << &wStr << " ";
	cout << wStr<<endl;

	cout << endl;

	String<wchar_t>wStr2(wStr);
	cout << "Wide string2: " << &wStr2 <<" ";
	cout << wStr2 << endl;

	cout << endl;

	String<wchar_t>wStr3 = move(wStr2);
	cout << "Wide string3: " << &wStr3 << " ";
	cout << wStr3 << endl;

	String<wchar_t>newWStr(L"kill me", wcslen(L"kill me"));//почему если я укажу размер + 1, то у меня обрежется буква?

	cout << endl;

	cout << "Wide string3 = new wide string" << endl;
	wStr3 = move(newWStr);
	cout << wStr3 << endl;






	



}


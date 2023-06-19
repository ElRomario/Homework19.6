#pragma once
#include <iostream>
#include <ostream>

using namespace std;

template <typename T>
class String
{
	T* chars;
	int size;
public:
	String() :chars{ nullptr }, size{ 0 }{};
	String(const T *str, int size) : size(size)
	{
		chars = new T[size];
		for (int i = 0; i < size; i++)
		{
			chars[i] = str[i];
		}
	}
	String(const String<T>& original)
	{
		cout << "Copying constructor was used for " << this<<endl;
		chars = new T[original.size];
		for (int i = 0; i < original.size; i++)
		{
			chars[i] = original.chars[i];
		}
		size = original.size;
	}
	String(String<T>&& dying)
	{
		cout << "<Moving constructor was used for " << this << endl;
		size = dying.size;
		chars = dying.chars;

		dying.chars = nullptr;
		dying.size = 0;
	}
	friend ostream& operator<<(ostream& out, const String<char>& str);
	friend ostream& operator<<(ostream& out, const String<wchar_t>& wstr);

	String<T>& operator=(String<T>&& dying);
	String<T>& operator=(const String<T>& original);

	const T operator[](int index) const;
		T & operator[](int index);

	~String()
	{
		delete[] chars;
	}
	
};

template<typename T>
const T String<T>::operator[](int index) const
{
	return chars[index];
}

template<typename T>
inline T& String<T>::operator[](int index)
{
	return chars[index];
}

ostream& operator<<(ostream& out, const String<char> &str)
{
	for (int i = 0; i < str.size; i++)
	{
		cout << str[i];
	}
	return out;
}

ostream& operator<<(ostream& out, const String<wchar_t>& wstr)
{
	
	for (int i = 0; i < wstr.size; i++)
	{
		wcout << wstr[i];
	}
	return out;
}
template<typename T>
String<T>& String<T>::operator=(String<T>&& dying)
{
	cout << "Assingment by moving: " << endl;
	delete[] chars;
	this->size = dying.size;
	this->chars = dying.chars;

	dying.chars = nullptr;
	dying.size = 0;
	return *this;
}

template<typename T>
inline String<T>& String<T>::operator=(const String<T>& original)
{
	size = original.size;
	chars = new T[original.size];
	for (int i = 0; i < size; i++)
	{
		chars[i] = original[i];
	}
	return *this;
}

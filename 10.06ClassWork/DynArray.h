#pragma once
#include <iostream>
using namespace std;
template<typename T>
class DynArray
{
	T* data;
	int size;
public: DynArray(int size) : size{ size }, data{ new T[size] }{}
	  DynArray(const DynArray<T>& original);
	  DynArray(const initializer_list<T>& list);
	  ~DynArray();
	  DynArray(DynArray<T>&& dying);

	  int getSize() const { return size; }

	  const T& operator[] (int index) const;

	  DynArray<T>& operator = (const DynArray<T> original);
	  DynArray<T>& operator = (DynArray<T>&& dying);
};
template<typename T>
DynArray<T>::DynArray(const DynArray<T>& original) : size{ original.size }, data{ new T[size] }
{
	for (int i = 0; i < original.size; i++)
	{
		data[i] = original.data[i];
	}
}

template<typename T>
inline DynArray<T>& DynArray<T>::operator=(DynArray<T>&& dying)
{
	delete[] data;//освободить старую память
	size = dying.size;//забираем старый размер
	data = dying.data;//забираем старые данные
	dying.data = nullptr;//чтобы он не высвободил наши данные
	dying.size = 0;//если массив отсустствует, то размер =0
	return *this;
}
template<typename T>
DynArray<T>::DynArray(const initializer_list<T>& list) : size(list.size()), data{ new T[list.size()] }
{
	int i = 0;
	for (T item : list) 
	{
		data[i++] = item;
	}
}


template <typename T>
DynArray<T>::~DynArray()
{
	delete[] data;
}

template<typename T>
inline DynArray<T>::DynArray(DynArray<T>&& dying) : size{ dying.size }, data{ dying.data }
{
	dying.data = nullptr;
	dying.size = 0;
}

template<typename T>
const T& DynArray<T>::operator[](int index) const
{
	if (index < 0 || index >= size)
	{
		cerr << "Выод за пределы массива" << index << ' ' << size << endl;
		abort();
	}
	return data[index];
}

template<typename T>
DynArray<T>& DynArray<T>::operator = (const DynArray<T> original)
{
	this->size = original.size;
	this->data = new T[original.size];
	for (int i = 0; i < size; i++)
		data[i] = original.data[i];
	return *this;

}



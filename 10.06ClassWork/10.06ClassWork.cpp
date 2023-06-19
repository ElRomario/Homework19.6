
#include <iostream>
#include "DynArray.h"
#include <string>
using namespace std;
int main()
{
	DynArray<int> numbers{1, 2, 3, 4, 5};

	for (int i = 0; i < numbers.getSize(); i++)
	{
		cout <<hex<< numbers[i] <<dec<< endl;
	}
	DynArray<int> a = DynArray<int>{ 6, 7, 8, 9 };
	DynArray<int> b  (DynArray<int>{ 6, 7, 8, 9 });
	DynArray<int> c{ DynArray<int>{ 6, 7, 8, 9 } };

	a = b;
	//a = DynArray<int>{ 0 };
	int price = 100;
	float discount = 0.1f;
	string bill = string("Total Price" ) + to_string(price) + "rub. Discount: " + to_string(discount) + "Your always welocme!";

	cout << bill;
}



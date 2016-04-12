// DynamicMemoryAllocation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define ARRAY_SIZE 100000000

bool custom_allocate();

int main()
{
	cout << "Please examine the memory that the application occuies. As can be seen (by tools like Task Manager and Resource Monitor), the memory is negligible." << endl;
	cin.get();

	custom_allocate();

	cout << "In contrast to previous state, the memory occupied by the program is signifcant, and equal to amount reserved in custom_allocate function. It shows that the OS assumes that memory is still reserved for the application." << endl;
	cin.get();

	//If you uncomment next line, the application will encounter an exception after few runs of the loop, exceeding maximum permitted memory for the application.
	//It indicates more allocation is not possible which can only mean that the memory reserved by custom_allocate function is NEVER freed after even returning.
	//while (custom_allocate());

	return 0;
}

bool custom_allocate()
{
	int* p = new int[ARRAY_SIZE];
	if (p)
		return true;
	else
		return false;

}


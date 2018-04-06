#pragma once
#ifndef CHANGELENGTH1D_H
#define CHANGELENGTH1D_H
#include "MyExceptions.h"

using namespace std;

template<class T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
	if (newLength < 0)
		throw illegalParameterValue("new length must be >= 0");

	T* temp = new T[newLength];              // new array
	int number = min(oldLength, newLength);  // number to copy
	copy(a, a + number, temp);
	delete[] a;                             // deallocate old memory
	a = temp;
}

#endif

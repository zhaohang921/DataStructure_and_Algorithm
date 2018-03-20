#pragma once
#ifndef LINEARLIST_H
#define LINEARLIST_
#include <iostream>
using namespace std; 
//一个线性表的抽象类
template<typename T>
class LinearList
{
public:
	virtual ~linearList() {};
	virtual bool empty() const = 0;
	// return true iff list is empty
	virtual int size() const = 0;
	// return number of elements in list
	virtual T& get(int theIndex) const = 0;
	// return element whose index is theIndex
	virtual int indexOf(const T& theElement) const = 0;
	// return index of first occurence of theElement
	virtual void erase(int theIndex) = 0;
	// remove the element whose index is theIndex
	virtual void insert(int theIndex, const T& theElement) = 0;
	// insert theElement so that its index is theIndex
	virtual void output(ostream& out) const = 0;
	// insert list into stream out
};
#endif
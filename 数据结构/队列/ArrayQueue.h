#pragma once
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include"Queue.h"
#include "MyExceptions.h"
#include <sstream>

using namespace std;

template<class T>
class ArrayQueue : public Queue<T>
{
public:
	ArrayQueue();
	~ArrayQueue();
};
#endif

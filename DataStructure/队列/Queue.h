#pragma once
#ifndef QUEUE_H
#define QUEUE_H
using namespace std;
//队列抽象类
template<typename T>
class Queue
{
public:
	virtual ~Queue() {}
	virtual bool empty() const = 0;
	// return true iff queue is empty
	virtual int size() const = 0;
	// return number of elements in queue
	virtual T& front() = 0;
	// return reference to the front element
	virtual T& back() = 0;
	// return reference to the back element
	virtual void pop() = 0;
	// remove the front element
	virtual void push(const T& theElement) = 0;
	// add theElement at the back of the queue
};
#endif
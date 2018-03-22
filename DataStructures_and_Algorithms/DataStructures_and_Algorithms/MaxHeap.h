#pragma once
#ifndef MAXHEAP_H
#define MAXHEAP_H
#include"MaxPriorityQueue.h"
#include"MyExceptions.h"
#include"ChangeLength1D.h"
#include<sstream>
#include<algorithm>
using namespace std;

//大根堆实现最大优先级队列
template<typename T>
class MaxHeap : public MaxPriorityQueue<T>
{
	friend ostream& operator<<(ostream& out, const MaxHeap<T>& x);
public:
	MaxHeap(int initialCapacity = 10);
	~MaxHeap();
	virtual bool empty() const override;
	virtual int size() const override;
	virtual const T& top() override;
	virtual void pop() override;
	virtual void push(const T& theElement) override;
	void initialize(T *theHeap, int theSize);
	void deactiveArray();
	void output(ostream &out) const;
private:
	int heapSize;      //堆中节点个数
	int arrayLength;//队列容量加1
	T *heap;      //元素数组
};

template<typeanme T>
ostream& operator<<(ostream& out, const MaxHeap<T>& x);

#endif


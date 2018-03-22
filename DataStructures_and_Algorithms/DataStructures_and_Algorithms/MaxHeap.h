#pragma once
#ifndef MAXHEAP_H
#define MAXHEAP_H
#include"MaxPriorityQueue.h"
#include"MyExceptions.h"
#include"ChangeLength1D.h"
#include<sstream>
#include<algorithm>
using namespace std;

//�����ʵ��������ȼ�����
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
	int heapSize;      //���нڵ����
	int arrayLength;//����������1
	T *heap;      //Ԫ������
};

template<typeanme T>
ostream& operator<<(ostream& out, const MaxHeap<T>& x);

#endif


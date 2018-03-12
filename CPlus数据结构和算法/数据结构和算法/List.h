#pragma once
/*
µ•œÚ¡¥±Ì
*/
#include"ListNode.h"

template<typename T>
class List
{
public:
	List();
	~List();

	bool AddTail(T value);
	bool RemoveTail();
	bool InsertAt(int index, T value);
	bool RemoveAt(int index);

	T& GetAt(int index);
	bool IsEmpty();
	int GetCount();
	void RemoveAll();

	ListNode<T>* GetHead();
	ListNode<T>* GetTail();
	ListNode<T>* GetNodeAt(int index);
	ListNode<T>* GetCur();
	ListNode<T>* TowardCur();

private:
	ListNode<T>* head;
	ListNode<T>* tail;
};


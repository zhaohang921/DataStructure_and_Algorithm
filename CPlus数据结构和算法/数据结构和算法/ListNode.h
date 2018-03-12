#pragma once

template<typename T>
class ListNode
{
public:
	//ListNode();
	ListNode() :link(NULL) {}
	ListNode(T value) :link(NULL), data(value) {}
	~ListNode();
	void SetLink(ListNode<T> *next);
	void SetData(T value);
	ListNode<T>* GetLink();
	T& GetData();

private:
	T data;
	ListNode<T> *link;
};


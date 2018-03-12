#include "ListNode.h"

//template<typename T>
//ListNode<T>::ListNode()
//{
//}

template<typename T>
ListNode<T>::~ListNode()
{
}

template<typename T>
void ListNode<T>::SetLink(ListNode<T> *next)
{
	link = next;
}

template<typename T>
void ListNode<T>::SetData(T value)
{
	data = value;
}

template<typename T>
ListNode<T>* ListNode<T>::GetLink()
{
	return link;
}

template<typename T>
T& ListNode<T>::GetData()
{
	return data;
}

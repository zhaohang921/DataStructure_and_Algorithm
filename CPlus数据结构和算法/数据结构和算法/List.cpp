#include "List.h"

template<typename T>
List<T>::List()
{
	head = new ListNode<T>();
	tail = head;
	tail->SetLink(NULL);
}

template<typename T>
List<T>::~List()
{
	RemoveAll();
	delete head;
}

template<typename T>
bool List<T>::AddTail(T value)//向表尾加新节点
{
	ListNode<T>* add = new ListNode<T> (value);
	tail->SetLink(add);
	tail = tail->GetLink();
	tail->SetLink(NULL);
	if (tail != NULL)
		return true;
	else
		return false;
}

template<typename T>
bool List<T>::RemoveTail()
{
	return RemoveAt(this->GetCount() - 1);
}

template<typename T>
bool List<T>::InsertAt(int index, T value)//判断索引值是否正确
{
	if (index > this->GetCount() - 1 || index < 0)
	{
		cout << "A wrong postion!" << endl;
		return false;
	}
	ListNode<T>* current = head;
	while (index)
	{
		current = current->GetLink();
		--index;
	}
	ListNode<T>* add = new ListNode<T>(value);
	add->SetLink(current->GetLink());
	current->SetLink(add);

	if (current->GetLink() != NULL)
		return true;
	else
		return false;
}

template<typename T>
bool List<T>::RemoveAt(int index)//按照索引值删除节点
{
	if (index > this->GetCount() - 1 || index < 0)
	{
		cout << "A wrong position!" << endl;
		return false;
	}
	ListNode<T>* cur, *curPre;//cur指向要删除的节点的前一个节点，curPre指向要删除的节点
	cur = head;
	curPre = cur->GetLink();

	while (index)
	{
		cur = cur->GetLink();
		curPre = curPre->GetLink();
		--index;
	}

	if (tail == curPre)
		tail = cur;

	cur->SetLink(curPre->GetLink());
	delete curPre;

	if (curPre != NULL)
		return true;
	else
		return false;
}

template<typename T>
T& List<T>::GetAt(int index)
{
	if (index > this->GetCount() - 1 || index < 0)
	{
		cout << "A wrong position!" << endl;
	}
	ListNode<T>* cur;
	cur = head->GetLink();
	while (index)
	{
		cur = cur->GetLink();
		--index;
	}
	return cur->GetData();
}

template<typename T>
bool List<T>::IsEmpty()
{
	return head->GetLink() == NULL;
}

template<typename T>
int List<T>::GetCount()
{
	int count = 0;
	ListNode<T>* current = head->GetLink();
	while (current != NULL)
	{
		++count;
		current = current->GetLink();
	}
	return count;
}

template<typename T>
void List<T>::RemoveAll()
{
	ListNode<T>* cur;
	while (head->GetLink() != NULL)
	{
		cur = head->GetLink();
		head->SetLink(cur->GetLink());
		delete cur;
	}
	tail = head;
}

template<typename T>
ListNode<T>* List<T>::GetHead()
{

}

template<typename T>
ListNode<T>* List<T>::GetTail()
{

}

template<typename T>
ListNode<T>* List<T>::GetNodeAt(int index)//返回指向索引值index的节点的指针
{
	if (index > this->GetCount() - 1 || index < 0)
	{
		cout << "A wrong position!" << endl;
	}
	ListNode<T>* handle = head->GetLink();
	while (index)
	{
		handle = handle->GetLink();
		--index;
	}
	return handle;
}

template<typename T>
ListNode<T>* List<T>::GetCur()
{

}

template<typename T>
ListNode<T>* List<T>::TowardCur()
{

}

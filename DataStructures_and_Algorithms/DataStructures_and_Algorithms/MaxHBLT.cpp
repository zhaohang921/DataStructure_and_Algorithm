#include "MaxHBLT.h"


template<typename T>
bool MaxHBLT<T>::empty() const
{
	return treeSize == 0;;
}

template<typename T>
int MaxHBLT<T>::size() const
{
	return treeSize;
}

template<typename T>
const T & MaxHBLT<T>::top()
{
	if (treeSize == 0)
		throw queueEmpty();
	return root->element.second;
}

template<typename T>
void MaxHBLT<T>::pop()
{
	if (root == nullptr)
		throw queueEmpty();
	BinaryTreeNode<pair<int, T>> *left = root->leftChild, *right = root->rightChild;
	delete root;
	root = left; 
	meld(root, rigtht);
	++treeSize;
}

template<typename T>
void MaxHBLT<T>::push(const T &theElement)
{
	BinaryTreeNode<pair<int, T>> *q = new BinaryTreeNode<pair<int, T>>(pair<int, T>(1, theElement));
	meld(root, q);
	++treeSize;
}

template<typename T>
void MaxHBLT<T>::initialize(T *theElements, int theSize)
{//������theElements[1:theSize]���������
	ArrayQueue<BinaryTreeNode<pair<int, T>>*> q(theSize);
	erase(); //ʹ*thisΪ��
	for (int i = 1; i <= theSize; i++)
		q.push(new BinaryTreeNode<pair<int, T>>(pair<int, T>(1, theElements[i])));
	for (int i = 1; i <= theSize - 1; i++)
	{//�Ӷ�����ȡ���������ϲ�
		BinaryTreeNode<pair<int, T>> *b = q.front();
		q.pop();
		BinaryTreeNode<pair<int, T>> *c = q.front();
		q.pop();
		meld(b, c);
		q.push(b);
	}
	if (theSize > 0)
		root = q.front();
	treeSize = theSize;
}

template<typename T>
void MaxHBLT<T>::meld(MaxHBLT<T>& theHBLT)
{
	meld(root, theHBLT.root);//����˽�з���
	treeSize += theHBLT.treeSize;
	theHBLT.root = nullptr;
	theHBLT.treeSize = 0;
}

template<typename T>
void MaxHBLT<T>::output()
{
	postOrder(HBLTOutput);
	cout << endl;
}

template<typename T>
void MaxHBLT<T>::meld(BinaryTreeNode<pair<int, T>>* &x, BinaryTreeNode<pair<int, T>>* &y)
{//�ϲ��ֱ���*x��*yΪ����������������ϲ�����������xΪ��������x��ָ��
	if (y == nullptr)
		return;
	if (x == nullptr)
	{
		x = y;
		return;
	}
	//x��y����Ϊ�գ���Ҫʱ����x��y����֤�ϲ�����xΪ��
	if (x->element.second < y->element.second)
		swap(x, y);
	//��x����������y�ϲ����ݹ鿪ʼ
	meld(x->rightChild, y);

	if (x->leftChild == nullptr)
	{
		x->leftChild = x->rightChild;
		x->rightChild = nullptr;
		x->element.first = 1;
	}
	else
	{//��������sֵ��Сʱ����
		if (x->leftChild->element.first < x->rightChild->element.first)
			swap(x->leftChild, x->rightChild);
		//����x��sֵ
		x->element.first = x->rightChild->element.first + 1;
	}
}

template<typename T>
void MaxHBLT<T>::HBLTOutput(BinaryTreeNode<pair<int, T>>* t)
{
	cout << t->element.second << '  ';
}

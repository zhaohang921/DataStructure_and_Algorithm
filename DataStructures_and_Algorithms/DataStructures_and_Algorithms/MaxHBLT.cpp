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
{//用数组theElements[1:theSize]建立左高树
	ArrayQueue<BinaryTreeNode<pair<int, T>>*> q(theSize);
	erase(); //使*this为空
	for (int i = 1; i <= theSize; i++)
		q.push(new BinaryTreeNode<pair<int, T>>(pair<int, T>(1, theElements[i])));
	for (int i = 1; i <= theSize - 1; i++)
	{//从队列中取出两棵树合并
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
	meld(root, theHBLT.root);//调用私有方法
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
{//合并分别以*x和*y为根的两棵左高树，合并后的左高树以x为根，返回x的指针
	if (y == nullptr)
		return;
	if (x == nullptr)
	{
		x = y;
		return;
	}
	//x和y都不为空，必要时交换x和y，保证合并后以x为根
	if (x->element.second < y->element.second)
		swap(x, y);
	//将x的右子树与y合并，递归开始
	meld(x->rightChild, y);

	if (x->leftChild == nullptr)
	{
		x->leftChild = x->rightChild;
		x->rightChild = nullptr;
		x->element.first = 1;
	}
	else
	{//左子树的s值较小时交换
		if (x->leftChild->element.first < x->rightChild->element.first)
			swap(x->leftChild, x->rightChild);
		//更新x的s值
		x->element.first = x->rightChild->element.first + 1;
	}
}

template<typename T>
void MaxHBLT<T>::HBLTOutput(BinaryTreeNode<pair<int, T>>* t)
{
	cout << t->element.second << '  ';
}

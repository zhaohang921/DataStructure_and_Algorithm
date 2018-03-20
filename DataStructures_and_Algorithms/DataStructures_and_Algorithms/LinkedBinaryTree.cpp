#include "LinkedBinaryTree.h"
#include<iostream>

template<typename E>
LinkedBinaryTree<E>::LinkedBinaryTree()
{
	root = nullptr;
	treeSize = 0;
}

template<typename E>
LinkedBinaryTree<E>::~LinkedBinaryTree()
{
	erase();
}

template<typename E>
bool LinkedBinaryTree<E>::empty() const
{
	return treeSize == 0;
}

template<typename E>
int LinkedBinaryTree<E>::size() const
{
	return treeSize;
}

template<typename E>
void LinkedBinaryTree<E>::preOrder(void(*theVisit)(BinaryTreeNode<E>*))
{
	visit = theVisit;
	preOrder(root);   //静态私有成员函数	static void preOrder(BinaryTreeNode<E> *t);
}

template<typename E>
void LinkedBinaryTree<E>::inOrder(void(*theVisit)(BinaryTreeNode<E>*))
{
	visit = theVisit;
	inOrder(root);    //静态私有成员函数	static void inOrder(BinaryTreeNode<E> *t);
}

template<typename E>
void LinkedBinaryTree<E>::postOrder(void(*theVisit)(BinaryTreeNode<E>*))
{
	visit = theVisit;
	postOrder(root);  //静态私有成员函数	static void postOrder(BinaryTreeNode<E> *t);
}

template<typename E>
void LinkedBinaryTree<E>::levelOrder(void(*theVisit)(BinaryTreeNode<E>*))
{
	ArrayQueue<binaryTreeNode<E>*> q;
	binaryTreeNode<E> *t = root;
	while (t != NULL)
	{
		theVisit(t);  // 访问t
		//将t的孩子插入队列
		if (t->leftChild != NULL)
			q.push(t->leftChild);
		if (t->rightChild != NULL)
			q.push(t->rightChild);

		// 提取下一个要访问的节点
		try { t = q.front(); }
		catch (queueEmpty) { return; }
		q.pop();
	}
}

template<typename E>
void LinkedBinaryTree<E>::erase()
{
	postOrder(dispose);
	root = nullptr;
	treeSize = 0;
}

template<typename E>
void LinkedBinaryTree<E>::preOrderOutput()
{
	preOrder(output);
	std::cout << std::endl;
}

template<typename E>
int LinkedBinaryTree<E>::height() const
{
	return height(root);  //调用静态私有成员函数	static int height(BinaryTreeNode<E> *t);//返回根为*t的树的高度
}

template<typename E>
void LinkedBinaryTree<E>::preOrder(BinaryTreeNode<E>* t)
{
	if (t != nullptr)
	{
		LinkedBinaryTree<E>::visit(t);
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}

template<typename E>
void LinkedBinaryTree<E>::inOrder(BinaryTreeNode<E>* t)
{
	if (t != nullptr)
	{
		LinkedBinaryTree<E>::visit(t);
		inOrder(t->leftChild);
		inOrder(t->rightChild);
	}
}

template<typename E>
void LinkedBinaryTree<E>::postOrder(BinaryTreeNode<E>* t)
{
	if (t != nullptr)
	{
		LinkedBinaryTree<E>::visit(t);
		postOrder(t->leftChild);
		postOrder(t->rightChild);
	}
}

template<typename E>
void LinkedBinaryTree<E>::dispose(BinaryTreeNode<E> *t)
{
	delete t;
}

template<typename E>
void LinkedBinaryTree<E>::output(BinaryTreeNode<E>* t)
{
	std::cout << t->element << '  ';
}

template<typename E>
int LinkedBinaryTree<E>::height(BinaryTreeNode<E>* t)
{
	if (t == nullptr)
		return 0;
	int left_subtree_height = height(t->leftChild);   //左子树高
	int right_subtree_height = height(t->rightChild);//右子树高
	/*return left_subtree_height > left_subtree_height ? ++left_subtree_height : ++left_subtree_height;*/
	if (left_subtree_height > right_subtree_height)
		return ++left_subtree_height;
	else
		return ++right_subtree_height;
}

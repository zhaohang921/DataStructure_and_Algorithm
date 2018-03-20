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
	preOrder(root);   //��̬˽�г�Ա����	static void preOrder(BinaryTreeNode<E> *t);
}

template<typename E>
void LinkedBinaryTree<E>::inOrder(void(*theVisit)(BinaryTreeNode<E>*))
{
	visit = theVisit;
	inOrder(root);    //��̬˽�г�Ա����	static void inOrder(BinaryTreeNode<E> *t);
}

template<typename E>
void LinkedBinaryTree<E>::postOrder(void(*theVisit)(BinaryTreeNode<E>*))
{
	visit = theVisit;
	postOrder(root);  //��̬˽�г�Ա����	static void postOrder(BinaryTreeNode<E> *t);
}

template<typename E>
void LinkedBinaryTree<E>::levelOrder(void(*theVisit)(BinaryTreeNode<E>*))
{
	ArrayQueue<binaryTreeNode<E>*> q;
	binaryTreeNode<E> *t = root;
	while (t != NULL)
	{
		theVisit(t);  // ����t
		//��t�ĺ��Ӳ������
		if (t->leftChild != NULL)
			q.push(t->leftChild);
		if (t->rightChild != NULL)
			q.push(t->rightChild);

		// ��ȡ��һ��Ҫ���ʵĽڵ�
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
	return height(root);  //���þ�̬˽�г�Ա����	static int height(BinaryTreeNode<E> *t);//���ظ�Ϊ*t�����ĸ߶�
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
	int left_subtree_height = height(t->leftChild);   //��������
	int right_subtree_height = height(t->rightChild);//��������
	/*return left_subtree_height > left_subtree_height ? ++left_subtree_height : ++left_subtree_height;*/
	if (left_subtree_height > right_subtree_height)
		return ++left_subtree_height;
	else
		return ++right_subtree_height;
}

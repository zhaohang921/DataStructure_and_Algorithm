#include"Tree.h"
template<typename T>
Tree<T>::Tree()
{
	root = NULL;
	parent = NULL;
}

template<typename T>
Tree<T>::Tree(TreeNode<T>* rt)//���캯�����������Ľṹ
{
	root = rt;
	parent = NULL;
}

template<typename T>
Tree<T>::~Tree()
{

}

template<typename T>
TreeNode<T>* Tree<T>::getRoot()//�������ĸ��ڵ㣬��Ϊ�������򷵻�Null
{
	return root;
}

template<typename T>
int Tree<T>::getParent(TreeNode<T>* t, TreeNode<T>* p)
{
	TreeNode<T>* q = t->getLeftChild();
	while (q != NULL && q != p)
	{
		if (getParent(q, p) != 0)
			return 2;
		q = q->getRightSibling();
	}
	if (q != NULL && q == p)
	{
		parent = t;
		return 1;
	}
	else return 0;
}
//���ؽڵ�current�ĸ��ڵ㣬����ڵ��Ǹ��ڵ㣬�򷵻�Null
template<typename T>
TreeNode<T>* Tree<T>::Parent(TreeNode<T>* current)
{
	TreeNode<T>* pointer = current, *t;
	if (current = NULL || current == root)
		return NULL;
	t = root;
	getParent(t, pointer);
	return parent;
}
//���ؽڵ�t�ĵ�һ���ӽڵ㣬�����򷵻�Null
template<typename T>
TreeNode<T>* Tree<T>::getFirstChild(TreeNode<T>* t)
{
	return t->getLeftChild();
}
//���ؽڵ�t����һ���ֵܽڵ㣬�����򷵻�Null
template<typename T>
TreeNode<T>* Tree<T>::getNextSibling(TreeNode<T>* t)
{
	return t->getRightSibling();
}
//�ڽڵ�t�²���һ���ӽڵ�n
template<typename T>
void Tree<T>::insertChild(TreeNode<T>* t, TreeNode<T>* n)
{
	if (t->getLeftChild() == NULL)
		t->setLeftChild(n);
	else
	{
		TreeNode<T>* p = t->getLeftChild();
		while (p->getRightSibling() != NULL)
			p = p->getRightSibling();
		p->setRightSibling(n);
	}
}

template<typename T>
void Tree<T>::deleteSubTree(TreeNode<T>* t)//ɾ����t�ڵ�Ϊ��������
{
	delete t;
}
template<typename T>
bool Tree<T>::isEmpty()//�ж��Ƿ�Ϊ����
{
	if (root == NULL)
		return true;
	else
		return false;
}


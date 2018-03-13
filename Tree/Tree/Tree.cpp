#include"Tree.h"
template<typename T>
Tree<T>::Tree()
{
	root = NULL;
	parent = NULL;
}

template<typename T>
Tree<T>::Tree(TreeNode<T>* rt)//构造函数，生成树的结构
{
	root = rt;
	parent = NULL;
}

template<typename T>
Tree<T>::~Tree()
{

}

template<typename T>
TreeNode<T>* Tree<T>::getRoot()//返回树的根节点，若为空树，则返回Null
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
//返回节点current的父节点，如果节点是根节点，则返回Null
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
//返回节点t的第一个子节点，若无则返回Null
template<typename T>
TreeNode<T>* Tree<T>::getFirstChild(TreeNode<T>* t)
{
	return t->getLeftChild();
}
//返回节点t的下一个兄弟节点，若无则返回Null
template<typename T>
TreeNode<T>* Tree<T>::getNextSibling(TreeNode<T>* t)
{
	return t->getRightSibling();
}
//在节点t下插入一个子节点n
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
void Tree<T>::deleteSubTree(TreeNode<T>* t)//删除以t节点为根的子树
{
	delete t;
}
template<typename T>
bool Tree<T>::isEmpty()//判断是否为空树
{
	if (root == NULL)
		return true;
	else
		return false;
}


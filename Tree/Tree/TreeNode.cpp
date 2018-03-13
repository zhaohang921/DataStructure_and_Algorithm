#include"TreeNode.h"

template<typename T>
TreeNode<T>::TreeNode() {}

template<typename T>
TreeNode<T>::TreeNode(const T& a)
{
	m_value = a;
	leftChild = rightSibling = nullptr;
}

template<typename T>
TreeNode<T>::~TreeNode() {}//析构函数

template<typename T>
bool TreeNode<T>::isLeaf()//是否是叶子节点
{
	if (leftChild == NULL)
		return true;
	else
		return false;
}

template<typename T>
T TreeNode<T>::getValue()
{
	return m_value;
}

template<typename T>
TreeNode<T>* TreeNode<T>::getLeftChild()
{
	return leftChild;
}

template<typename T>
TreeNode<T>* TreeNode<T>::getRightSibling()
{
	return rightSibling;
}

template<typename T>
void TreeNode<T>::setValue(T& value)//设置该节点值
{
	m_value = value;
}

template<typename T>
void TreeNode<T>::setLeftChild(TreeNode<T>* pLeftChild)//设置该节点的最左子节点
{
	leftChild = pLeftChild;
}

template<typename T>
void TreeNode<T>::setRightSibling(TreeNode<T>* pRightSibling)//设置该节点的右兄弟节点
{
	rightSibling = pRightSibling;
}
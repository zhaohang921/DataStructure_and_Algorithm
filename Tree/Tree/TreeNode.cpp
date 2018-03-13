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
TreeNode<T>::~TreeNode() {}//��������

template<typename T>
bool TreeNode<T>::isLeaf()//�Ƿ���Ҷ�ӽڵ�
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
void TreeNode<T>::setValue(T& value)//���øýڵ�ֵ
{
	m_value = value;
}

template<typename T>
void TreeNode<T>::setLeftChild(TreeNode<T>* pLeftChild)//���øýڵ�������ӽڵ�
{
	leftChild = pLeftChild;
}

template<typename T>
void TreeNode<T>::setRightSibling(TreeNode<T>* pRightSibling)//���øýڵ�����ֵܽڵ�
{
	rightSibling = pRightSibling;
}
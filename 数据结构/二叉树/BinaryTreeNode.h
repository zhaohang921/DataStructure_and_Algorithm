#pragma once
#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
//�������Ľڵ���

template<typename T>
class BinaryTreeNode
{
public:

	T element; //����Ԫ��
	BinaryTreeNode<T> *leftChild;     //ָ�����ӽڵ��ָ��
	BinaryTreeNode<T> *rightChild;   //ָ���Һ��ӽڵ��ָ��

	//Ĭ�Ϲ��캯�������������Ĺ��캯������Ĭ�Ϲ��캯��
	BinaryTreeNode() {
		leftChild = rightChild = nullptr;
	}
	//��ʼ��element��ָ����Ϊ��
	BinaryTreeNode(const T& theElement) : element(theElement){
		leftChild = rightChild = nullptr;
	}
	//��ʼ��element�Լ�ָ����
	BinaryTreeNode(const T& theElement, BinaryTreeNode *theLeftChild, BinaryTreeNode *theRightChild) : element(theElement){
		leftChild = theLeftChild;
		rightChild = theRightChild;
	}
};
#endif
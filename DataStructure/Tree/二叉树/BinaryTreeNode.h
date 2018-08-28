#pragma once
#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
//二叉树的节点类

template<typename T>
class BinaryTreeNode
{
public:

	T element; //数据元素
	BinaryTreeNode<T> *leftChild;     //指向左孩子节点的指针
	BinaryTreeNode<T> *rightChild;   //指向右孩子节点的指针

	//默认构造函数，不带参数的构造函数就是默认构造函数
	BinaryTreeNode() {
		leftChild = rightChild = nullptr;
	}
	//初始化element，指针域为空
	BinaryTreeNode(const T& theElement) : element(theElement){
		leftChild = rightChild = nullptr;
	}
	//初始化element以及指针域
	BinaryTreeNode(const T& theElement, BinaryTreeNode *theLeftChild, BinaryTreeNode *theRightChild) : element(theElement){
		leftChild = theLeftChild;
		rightChild = theRightChild;
	}
};
#endif
#pragma once
#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H
#include"BinaryTree.h"
#include"BinaryTreeNode.h"
#include <iostream>
#include "ArrayQueue.h"
#include "MyExceptions.h"


//����ʵ�ֵĶ�����
template<typename E>
class LinkedBinaryTree : public BinaryTree<BinaryTreeNode<E> >
{
public:
	LinkedBinaryTree();
	~LinkedBinaryTree();
	virtual bool empty() const override;
	virtual int size() const override;
	virtual void preOrder(void(*theVisit) (BinaryTreeNode<E>*)) override;
	virtual void inOrder(void(*theVisit) (BinaryTreeNode<E>*)) override;
	virtual void postOrder(void(*theVisit) (BinaryTreeNode<E>*)) override;
	virtual void levelOrder(void(*theVisit) (BinaryTreeNode<E>*)) override;
	void erase();
	void preOrderOutput();//��ǰ������������ڵ�
	void inOrderOutput();
	int height() const;  //ȷ���������߶�
protected:
	BinaryTreeNode<E> *root;             //ָ�����ָ��
	int treeSize;                                    //�������Ľڵ����
	static void(*visit)(BinaryTreeNode<E> *); //���ʺ���
	static void preOrder(BinaryTreeNode<E> *t);
	static void inOrder(BinaryTreeNode<E> *t);
	static void postOrder(BinaryTreeNode<E> *t);
	static void dispose(BinaryTreeNode<E> *t);//ɾ���ڵ�
	static void output(BinaryTreeNode<E> *t);//����ڵ�element����
	static int height(BinaryTreeNode<E> *t);//���ظ�Ϊ*t�����ĸ߶�
};
#endif 

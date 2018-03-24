#pragma once
#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H
#include"BinaryTree.h"
#include"BinaryTreeNode.h"
#include <iostream>
#include "ArrayQueue.h"
#include "MyExceptions.h"


//链表实现的二叉树
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
	void preOrderOutput();//按前序输出二叉树节点
	void inOrderOutput();
	int height() const;  //确定二叉树高度
protected:
	BinaryTreeNode<E> *root;             //指向根的指针
	int treeSize;                                    //二叉树的节点个数
	static void(*visit)(BinaryTreeNode<E> *); //访问函数
	static void preOrder(BinaryTreeNode<E> *t);
	static void inOrder(BinaryTreeNode<E> *t);
	static void postOrder(BinaryTreeNode<E> *t);
	static void dispose(BinaryTreeNode<E> *t);//删除节点
	static void output(BinaryTreeNode<E> *t);//输出节点element数据
	static int height(BinaryTreeNode<E> *t);//返回根为*t的树的高度
};
#endif 

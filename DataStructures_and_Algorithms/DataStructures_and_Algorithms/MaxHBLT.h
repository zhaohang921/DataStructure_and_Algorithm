#pragma once
#ifndef MAXHBLT_H
#define MAXHBLT_H
#include"MaxPriorityQueue.h"
#include"LinkedBinaryTree.h"
#include"BinaryTreeNode.h"
#include"MyExceptions.h"
#include<sstream>
using namespace std;

//最大高度优先左高树
template<typename T>
class MaxHBLT : public MaxPriorityQueue<T>,
						 public LinkedBinaryTree<pair<int,T>>
{
public:
	MaxHBLT() {}
	~MaxHBLT() {}
	virtual bool empty() const override;
	virtual int size() const override;
	virtual const T& top() override;
	virtual void pop() override;//删除
	virtual void push(const T& theElement) override;//插入
	void initialize(T *theElements, int theSize);//初始化
	void meld(MaxHBLT<T>& theHBLT);//合并，调用私有成员
	void output();
private:
	//pair的第一个成员是节点的s值，第二个成员是优先级队列元素
	void meld(BinaryTreeNode<pair<int, T>>* &x, BinaryTreeNode<pair<int, T>>* &y);
	static void HBLTOutput(BinaryTreeNode<pair<int, T>> *t);
};
#endif

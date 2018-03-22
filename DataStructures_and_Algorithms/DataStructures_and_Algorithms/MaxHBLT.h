#pragma once
#ifndef MAXHBLT_H
#define MAXHBLT_H
#include"MaxPriorityQueue.h"
#include"LinkedBinaryTree.h"
#include"BinaryTreeNode.h"
#include"MyExceptions.h"
#include<sstream>
using namespace std;

//���߶����������
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
	virtual void pop() override;//ɾ��
	virtual void push(const T& theElement) override;//����
	void initialize(T *theElements, int theSize);//��ʼ��
	void meld(MaxHBLT<T>& theHBLT);//�ϲ�������˽�г�Ա
	void output();
private:
	//pair�ĵ�һ����Ա�ǽڵ��sֵ���ڶ�����Ա�����ȼ�����Ԫ��
	void meld(BinaryTreeNode<pair<int, T>>* &x, BinaryTreeNode<pair<int, T>>* &y);
	static void HBLTOutput(BinaryTreeNode<pair<int, T>> *t);
};
#endif

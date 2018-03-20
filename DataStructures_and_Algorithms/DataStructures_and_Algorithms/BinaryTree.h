#pragma once
#ifndef BINARY_H
#define BINARY_H

//������������
template<typename T>
class BinaryTree
{
public:
	virtual ~BinaryTree() {}
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual void preOrder(void (*) (T *)) = 0;
	virtual void inOrder(void (*) (T *)) = 0;
	virtual void postOrder(void (*) (T *)) = 0;
	virtual void levelOrder(void(*) (T *)) = 0;
};
#endif
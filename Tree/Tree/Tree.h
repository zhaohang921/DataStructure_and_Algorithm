#pragma once
#ifndef TREE_H
#define TREE_H
#include"TreeNode.h"
template<typename T>
class Tree
{
private:
	TreeNode<T>* root, *parent;
	int getParent(TreeNode<T>* t, TreeNode<T>* p);
public:
	Tree();
	Tree(TreeNode<T>* rt);//���캯�����������Ľṹ
	~Tree();

	TreeNode<T>* getRoot();//�������ĸ��ڵ㣬��Ϊ�������򷵻�Null
	//���ؽڵ�current�ĸ��ڵ㣬����ڵ��Ǹ��ڵ㣬�򷵻�Null
	TreeNode<T>* Parent(TreeNode<T>* current);
	//���ؽڵ�t�ĵ�һ���ӽڵ㣬�����򷵻�Null
	TreeNode<T>* getFirstChild(TreeNode<T>* t);
	//���ؽڵ�t����һ���ֵܽڵ㣬�����򷵻�Null
	TreeNode<T>* getNextSibling(TreeNode<T>* t);
	//�ڽڵ�t�²���һ���ӽڵ�n
	void insertChild(TreeNode<T>* t, TreeNode<T>* n);

	void deleteSubTree(TreeNode<T>* t);//ɾ����t�ڵ�Ϊ��������
	bool isEmpty();//�ж��Ƿ�Ϊ����
};

#endif
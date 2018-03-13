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
	Tree(TreeNode<T>* rt);//构造函数，生成树的结构
	~Tree();

	TreeNode<T>* getRoot();//返回树的根节点，若为空树，则返回Null
	//返回节点current的父节点，如果节点是根节点，则返回Null
	TreeNode<T>* Parent(TreeNode<T>* current);
	//返回节点t的第一个子节点，若无则返回Null
	TreeNode<T>* getFirstChild(TreeNode<T>* t);
	//返回节点t的下一个兄弟节点，若无则返回Null
	TreeNode<T>* getNextSibling(TreeNode<T>* t);
	//在节点t下插入一个子节点n
	void insertChild(TreeNode<T>* t, TreeNode<T>* n);

	void deleteSubTree(TreeNode<T>* t);//删除以t节点为根的子树
	bool isEmpty();//判断是否为空树
};

#endif
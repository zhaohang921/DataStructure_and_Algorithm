#pragma once
#ifndef TREENODE_H
#define TREENODE_H

template<typename T>
class TreeNode
{
private:
	T m_value;
	TreeNode<T> * leftChild;
	TreeNode<T> * rightSibling;
public:
	TreeNode();
	TreeNode(const T&);//构造函数
	~TreeNode();//析构函数

	bool isLeaf();//是否是叶子节点
	T getValue();
	TreeNode<T>* getLeftChild();
	TreeNode<T>* getRightSibling();

	void setValue(T& value);//设置该节点值

	//设置该节点的最左子节点
	void setLeftChild(TreeNode<T>* pLeftChild);
	//设置该节点的右兄弟节点
	void setRightSibling(TreeNode<T>* pRightSibling);


};

#endif

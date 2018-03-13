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
	TreeNode(const T&);//���캯��
	~TreeNode();//��������

	bool isLeaf();//�Ƿ���Ҷ�ӽڵ�
	T getValue();
	TreeNode<T>* getLeftChild();
	TreeNode<T>* getRightSibling();

	void setValue(T& value);//���øýڵ�ֵ

	//���øýڵ�������ӽڵ�
	void setLeftChild(TreeNode<T>* pLeftChild);
	//���øýڵ�����ֵܽڵ�
	void setRightSibling(TreeNode<T>* pRightSibling);


};

#endif

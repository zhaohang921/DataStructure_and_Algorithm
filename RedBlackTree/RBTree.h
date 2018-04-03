#ifndef RBTREE_H
#define RBTREE_H
#include<iostream>
#include<iomanip>
using namespace std;

enum RBTColor{ RED , BLACK };

template<typename T>
class RBTNode 
{
public:
    RBTNode(){}; //默认构造函数
    RBTNode(T value,RBTColor c,RBTNode *p,RBTNode *l,RBTNode *r):key(value),color(c),parent(p),left(l),right(r){}
public:
    T key;            //节点关键字
    RBTColor color;   //节点颜色
    RBTNode *parent;  //父节点
    RBTNode *left;    //左孩子
    RBTNode *right;   //右孩子
};

template<typename T>
class RBTree
{
public: //外部接口
    RBTree():Root(nullptr){} //默认构造函数
    ~RBTree(); //默认析构函数
    void preOrder(); //前序遍历的外部接口
    void inOrder(); //中序遍历的外部接口
    void postOrder(); //后序遍历的外部接口
    RBTNode<T>* search(T key); //非递归实现的查找关键字为key的节点
    RBTNode<T>* iterativeSearch(T key);//递归实现的查找
    T minimum(); //查找最小节点，返回最小节点的关键字
    T maximum(); //查找最大节点，返回最大节点的关键字
    RBTNode<T>* successor(RBTNode<T> *x); //寻找节点x的后继节点（关键字大于该节点的最小节点）
    RBTNode<T>* predecessor(RBTNode<T> *x); //寻找节点x的前驱节点（关键字小于该节点的最小节点）
    void insert(T key); //插入节点，关键字key
    void remove(T key); //删除关键字为key的节点
    void destroy(); //销毁红黑树
    void print(); //打印红黑树

private: //内部接口
    void preOrder(RBTNode<T> *tree) const; //前序遍历的内部实现函数
    void inOrder(RBTNode<T> *tree) const; //中序遍历的内部实现函数
    void postOrder(RBTNode<T> *tree) const; //后序遍历的内部实现函数
    RBTNode<T>* search(RBTNode<T>* x,T key) const; //非递归search的内部实现函数
    RBTNode<T>* iterativeSearch(RBTNode<T>* x,T key) const; //递归iterativeSearch的内部实现函数
    RBTNode<T>* minimum(RBTNode<T> *tree); //minimum的内部实现函数
    RBTNode<T>* maximum(RBTNode<T> *tree); //maximum的内部实现函数
    void insert(RBTNode<T>* &root,RBTNode<T>* node); //insert的内部实现函数
    void remove(RBTNode<T>* &root,RBTNode<T> *node); //remove的内部实现函数
    void destroy(RBTNode<T>* &tree); //destroy的内部实现函数
    void print(RBTNode<T> *tree,T key,int direction); //print的内部实现函数
    void leftRotate(RBTNode<T>* &root,RBTNode<T>* x); //左旋
    void rightRotate(RBTNode<T>* &root,RBTNode<T>* x); //右旋
    void insertFixUp(RBTNode<T>* &root,RBTNode<T>* node); //插入修正函数
    void removeFixUp(RBTNode<T>* &root,RBTNode<T>* node,RBTNode<T>* parent); //删除修正函数

private:
    RBTNode<T> *Root;   //根结点

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)


};
#endif
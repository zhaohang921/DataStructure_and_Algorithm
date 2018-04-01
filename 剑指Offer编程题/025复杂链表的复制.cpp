// 题目描述
// 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
// 另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
// （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）



struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};


//思路一：递归，但是不通过
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==nullptr)
            return nullptr;
        RandomListNode *pNewHead=new RandomListNode(pHead->label);
        pNewHead->next = pHead->next;
        pNewHead->random=pHead->random;
        pNewHead->next=Clone(pHead->next);
        return pNewHead;
    }
};

//思路二：三步法
//第一步：复制节点，每个节点接在原来节点后面
//第二步：复制随机节点，新节点的随机节点就在旧的节点的随机节点的下一个
//第三步，拆分出新的链表
//注意：
//头节点不能改变，一定要用新的指针指向头节点，不然这个链表头就再也回不去了

class Solution {
public:
    void CloneNodes(RandomListNode* pHead)
    {
        RandomListNode* newNode=pHead;
       
        while(newNode!=nullptr)
        {
            RandomListNode* pClone=new RandomListNode(0);
            pClone->label=newNode->label;
            pClone->next=newNode->next;
            pClone->random=nullptr;
            newNode->next=pClone;
            newNode=pClone->next;
        }
    }
    void ConnectRandomNodes(RandomListNode* pHead)
    {
        RandomListNode* newNode=pHead;
        while(newNode!=nullptr)
        {
            RandomListNode* pCloned=newNode->next;
            if(newNode->random!=NULL)
                pCloned->random=newNode->random->next;
            newNode=pCloned->next;
        }
    }
    RandomListNode* splitNewList(RandomListNode* pHead)
    {
        if(pHead==nullptr)
            return nullptr;
        RandomListNode* newNode=pHead;
        RandomListNode* newListHead=newNode->next;
        RandomListNode* newListNode=newNode->next;
        newNode->next=newListNode->next;
        newNode=newNode->next;
        while(newNode!=nullptr)
        {
            newListNode->next=newNode->next;
            newListNode=newListNode->next;
            newNode->next=newListNode->next;
            newNode=newNode->next;
        }
        return newListHead;
    }
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return splitNewList(pHead);
    }
};

#include<unorderd_map>
//思路三：哈希表法
class Solution{
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if(pHead==nullptr)
            return nullptr;
        //定义一个无序的允许重复关键字的map，使用的是哈希技术
        unordered_multimap<RandomListNode* ,RandomListNode* > table;
        //new一个新的头节点
        RandomListNode* pClonedHead=new RandomListNode(pHead->label);
        pClonedHead->next=nullptr;
        pClonedHead->random=nullptr;

        table.insert(make_pair(pHead,pClonedHead));

        RandomListNode* pNode=pHead->next;
        RandomListNode* pClonedNode=pClonedHead;

        while(pNode!=nullptr)
        {
            RandomListNode* pClonedTail=new RandomListNode(pNode->label);
            pClonedTail->next=nullptr;
            pClonedTail->random=nullptr;

            pClonedNode->next=pClonedTail;
            pClonedNode=pClonedTail;

            table.insert(make_pair(pNode,pClonedTail));

            pNode=pNode->next;
        }
        pNode=pHead;
        pClonedNode=pClonedHead;
        while(pNode!=nullptr)
        {
            if(pNode->random!=nullptr)
                //table里面存放的元素的first是原来链表的节点，second是新的链表中对应的节点
                pClonedNode->random=table.find(pNode->random)->second;
            pNode=pNode->next;
            pClonedNode=pClonedNode->next;
        }
        return pClonedHead;
    }
};


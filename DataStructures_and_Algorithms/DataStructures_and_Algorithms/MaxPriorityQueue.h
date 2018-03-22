#ifndef MAXPRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_H

//最大优先级队列抽象类
template<typename T>
class MaxPriorityQueue
{
public:
	virtual MaxPriorityQueue() {}
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual const T& top() = 0;//返回优先级最大的元素的引用
	virtual void pop() = 0;//删除队首元素，也就是优先级最大的元素
	virtual push(const T& theElement) = 0;//插入元素theELement
};
#endif
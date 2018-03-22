#ifndef MAXPRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_H

//������ȼ����г�����
template<typename T>
class MaxPriorityQueue
{
public:
	virtual MaxPriorityQueue() {}
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual const T& top() = 0;//�������ȼ�����Ԫ�ص�����
	virtual void pop() = 0;//ɾ������Ԫ�أ�Ҳ�������ȼ�����Ԫ��
	virtual push(const T& theElement) = 0;//����Ԫ��theELement
};
#endif
#include"MaxHeap.h"

template<typename T>
MaxHeap<T>::MaxHeap(int initialCapacity)
{
	if (init < 1)
	{
		ostringstream s;
		s << "Initial capacity=" << initialCapacity << "Must be >0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity + 1;
	heap = new T[arrayLength];
	heapSize = 0;
}

template<typename T>
MaxHeap<T>::~MaxHeap()
{
	delete[] heap;
}

template<typename T>
bool MaxHeap<T>::empty() const
{
	return heapSize == 0;
}

template<typename T>
int MaxHeap<T>::size() const
{
	return heapSize;
}

template<typename T>
const T & MaxHeap<T>::top()
{
	if (heapSize == 0)
		throw queueEmpty();
	return heap[1];
}

//删除队首元素，也就是优先级最大的元素，也就是大根堆根节点的元素
template<typename T>
void MaxHeap<T>::pop()
{
	if (heapSize == 0)
		throw queueEmpty();
	heap[1].~T();//删除根节点的元素
	T lastElement = heap[heapSize--];
	//从根开始，为最后一个元素寻找位置
	int currentNode = 1, child = 2;//currentNode是根节点，child是currentNode的第一个孩子
	while (child <= heapSize)
	{
		//找到currentNode的有最大元素的子节点
		if (child < heapSize && heap[child] < heap[child + 1])
			child++;
		//如果最后一个元素比currentNode最大的孩子节点的元素还大，就退出循环
		if (lastElement >= heap[child])
			break;
		//如果如果最后一个元素比currentNode最大的孩子节点的元素小，就向下移动一层为最后一个元素寻找位置
		heap[currentNode] = heap[child];
		currentNode = child;
		child *= 2;
	}
	//将最后一个元素放在currentNode的位置
	heap[currentNode] = lastElement;
}

template<typename T>
void MaxHeap<T>::push(const T & theElement)
{
	//必要时增加数组长度
	if (heapSize == arrayLength - 1)
	{
		changeLength1D(heap, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	//为元素theElement寻找插入的位置
	//currentNode从新叶节点向上移动
	int currentNode = ++heapSize;
	//新插入的元素比当前节点的父节点的元素大
	while (currentNode != 1 && heap[currentNode / 2] < theElement)
	{
		heap[currentNode] = heap[currentNode / 2];//父节点的元素向下移动
		currentNode /= 2;         //当前节点移向双亲
	}
	heap[currentNode] = theElement;
}

template<typename T>
void MaxHeap<T>::initialize(T * theHeap, int theSize)
{
	//再数组theHeap中建大根堆，令heap指向数组theHeap
	delete[] heap;
	heap = theHeap;
	heapSize = theSize;
	//从最后一个具有孩子的节点开始到根节点进行扫描,root表示当前在处理的节点，
	for (int root = heapSize / 2; root >= 1; root--)
	{
		T rootElement = heap[root];
		int child = 2 * root;
		//对于每一个root，while循环将其子树调整为大根堆
		while (child <= heapSize)
		{
			//找到子节点中最大的
			if (child < heapSize && heap[child] < heap[child + 1])
				child++;
			//如果当前节点元素比子节点中最大的元素还大，就跳出循环，将当前节点的值给子节点的父节点
			if (rootElement >= heap[child])
				break;
			//孩子上移
			heap[child / 2] = heap[child];
			//移到下一层继续循环
			child *= 2;
		}
		heap[child / 2] = rootElement;
	}
}

template<typename T>
void MaxHeap<T>::deactiveArray()
{
	heap = nullptr;
	arrayLength = heapSize = 0;
}

template<typename T>
void MaxHeap<T>::output(ostream & out) const
{
	copy(heap + 1, heap + heapSize + 1, ostream_iterator<T>(cout, " "));
}

template<typename T>
ostream & operator<<(ostream & out, const MaxHeap<T>& x)
{
	x.output(out);
	return out;
}

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

//ɾ������Ԫ�أ�Ҳ�������ȼ�����Ԫ�أ�Ҳ���Ǵ���Ѹ��ڵ��Ԫ��
template<typename T>
void MaxHeap<T>::pop()
{
	if (heapSize == 0)
		throw queueEmpty();
	heap[1].~T();//ɾ�����ڵ��Ԫ��
	T lastElement = heap[heapSize--];
	//�Ӹ���ʼ��Ϊ���һ��Ԫ��Ѱ��λ��
	int currentNode = 1, child = 2;//currentNode�Ǹ��ڵ㣬child��currentNode�ĵ�һ������
	while (child <= heapSize)
	{
		//�ҵ�currentNode�������Ԫ�ص��ӽڵ�
		if (child < heapSize && heap[child] < heap[child + 1])
			child++;
		//������һ��Ԫ�ر�currentNode���ĺ��ӽڵ��Ԫ�ػ��󣬾��˳�ѭ��
		if (lastElement >= heap[child])
			break;
		//���������һ��Ԫ�ر�currentNode���ĺ��ӽڵ��Ԫ��С���������ƶ�һ��Ϊ���һ��Ԫ��Ѱ��λ��
		heap[currentNode] = heap[child];
		currentNode = child;
		child *= 2;
	}
	//�����һ��Ԫ�ط���currentNode��λ��
	heap[currentNode] = lastElement;
}

template<typename T>
void MaxHeap<T>::push(const T & theElement)
{
	//��Ҫʱ�������鳤��
	if (heapSize == arrayLength - 1)
	{
		changeLength1D(heap, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	//ΪԪ��theElementѰ�Ҳ����λ��
	//currentNode����Ҷ�ڵ������ƶ�
	int currentNode = ++heapSize;
	//�²����Ԫ�رȵ�ǰ�ڵ�ĸ��ڵ��Ԫ�ش�
	while (currentNode != 1 && heap[currentNode / 2] < theElement)
	{
		heap[currentNode] = heap[currentNode / 2];//���ڵ��Ԫ�������ƶ�
		currentNode /= 2;         //��ǰ�ڵ�����˫��
	}
	heap[currentNode] = theElement;
}

template<typename T>
void MaxHeap<T>::initialize(T * theHeap, int theSize)
{
	//������theHeap�н�����ѣ���heapָ������theHeap
	delete[] heap;
	heap = theHeap;
	heapSize = theSize;
	//�����һ�����к��ӵĽڵ㿪ʼ�����ڵ����ɨ��,root��ʾ��ǰ�ڴ���Ľڵ㣬
	for (int root = heapSize / 2; root >= 1; root--)
	{
		T rootElement = heap[root];
		int child = 2 * root;
		//����ÿһ��root��whileѭ��������������Ϊ�����
		while (child <= heapSize)
		{
			//�ҵ��ӽڵ�������
			if (child < heapSize && heap[child] < heap[child + 1])
				child++;
			//�����ǰ�ڵ�Ԫ�ر��ӽڵ�������Ԫ�ػ��󣬾�����ѭ��������ǰ�ڵ��ֵ���ӽڵ�ĸ��ڵ�
			if (rootElement >= heap[child])
				break;
			//��������
			heap[child / 2] = heap[child];
			//�Ƶ���һ�����ѭ��
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

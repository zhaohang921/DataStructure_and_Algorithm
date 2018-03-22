/*����N���������Ԫ������ʼ��һ������ѣ�
Ȼ��Ӷ��������ȡԪ�أ���Ϊ�������ÿ����ȡ���Ķ�������Ԫ�أ�
������ȡ����Ԫ�ذ��ǵ���˳�����С�
��ʼ��ʱ��ΪO(n)��ÿ��ɾ����ʱ��ΪO(logn)
�����ʱ��ΪO(nlogn)*/
#include"MaxHeap.h"
using namespace std;

template<typename T>
void HeapSort(T a[], int n)
{//ʹ�ö�����ķ���������a[1:n]����
	MaxHeap<T> heap(1);
	heap.initialize(a, n);
	//����Ӵ��������ȡԪ��
	for (int i = n - 1; i >= 1; i--)
	{
		T x = heap.top();
		heap.pop();
		a[i + 1] = x;
	}
	//�Ӷѵ����������б�������a
	heap.deactiveArray();
}

//#include<iostream>
//#include<algorithm>
//int main(void)
//{
//	int a[11], i, n = 10;
//	// initialize descending data
//	for (i = 1; i <= 10; i++)
//		a[i] = n - i + 1;
//
//	HeapSort(a, 10);
//
//	// output sorted data
//	copy(a, a + n, ostream_iterator<int>(cout, " "));
//	cout << endl;
//	return 0;
//}

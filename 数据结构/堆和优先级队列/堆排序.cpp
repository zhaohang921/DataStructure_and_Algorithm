/*先用N个待排序的元素来初始化一个大根堆，
然后从堆中逐个提取元素，因为大根堆中每次提取出的都是最大的元素，
所以提取出的元素按非递增顺序排列。
初始化时间为O(n)，每次删除的时间为O(logn)
因此总时间为O(nlogn)*/
#include"MaxHeap.h"
using namespace std;

template<typename T>
void HeapSort(T a[], int n)
{//使用堆排序的方法给数组a[1:n]排序
	MaxHeap<T> heap(1);
	heap.initialize(a, n);
	//逐个从大根堆中提取元素
	for (int i = n - 1; i >= 1; i--)
	{
		T x = heap.top();
		heap.pop();
		a[i + 1] = x;
	}
	//从堆的析构函数中保存数组a
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

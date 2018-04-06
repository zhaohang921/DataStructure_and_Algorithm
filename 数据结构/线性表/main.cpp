//#include"List.h"
//
//int main()
//{
//	List<int> listFirst;
//	List<int> listSecond;
//
//	listFirst.AddTail(1);
//	listFirst.AddTail(6);
//	listFirst.AddTail(8);
//	listFirst.AddTail(9);
//	listFirst.AddTail(13);
//
//	listSecond.AddTail(0);
//	listSecond.AddTail(3);
//	listSecond.AddTail(4);
//	listSecond.AddTail(6);
//	listSecond.AddTail(11);
//	listSecond.AddTail(17);
//
//	while (listSecond.GetCount() != 0)
//	{
//		int indexFirst = 0;
//		while (listSecond.GetAt(0) > listFirst.GetAt(indexFirst))
//		{
//			++indexFirst;
//			if (indexFirst == listFirst.GetCount())
//			{
//				break;
//			}
//		}
//		if (indexFirst == listFirst.GetCount())
//		{
//				listFirst.AddTail(listSecond.GetAt(0));
//				listSecond.RemoveAt(0);
//			}
//			else
//			{
//				listFirst.InsertAt(indexFirst, listSecond.GetAt(0));
//				listSecond.RemoveAt(0);
//			}
//	}
//	return 0;
//}
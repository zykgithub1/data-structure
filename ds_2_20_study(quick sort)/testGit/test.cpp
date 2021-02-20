#include <iostream>
#include <stdio.h>
using namespace std;

//冒泡排序
//void burboSort(int arr[],int sz)
//{
//	int bound,exchange;
//	exchange = sz-1;
//	while (exchange)
//	{
//		bound = exchange;
//		exchange = 0;
//		for (int j = 0; j < bound; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				exchange = j;
//			}
//		}
//
//	}
//}
//快速排序
//int postion(int arr[], int first, int end)
//{
//	int i = first; int j = end;
//	while (i < j)
//	{
//		while (i < j&&arr[i] <= arr[j])
//			j--;
//		if (i < j)
//		{
//			int tmp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = tmp;
//			i++;
//		}
//		while (i < j&&arr[i] <= arr[j])
//			i++;
//		if (i < j)
//		{
//			int tmp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = tmp;
//			j--;
//		}
//	}
//	return i;
//}
//void QuickSort(int arr[],int first,int end)
//{
//	
//	if (first < end)
//	{
//		int pos;
//		pos= postion(arr, first, end);
//		QuickSort(arr, first, pos-1);
//		QuickSort(arr, pos+1, end);
//	}
//}
//void selectSort(int arr[], int sz)
//{
//	int i=0,min=999;
//	for (i = 0; i < sz; i++)
//	{
//		for (int j = i; j < sz; j++)
//		{
//			if (min >= arr[j])
//			{
//				min = arr[j];
//			}
//			int tmp = arr[i];
//			arr[i] = min;
//			arr[j] = tmp;
//			min = 999;
//		}
//	}
//}
//选择排序：min为下标
void selectSort1(int arr[], int sz)
{
	int i, min;
	for (i = 0; i < sz; i++)
	{
		min = i;
		for (int j = i + 1; j < sz; j++)
		{
			if (arr[j]<arr[min])
			{
				min = j;
			}
			if (min != i)
			{
				int tmp = arr[i];
				arr[i] = arr[min];
				arr[min] = tmp;
			}
		}
	}
}
int main()
{
	int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	//burboSort(arr,sz);
	//QuickSort(arr,0,sz-1);
	//selectSort(arr, sz);
	selectSort1(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
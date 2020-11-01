#include<stdio.h>


int Search_seq(int *arr, int key,int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}

int Search_bin(int* arr, int key, int size)
{
	int low = 0, high = size - 1,mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == key) return mid;
		else if (arr[mid] > key) high = mid - 1;
		else low = mid + 1;
	}
}
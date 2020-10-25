#include<stdio.h>
void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void display(int* arr,int size) {
	for (int i = 0; i < size; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

void BubbleSort(int* arr, int size)
{
	int tmp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void SelectSort(int* arr, int size)
{
	int i, j, k;
	for (i = 0; i < size - 1; i++)
	{
		k = i;
		for (j = i; j < size; j++)
		{
			if (arr[k] > arr[j])
				k = j;
		}
		swap(&arr[k], &arr[i]);
	}
}
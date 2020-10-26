#include<stdio.h>
void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void display(int* arr,int size) {
	for (int i = 1; i < size; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

void BubbleSort(int* arr, int size)
{
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

void InsertionSort(int* arr, int size)
{
	int i, j, tmp;
	for (i = 1; i < size; i++) 
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp;
	}
}

void ShellSort(int* arr, int size)
{
	int i, j, tmp, increment;
	increment = size / 2;
	for (increment = size / 2; increment > 0; increment = increment / 2)
	{
		for (i = increment; i < size; i++)
		{
			tmp = arr[i];
			for (j = i - increment; j >= 0 && arr[j] > tmp; j -= increment)
			{
				arr[j + increment] = arr[j];
			}
		}
		arr[j + increment] = tmp;
	}
}

void Merge(int* SR, int* TR, int i, int middle, int rightend)
{
	int j, k, l;
	for (k = i, j = middle + 1; i <= middle && j <= rightend; k++)
	{
		if (SR[i] < SR[j])
		{
			TR[k] = SR[i++];
		}else{
			TR[k] = SR[j++];
		}
	}

	if (i <= middle)
	{
		for (l = 0; l <= middle - i; l++)
		{
			TR[k + l] = SR[i + l];
		}
	}
	if (j <= rightend)
	{
		for (l = 0; l <= rightend - j; l++)
		{
			TR[k + l] = SR[j + l];
		}
	}

}
#define MAXSIZE 100  

void MergeSort(int* SR, int* TR1, int s, int t)
{
	int middle;
	int TR2[MAXSIZE + 1];
	//= (int *)malloc(sizeof(int)*50);
	if (s == t)
	{
		TR1[s] = SR[s];
	}
	else
	{
		middle = (s + t) / 2;
		MergeSort(SR, TR2, s, middle);
		MergeSort(SR, TR2, middle + 1, t);
		Merge(TR2, TR1, s, middle, t);
	}
}
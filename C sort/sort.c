#include<stdio.h>
#include<string.h>
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

void QuickSort(int* arr, int maxlen, int begin, int end)
{
	int i, j, tmp;
	if (begin < end)
	{
		i = begin + 1;
		j = end;
		tmp = arr[begin];
		while (i < j)
		{
			if (arr[i] > tmp)
			{
				swap(&arr[i], &arr[j]);
				j--;
			}
			else i++;
		}
		if (arr[i] >= tmp)
		{
			i--;
		}
		swap(&arr[begin], &arr[i]);
		QuickSort(arr, maxlen, begin, i);
		QuickSort(arr, maxlen, j, end);
	}
}

void Heapify(int* arr, int m, int size)
{
	int i, tmp;
	tmp = arr[m];
	for (i = 2 * m; i <= size; i*=2)
	{
		if (i + 1 <= size && arr[i] < arr[i + 1]) i++;
		if (arr[i] < tmp) break;
		arr[m] = arr[i];
		m = i;
	}
	arr[m] = tmp;
}

void BuildHeap(int* arr, int size)
{
	int i;
	for (i = size / 2; i > 0; i--)
	{
		Heapify(arr, i, size);
	}
}

void HeapSort(int* arr, int size)
{
	int i;
	BuildHeap(arr, size);
	for (i = size; i > 1; i--)
	{
		swap(&arr[1], &arr[i]);
		Heapify(arr, 1, i - 1);
	}
}

void CountingSort(int* A, int* B, int n, int k)
{
	int* C = (int*)malloc(sizeof(int) * (k + 1));
	int i;
	for (i = 0; i <= k; i++) {
		C[i] = 0;
	}
	for (i = 0; i <= k; i++)
	{
		C[A[i]]++;
	}
	for (i = 1; i <= k; i++)
	{
		C[i] = C[i] + C[i - 1];
	}
	for (i = n - 1; i >= 0; i--) {
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}

void bucketSort(int* arr, int size, int max)
{
	int i, j;
	int buckets[50];//”¶∏√ «max
	memset(buckets, 0, max * sizeof(int));
	for (i = 0; i < size; i++) {
		buckets[arr[i]]++;
	}
	for (i = 0, j = 0; i < max; i++)
	{
		while ((buckets[i]--) > 0)
		{
			arr[j++] = i;
		}
	}
}


int get_index(int num, int dec, int order)
{
	int i, j, n;
	int index;
	int div;
	for (i = dec; i > order; i--)
	{
		n = 1;
		for (j = 0; j < dec - 1; j++)   n *= 10;
		div = num / n;
		num -= div * n;
		dec--;
	}
	n = 1;
	for (i = 0; i < order - 1; i++) n *= 10;
	index = num / n;
	return index;
}

void RadixSort(int* arr, int len, int dec, int order)
{
	int i, j;
	int index;
	int tmp[50];
	int num[10];
	memset(num, 0, 10 * sizeof(int));
	memset(tmp, 0, 10 * sizeof(int));
	if (dec < order) return;
	for (i = 0; i < len; i++)
	{
		index = get_index(arr[i], dec, order);
		num[index]++;
	}
	for (i = 1; i < 10; i++)
		num[i] += num[i - 1];
	for (i = len - 1; i >= 0; i--)
	{
		index = get_index(arr[i], dec, order);
		j = --num[index];
		tmp[j] = arr[i];
	}

	for (i = 0; i < len; i++) {
		arr[i] = tmp[i];
	}
	RadixSort(arr, len, dec, order + 1);

}
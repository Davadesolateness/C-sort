#include<stdio.h>
#include "sort.h"

int main()
{
	int data[] = { 60,2,97,78,0,84,68,23,48,22,63,31,43,42,82,9,
				57,21,42,62,83,98,64,72,96,31,76,13,70,49,10,60,72,36,
				26,4,56,54,13,9,98,45,61,90,88,80,30,50,77,83,1};
	int size = sizeof(data) / sizeof(int);
	printf("index = %d", get_index(123111, 1, 5));
}
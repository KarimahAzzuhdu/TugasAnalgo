// Quiz ANALGO
// Karimah A.T.M.
// 140810170027

#include<stdlib.h> 
#include<stdio.h> 

void merge(int array[], int left, int mid, int right) 
{ 
	int i, j, k; 
	int n1 = mid - left + 1; 
	int n2 = right - mid; 
	int Kiri[n1], Kanan[n2]; 

	for (i = 0; i < n1; i++) 
		Kiri[i] = array[left + i]; 
	for (j = 0; j < n2; j++) 
		Kanan[j] = array[mid + 1+ j]; 

	i = 0; j = 0; k = left;
	while (i < n1 && j < n2) 
	{ 
		if (Kiri[i] <= Kanan[j]) 
		{ 
			array[k] = Kiri[i]; 
			i++; 
		} 
		else
		{ 
			array[k] = Kanan[j]; 
			j++; 
		} 
		k++; 
	} 
	while (i < n1) 
	{ 
		array[k] = Kiri[i]; 
		i++; 
		k++; 
	} 
	while (j < n2) 
	{ 
		array[k] = Kanan[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(int array[], int left, int right) 
{ 
	if (left < right) 
	{
		int mid = left+(right-left)/2; 
		mergeSort(array, left, mid); 
		mergeSort(array, mid+1, right); 
		merge(array, left, mid, right); 
	} 
} 

void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

int main() 
{ 
	int array[] = {12, 11, 13, 5, 6, 7}; 
	int arr_size = sizeof(array)/sizeof(array[0]); 

	printf("Array yang belum terurut : \n"); 
	printArray(array, arr_size); 

	mergeSort(array, 0, arr_size - 1); 

	printf("\nArray yang terurut : \n"); 
	printArray(array, arr_size); 
	return 0; 
} 

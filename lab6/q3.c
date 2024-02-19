//merge sort
#include<stdio.h>
#include<stdlib.h>
int opcount = 0;
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
			opcount ++;
		}
		else {
			arr[k] = R[j];
			j++;
			opcount++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
		opcount++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
		opcount++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void print_array(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
int main()
{
	printf("Enter the no of elements in the array\n");
    int n;
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Original array : \n");
    print_array(a,n);
    
    mergeSort(a,0,n-1);
    
    printf("Sorted array : \n");
    print_array(a,n);
    printf("Opcount : %d",opcount);
    return 0;
}

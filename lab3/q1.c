#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int a[],int n){
	int opcount = 0;
	for(int i=0;i<=n-2;i++){
		for(int j=0;j<=n-2-i;j++){
			opcount++;
			if(a[j+1]<a[j]){
				opcount++;
				int temp = a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\nOpcount : %d\n",opcount);
}
int main(){
	printf("Enter the no of integers in the array :\n ");
	int n ;
	scanf("%d",&n);
	printf("Enter the elements of the array\n");
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Before Sorting : \n");
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\nAfter bubble sort :\n");
	bubble_sort(a,n);
	return 0;
}
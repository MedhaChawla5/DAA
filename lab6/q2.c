#include<stdio.h>
#include<stdlib.h>
int opcount=0;
int partition(int a[] , int l , int r){
    int pivot = a[l];
    int i = l+1;
    int j = r;
    while(i<=j){
    while(a[i]<=pivot && i <=r){
        i++;
        opcount++;
    }
    while(a[j]>pivot && j>=l){
        j--;
        opcount++;
    }
    if(i<j){
        opcount++;
        int temp = a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    else{
        opcount++;
        int temp = a[l];
        a[l]=a[j];
        a[j]=temp;
        return j;
    }
    }
}
void quicksort(int a[] , int l , int r){
    if(l<r){
        int pivot_index = partition(a,l,r);
        quicksort(a,l,pivot_index-1);
        quicksort(a,pivot_index+1,r);
    }
}
void print_array(int a[] , int n ){
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

int main(){
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
    
    quicksort(a,0,n-1);
    
    printf("Sorted array : \n");
    print_array(a,n);
    printf("Opcount : %d",opcount);
    return 0;
}

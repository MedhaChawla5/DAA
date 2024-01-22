//selection sort with opcount 
#include<stdio.h>
#include<stdlib.h>
void selection_sort(int a[],int n){
    int opcount = 0 ;
    for(int i=0;i<=n-2;i++){
        int min = a[i];
        for(int j=i+1;j<=n-1;j++){
            opcount++;
            if(a[j]<a[i]){
                int temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\nOpcount : %d",opcount);
}
int main(){
    printf("Enter no of elements ");
    int n ; 
    scanf("%d",&n);
    printf("Enter the elements ");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Before sorting : ");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("After sorting : ");
    selection_sort(arr,n);
    return 0;
}
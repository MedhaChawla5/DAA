/*Write a program to sort set of integers using bubble sort. Analyze its time 
efficiency. Obtain the experimental result of order of growth. Plot the result for 
the best and worst case.*/ 
void bubble_sort(int a[],int n){
    int opcount =0;
    for(int i=0;i<=n-2;i++){
        for(int j=0;j<=n-2-i;j++){
            opcount++;
            if(a[j+1]<a[j]){
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
            printf("%d\t",a[i]);
        }
    printf("\nOpcount : %d ",opcount);
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
    bubble_sort(arr,n);
    return 0;
}
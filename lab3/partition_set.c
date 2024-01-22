/*Write a program to implement solution to partition problem using brute-force 
technique and analyze its time efficiency theoretically. A partition problem takes 
a set of numbers and finds two disjoint sets such that the sum of the elements in 
the first set is equal to the second set. [Hint: You may generate power set] */
#include <stdio.h>
#include <math.h>

void printPowerSet(int set[], int n) {
    int powSetSize = pow(2, n);
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum = sum+set[i];
    }
    printf("Sum of elements of parent array : %d\n",sum);

    for (int counter = 0; counter < powSetSize; counter++) {
        int sumx = 0;
        for (int j = 0; j < n; j++) {
            if (counter & (1 << j))
                sumx=sumx+set[j];
        }
        if(sumx==sum/2){
            printf("{\t");
            for(int j=0;j<n;j++){
                if(counter & (1<<j)){
                    printf("%d\t",set[j]);
                }
            }
            printf("}\n");
        }
    }
}

int main() {
    int set[] = {1, 2, 3,4,5,6,7};
    int n = sizeof(set) / sizeof(set[0]);

    printf("Power set of the given array:\n");
    printPowerSet(set, n);

    return 0;
}

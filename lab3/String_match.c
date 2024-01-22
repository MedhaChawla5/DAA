/*Write a program to implement brute-force string matching. Analyze time 
efficiency. */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int string_match(char* str,char* pat){
    int opcount = 0;
    int n = strlen(str);
    int m = strlen(pat);
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<m;j++){
            opcount ++;
            if(j==m-1){
                printf("opcount = %d\n",opcount);
                return i;
            }
            if(pat[j]!=str[j+i]){
                break;
            }
        }
    }
    printf("opcount = %d\n",opcount);
    return -1;
}
int main(){
    printf("Enter input string\n");
    char* str[100];
    gets(str);
    printf("Enter a string you want to match\n");
    char* pat[100];
    gets(pat);
    int m = string_match(str,pat);
    printf("Match result : %d",m);
}
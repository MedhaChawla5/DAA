
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int string_match(char* str,char* pat){
    int opcount = -1;
    int n = strlen(str);
    int m = strlen(pat);
    for(int i=0;i<=n-m;i++){
        opcount++;
        for(int j=0;j<m;j++){
            if(j==m-1){
                printf("opcount = %d\n",opcount);
                return i;
            }
            if(pat[j]==str[j+i]){
                opcount++;
                continue;
            }
            else{
                opcount++;
                break;
            }
        }
    }
    printf("opcount = %d\n",opcount);
    return -1;
}
int main(){
    printf("Enter input string\n");
    char str[MAX];
    fgets(str,MAX,stdin);
    printf("Enter a string you want to match\n");
    char pat[MAX];
    fgets(pat,MAX,stdin);
    int m = string_match(str,pat);
    printf("Match result : %d\n",m);
}
#include<stdio.h>
#include<stdlib.h>
int adj[4][4]={
    {0,0,1,0},
    {0,0,0,1},
    {1,0,0,1},
    {0,1,1,0}
};
int visited[4]={0,0,0,0};
int dfs_order[4];
int r=-1;

void dfs(int i){
    visited[i]=1;
    dfs_order[++r]=i;
    for(int j=0;j<4;j++){
        if(visited[j]==0 && adj[i][j]==1){
            dfs(j);
        }
    }
}

void top_order(){
    for(int i=3;i>=0;i--){
        printf("%d",dfs_order[i]);
    }
}
int main(){
    printf("dfs traversal of the given graph is ");
    dfs(1);
    for(int i=0;i<4;i++){
        printf("%d",dfs_order[i]);
    }
    printf("\nTopological oder : ");
    top_order();
    return 0;
}
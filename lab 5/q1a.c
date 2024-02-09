#include<stdio.h>
#include<stdlib.h>
#define n 9

int dfs_order[n];
int r=-1;
int pop_order[n];
int m =-1;
void dfs(int a[n][n] ,int x, int visited[n]){
	dfs_order[++r]=x;
	visited[x]=1;
	for(int i=0;i<n;i++){
		if(a[x][i]==1 && visited[i]==0){
			dfs(a,i,visited);
		}
	}
	pop_order[++m]=x;
}
int main(){
	printf("\nEnter graph as adjacency matrix : \n");
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int visited[n];
	for(int i=0;i<n;i++){
		visited[i]=0;
	}
	printf("\nEnter starting node : \n");
	int x;
	scanf("%d",&x);
	dfs(a,x,visited);
	printf("\nDfs order is : \n");
	for(int i=0;i<n;i++){
		printf("%d\t",dfs_order[i]);
	}
	printf("\nTopological order is : \n");
	for(int i=n-1;i>=0;i--){
		printf("%d\t",pop_order[i]);
	}
}

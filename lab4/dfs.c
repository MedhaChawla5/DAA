#include<stdio.h>
#include<stdlib.h>
int push[9]={0,0,0,0,0,0,0,0,0};
int pop[9]={0,0,0,0,0,0,0,0,0};
int pushit = 0;
int popit = 0;
void dfs(int a[9][9], int n ,int visited[], int x){
	visited[x]=1;
	push[x] = ++pushit;
	printf("%d",x);
	for(int i=0;i<n;i++){
		if(a[x][i]==1 && visited[i]==0){
			dfs(a,n,visited,i);
		}
	}
	pop[x]= ++popit;
}
int main(){
	printf("Enter no of vertices of graph\n");
	int n;
	scanf("%d",&n);
	int visited[9]={0,0,0,0,0,0,0,0,0};
	printf("Enter graph as adjacency matrix\n");
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("Entered adjacency matrix for graph is :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("dfs traversal starting at 0 :");
	int x = 0;
	dfs(a,n,visited,x);
	printf("\nPush order is :\n");
	int y = 0;
	for(int i=0;i<n;i++){
		printf("%d : %d\t",y ,push[i]);
		y++;
	}
	printf("\nPop order is :\n");
	int k = 0;
	for(int i=0;i<n;i++){
		printf("%d : %d\t",k ,pop[i]);
		k++;
	}
	return 0;
}
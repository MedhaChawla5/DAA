//warshalls transitive closure 
#include<stdio.h>
#include<stdlib.h>
#define v 4

int reach[v][v];
int op=0;

void print_sol(){
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			if(i==j){
				printf("1\t");
			}
			else{
				printf("%d\t",reach[i][j]);
			}
		}
		printf("\n");
	}
}

void transitive(int graph[][v]){
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			reach[i][j] = graph[i][j];
		}
	}

	for(int k=0;k<v;k++){
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				op++;
				reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
			}
		}
	}
	print_sol(reach);
}

int main(){
	printf("Enter adj matrix for graph with %d vertices\n",v);
	int graph[v][v];
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	transitive(graph);
	printf("Opcount : %d",op);
}
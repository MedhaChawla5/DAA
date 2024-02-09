#include <stdio.h>
#include <stdlib.h>
# define N 4
int main() {
    int adj[N][N] = {
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 0},
        {1, 0, 0, 0}
    };
    int indeg[N] = {0, 0, 0, 0};
    for (int m = 0; m < N; m++) {
        for (int n = 0; n < N; n++) {
            if (adj[n][m] != 0) {
                indeg[m] = indeg[m] + 1;
            }
        }
    }

    int visited[N] = {0, 0, 0, 0};
    int top_order[N];
    int r = -1;
    int cnt = 0;

    while (cnt < N) {
        int flag = 0;  
        for (int i = 0; i < N; i++) {
            if (indeg[i] == 0 && visited[i] == 0) {
                visited[i] = 1;
                cnt++;
                top_order[++r] = i;
                flag = 1;

                for (int k = 0; k < N; k++) {
                    if (adj[i][k] == 1) {
                        indeg[k] = indeg[k] - 1;
                    }
                }
            }
        }

        if (!flag) {
            printf("Graph contains a cycle.\n");
            break;
        }
    }

    if (cnt == N) {
        printf("Topological order: \n");
        for (int i = 0; i < N; i++) {
            printf("%d ", top_order[i]);
        }
    }
    return 0;
}
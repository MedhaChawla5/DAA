#include <stdio.h>
#include <stdlib.h>

int main() {
    int adj[4][4] = {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0}
    };

    int indeg[4] = {0, 0, 0, 0};
    for (int m = 0; m < 4; m++) {
        for (int n = 0; n < 4; n++) {
            if (adj[n][m] != 0) {
                indeg[m] = indeg[m] + 1;
            }
        }
    }

    int visited[4] = {0, 0, 0, 0};
    int top_order[4];
    int r = -1;
    int cnt = 0;

    while (cnt < 4) {
        int flag = 0;  // Flag to check if any vertex is processed in this iteration
        for (int i = 0; i < 4; i++) {
            if (indeg[i] == 0 && visited[i] == 0) {
                visited[i] = 1;
                cnt++;
                top_order[++r] = i;
                flag = 1;

                for (int k = 0; k < 4; k++) {
                    if (adj[i][k] == 1) {
                        indeg[k] = indeg[k] - 1;
                    }
                }
            }
        }

        if (!flag) {
            // If no vertex is processed in this iteration, there is a cycle
            printf("Graph contains a cycle.\n");
            break;
        }
    }

    if (cnt == 4) {
        printf("Topological order: ");
        for (int i = 0; i < 4; i++) {
            printf("%d ", top_order[i]);
        }
    }

    return 0;
}

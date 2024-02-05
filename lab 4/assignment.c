#include <stdio.h>

#define N 3 // Number of workers and tasks

int costMatrix[N][N] = {
    {2, 7, 5},
    {3, 1, 2},
    {6, 5, 3}
};

int minCost = 99; // Initialize to maximum possible integer

void assignTask(int assignment[], int worker, int totalCost) {
    if (worker == N) {
        // All workers are assigned, check if the cost is minimum
        if (totalCost < minCost) {
            minCost = totalCost;
        }
        return;
    }

    for (int task = 0; task < N; task++) {
        if (assignment[task] == -1) {
            assignment[task] = worker;
            assignTask(assignment, worker + 1, totalCost + costMatrix[worker][task]);
            assignment[task] = -1; // Backtrack
        }
    }
}

int main() {
    int assignment[N];
    for (int i = 0; i < N; i++) {
        assignment[i] = -1; // Initialize assignments to -1 (unassigned)
    }

    assignTask(assignment, 0, 0);

    printf("Minimum Cost: %d\n", minCost);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 10

int n; // Number of agents and tasks
int cost[MAX_N][MAX_N]; // Cost matrix
int assignment[MAX_N]; // Store the assignment

bool rowUsed[MAX_N];
bool colUsed[MAX_N];
int totalCost = INT_MAX; // Initialize with a large value

void branchAndBound(int row, int currentCost) {
    if (row == n) {
        if (currentCost < totalCost) {
            totalCost = currentCost;
            // Store the assignment
            for (int i = 0; i < n; ++i) {
                assignment[i] = colUsed[i];
            }
        }
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (!colUsed[col]) {
            colUsed[col] = true;
            rowUsed[row] = true;

            int reducedCost = currentCost + cost[row][col];
            // Add lower bounds here to prune unnecessary branches

            branchAndBound(row + 1, reducedCost);

            colUsed[col] = false;
            rowUsed[row] = false;
        }
    }
}

int main() {
    printf("Enter the number of agents/tasks: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        rowUsed[i] = false;
        colUsed[i] = false;
        assignment[i] = -1; // Initialize assignments to -1
    }

    branchAndBound(0, 0);

    printf("Minimum cost: %d\n", totalCost);
    printf("Assignment: ");
    for (int i = 0; i < n; ++i) {
        printf("(%d, %d) ", i, assignment[i]);
    }
    printf("\n");

    return 0;
}

#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void permute(int arr[], int start, int end) {
    if (start == end) {
        printf("[");
        for (int i = 0; i <= end; i++) {
            printf("%d", arr[i]);
            if (i < end) {
                printf(", ");
            }
        }
        printf("]\n");
    } else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);
            permute(arr, start + 1, end);
            swap(&arr[start], &arr[i]); // Backtrack
        }
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("All possible permutations:\n");
    permute(arr, 0, n - 1);

    return 0;
}

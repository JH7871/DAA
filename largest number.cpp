#include <stdio.h>

int main() {
    int arr[] = {12, 45, 69, 24, 57, 89, 105, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n == 0) {
        printf("Array is empty, no largest element.\n");
        return 1; // Exit with an error code
    }

    int max = arr[0]; // Assume the first element is the largest

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Update max if a larger element is found
        }
    }

    printf("The largest element in the array is: %d\n", max);

    return 0;
}

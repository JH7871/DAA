#include <stdio.h>
#include <string.h>

int main() {
    char str[100]; // Assuming a maximum string length of 100 characters

    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);

    printf("Reverse of the string: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    printf("\n");

    return 0;
}

#include<stdio.h>
int main()
{
    int num, rem, i;
    printf("Enter any number: ");
    scanf("%d", &num);
    printf("\nFactors of %d:\n", num);
    for(i=1; i<num; i++)
    {
        if(num%i==0)
            printf("%d\n", i);
    }
    return 0;
}
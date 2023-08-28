#include<stdio.h>
int fibonacci (int n)
{
	if (n<=0)
	{
		return 0;
	}
	else if (n==1)
	{
		return 1;
	}
	else
	{
	return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
int main()
{
	int n;
	 printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &n);
	if(n<=0)
	{
		printf("Please enter a positive integer.\n");
	}
	else
	{
		printf("Fibonacci Series:\n");
		for (int i = 0;i<n;i++)
		{
			printf("%d",fibonacci(i));
		}
		printf("\n");
	}
	return 0;
}
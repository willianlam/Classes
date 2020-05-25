#include<stdio.h>

int Josafu(int n)
{
	if (n == 1)
		return 1;
	else if (n % 2 == 0)
		return Josafu(n / 2) * 2 - 1;
	else
		return Josafu(n / 2) * 2 + 1;
}

void main()
{
	int n;
	printf("Enter the number of peoples:");
	scanf("%d", &n);
	printf("The survivor is %d.\n", Josafu(n));
}
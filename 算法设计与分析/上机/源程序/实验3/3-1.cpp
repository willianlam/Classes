#include <stdio.h>
#include <time.h>
#include <stdlib.h>

bool match(int n)
{
	if (n == 0)
	{
		return false;
	}
	else if (n < 5)
	{
		printf("A catches %d.\n", n);
		return true;
	}
	else
	{
		bool r = match(n - 5);
		if (r)
		{
			int B = rand() % 4 + 1;
			int A = 5 - B;
			printf("B catches %d.\nA catches %d.\n", B, A);
		}
		else
		{
			int A = rand() % 4 + 1;
			int B = 5 - A;
			printf("A catches %d.\nB catches %d.\n", A, B);
		}
		return r;
	}
}

int main()
{
	int n;
	printf("Enter the number of matches:");
	scanf("%d", &n);
	srand(time(NULL));
	if (match(n))
		printf("A wins\n");
	else
		printf("A Loses\n");
}
#include <stdio.h>

void solve(int a, int b);

int main()
{
	int a, b;
	if (2 != scanf("%d%d", &a, &b))
	{
		printf("Wrong input");
		return 0;
	}

	solve(a, b);

	return 0;
}

void solve(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		int sumOfDigit = 0;
		int copyI = i;
		while (copyI > 0)
		{
			sumOfDigit += copyI%10;
			copyI /= 10;
		}

		if (i*i == sumOfDigit*sumOfDigit*sumOfDigit)
		{
			printf("%d\n", i);
		}
	}
}

#include <stdio.h>

int factorial(int num)
// 팩토리얼 계산
{
	if (num <= 1)
	{
		return 1;
	}

	else
	{
		return (num * factorial(num - 1));
	}
}

int main()
{
	int num = 0;
	int result = 0;

	scanf("%d", &num);
	result = factorial(num);

	printf("%d", result);
	return 0;
}
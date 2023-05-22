#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	bool* nums = new bool[b + 1];
	if (b <= 1) return 0;

	for (int i = 2; i <= b; i++)
		nums[i] = true;


	for (int i = 2; i * i <= b; i++)
	{
		if (nums[i])
			for (int j = i * i; j <= b; j += i)
				nums[j] = false;
	}

	for (int k = 0; k <= b; k++)
	{
		if (nums[k] == true && (k) >= a)
			printf("%d\n", k);

	}
	return 0;
}
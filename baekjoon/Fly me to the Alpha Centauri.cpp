#include <stdio.h>


int main()
{
	int x, y, test,num,tcase,range = 0;
	scanf("%d", &test);
	while (test > 0)
	{
		scanf("%d %d", &x, &y);
		range = y - x;
		for (int k = 1; range > 0; k++)
		{
			range -= k * 2;
			num = k;
		}
		if (range <= (num*(-1)))
		{
			tcase = 0;
		}
		else
			tcase = 1;
		switch (tcase)
		{
		case 0:
			printf("%d\n", (num * 2 - 1));
			break;
		case 1:
			printf("%d\n", (num * 2));
			break;
		default:
			break;
		}
		test--;
	}

	return 0;
}


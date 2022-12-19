#include <iostream>
#include <math.h>
using namespace std;

bool prime[10001];

void getp()
{
	for (int i = 2; i <= 10000; i++)
	{
		for (int j = i + i; j <= 10000; j += i)
		{
			prime[j] = 0;
		}
	}
}

int main()
{
	int n, i =2;
	cin >> n;
	int cup = n;
	while (n > 1)
	{
		while (n % i == 0)
		{
			cout << i << '\n';
			n /= i;
		}
		i++;
	}
	return 0;
}
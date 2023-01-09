#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int arr[1000];
	arr[0] = 1;
	while (true)
	{
		cin >> n;
		if (n == -1)
			break;
		int r = 1;
		int c = 1;
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				if (i * i != n)
				{
					r += i + n / i;
					arr[c++] = i;
					arr[c++] = n / i;
				}
				else
				{
					r += i;
					arr[c++] = i;
				}
			}
		}
		sort(arr, arr + c);
		if (r == n)
		{
			cout << n << " = ";
			for (int i = 0; i < c-1; i++)
			{
				cout << arr[i] << " + ";
			}
			cout << arr[c - 1] << '\n';
		}
		else
		{
			cout << n << " is NOT perfect." << '\n';
		}
	}
	return 0;
}
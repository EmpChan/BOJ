#include <iostream>

using namespace std;

int nums[1000000] = { 0 };
void eratos()
{
	nums[0] = 1;
	nums[1] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		for (int j = i + i; j <= 1000000; j += i)
		{
			nums[j] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	eratos();
	while (n != 0)
	{
		int a=0, b;
		for (int i = n; i >= 2; i--)
		{
			if (nums[i]==0 && nums[n - i]==0)
			{
				a = i;
				b = n - i;
				break;
			}
		}
		if (a != 0)
			cout << n << " = " << b << " + " << a << '\n';
		else
			cout << "Goldbach's conjecture is wrong." << '\n';
		cin >> n;
	}

	return 0;
}
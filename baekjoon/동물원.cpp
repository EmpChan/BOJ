#include <iostream>

using namespace std;

int height[40];
int counting[40] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,mini = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> height[i];
		counting[height[i]]++;
		if (mini < height[i])
			mini = height[i];
	}
	long long c = 1;
	if (counting[0] <= 0 || counting[0] >=3)
	{
		cout << 0;
		return 0;
	}
	if (counting[0] == 1)
	{
		c = 1;
	}
	else
	{
		c = 2;
	}
	for (int i = 1; i <= mini; i++)
	{
		if (counting[i] > counting[i-1] || counting[i] == 0)
		{
			c = 0;
		}
		else
		{
			if (counting[i] == 2)
			{
				c *= 2;
			}
		}
	}
	if (counting[mini] == 1)
	{
		cout << c * 2;
	}
	else
	{
		cout << c;
	}
	return 0;
}
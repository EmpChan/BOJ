#include <iostream>
using namespace std;

int check(string* data, int x, int y);

int main()
{
	int m, n, mini=33;
	string map[50];
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}
	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			int k=check(map, j, i);
			if (k < mini)
				mini = k;
		}
	}
	cout << mini;
	return 0;
}

int check(string* data, int x, int y)
{
	int c1=0,c2=0;
	string a = "WBWBWBWB";
	string b = "BWBWBWBW";
	for (int i = y; i < y + 8; i++)
	{
		if ((i - y) % 2 == 0)
		{
			for (int j = x; j < x + 8; j++)
			{
				if (a[j - x] != data[i][j])
					c1++;
			}
		}
		else
		{
			for (int j = x; j < x + 8; j++)
			{
				if (b[j - x] != data[i][j])
					c1++;
			}
		}
		if ((i - y) % 2 != 0)
		{
			for (int j = x; j < x + 8; j++)
			{
				if (a[j - x] != data[i][j])
					c2++;
			}
		}
		else
		{
			for (int j = x; j < x + 8; j++)
			{
				if (b[j - x] != data[i][j])
					c2++;
			}
		}
	}
	if (c1 > c2)
		return c2;
	else
		return c1;
}
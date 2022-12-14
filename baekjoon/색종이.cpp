#include <iostream>

using namespace std;

int map[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				map[y + j][x + k] = 1;
			}
		}
	}
	int countit = 0;
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (map[i][j])
				countit++;
		}
	}
	cout << countit << '\n';
}
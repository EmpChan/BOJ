#include <iostream>

using namespace std;

int picture[250000];
bool map[1000][1000];

int c = 0;
int n, m;

void check(int sx,int sy,int i)
{
	if (sy >= m || sx >= n)
		return;
	if (sy < 0 || sx < 0)
		return;
	if (map[sx][sy] == 0)
		return;
	map[sx][sy] = 0;
	picture[i]++;
	check(sx, sy + 1,i);
	check(sx, sy - 1,i);
	check(sx + 1, sy,i);
	check(sx - 1, sy,i);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j])
			{
				check(i, j, c);
				c++;
			}
		}
	}
	int maxi = 0;
	for (int i = 0; i < c; i++)
	{
		if (maxi < picture[i])
			maxi = picture[i];
	}
	cout << c << '\n' << maxi << '\n';
	return 0;
}


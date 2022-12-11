#include <iostream>

using namespace std;

char star = '*';
char space = ' ';

char map[3100][6200];

void loopit(int sx, int sy, int n)
{
	if (n > 3)
	{
		int a = n / 2;
		loopit(sx+a, sy, a);
		loopit(sx + a, sy + 6 * (a / 3), a);
		loopit(sx, sy + a, a);

	}
	else
	{
		map[sx][sy + 2] = star;
		map[sx + 1][sy + 1] = star;
		map[sx + 1][sy + 3] = star;
		map[sx + 2][sy] = star;
		map[sx + 2][sy+1] = star;
		map[sx + 2][sy+2] = star;
		map[sx + 2][sy+3] = star;
		map[sx + 2][sy+4] = star;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < 3100; i++)
	{
		for (int j = 0; j < 6200; j++)
		{
			map[i][j] = space;
		}
	}

	loopit(0,0,n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 6 * (n / 3); j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}

	return 0;
}
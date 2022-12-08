#include <iostream>

using namespace std;

int map[128][128] = { 0 };
int countit[2] = { 0 };

void get_colorpaper(int n, int sx, int sy)
{
	int base = map[sx][sy];
	if (n == 1)
	{
		countit[base]++;
		return;
	}
	for (int i = sx; i < sx + n; i++)
	{
		for (int j = sy; j < sy + n; j++)
		{
			if (base != map[i][j])
			{
				get_colorpaper(n / 2, sx, sy);
				get_colorpaper(n / 2, sx+n/2, sy);
				get_colorpaper(n / 2, sx, sy+n/2);
				get_colorpaper(n / 2, sx+n/2, sy+n/2);
				return;
			}
		}
	}
	countit[base]++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	get_colorpaper(n, 0, 0);
	cout << countit[0] << '\n' << countit[1];
	return 0;
}
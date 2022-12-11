#include <iostream>

using namespace std;
char space = ' ';
char star = '*';
char map[6561][6561];

void get_star(int sx,int sy,int n)
{
	if (n >= 3)
	{
		int a = n / 3;
		get_star(sx, sy, a); // 0,0
		get_star(sx + a, sy, a); // 1, 0
		get_star(sx + (a*2), sy, a); // 2, 0
		get_star(sx, sy+a, a); // 0, 1
		get_star(sx, sy + (a * 2), a); // 0, 2
		get_star(sx + a, sy + (a * 2), a); // 1, 2
		get_star(sx + (a * 2), sy + a, a); // 2, 1
		get_star(sx + (a*2), sy+(a*2), a); // 2, 2
	}
	else
	{
		map[sx][sy] = star;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < 6561; i++)
	{
		for (int j = 0; j < 6561; j++)
		{
			map[i][j] = space;
		}
	}
	
	get_star(0,0,n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}
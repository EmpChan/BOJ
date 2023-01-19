#include <iostream>

using namespace std;

int map[50][50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,s=1;
	string cup;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> cup;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = cup[j] - '0';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = i + 1; k < n; k++)
			{
				if (map[k][j] == map[i][j])
				{
					if (j + k-i < m)
					{
						if ((map[k][j + k - i] == map[i][j] && map[i][j + k - i] == map[i][j]) && s < (k - i + 1) * (k - i + 1))
						{
							s = (k - i + 1) * (k - i + 1);
						}
					}
				}
			}
		}
	}
	
	cout << s;

	return 0;
}
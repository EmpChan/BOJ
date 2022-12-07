#include <iostream>
#include <math.h>

using namespace std;

int map[2187][2187];

int counting[3]; // 0==-1 1 == 0 2 == 1

void searchit(int sx, int sy,int n)
{
	if (n==1)
	{
		counting[map[sx][sy]+1]++;
		return;
	}
	int base = map[sx][sy];
	for (int i = sx; i < sx+n; i++)
	{
		for (int j = sy; j < sy+n; j++)
		{
			if (base != map[i][j])
			{
				for (int a = sx; a < sx+n; a+=n/3)
				{
					for (int b = sy; b < sy+n; b += n/3)
					{
						searchit(a, b,n/3);
					}
				}
				return;
			}
		}
	}
	counting[base + 1]++;
	return;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> map[j][i];
		}
	}
	searchit(0, 0, n);
	cout << counting[0] << '\n' << counting[1] << '\n' << counting[2];
	return 0;
}
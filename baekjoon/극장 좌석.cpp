#include <iostream>
#include <algorithm>

using namespace std;

int map[41];

long long counting(int s,int e)
{
	long long r=1;
	long long r2= 1;
	for (int i = s; i < e; i++)
	{
		long long cup = r2;
		r2 += r;
		r = cup;
	}

	return r2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 40; i++)
		map[i] = 0;
	long long r = 1;
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int c;
		cin >> c;
		map[c] = 1;
	}
	int s=1, e=1;
	for (int i = 1; i <= n; i++)
	{
		if (map[i])
		{
			e = i-1;
			r *= counting(s, e);
			s = i+1;
		}
	}
	r *= counting(s, n);
	cout << r << '\n';
	return 0;
}
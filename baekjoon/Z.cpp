#include <iostream>

using namespace std;

long long count_it(int n, int r, int c)
{
	if (r < 2 && c < 2)
	{
		if (r == 0 && c == 0)
			return 1;
		else if (r == 0 && c == 1)
			return 2;
		else if (r == 1 && c == 0)
			return 3;
		else 
			return 4;
	}
	long long count=0, k=2;
	long long big_one=max(r,c), small_one = min(r, c);
	while (k - 1 < big_one)
	{
		k *= 2;
	}
	if (small_one > k / 2-1)
	{
		count = k * k * 3 / 4;
		k /= 2;
		r -= k;
		c -= k;
	}
	else
	{
		if (small_one == r)
		{
			count = k * k / 4;
			k /= 2;
			c -= k;
		}
		else
		{
			count = k * k / 2;
			k /= 2;
			r -= k;
		}
	}
	return count + count_it(n, r, c);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, r, c;
	cin >> n;
	cin >> r;
	cin >> c;

	cout << count_it(n, r, c)-1;

	return 0;
}
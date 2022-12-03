#include <iostream>

using namespace std;

int nums[1024 * 1024];

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 0; i < n*n; i++) cin >> nums[i];

	for (int i = 1; i < n * n; i++)
	{
		if (i % n == 0) continue;
		else
		{
			nums[i]+=nums[i-1];
		}
	}
	int x1, x2, y1, y2;
	for (int i = 0; i < m; i++)
	{
		cin >> x1;
		cin >> y1;
		cin >> x2;
		cin >> y2;
		int s = 0;
		for (int j = x1; j <= x2; j++)
		{
			if (y1 > 1)
				s += nums[(j - 1) * n + y2 - 1] - nums[(j - 1) * n + y1 - 2];
			else
				s += nums[(j - 1) * n + y2 - 1];
		}
		cout << s << '\n';
	}


	return 0;
}
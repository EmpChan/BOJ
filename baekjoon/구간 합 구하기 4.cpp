#include <iostream>

using namespace std;

int nums[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;
	int a, b;

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	for (int i = 1; i < n; i++)
	{
		nums[i] += nums[i - 1];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		cin >> b;
		cout << nums[b-1] - nums[a-2] << '\n';
	}

	return 0;
}
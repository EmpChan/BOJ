#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int r = 0;
	int cup=-1;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		if (k - 1 != cup)
		{
			r += k;
		}
		cup = k;
	}
	cout << r;
	return 0;
}
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int o = 1, t = 1;
	for (int i = 2; i <= n; i++)
	{
		int cup = t;
		t = (t + o)%15746;
		o = cup;
	}
	cout << t%15746;

	return 0;
}
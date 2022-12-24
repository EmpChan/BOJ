#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m;
	while (cin >> n >> m)
	{
		cout << m / (n + 1) << '\n';
	}

	return 0;
}
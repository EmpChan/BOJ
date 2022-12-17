#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	long long a, b;
	cin >> a;
	cin >> b;
	if (a == b)
	{
		cout << 0;
		return 0;
	}
	cout << max(a,b) - min(a, b) - 1 << '\n';
	for (long long i = min(a,b)+1; i < max(a,b); i++)
	{
		cout << i << ' ';
	}
	return 0;
}
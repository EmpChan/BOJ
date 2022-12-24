#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	while (n != 0)
	{
		cout << n * (n + 1) / 2 << '\n';
		cin >> n;
	}
	return 0;
}
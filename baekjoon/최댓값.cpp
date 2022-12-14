#include <iostream>

using namespace std;

int map[81];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int maxi = 0, k=0;

	for (int i = 0; i < 81; i++)
	{
		cin >> map[i];
		if (maxi < map[i])
		{
			maxi = map[i];
			k = i;
		}
	}
	cout << maxi << '\n' << k/9 + 1 << ' ' << k % 9 + 1 << '\n';

	return 0;
}
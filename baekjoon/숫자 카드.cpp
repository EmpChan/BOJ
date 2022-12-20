#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int>cards;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int cup;
		cin >> cup;
		cards[cup] = 1;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int cup;
		cin >> cup;
		if (cards[cup])
			cout << 1 << ' ';
		else
			cout << 0 << ' ';
	}

	return 0;
}
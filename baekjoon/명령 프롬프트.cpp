#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string j[50];
	string ans = "";
	for (int i = 0; i < n; i++)
	{
		cin >> j[i];
	}
	for (int i = 0; i < j[0].length(); i++)
	{
		char cup = j[0][i];
		bool same = 1;
		for (int k = 1; k < n; k++)
		{
			if (cup != j[k][i])
			{
				ans += '?';
				same = 0;
				break;
			}
		}
		if (same)
			ans += cup;
	}
	cout << ans;
	return 0;
}
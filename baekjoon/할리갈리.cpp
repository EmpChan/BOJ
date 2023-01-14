#include <iostream>
#include <map>



using namespace std;

map<string, int>cards;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a;
		int x;
		cin >> a >> x;
		if (cards.find(a) == cards.end())
		{
			cards[a] = x;
		}
		else
		{
			cards[a] += x;
		}
	}
	bool flag = 0;
	for (auto i : cards)
	{
		if (i.second == 5)
			flag = 1;
	}
	if (flag)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
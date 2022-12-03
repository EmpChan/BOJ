#include <iostream>
#include <map>

using namespace std;

map<string, int>s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string ans, cup;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cup = "",count = 0;
		cin >> ans;
		for (auto i : ans)
		{
			if (count)
				cup += i;
			if (i == '.')
				count = 1;
		}
		if (s.find(cup) == s.end())
		{
			s[cup] = 1;
		}
		else
		{
			s[cup]++;
		}
	}
	for (auto i : s)
	{
		cout << i.first << ' ' << i.second << '\n';
	}
		
	return 0;
}
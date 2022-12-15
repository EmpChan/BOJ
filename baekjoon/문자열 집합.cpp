#include <iostream>
#include <algorithm>
using namespace std;

string s[10000];
string comes[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> comes[i];
	}

	sort(s, s+n);
	sort(comes, comes + m);
	
	int i=0, j=0;
	int countit = 0;
	while (i < n && j < m)
	{
		if (s[i] == comes[j])
		{
			countit++;
			j++;
		}
		else
		{
			if (s[i] > comes[j])
				j++;
			else
				i++;
		}
	}

	cout << countit << '\n';
	return 0;
}
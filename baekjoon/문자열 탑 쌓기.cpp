#include <iostream>

using namespace std;

string s[100];

string getstring(string a, int start, int end)
{
	string c = "";
	for (int i = start; i <= end; i++)
		c += a[i];
	return c;
}

int check(string o, string t)
{
	int k = 0,j = 0;
	string cup1, cup2;
	for (int i = 0; i < o.length(); i++)
	{
		cup1 = getstring(o, 0, i);
		cup2 = getstring(t, t.length() - i-1, t.length()-1);
		if (cup1 == cup2)
			return 1;
	}
	for (int i = 0; i < o.length(); i++)
	{
		cup1 = getstring(t, 0, i);
		cup2 = getstring(o, t.length() - i-1, t.length()-1);
		if (cup1 == cup2)
			return 1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 1; i < n; i++)
	{
		if (check(s[i-1], s[i]) == 0)
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}
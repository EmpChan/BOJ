#include <iostream>

using namespace std;

int absol(int a)
{
	if (a < 0)
	{
		return a + 26;
	}
	else
		return a;
}

bool check(string one, string two, int s)
{
	int j = s;
	for (auto i : one)
	{
		if (i != two[j++])
			return 0;
	}
	return 1;
}

string shot(string a)
{
	int c = 0;
	string cup="";
	for (int i = 0; i < a.length(); i++)
	{
		bool nope = 0;
		c++;
		cup += a[i];
		for (int j = 0; j < a.length(); j += c)
		{
			if (!check(cup,a,j))
			{
				nope = 1;
				break;
			}
		}
		if (!nope)
			return cup;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string f, s,ans="";
	cin >> f;
	cin >> s;
	for (int i = 0; i < f.length(); i++)
	{
		ans += absol(s[i]-f[i]) + 'A' - 1;
	}
	cout << shot(ans);
	return 0;
}
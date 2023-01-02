#include <iostream>

using namespace std;

bool check(int a, int b, int c, int p)
{
	if (a % p == 0)
	{
		if (b % p != 0 && c % p != 0)
			return false;
		else
			return true;
	}
	else if (b % p == 0)
	{
		if (c % p != 0)
			return false;
		else
			return true;
	}
	else
	{
		return false;
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,a,b,c,p;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b >> c >> p;
		if (check(a, b, c, p))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}
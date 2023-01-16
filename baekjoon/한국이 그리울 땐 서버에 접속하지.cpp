#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	string a;
	cin >> a;
	int p = 0, q = 0;
	bool flag = 0;
	for (auto i : a)
	{
		if (flag)
			q++;
		else if (i == '*')
			flag = 1;
		else
			p++;
	} 
	for (int i = 0; i < n; i++)
	{
		string cup;
		cin >> cup;
		flag = 0;
		if (p + q > cup.length())
			flag = 1;
		for (int j = 0; j < p; j++)
		{
			if (a[j] != cup[j])
				flag = 1;
		}
		for (int j = 0; j < q; j++)
		{
			if (a[a.length() - 1 - j] != cup[cup.length() - 1 - j])
				flag = 1;
		}
		if (flag)
			cout << "NE";
		else
			cout << "DA";
		cout << '\n';
	}

	return 0;
}
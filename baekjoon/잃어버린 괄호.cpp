#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r=0;
	int pm = 1;
	string a;
	cin >> a;
	string cup="";
	for (auto i : a)
	{
		if (i >= '0' && i <= '9')
			cup += i;
		else
		{
			int j = 1;
			for (int k = cup.length()-1; k >= 0; k--)
			{
				if (pm)
				{
					r += (cup[k] - '0') * j;
				}
				else
				{
					r -= (cup[k] - '0') * j;
				}
				j *= 10;
			}
			if (pm && i == '-')
			{
				pm = 0;
			}
			cup = "";
		}
	}
	int j = 1;
	for (int k = cup.length() - 1; k >= 0; k--)
	{
		if (pm)
		{
			r += (cup[k] - '0') * j;
		}
		else
		{
			r -= (cup[k] - '0') * j;
		}
		j *= 10;
	}
	cout << r;
	return 0;
}

#include <iostream>

using namespace std;

char stackit[1000000];
string str;
string boom;
int c1 = 0;
void boomit()
{
	int c2 = 0;
	
	for (auto i: str)
	{
		stackit[c2++] = i;
		if (c2 >= boom.length())
		{
			int cup = 0;
			while (cup != c2)
			{
				cup = c2;
				string a="";
				for (int j =c2-boom.length(); j < c2; j++)
					a += stackit[j];
				if (a == boom)
				{
					c2 -= boom.length();
				}
			}
		}
	}
	c1 = c2;
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> str;
	cin >> boom;

	boomit();
	if (c1<=0)
		cout << "FRULA" << '\n';
	else
	{
		for (int i = 0; i < c1; i++)
		{
			cout << stackit[i];
		}
	}

	return 0;
}
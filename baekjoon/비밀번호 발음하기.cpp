#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a="";
	cin >> a;
	while (a != "end")
	{
		char cup = ' ';
		bool flag = 1;
		int c1=0, c2=0;
		for (int i=0; i<a.length();i++)
		{
			if (cup == a[i])
			{
				if (a[i] == 'e' || a[i] == 'o');
				else
				{
					flag = 1;
					break;
				}
				
			}
			if (((a[i] == 'a' || a[i] == 'e') || a[i] == 'i') || (a[i] == 'o' || a[i] == 'u'))
			{
				c1++;
				c2 = 0;
				flag = 0;
			}
			else
			{
				c2++;
				c1 = 0;
			}
			if (c1 >= 3 || c2 >= 3)
			{
				flag = 1;
				break;
			}
			cup = a[i];
		}
		if (!flag)
		{
			cout << '<' << a << "> is acceptable.";
		}
		else
		{
			cout << '<' << a << "> is not acceptable.";
		}
		cout << '\n';
		cin >> a;
	}

	return 0;
}
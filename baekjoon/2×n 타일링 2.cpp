#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	int one = 1,two = 3;
	if (n == 1)
		cout << 1;
	else if (n == 2)
		cout << 3;
	else
	{
		for (int i = 2; i < n; i++)
		{
			if (i % 2 == 0)
			{
				two += two-1;
			}
			else
			{
				two += two + 1;
			}
			if (two % 10007 != 0)
				two %= 10007;
		}
		cout << two % 10007;
	}
	return 0;
}
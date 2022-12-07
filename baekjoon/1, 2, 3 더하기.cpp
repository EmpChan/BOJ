#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int one = 1, two = 2, three = 4,cup;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if (t == 1)
			cout << 1 << '\n';
		else if (t == 2)
			cout << 2 << '\n';
		else if (t == 3)
			cout << 4 << '\n';
		else
		{
			one = 1, two = 2, three = 4;
			for (int j = 3; j < t; j++)
			{
				cup = three;
				three = one + two + three;
				one = two;
				two = cup;
			}
			cout << three << '\n';
		}
	}
	
	
	return 0;
}
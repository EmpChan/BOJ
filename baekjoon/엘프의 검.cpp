#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;
	while (true)
	{
		int c=0;
		long long cup;
		cin >> n;
		if (cin.eof())
			break;
		int a[10] = { 0 };
		int countit = 10;
		while (countit>0)
		{
			c++;
			cup = n * c;
			while (cup > 0)
			{
				if (!a[cup % 10])
				{
					a[cup % 10] = 1;
					countit--;
				}
				cup /= 10;
			}
		}
		cout << c << '\n';
	}


	return 0;
}
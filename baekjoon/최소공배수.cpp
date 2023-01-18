#include <iostream>

using namespace std;

long long gcf(long long a, long long b)
{
	if (a > b)
	{
		if (a % b == 0)
			return b;
		else
			return gcf(a % b, b);
	}
	else
	{
		if (b % a == 0)
			return a;
		else
			return gcf(b % a, a);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a,b;
	cin >> a >> b;
	
	cout << a * b / gcf(a, b);

	return 0;
}
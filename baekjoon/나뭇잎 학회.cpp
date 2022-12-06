#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,r;
	cin >> n;
	r = n * n / 2;
	if (n == 1)
	{
		cout << 0;
	}
	else
	{
		if (n % 2 == 0)
			cout << r;
		else
			cout << r+1;
	}

	return 0;
}
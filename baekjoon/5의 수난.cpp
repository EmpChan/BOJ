#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long r=0;
	int n;
	cin >> n;
	while (n >= 1)
	{
		r += pow(n % 10, 5);
		n /= 10;
	}
	cout << r;
	return 0;
}
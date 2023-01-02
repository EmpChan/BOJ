#include <iostream>

using namespace std;

long long arr[1000000] = { 0 };

void getvalue()
{
	for (int i = 0; i < 1000000; i++)
		arr[i] = 0;
	for (int i = 1; i <= 1000000; i++)
	{
		for (int j = i; j <= 1000000; j += i)
		{
			arr[j-1] += i;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	getvalue();
	long long r = 0;
	for (int i = 0; i < n; i++)
	{
		r += arr[i];
	}
	cout << r;

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int arr[500000];
int absol(int a)
{
	if (a > 0)
		return a;
	else
		return a * -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	long long r = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 1; i <= n; i++)
	{
		r += absol(i - arr[i - 1]);
	}
	cout << r << '\n';
	return 0;
}
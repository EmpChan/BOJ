#include <iostream>
#include <algorithm>
using namespace std;

int arr[500];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	double mean=0;
	double middle;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		mean += arr[i];
	}
	mean /= n;
	sort(arr, arr + n);
	if (n % 2 == 0)
	{
		middle = arr[n / 2] + arr[n / 2 -1];
		middle /= 2;
	}
	else
		middle = arr[n / 2];

	cout << mean << '\n' << middle;
	return 0;
}
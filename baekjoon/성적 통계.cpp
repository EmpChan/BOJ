#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t,arr[100],maxi = 0;
		cin >> t;
		for (int j = 0; j < t; j++)
		{
			cin >> arr[j];
		}
		sort(arr, arr + t);
		for (int j = 1; j < t; j++)
		{
			if (maxi < arr[j] - arr[j - 1])
				maxi = arr[j] - arr[j - 1];
		}
		cout << "Class " << i << '\n';
		cout << "Max " << arr[t-1] << ", Min " << arr[0] << ", Largest gap " << maxi << '\n';
	}

	return 0;
}
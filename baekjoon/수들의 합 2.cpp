#include <iostream>

using namespace std;

int arr[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,count=0;
	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 1; i < n; i++)
	{
		arr[i] += arr[i - 1];
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > m)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (arr[i] - arr[j] == m)
					count++;
				else if (arr[i] - arr[j] > m)
					break;
			}
		}
		else if (arr[i] == m)
			count++;
	}
	cout << count;

	return 0;
}
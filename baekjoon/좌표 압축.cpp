#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int arr[1000000];
int temp[1000000];
map<int, int> numcount;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		temp[i] = arr[i];
	}
	sort(arr, arr + n);
	int cup=arr[0];
	int overlap = 0;
	for (int i = 1; i < n; i++)
	{
		if (cup == arr[i])
		{
			overlap++;
			continue;
		}
		cup = arr[i];
		numcount[arr[i]] = i - overlap;
	}
	for (int i = 0; i < n; i++)
	{
		cout << numcount[temp[i]] << ' ';
	}
	return 0;
}
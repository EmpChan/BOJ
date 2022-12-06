#include <iostream>

using namespace std;

int arr[3000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		int cup;
		for (int j = 0; j < n+m; j++)
		{
			cin >> cup;
			arr[i] -= cup;
			arr[j] += cup;
		}
	}
	for (int i = 0; i < n + m; i++)
		cout << arr[i] << ' ';
	return 0;
}
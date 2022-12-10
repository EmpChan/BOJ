#include <iostream>

using namespace std;
long long arr[100] = { 1, 1, 1};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 3; i < 100; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 3];
	}
	for (int i = 0; i < n; i++)
	{
		int ans;
		cin >> ans;
		cout << arr[ans-1] << '\n';
	}

	return 0;
}
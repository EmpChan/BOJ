#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	string a;
	cin >> a;
	int arr[20];
	for (int i = 0; i < a.length(); i++)
	{
		arr[i] = a[i] - '0';
	}
	sort(arr, arr + a.length());
	for (int i = a.length()-1; i >= 0; i--)
	{
		cout << arr[i];
	}

	return 0;
}
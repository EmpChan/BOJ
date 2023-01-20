#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	int d = 1;
	int m = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = n-1; i >=0; i--){
		if (m < ++d + arr[i])
			m = d + arr[i];
	}
	cout << m;
	return 0;
}
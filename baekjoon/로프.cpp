#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,maxi=0;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) maxi = max(arr[i] *( n - i), maxi);
	cout << maxi << '\n';
	return 0;
}
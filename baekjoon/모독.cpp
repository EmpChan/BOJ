#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	long long n, wave = 0;
	long long r=0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (arr[i] <= wave) continue;
		else {
			r += arr[i] - ++wave;
		}
	}

	cout << r;

	return 0;
}
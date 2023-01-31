#include <iostream>

using namespace std;

int arr[20000];
int absol(int a) {
	if (a > 0)
		return a;
	else
		return a * -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x=-1,y=999999999;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int r = 0;
		for (int j = 0; j < n; j++) {
			r += absol(arr[i] - arr[j]);
		}
		if (r < y) {
			y = r;
			x = arr[i];
		}
		if (r == y) {
			x = min(arr[i], x);
		}
	}
	cout << x;
	return 0;
}
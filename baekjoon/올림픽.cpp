#include <iostream>

using namespace std;

int arr[1000][4];

bool compare(int a[], int b[]) {
	for (int i = 1; i < 4; i++) {
		if (a[i] > b[i])
			return 1;
		else if (a[i] < b[i])
			return 0;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, in = 0,r=1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
		if (arr[i][0] == m) in = i;
	}

	for (int i = 0; i < n; i++) {
		if (compare(arr[i], arr[in]))r++;
	}
	cout << r << '\n';
	return 0;
}
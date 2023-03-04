#include <iostream>

using namespace std;

int arr[1000][1000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	arr[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0)
				continue;
			if (j == 0) {
				arr[i][j] = arr[i - 1][j] + 1;
			}
			else {
				arr[i][j] = arr[i][j - 1] + 1;
			}
		}
	}
	
	if (k >= arr[n - 1][m - 1]) {
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	else {
		cout << "NO\n";
	}


	return 0;
}
#include <iostream>
#include <math.h>
#define MAX 1001

using namespace std;

int map[MAX][MAX];

void sol() {
	for (int i = 1; i < 1000; i++) {
		for (int j = 1; j < 1000; j++) {
			if (map[i][j] && map[i - 1][j] && map[i - 1][j - 1] && map[i][j - 1]) {
				map[i][j] = min(sqrt(map[i][j - 1]), min(sqrt(map[i - 1][j - 1]), sqrt(map[i - 1][j])))+1;
				map[i][j] *= map[i][j];
			}
		}
	}
}

void printmap() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

int biggest() {
	int maxi = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			maxi = max(maxi, map[i][j]);
		}
	}
	return maxi;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < m; j++) {
			map[i][j] = a[j] - '0';
		}
	}
	sol();
	cout << biggest();
	return 0;
}
#include<iostream>
#define INF 10000000

using namespace std;
using lld = long long;
using info = pair<int, int>;

int ans, n;

bool map[15][15];

bool putQ(int x, int y) {
	// check row and column
	for (int i = 0; i < n; i++) {
		if (map[x][i] || map[i][y])return 0;
	}
	// check dialog
	for (int i = 1; i <= min(x, y); i++) {
		if (map[x - i][y - i])return 0;
	}
	for (int i = 1; i <= min(x, n - y); i++) {
		if (map[x - i][y + i]) return 0;
	}
	for (int i = 1; i <= min(n - x, n - y); i++) {
		if (map[x + i][y + i])return 0;
	}
	for (int i = 1; i <= min(n - x, y); i++) {
		if (map[x + i][y - i])return 0;
	}
	return 1;
}

void sol(int y,int t) {
	if (t == n) ans++;
	else {
		for (int i = 0; i < n; i++) {
			if (putQ(t, i)) {
				map[t][i] = 1;
				sol(i, t + 1);
				map[t][i] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	sol( 0, 0);
	
	cout << ans;

	return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#define INF 1000000000
#define MAX 1000000007

using namespace std;
using lld = long long;
using info = pair<int, int>;
using vect = vector<vector<info>>;

int map[15][15];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int x = max((k - 1) / m,0), y = max((k - 1) % m,0);
	map[0][0] = 1;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if (i && j)map[i][j] = map[i - 1][j] + map[i][j - 1];
			else if (i) map[i][j] = map[i - 1][j];
			else if (j) map[i][j] = map[i][j - 1];
		}
	}
	int t = map[x][y];
	for (int i = 0; i < n-x; i++) {
		for (int j = 0; j < m-y; j++) {
			if (i && j)map[i][j] = map[i - 1][j] + map[i][j - 1];
			else if (i) map[i][j] = map[i - 1][j];
			else if (j) map[i][j] = map[i][j - 1];
		}
	}
	cout << t * map[n - x-1][m - y-1];

	return 0;
}
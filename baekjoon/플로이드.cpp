#include<iostream>
#include<queue>
#define INF 10000010

using namespace std;

int dis[101][101];

void sol(int n) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	int a, b, c;
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			if (i == j) dis[j][i] = 0;
			else dis[j][i] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dis[a][b] = min(dis[a][b],c);
	}

	sol(n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dis[i][j] != INF)cout << dis[i][j] << ' ';
			else cout << 0 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
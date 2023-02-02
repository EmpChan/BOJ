#include <iostream>

using namespace std;

int map[1000][1000];
int visit[1000][1000];
int x[1000000],tx[1000000];
int y[1000000],ty[1000000];
int n, m;

void printvisit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visit[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	

	int j,k=0,counting=0;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1)
				visit[i][j] = 1;
			if (map[i][j] == 1) {
				visit[i][j] = 1;
				x[k] = i;
				y[k++] = j;
			}
		}
	}
	while (k > 0) {
		j = k;
		k = 0;
		for (int i = 0; i < j; i++) {
			if (x[i] + 1 < n) {
				if (!visit[x[i] + 1][y[i]]) {
					visit[x[i] + 1][y[i]] = 1;
					tx[k] = x[i] + 1;
					ty[k++] = y[i];
				}
			}
			if (x[i] - 1 >= 0) {
				if (!visit[x[i] - 1][y[i]]) {
					visit[x[i] - 1][y[i]] = 1;
					tx[k] = x[i] - 1;
					ty[k++] = y[i];
				}
			}
			if (y[i] + 1 < m) {
				if (!visit[x[i]][y[i] + 1]) {
					visit[x[i]][y[i] + 1] = 1;
					tx[k] = x[i];
					ty[k++] = y[i] + 1;
				}
			}
			if (y[i] - 1 >= 0) {
				if (!visit[x[i]][y[i] - 1]) {
					visit[x[i]][y[i] - 1] = 1;
					tx[k] = x[i];
					ty[k++] = y[i] - 1;
				}
			}
		}
		for (int i = 0; i < k; i++) {
			x[i] = tx[i];
			y[i] = ty[i];
		}
		counting++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << counting-1;
	return 0;
}
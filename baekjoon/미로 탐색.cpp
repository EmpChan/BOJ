#include <iostream>

using namespace std;

int map[100][100];
bool visit[100][100];
int counting;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string cup;
		cin >> cup;
		for (int j = 0; j < m; j++) {
			map[i][j] = cup[j] - '0';
			if (map[i][j] == 0)
				visit[i][j] = 1;
		}
	}
	int x[10000],y[10000], k = 1;
	x[0] = 0, y[0] = 0,counting=0;
	while (true) {
		counting++;
		int j = k;
		k = 0;
		int tx[10000], ty[10000];
		for (int i = 0; i < j; i++) {
			if (x[i] == n - 1 && y[i] == m - 1){
				cout << counting;
				return 0;
			}
			if (!visit[x[i]][y[i]]) {
				visit[x[i]][y[i]] = 1;
				if(x[i]+1<n) tx[k] = x[i] + 1, ty[k++] = y[i];
				if(x[i]-1>=0) tx[k] = x[i] - 1, ty[k++] = y[i];
				if(y[i]+1 < m) tx[k] = x[i], ty[k++] = y[i] + 1;
				if(y[i]-1 >=0)tx[k] = x[i], ty[k++] = y[i] - 1;
			}
		}
		for (int i = 0; i < k; i++) {
			x[i] = tx[i];
			y[i] = ty[i];
		}
	}

	return 0;
}
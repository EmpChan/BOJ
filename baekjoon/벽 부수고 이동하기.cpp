#include <iostream>

using namespace std;

int x[1000000][2];
int temp[1000000][2];
int visit[1000000];
int n, m,wc;

void outmap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visit[i * m + j];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int mini=1000000;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < m; j++) {
			if (a[j] == '0') {
				visit[i * m + j] = 9;
			}
			else visit[i * m + j] = -1;
		}
	}
	x[0][0] = 0, x[0][1]=0;
	visit[0] = 0;
	int j, k = 1, counting = 0; 
	while (k > 0) {
		j = k;
		k = 0;
		for (int i = 0; i < j; i++) {
			if (x[i][0] == n * m - 1 && x[i][1] <= 1) {
				cout << counting+1;
				k = 0;
				return 0;
				break;
			}
			if ((x[i][0])%m != 0) {
				if (visit[x[i][0] - 1] == -1) {
					if (x[i][1] + 1 < 2) {
						temp[k][0] = x[i][0] - 1, temp[k++][1] = x[i][1] + 1;
					}
				}
				else {
					if (visit[x[i][0] - 1] > x[i][1]) {
						visit[x[i][0] - 1] = x[i][1];
						temp[k][0] = x[i][0] - 1, temp[k++][1] = x[i][1];
					}
				}
			}
			if ((x[i][0] + 1)%m != 0 && x[i][0] < n*m) {
				if (visit[x[i][0] + 1] == -1) {
					if (x[i][1] + 1 < 2) {
						temp[k][0] = x[i][0] + 1, temp[k++][1] = x[i][1] + 1;
					}
				}
				else {
					if (visit[x[i][0] + 1] > x[i][1]) {
						visit[x[i][0] + 1] = x[i][1];
						temp[k][0] = x[i][0] + 1, temp[k++][1] = x[i][1];
					}
				}
			}
			if (x[i][0] - m >= 0) {
				if (visit[x[i][0] - m] == -1) {
					if (x[i][1] + 1 < 2) {
						temp[k][0] = x[i][0] - m, temp[k++][1] = x[i][1] + 1;
					}
				}
				else {
					if (visit[x[i][0] - m] > x[i][1]) {
						visit[x[i][0] - m] = x[i][1];
						temp[k][0] = x[i][0] - m, temp[k++][1] = x[i][1];
					}
				}
			}
			if (x[i][0] + m < n*m) {
				if (visit[x[i][0] +m] == -1) {
					if (x[i][1] + 1 < 2) {
						temp[k][0] = x[i][0] + m, temp[k++][1] = x[i][1] + 1;
					}
				}
				else {
					if (visit[x[i][0] + m] > x[i][1]) {
						visit[x[i][0] + m] = x[i][1];
						temp[k][0] = x[i][0] + m, temp[k++][1] = x[i][1];
					}
				}
			}
		}
		for (int i = 0; i < k; i++) {
			x[i][0] = temp[i][0], x[i][1] = temp[i][1];
		}
		counting++;
	}
	cout << -1;

	return 0;
}
#include <iostream>
#include <utility>

using namespace std;
using place = pair<int, int>;

int map[10][10];
place arr[3];
int minimum = 20001;
bool visit[10][10];

void search(int k,int t,int n) {
	int dx[] = { -1,1,0,0, 0 };
	int dy[] = { 0,0,1,-1, 0 };
	if (t == 3) {
		int s = 0;
		for (int i = 0; i < t; i++) {
			for (int p = 0; p < 5; p++) {
				s += map[arr[i].first + dx[p]][arr[i].second + dy[p]];
			}
		}
		minimum = min(s, minimum);
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				bool flag = 0;
				for (int p = 0; p < 5; p++) {
					if (i + dx[p] < 0 || j+dy[p] < 0) {
						flag = 1;
						break;
					}
					if (i + dx[p] >= n || j + dy[p] >= n) {
						flag = 1;
						break;
					}
					if (visit[i + dx[p]][j + dy[p]]) {
						flag = 1;
						break;
					}
				}
				if (flag)continue;
				arr[k] = make_pair(i, j);
				for (int p = 0; p < 5; p++) {
					visit[i + dx[p]][j + dy[p]] = 1;
				}
				search(k + 1, t + 1,n);
				for (int p = 0; p < 5; p++) {
					visit[i + dx[p]][j + dy[p]] = 0;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	search(0,0,n);

	cout << minimum;

	return 0;
}
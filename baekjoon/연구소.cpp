#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using p = pair<int, int>;// x,y

int map[8][8];
bool visit[8][8];
int maxi;

void set0() {
	for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) visit[i][j] = 0;
}

void search(int n, int m) {
	vector<p>list;
	vector<p>temp;
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2) {
				list.push_back(make_pair(i, j));
			}
			if (map[i][j]!=0) visit[i][j] = 1;
		}
	}
	while (list.size()) {
		for (auto i : list) {
			for (int p = 0; p < 4; p++) {
				if (i.first + dx[p] < 0 || i.first + dx[p] >= n)
					continue;
				if (i.second + dy[p] < 0 || i.second + dy[p] >= m)
					continue;
				if (!visit[i.first + dx[p]][i.second + dy[p]]) {
					temp.push_back(make_pair(i.first + dx[p], i.second + dy[p]));
					visit[i.first + dx[p]][i.second + dy[p]] = 1;
				}
			}
		}
		list.clear();
		for (auto i : temp) {
			list.push_back(i);
		}
		temp.clear();
	}
	int s = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!visit[i][j]) s++;
	maxi = max(s, maxi);
}

void setwall(int i,int x,int y, int n, int m) {
	if (i == 3) {
		set0();
		search(n, m);
	}
	else {
		for (int p = max(x-2,0); p < n; p++) {
			for (int q = max(y-2,0); q < m; q++) {
				if (map[p][q])
					continue;
				map[p][q] = 1;
				setwall(i + 1, p, q, n, m);
				map[p][q] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	
	setwall(0, 0, 0, n, m);

	cout << maxi;

	return 0;
}
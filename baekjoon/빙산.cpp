#include <iostream>
#include <vector>
#define MAX 300

using namespace std;

bool visit[MAX][MAX];
int map[MAX][MAX];
int n, m;
vector<pair<int, int>>ice;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

void printmap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				ice.push_back(make_pair(i, j));
			}
			else
				visit[i][j] = 1;
		}
	}
}

void searchit(pair<int,int> i) {
	for (int p = 0; p < 4; p++) {
		int x = i.first + dx[p];
		int y = i.second + dy[p];
		if (visit[x][y]) continue;
		if (!visit[x][y]) {
			visit[x][y] = 1;
			searchit(make_pair(x, y));
		}
	}
}

void set0(vector<pair<int,int>>t) {
	for (auto i : t) {
		visit[i.first][i.second] = 0;
	}
}

int sol() {
	int ans = 0;

	while (1) {
		ans++;
		vector<int>melt;
		vector<pair<int, int>>temp;
		for (auto i : ice) {
			int c = 0;
			for (int j = 0; j < 4; j++) {
				int x = i.first + dx[j];
				int y = i.second + dy[j];
				if (x < 0 || x >= n) continue;
				if (y < 0 || y >= m) continue;
				if (map[x][y] == 0) c++;
			}
			melt.push_back(c);
		}
		for (int i = 0; i < melt.size(); i++) {
			int x = ice[i].first;
			int y = ice[i].second;
			if (map[x][y] - melt[i] <= 0) map[x][y] = 0;
			else {
				map[x][y] = map[x][y] - melt[i];
				temp.push_back(make_pair(x, y));
			}
		}
		bool flag = 0;
		ice.clear();
		set0(temp);
		for (auto i : temp) {
			if (!visit[i.first][i.second]) {
				//cout << i.first << ' ' << i.second << '\n';
				visit[i.first][i.second] = 1;
				if (!flag)
					flag = 1;
				else
					return ans;
				searchit(i);
			}
			ice.push_back(i);
		}
		if (temp.size() == 0)
			return 0;
		//printmap();
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	input();
	cout << sol();

	return 0;
}
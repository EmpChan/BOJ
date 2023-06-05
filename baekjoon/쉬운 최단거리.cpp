#include<iostream>
#include<queue>

using namespace std;
using place = pair<int, int>;

int map[1000][1000];
bool visit[1000][1000];
int n, m;
place k;

void sol() {
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };
	queue<place>q;
	int c = 1;
	q.push(k);
	visit[k.first][k.second] = 1;
	map[k.first][k.second] = 0;
	while (!q.empty()) {
		queue<place>tmp;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = dx[i] + x;
				int yy = dy[i] + y;
				if (xx < 0 || xx >= n) continue;
				if (yy < 0 || yy >= m)continue;
				if (visit[xx][yy])continue;
				visit[xx][yy] = 1;
				map[xx][yy] = c;
				tmp.push(make_pair(xx, yy));
			}
		}
		swap(q, tmp);
		c++;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)k = make_pair(i, j);
			if (!map[i][j])visit[i][j] = 1;
		}
	}
	sol();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j])cout << map[i][j] << ' ';
			else cout << -1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
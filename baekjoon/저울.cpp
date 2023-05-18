#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int counts[101];
vector<int>highrank[101];
bool visit[101];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, a, b;
	queue<int>bfs;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		highrank[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 100; j++) visit[j] = 0;
		visit[i] = 1;
		bfs.push(i);
		while (!bfs.empty()) {
			for (auto k : highrank[bfs.front()]) {
				if (!visit[k]) {
					counts[k]++;
					bfs.push(k);
					visit[k] = 1;
					counts[i]++;
				}
			}
			bfs.pop();
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << n-1-counts[i] << '\n';
	}

	return 0;
}
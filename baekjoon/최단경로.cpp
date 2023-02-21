#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#define INF 2000000

using namespace std;

vector<pair<int, int>>dots[20001];
int dist[20001];

void sol(int n, int m, int v) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push(make_pair(0, v));
	dist[v] = 0;
	while (!pq.empty()) {
		int d = pq.top().first;
		int p = pq.top().second;
		pq.pop();
		for (auto i : dots[p]) {
			int linkd = d+i.first;
			int linkp = i.second;
			if (dist[linkp] > linkd) {
				dist[linkp] = linkd;
				pq.push(make_pair(linkd,linkp));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 1; i <= 20000; i++) dist[i] = INF;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dots[a].push_back(make_pair(c, b));
	}
	sol(n,m,v);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

	return 0;
}

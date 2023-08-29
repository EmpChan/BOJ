#include<iostream>
#include<vector>
#include<queue>
#define INF 1000000000

using namespace std;
using lld = long long;
using info = pair<int, int>;

int n, m, a, b, c, s, e;
vector<info> load[1001];
vector<int> way[1001];
int dist[1001];

void sol() {
	priority_queue<info, vector<info>, greater<info>>pq;
	for (int i = 1; i <= n; i++) dist[i] = INF;
	for (auto i : load[s]) {
		if (!dist[i.second] || dist[i.second] > i.first) {
			way[i.second].clear();
			way[i.second].push_back(i.second);
			dist[i.second] = i.first;
			pq.push(i);
		}
	}
	dist[s] = 0;
	while (!pq.empty()) {
		int l = pq.top().first;
		int d = pq.top().second;
		pq.pop();
		if (l > dist[d])continue;
		for (auto i : load[d]) {
			int ll = l + i.first;
			int dd = i.second;
			if (ll < dist[dd]) {
				dist[dd] = ll;
				way[dd].clear();
				for (auto j : way[d]) {
					way[dd].push_back(j);
				}
				way[dd].push_back(dd);
				pq.push(make_pair(ll, dd));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		load[a].push_back(make_pair(c, b));
	}
	cin >> s >> e;
	sol();
	
	cout << dist[e] << '\n' << way[e].size() + 1 << '\n';
	cout << s << ' ';
	for (auto i : way[e]) {
		cout << i << ' ';
	}

	return 0;
}
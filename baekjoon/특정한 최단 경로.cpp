#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define MAX 200000001;

using namespace std;

vector<pair<int, int>> dots[801];
long long dist[3][801];
int arr[3];

void setting() {
	arr[0] = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= 800; j++)
			dist[i][j] = MAX;
	}
}


void sol(int v) {
	priority_queue<pair<long,long>, vector<pair<long, long>>, greater<pair<long, long>>>pq;
	pq.push(make_pair(0, arr[v]));
	dist[v][arr[v]] = 0;
	while (!pq.empty()) {
		int d = pq.top().first;
		int p = pq.top().second;
		pq.pop();
		for (auto i : dots[p]) {
			int linkd = i.first+d;
			int linkp = i.second;
			if (linkd < dist[v][linkp]) {
				dist[v][linkp] = linkd;
				pq.push(make_pair(linkd, linkp));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	setting();
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dots[a].push_back(make_pair(c, b));
		dots[b].push_back(make_pair(c, a));
	}
	cin >> arr[1] >> arr[2];
	arr[0] = 1;
	for (int i = 0; i < 3; i++) sol(i);
	/*for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}*/
	if (dist[0][arr[1]] >= 200000001 || (dist[0][arr[2]] >= 200000001 || dist[0][n] >= 200000001))
		cout << -1;
	else
		cout << min(dist[0][arr[1]] + dist[1][arr[2]] + dist[2][n], dist[0][arr[2]] + \
			dist[2][arr[1]] + dist[1][n]);

	return 0;
}
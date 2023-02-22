#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

bool visit[110000];

int sol(int p,int ans) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	visit[p] = 1;
	pq.push(make_pair(0, p));
	while (!pq.empty()) {
		int d = pq.top().first;
		int l = pq.top().second;
		pq.pop();
		if (l == ans)
			return d;
		if (l*2<110000) {
			if (!visit[l * 2]) {
				pq.push(make_pair(d, l * 2));
				visit[l * 2] = 1;
			}
		}
		if (l - 1 >= 0) {
			if (!visit[l - 1]) {
				pq.push(make_pair(d + 1, l - 1));
				visit[l - 1] = 1;
			}
		}
		if (l + 1 <= 100000) {
			if (!visit[l + 1]) {
				pq.push(make_pair(d + 1, l + 1));
				visit[l + 1] = 1;
			}
		}
	}
	return 0;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	cout << sol(n, m);
	
	return 0;
}
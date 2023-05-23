#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>>pq[7];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, c = 0, a,b;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		while (!pq[a].empty() && pq[a].top() > b) {
			c++;
			pq[a].pop();
		}
		if (!pq[a].empty() && pq[a].top() == b)continue;
		else {
			pq[a].push(b);
			c++;
		}
	}

	cout << c << '\n';

	return 0;
}
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int cnt[101];
vector<pair<int, int>>info[101];

void sol(int n) {
	set<int>s;
	s.insert(n);
	cnt[n] = 1;
	while (!s.empty()) {
		int k = *(--s.end());
		int w = cnt[k];
		s.erase(k);
		if (!info[k].size())continue;
		for (auto i : info[k]) {
			s.insert(i.second);
			cnt[i.second] += w * i.first;
		}
		cnt[k] -= w;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		info[a].push_back(make_pair(c, b));
	}

	sol(n);

	for (int i = 1; i <= n; i++) {
		if (!info[i].size())cout << i << ' ' << cnt[i] << '\n';
	}

	return 0;
}

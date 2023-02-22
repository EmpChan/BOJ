#include <iostream>
#include <vector>

using namespace std;

vector<int>needs[1001];
int weight[1001];
bool visit[1001];
int key;


void set0() {
	for (int i = 1; i <= 1000; i++) {
		needs[i].clear();
		visit[i] = 0;
	}
}

void input(int m) {
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		needs[b].push_back(a);
	}
	cin >> key;
}

void sol(int i) {
	int maxi = 0;
	for (auto p : needs[i]) {
		if (!visit[p]) {
			sol(p);
			visit[p] = 1;
		}
		maxi = max(weight[p], maxi);
	}
	weight[i] += maxi;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	for (int p = 0; p < t; p++) {
		set0();
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> weight[i];
		input(m);
		sol(key);
		cout << weight[key] << '\n';
	}

	return 0;
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int>links[32001];
int counts[32001];

void sol(int n) {
	priority_queue<int, vector<int>, greater<int>>pro;
	for (int i = 1; i <= n; i++) {
		if (counts[i] == 0) {
			pro.push(i);
		}
	}
	while (!pro.empty()) {
		int cup = pro.top();
		pro.pop();
		cout << cup << ' ';
		for (auto i : links[cup]) {
			if (--counts[i] == 0)
				pro.push(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		counts[b]++;
		links[a].push_back(b);
	}
	sol(n);
	return 0;
}
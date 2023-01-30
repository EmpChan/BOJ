#include <iostream>
#include <set>
#include <map>

using namespace std;

map<int, set<int>>computer;
bool visited[101];

void infect(int v) {
	for (auto i : computer[v]) {
		if (!visited[i]) {
			visited[i] = 1;
			infect(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, c=0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		computer[a].insert(b);
		computer[b].insert(a);
	}
	visited[1] = 1;
	infect(1);
	for (int i = 1; i <= n; i++) {
		if (visited[i])
			c++;
	}
	cout << c-1;
	return 0;
}
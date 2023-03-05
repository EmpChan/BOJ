#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int>tree[100001];
bool visit[100001];
int subtree[100001];

void search(int root) {
	for (auto i : tree[root]) {
		if (!visit[i]) {
			visit[i] = 1;
			search(i);
			subtree[root] += subtree[i];
		}
		else {
			continue;
		}
	}
	subtree[root]++;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, r, q;
	cin >> n >> r >> q;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	visit[r] = 1;
	search(r);

	for (int i = 1; i <= q; i++) {
		int a;
		cin >> a;
		cout << subtree[a] << '\n';
	}


	return 0;
}
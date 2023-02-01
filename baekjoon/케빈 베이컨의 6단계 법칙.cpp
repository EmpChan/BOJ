#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<int, set<int>>nodes;
bool visit[101];
int r[101];

void set0() {
	for (int i = 1; i <= 100; i++) {
		visit[i] = 0;
	}
}

void bfs(int v,int n) {
	int arr[100];
	int temp[100];
	arr[0] = v;
	int k = 1;
	int x = 0;
	int counting = 1;
	while (counting <n ) {
		int cup = k;
		k = 0;
		x++;
		for (int i = 0; i < cup; i++) {
			for (auto j : nodes[arr[i]]) {
				if (!visit[j]) {
					r[v] += x;
					temp[k++] = j;
					counting++;
					visit[j] = 1;				}
			}
		}
		for (int i = 0; i < k; i++) {
			arr[i] = temp[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		nodes[a].insert(b);
		nodes[b].insert(a);
	}
	for (int i = 1; i <= n; i++) {
		visit[i] = 1;
		bfs(i,n);
		set0();
	}
	int asdf = 9999999;
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (r[i] < asdf) {
			asdf = r[i];
			result = i;
		}
	}
	cout << result;
	return 0;
}
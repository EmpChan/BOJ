#include <iostream>
#include <algorithm>

using namespace std;

int map[1001][1000];
int counting[1001];
bool visit[1001];

void set0() {
	for (int i = 1; i <= 1000; i++) {
		visit[i] = 0;
	}
	visit[0] = 1;
}

void bfs(int v) {
	int arr[1000];
	int temp[1000];
	int j = 0,k=1;
	cout << v << ' ';
	visit[v] = 1;
	arr[0] = v;
	while (k > 0) {
		j = k;
		k = 0;
		for (int i = 0; i < j; i++) {
			for (int q : map[arr[i]]) {
				if (!visit[q]) {
					temp[k++] = q;
					visit[q] = 1;
					cout << q << ' ';
				}
			}
		}
		for (int i = 0; i < k; i++) {
			arr[i] = temp[i];
		}
	}
}

void dfs(int v) {
	cout << v << ' ';
	visit[v] = 1;
	for (int i : map[v]) {
		if (visit[i])
			continue;
		dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][counting[a]++] = b;
		map[b][counting[b]++] = a;
	}
	for (int i = 1; i <= n; i++) {
		sort(map[i], map[i] + counting[i]);
	}
	set0();
	dfs(v);
	cout << '\n';
	set0();
	bfs(v);


	return 0;
}
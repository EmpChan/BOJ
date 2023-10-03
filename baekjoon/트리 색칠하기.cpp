#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define MAX 3000000000

using namespace std;
using lld = long long;
using info = pair<pair<int,int>, int>;
using dvect = vector<vector<int>>;

vector<int> color;
vector<int> link[200001];
vector<bool>visit;
int cnt;

void dfs(int n, int c) {
	if (color[n] != c) {
		cnt++;
	}
	for (auto i : link[n]) {
		if (visit[i])continue;
		else {
			visit[i] = 1;
			dfs(i, color[n]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,a,b;
	cin >> n;
	color.resize(n+1);
	visit.resize(n+1);
	for (int i = 1; i <= n; i++) cin >> color[i];
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
	}
	visit[1] = 1;
	dfs(1, 0);
	cout << cnt;

	return 0;
}
#include <iostream>

using namespace std;
using item = pair<int, int>; // time, val;

int napsack[10001];
item items[100];


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		items[i] = make_pair(a, b);
	}
	for (int i = 0; i < n; i++) {
		int t = items[i].first;
		int val = items[i].second;
		for (int j = m; j >= t; j--) {
			napsack[j] = max(napsack[j], napsack[j - t] + val);
		}
	}
	cout << napsack[m] << '\n';
	return 0;
}
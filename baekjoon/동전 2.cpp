#include <iostream>
#include <vector>

using namespace std;

int coincount[10001];

vector<int> coins;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		coins.push_back(a);
	}

	for (auto c : coins) { // c is coin's value
		for (int v = c; v <= m; v++) {
			if ((!coincount[v-c] && v%c != 0)) {
				continue;
			}
			else{
				if (!coincount[v - c]) {
					coincount[v] = v / c;
				}
				else {
					if (!coincount[v])coincount[v] = coincount[v - c] + 1;
					else {
						coincount[v] = min(coincount[v], coincount[v - c] + 1);
					}
				}
			}
		}
	}
	if (!coincount[m]) cout << -1;
	else cout << coincount[m];

	return 0;
}
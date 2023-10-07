#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
#define INF 1000000001

using namespace std;
using lld = long long;
using info = pair<int, int>;

int n, m;

info memory[MAX];
int dp[10000001];

void sol() {
	dp[0] = 0;
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (memory[i].first >= m) {
			dp[m] = min(dp[m], memory[i].second);
			continue;
		}
		for (int j = min(m,s+memory[i].first); j >= 0; j--) {
			dp[j] = min(dp[j], memory[i].second + dp[max(0,j - memory[i].first)]);
		}
		s += memory[i].first;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> memory[i].first;
	}
	for (int j = 0; j < n; j++) {
		cin >> memory[j].second;
	}
	for (int i = 0; i <= m; i++)dp[i] = INF;

	sol();

	/*for (int i = 0; i <= m; i++) {
		cout << dp[i] << ' ';
		if (i > 0 && i % 10 == 0)cout << '\n';
	}*/

	cout << dp[m];

	return 0;
}
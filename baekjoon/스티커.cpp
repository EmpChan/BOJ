#include <iostream>

using namespace std;

int map[220000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < 2*n; j++) {
			cin >> map[j];
		}
		int dp[3][2] = {0};
		if (n == 1) {
			cout << max(map[0], map[1]) << '\n';
			continue;
		}
		dp[1][0] = map[0];
		dp[1][1] = map[n];
		dp[2][0] = dp[1][1] + map[1];
		dp[2][1] = dp[1][0] + map[n+1];
		for (int j = 2; j < n; j++) {
			dp[0][0] = dp[1][0];
			dp[0][1] = dp[1][1];
			dp[1][0] = dp[2][0];
			dp[1][1] = dp[2][1];
			dp[2][0] = max(dp[1][1] + map[j], dp[0][1] + map[j]);
			dp[2][1] = max(dp[1][0] + map[j + n], dp[0][0] + map[j + n]);
		}
		cout << max(dp[2][0], dp[2][1]) << '\n';
	}
	
	return 0;
}
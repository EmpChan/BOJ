#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
#define INF 1000000001

using namespace std;
using lld = long long;
using info = pair<int, int>;

int n;
vector<vector<int>>cost;
int dp[MAX][3];
int mini = INF;

void sol() {
	dp[1][0] = cost[1][0]; 
	dp[1][1] = cost[1][1]; 
	dp[1][2] = cost[1][2];
	dp[2][0] = cost[2][0] + min(dp[1][1], dp[1][2]);
	dp[2][2] = cost[2][2] + min(dp[1][0], dp[1][1]);
	dp[2][1] = cost[2][1] + min(dp[1][0], dp[1][2]);
	for (int i = 3; i <= n; i++) {
		dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}
	/*for (int i = 1; i <= n; i++) {
		for(int j=0; j<3; j++)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';*/
	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n; cost.resize(n+1);
	for (int i = 0; i <= n; i++)cost[i].resize(3);
	for (int i = 1; i <= n; i++) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	
	for (int i = 0; i < 3; i++) {
		int tmp = cost[1][i];
		cost[1][i] = INF;
		sol();
		
		mini = min(mini, dp[n][i]);
		cost[1][i] = tmp;
	}


	cout << mini;
	
	return 0;
}
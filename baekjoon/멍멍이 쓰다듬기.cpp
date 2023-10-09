#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#define MAX 1000000001
#define INF 100000000001

using namespace std;
using lld = long long;

vector<int>arr;
vector<pair<int, int>> step;
vector<int>dp;

void sol() {
	dp.resize(arr.size() + 1);
	dp[0] = 0;
	step[0] = make_pair(0, 0);
	dp[1] = 2;
	step[1] = make_pair(arr[1], 0);


}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b;
	lld s = 0;
	cin >> a >> b;
	for (int i = 0; s*2 <= b - a; i++) {
		s += i;
		if (s * 2 >= b - a) {
			cout << i * 2;
			return 0;
		}
		else if (s * 2 + i + 1 >= b - a) {
			cout << i * 2 + 1;
			return 0;
		}
	}

	return 0;
}
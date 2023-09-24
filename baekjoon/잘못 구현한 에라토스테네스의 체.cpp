#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#define MAX 1000001

using namespace std;
using lld = long long;
using info = pair<int, int>;
using dvect = vector<vector<int>>;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	lld ans = 0;
	int n;
	cin >> n;
	ans = n;
	int i;
	if (n > 1000000) {
		for (i = 1; (n - 1) / i >= 1000; i++) {
			ans += (n - 1) / i;
		}
		ans -= (i * 999);
		for (int i = 1; i < 1000; i++) {
			ans += 1 + (n - 1) / i;
		}
	}
	else {
		for (i = 1; (n - 1) / i > 0; i++) {
			ans += (n - 1) / i;
		}
	}
	cout << ans;
	return 0;
}
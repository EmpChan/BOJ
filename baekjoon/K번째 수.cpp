#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#define MAX 2000000000

using namespace std;
using lld = long long;

lld n, ans;

void sol() {
	lld mini = 1, maxi = n*n;
	while (mini!=maxi) {
		//cout << mini << ' ' << maxi << '\n';
		lld mid = (maxi + mini) / 2;
		lld r = 0;
		for (int i = 1; i <= min(mid, n); i++) {
			r += min(n, mid / i);
		}
		if (r == ans) break;
		else if (r > ans) maxi = mid;
		else mini = mid + 1;
	}
	lld mid = (mini + maxi) / 2;
	maxi = 0;
	for (int i = 1; i <= min(mid, n); i++) {
		maxi = max(maxi,i * min(n, mid / i));
	}
	ans = maxi;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> ans;

	sol();

	cout << ans;

	return 0;
}
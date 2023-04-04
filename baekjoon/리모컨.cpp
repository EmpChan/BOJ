#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool but[10];

int sol(int n) {
	int mini = abs(n - 100);
	for (int i = 0; i <= 1000000; i++) {
		int cup = i;
		if (cup == 0) {
			if (but[cup])
				continue;
			else {
				mini = min(mini, n+1);
			}
		}
		else {
			bool flag = 0;
			int s = 0;
			while (cup > 0) {
				s++;
				if (but[cup%10]) {
					flag = 1;
					break;
				}
				cup /= 10;
			}
			if (!flag) {
				mini = min(mini, abs(n - i) + s);
			}
		}
	}
	return mini;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		but[a] = 1;
	}

	cout << sol(n);


	return 0;
}
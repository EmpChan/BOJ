#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int mini = 50000;

void solution(int i, int k) {
	if (i + 1 >= mini)
		return;
	for (int p = sqrt(k); p >= 1; p--) {
		if (k - p * p == 0) {
			mini = min(i + 1, mini);
		}
		else {
			solution(i + 1, k - p * p);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	solution(0, n);
	cout << mini;
	return 0;
}
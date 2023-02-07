#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin >> n;
	int l = 0;
	long long cup = n;
	while (cup > 0) {
		cup /= 10;
		l++;
	}
	for (long long i = n - (9 * l); i <= n; i++) {
		long long r = i;
		cup = i;
		while (cup > 0) {
			r += cup % 10;
			cup /= 10;
		}
		if (r == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0; 
	return 0;
}
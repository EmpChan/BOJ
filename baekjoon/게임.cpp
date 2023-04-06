#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int r = 1000000000;
	long long x, y, z, cup,count = 0;
	cin >> x >> y;
	z = (y * 100) / (x);
	if (z >= 99) {
		cout << -1 << '\n';
		return 0;
	}
	while (r > 0) {
		cup = ((y + r) * 100) / (x + r);
		//cout << cup << ' ' << z << ' ' << count << '\n';
		if (r == 1) {
			cup = ((y) * 100) / (x);
			while (cup == z) {
				y++; x++;
				cup = ((y) * 100) / (x);
				count++;
			}
			break;
		}
		else if (cup > z) {
			r /= 10;
		}
		else {
			y += r;
			x += r;
			count += r;
		}
	}
	cout << count << '\n';

	return 0;
}
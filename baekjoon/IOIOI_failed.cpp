#include <iostream>

using namespace std;

string cutstring(string a, int i, int j) {
	string cup = "";
	for (int p = i; p <= j; p++) {
		cup += a[p];
	}
	return cup;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m,c=0,r =0;
	cin >> n >> m;
	string a;
	cin >> a;
	bool flag = 0;
	for (int i = 0; i < m; i++) {
		if (!flag) {
			if (a[i] == 'O') continue;
			if (i + 2 >= m) break;
			if (cutstring(a, i, i + 2) == "IOI") {
				flag = 1;
				c = 1;
				i += 2;
			}
		}
		else {
			while (i + 1 < m && cutstring(a, i, i + 1) == "OI") {
				c++;
				i += 2;
			}
			flag = 0;
			if (c >= n) {
				r += (c - n + 1);
			}
			c = 0;
			i--;
		}
	}
	if (c >= n) {
		r += (c - n + 1);
	}

	cout << r << '\n';
	
	return 0;
}

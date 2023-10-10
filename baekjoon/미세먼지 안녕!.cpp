#include <iostream>

using namespace std;

int map[50 * 50];
int mtemp[50 * 50];
int a[2] = { -1 };
int n, m;

void outmap() {
	for (int i = 0; i < n*m; i++) {
		if (i % m == 0)
			cout << '\n';
		cout << map[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int t;
	cin >> n >> m >> t;

	for (int i = 0; i < n * m; i++) {
		cin >> map[i];
		if (map[i] == -1) {
			if (a[0] == -1)
				a[0] = i;
			else
				a[1] = i;
		}
		mtemp[i] = map[i];
	}
	

	for (int qwer = 0; qwer < t; qwer++) {
		for (int i = 0; i < n * m; i++) {
			if (map[i] == 0 || map[i] == -1)
				continue;
			int cup = map[i] / 5;
			if (i % m != 0) {
				if (map[i - 1] != -1) {
					mtemp[i - 1] += cup;
					mtemp[i] -= cup;
				}
			}
			if (i % m != m - 1) {
				mtemp[i + 1] += cup;
				mtemp[i] -= cup;
			}
			if (i - m >= 0) {
				if (map[i - m] != -1) {
					mtemp[i - m] += cup;
					mtemp[i] -= cup;
				}
			}
			if (i + m < n * m) {
				if (map[i + m] != -1) {
					mtemp[i + m] += cup;
					mtemp[i] -= cup;
				}
			}
		}
		for (int i = a[0]-m; i >=0; i -= m) { // airfresher left
			if (mtemp[i + m] == -1)
				mtemp[i] = 0;
			else {
				mtemp[i + m] = mtemp[i];
				mtemp[i] = 0;
			}
		}
		for (int i = 1; i <= m - 1; i++) {
			mtemp[i - 1] = mtemp[i];
			mtemp[i] = 0;
		}
		for (int i = m+m-1; i <= a[0] + m - 1; i += m) {
			mtemp[i - m] = mtemp[i];
			mtemp[i] = 0;
		}
		for (int i = a[0] + m - 2; i > a[0]; i--) {
			mtemp[i + 1] = mtemp[i];
			mtemp[i] = 0;
		}
		for (int i = a[1] + m; i < n*m; i += m) { // airfresher right
			if (mtemp[i - m] == -1)
				mtemp[i] = 0;
			else {
				mtemp[i - m] = mtemp[i];
				mtemp[i] = 0;
			}
		}
		for (int i = (n-1)*m+1; i < n*m; i++) {
			mtemp[i - 1] = mtemp[i];
			mtemp[i] = 0;
		}
		for (int i = n*m-1; i >= a[1] + m - 1; i -= m) {
			mtemp[i + m] = mtemp[i];
			mtemp[i] = 0;
		}
		for (int i = a[1] + m - 2; i > a[1]; i--) {
			mtemp[i + 1] = mtemp[i];
			mtemp[i] = 0;
		}
		for (int i = 0; i < n * m; i++) {
			map[i] = mtemp[i];
		}
	}
	
	int s = 0;

	for (int i = 0; i < n * m; i++) {
		s += map[i];
	}

	cout << s + 2;

	return 0;
}
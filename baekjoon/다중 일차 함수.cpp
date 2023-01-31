#include <iostream>

using namespace std;

int map[100001];
int x[100000];

int search(double n,int m) {
	int a = m / 2, h=m,l=0;
	while (true) {
		if (n < x[a+1] && n>x[a])
			break;
		else {
			if (x[a+1] < n) {
				l = a;
				a = (h + l) / 2;
			}
			else {
				h = a;
				a = (h + l) / 2;
			}
		}
	}
	return map[a+1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> x[i] >> b;
		if (b > k)
			map[i] = 1;
		else if (b < k)
			map[i] = -1;
		else
			map[i] = 0;
		k = b;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		double cup;
		cin >> cup;
		cout << search(cup,n-1) << '\n';
	}
	return 0;
}
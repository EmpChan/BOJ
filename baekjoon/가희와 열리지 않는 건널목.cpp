#include <iostream>

using namespace std;

bool down[60 * 60 * 24];

void checkt(string a) {
	int t = 0;
	int k = 0;
	int arr[] = { 1,10, 60,600, 3600,36000};
	for (int i = a.length() - 1; i >= 0; i--) {
		if (a[i] == ':')continue;
		else {
			t += (a[i] - '0') * arr[k++];
		}
	}
	for (int i = 0; i < 40; i++) {
		down[i+t] = 1;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m,c=0;
	int maxt = 60 * 60 * 24;
	cin >> n >> m;
	for (int i = 0; i < n+m; i++) {
		string a;
		cin >> a;
		checkt(a);
	}

	for (int i = 0; i < maxt; i++) {
		if (!down[i])c++;
	}

	cout << c << '\n';

	return 0;
}
#include <iostream>

using namespace std;

int belong[1000001];
int arr[200000];

int find_its_root(int n) {
	int a=n, b=belong[n];
	int x = 0;
	arr[x++] = a;
	while (a != b) {
		a = b;
		b = belong[a];
	}
	for (int i = 0; i < x; i++) {
		belong[arr[i]] = b;
	}
	return b;
}

void unionset(int a, int b) {
	belong[find_its_root(b)] = belong[find_its_root(a)];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 1000000; i++) belong[i] = i;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k, a, b;
		cin >> k >> a >> b;
		if (!k) {
			unionset(a, b);
		}
		else {
			if (find_its_root(a) == find_its_root(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	
	return 0;
}
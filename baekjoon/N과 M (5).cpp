#include <iostream>
#include <algorithm>

using namespace std;

int n[8];
int arr[8];
int visit[8];

void nnm(int a, int b, int c) {
	if (c >= b) {
		for (int i = 0; i < c; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < a; i++) {
		if (!visit[i]) {
			arr[c] = n[i];
			visit[i] = 1;
			nnm(a, b, c + 1);
			visit[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> n[i];
	}
	sort(n, n + a);
	nnm(a, b, 0);
	

	return 0;
}
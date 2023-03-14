#include <iostream>
#include <algorithm>

using namespace std;

int arr[8];
int ans[8];
int visit[8];

void nnms(int c,int j, int n,int m) {
	if (c == m) {
		for (int i = 0; i < c; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = j; i < n; i++) {
			if (!visit[i] && arr[i] >= ans[c-1]) {
				visit[i] = 1;
				ans[c] = arr[i];
				nnms(c + 1, j + 1, n, m);
				visit[i] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	nnms(0,0, n, m);

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

char arr[16];
char output[20];
bool visit[16];

void outit(int p,int q, int n,int m) {
	if (p+q >= n) {
		if (p < 1 || q < 2)
			return;
		for (int i = 0; i < n; i++) {
			cout << output[i];
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < m; i++) {
		bool flag = 0;
		if (visit[i])
			continue;
		for (int k = 0; k < p+q; k++) {
			if (output[k] > arr[i]) {
				flag = 1;
				break;
			}
		}
		if (flag)
			continue;
		visit[i] = 1;
		output[p+q] = arr[i];
		if (arr[i] == 'a' || ((arr[i] == 'e' || arr[i] == 'i') || (arr[i] == 'o' || arr[i] == 'u')))
			outit(p + 1, q, n, m);
		else
			outit(p, q + 1, n, m);
		visit[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + m);
	outit(0,0,n,m);

	return 0;
}
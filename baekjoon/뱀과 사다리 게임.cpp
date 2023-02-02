#include <iostream>

using namespace std;

int teleport[101];
int visit[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int a, b;
		cin >> a >> b;
		teleport[a] = b;
	}
	int counting=0;
	int arr[100], temp[100],j,k=1;
	arr[0] = 1;
	while (true) {
		j = k;
		k = 0;
		for (int i = 0; i < j; i++) {
			if (arr[i] == 100){
				cout << counting;
				return 0;
			}
			for (int a = 1; a <= 6; a++) {
				if (visit[arr[i] + a] || arr[i]+a >100)
					continue;
				visit[arr[i] + a] = 1;
				if (teleport[arr[i] + a]) {
					temp[k++] = teleport[arr[i] + a];
				}
				else {
					temp[k++] = arr[i] + a;
				}
			}
		}
		for (int i = 0; i < k; i++) {
			arr[i] = temp[i];
		}
		counting++;
	}

	return 0;
}
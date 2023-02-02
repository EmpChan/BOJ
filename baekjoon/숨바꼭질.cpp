#include <iostream>

using namespace std;

int map[110001];
int visit[110001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m,counting=0;
	cin >> n >> m;
	int arr[110000], temp[110000],j,k=1;
	arr[0] = n;
	while (true) {
		counting++;
		j = k;
		k = 0;
		for (int i = 0; i < j; i++) {
			if (arr[i] == m) {
				cout << counting-1;
				return 0;
			}
			if (!visit[arr[i]]) {
				visit[arr[i]] = 1;
				if (arr[i] - 1 >= 0) { 
					if(!visit[arr[i]-1])
						temp[k++] = arr[i] - 1; 
				}
				if (arr[i] * 2 <= 110000) {
					if(!visit[arr[i]*2])
						temp[k++] = arr[i] * 2;
				}
				if (arr[i] + 1 <= 110000) {
					if (!visit[arr[i] + 1])
						temp[k++] = arr[i] + 1;
				}
			}
		}
		for (int i = 0; i < k; i++) {
			arr[i] = temp[i];
		}
	}

	return 0;
}
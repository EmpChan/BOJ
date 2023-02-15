#include <iostream>

using namespace std;

int map[1000001];
int area[1000001];
int n, m, j;

void search(int i) {
	if (map[i] != 0)
		return;
	map[i] = j;
	if (i % m != 0) search(i - 1);
	if (i % m != m - 1) search(i + 1);
	if(i+m <n*m) search(i + m);
	if(i-m >=0) search(i - m);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < a.length(); j++) {
			map[i * m + j] = a[j]-'0';
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (map[i] == 0) {
			j--;
			search(i);
		}
	}
	for (int i = 0; i < n*m; i++) {
		if (map[i] != 1) {
			area[map[i]*-1]++;
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (map[i] == 1) {
			int carr[5];
			int k = 0;
			if (i %m != 0)carr[k++] = i - 1;
			if (i % m != m - 1) carr[k++] = i + 1;
			if (i + m < n * m) carr[k++] = i + m;
			if (i - m >= 0) carr[k++] = i - m;
			for (int p = 0; p < k; p++) {
				bool flag = 0;
				for (int q = 0; q < p; q++) {
					if (map[carr[p]] == map[carr[q]])
						flag = 1;
				}
				if (!flag && map[carr[p]]<0)
					map[i] += area[map[carr[p]]*-1];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int p = 0; p < m; p++) {
			cout << max((map[i*m+p])%10,0);
		}
		cout << '\n';
	}

	return 0;
}
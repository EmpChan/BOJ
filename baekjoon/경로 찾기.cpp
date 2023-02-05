#include <iostream>

using namespace std;

bool map[100][100];
bool visit[100];

void set0() {
	for (int i = 0; i < 100; i++)
		visit[i] = 0;
}

void search(int i,int v) {
	for (int j = 0; j < 100; j++) {
		if (map[i][j] && !visit[j]) {
			visit[j] = 1;
			map[v][j] = 1;
			search(j, v);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		set0();
		search(i,i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
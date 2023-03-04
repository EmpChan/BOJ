#include <iostream>

using namespace std;

int map[50][50];
bool visit[50][50];

int n, mi, ma,s,counting;
int arr[2500][2];
bool flag;

void set0() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			visit[i][j] = 0;
		}
	}
}

void printmap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool isinrange(int x1, int y1, int x, int y) {
	int d = max(map[x][y], map[x1][y1]) - min(map[x][y], map[x1][y1]);
	if (d >= mi && d <= ma)
		return 1;
	else
		return 0;
}

void search(int x, int y) {
	arr[counting][0] = x;
	arr[counting++][1] = y;
	s += map[x][y];
	if (x - 1 >= 0 && (isinrange(x-1,y,x,y) && !visit[x-1][y])) {
		visit[x - 1][y] = 1;
		search(x - 1, y);
	}
	if (x + 1 < n && (isinrange(x + 1, y, x, y) && !visit[x + 1][y])) {
		visit[x + 1][y] = 1;
		search(x + 1, y);
	}
	if (y - 1 >= 0 && (isinrange(x, y - 1, x, y) && !visit[x][y - 1])) {
		visit[x][y - 1] = 1;
		search(x, y - 1);
	}
	if (y + 1 < n && (isinrange(x, y + 1, x, y) && !visit[x][y + 1])) {
		visit[x][y + 1] = 1;
		search(x, y + 1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> mi >> ma;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int c = -1;
	while (!flag) {
		c++;
		set0();
		flag = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j]) {
					s = 0;
					counting = 0;
					visit[i][j] = 1;
					search(i, j);
					if (counting >= 2)
						flag = 0;
					for (int p = 0; p < counting; p++) {
						map[arr[p][0]][arr[p][1]] = s / counting;
					}
				}
			}
		}
	}
	cout << c;

	return 0;
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[100][100];
bool visit[100][100];
int maxcount;
int counting;
int n;

void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
		}
	}
	counting = 0;
}

void search(int h, int x, int y) {
	if (x < 0 || y < 0)
		return;
	if (x >= n || y >= n)
		return;
	if (visit[x][y])
		return;
	visit[x][y] = 1;
	if (map[x][y] <= h)
		return;
	search(h, x + 1, y);
	search(h, x - 1, y);
	search(h, x, y + 1);
	search(h, x, y - 1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i <= 100; i++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (visit[x][y])
					continue;
				if (map[x][y] <= i){
					visit[x][y] = 1;
					continue;
				}
				counting++;
				search(i, x, y);
			}
		}
		//cout << i << ' ' << counting << '\n';
		maxcount = max(maxcount, counting);
		reset();
	}

	cout << maxcount << '\n';

	return 0;
}
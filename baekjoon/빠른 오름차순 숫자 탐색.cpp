#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using p = tuple<int, int>;
int map[5][5];
bool visit[5][5];

void set0() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			visit[i][j] = 0;
		}
	}
}

void bfs() {
	queue<p>places;
	p cup;
	int k = 1, key = 1,moves=0;
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };
	places.push(cup);
	cin >> get<0>(places.front()) >> get<1>(places.front());
	visit[get<0>(places.front())][get<1>(places.front())] = 1;
	while (k) {
		moves++;
		for (int i = 0; i < k; i++) {
			int fx = get<0>(places.front());
			int fy = get<1>(places.front());
			places.pop();
			for (int j = 0; j < 4; j++) {
				int x = fx + dx[j];
				int y = fy + dy[j];
				if (x >= 5 || x < 0) continue;
				if (y >= 5 || y < 0) continue;
				if (visit[x][y] || map[x][y] == -1) continue;
				visit[x][y] = 1;
				if (map[x][y] == key) {
					map[x][y] = 0;
					if (key >= 6) {
						cout << moves;
						return;
					}
					key++;
					k = 0;
					queue<p>temp;
					swap(places, temp);
					places.push(make_tuple(x, y));
					set0();
					break;
				}
				else {
					places.push(make_tuple(x, y));
				}
			}
		}
		k = places.size();
	}
	cout << -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	bfs();
	return 0;
}

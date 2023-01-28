#include <iostream>

using namespace std;

int map1[100][100];
int map2[100][100];

int common,uncommon;
int n;
void check_map1(int k, int p, int q) {
	if (p >= n || q >= n)
		return;
	if (p < 0 || q < 0)
		return;
	if (map1[p][q] == k)
		map1[p][q] = 0;
	else
		return;
	check_map1(k, p + 1, q);
	check_map1(k, p - 1, q);
	check_map1(k, p, q - 1);
	check_map1(k, p, q + 1);
}
void check_map2(int k, int p, int q) {
	if (p >= n || q >= n)
		return;
	if (p < 0 || q < 0)
		return;
	if (map2[p][q] == k)
		map2[p][q] = 0;
	else
		return;
	check_map2(k, p + 1, q);
	check_map2(k, p - 1, q);
	check_map2(k, p, q - 1);
	check_map2(k, p, q + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string cup;
		cin >> cup;
		for (int j = 0; j < cup.length(); j++) {
			map1[i][j] = cup[j] - 'A';
			if (cup[j] == 'R' || cup[j] == 'G') {
				map2[i][j] = 'R' - 'A';
			}
			else {
				map2[i][j] = 'B' - 'A';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map1[i][j] != 0) {
				common++;
				check_map1(map1[i][j], i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map2[i][j] != 0) {
				uncommon++;
				check_map2(map2[i][j], i, j);
			}
		}
	}
	cout << common << ' ' << uncommon;
	return 0;
}

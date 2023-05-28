#include <iostream>

using namespace std;

int n, m, robot[2];
int map[50 * 50];

bool check() {
	if (robot[0] - m >= 0) {
		if (map[robot[0] - m] == 0) {
			return 1;
		}
	}
	if ((robot[0]) % m != 0) {
		if (map[robot[0] - 1] == 0) {
			return 1;
		}
	}
	if (robot[0] % m != m - 1) {
		if (map[robot[0] + 1] == 0) {
			return 1;
		}
	}
	if (robot[0] + m < n * m) {
		if (map[robot[0] + m] == 0) {
			return 1;
		}
	}
	return 0;
}

void turn() {
	if (robot[1] == 0) {
		robot[1] = 3;
	}
	else {
		robot[1] --;
	}
}

bool goback() {
	if (robot[1] == 0) {
		if (robot[0] + m > n * m)
			return 1;
		if (map[robot[0] + m] == 1)
			return 1;
		robot[0] += m;
	}
	else if (robot[1] == 1) {
		if (robot[0] % m == 0)
			return 1;
		if (map[robot[0] - 1] == 1)
			return 1;
		robot[0]--;
	}
	else if (robot[1] == 2) {
		if (robot[0] - m < 0)
			return 1;
		if (map[robot[0] - m] == 1)
			return 1;
		robot[0] -= m;
	}
	else {
		if (robot[0] % m == m - 1)
			return 1;
		if (map[robot[0] + 1] == 1)
			return 1;
		robot[0]++;
	}
	return 0;
}

void gofoward() {
	if (robot[1] == 0) {
		if (robot[0] - m < 0)
			return;
		if (map[robot[0] - m] == 1 || map[robot[0]-m] == -1)
			return;
		robot[0] -= m;
	}
	else if (robot[1] == 3) {
		if (robot[0] % m == 0)
			return;
		if (map[robot[0] - 1] == 1 || map[robot[0]-1] == -1)
			return;
		robot[0]--;
	}
	else if (robot[1] == 2) {
		if (robot[0] + m > n * m)
			return;
		if (map[robot[0] + m] == 1 || map[robot[0]+m]==-1)
			return;
		robot[0] += m;
	}
	else {
		if (robot[0] % m == m - 1)
			return ;
		if (map[robot[0] + 1] == 1 || map[robot[0]+1] == -1)
			return ;
		robot[0]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	int counting=0;
	bool flag = 0;
	cin >> n >> m;
	if (1) {
		int a, b;
		cin >> a >> b >> robot[1];
		robot[0] = a * m + b;
	}
	for (int i = 0; i < n * m; i++) { // clean=-1 dirty = 0 wal= 1
		cin >> map[i];
	}
	while (!flag) {
		if (map[robot[0]] == 0) {
			map[robot[0]] = -1;
			counting++;
		}
		else{
			if (check()) {
				turn();
				gofoward();
			}
			else {
				if (goback())
					flag = 1;
			}

		}
	}

	cout << counting;

	return 0;
}
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using dat = tuple<int, char, int, int>; // val,oper,x,y

char map[5][5];
int n;
int maxi = -1000000000, mini = 1000000000;

void sol() {
	queue<dat>val;
	val.push(make_tuple(map[0][0] - '0', ' ', 0, 0));
	int k = 1;
	int dx[] = { 1, 0 };
	int dy[] = { 0, 1 };
	while (!val.empty()) {
		for (int i = 0; i < k; i++) {
			int x = get<2>(val.front());
			int y = get<3>(val.front());
			char oper = get<1>(val.front());
			int v = get<0>(val.front());
			val.pop();
			if (x == n - 1 && y == n - 1) {
				maxi = max(maxi, v);
				mini = min(mini, v);
				continue;
			}
			for (int j = 0; j < 2; j++) {
				if (x + dx[j] >= n)continue;
				if (y + dy[j] >= n)continue;
				char tmp = map[x + dx[j]][y + dy[j]];
				int vtmp = v;
				char opert = oper;
				if (tmp >= '0' && tmp <= '9') {
					if (oper == '*') {
						vtmp *= tmp - '0';
					}
					else if (oper == '-') {
						vtmp -= tmp - '0';
					}
					else if (oper == '+') {
						vtmp += tmp - '0';
					}
				}
				else {
					opert = tmp;
				}
				val.push(make_tuple(vtmp, opert, x + dx[j], y + dy[j]));
			}
		}
		k = val.size();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	sol();

	cout << maxi << ' ' << mini;

	return 0;
}
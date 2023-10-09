#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#define MAX 1000000001
#define INF 100000000001

using namespace std;
using lld = long long;

int n, m,cnt;
string dir[1000];
int nums[1000][1000];
bool visit[1000][1000];
vector<int>parent;
int k = 0;

void find(int x, int y, int num) {
	visit[x][y] = 1;
	nums[x][y] = num;
	if (dir[x][y] == 'U') {
		if (visit[x - 1][y])parent[num] = nums[x-1][y];
		else {
			find(x - 1, y, num);
		}
	}
	else if (dir[x][y] == 'D') {
		if (visit[x + 1][y])parent[num] = nums[x + 1][y];
		else {
			find(x + 1, y, num);
		}
	}
	else if (dir[x][y] == 'R') {
		if (visit[x][y+1])parent[num] = nums[x][y+1];
		else {
			find(x, y + 1, num);
		}
	}
	else if(dir[x][y] == 'L') {
		if (visit[x][y - 1])parent[num] = nums[x][y - 1];
		else {
			find(x, y - 1, num);
		}
	}
}

void sol() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				parent.push_back(cnt);
				find(i, j, cnt++);
			}
		}
	}
}

int findans() {
	int ans = 0;
	for (int i = 0; i < parent.size();i++) {
		if (i == parent[i])ans++;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> dir[i];

	sol();

	cout << findans();

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000001
#define INF 100000000001

using namespace std;
using lld = long long;

int n;
bool visit[10][10];
vector<bool>isPutX;
vector<bool>isPutY;
vector<pair<int,int>>start;
int maxShop, now;

void putShop(int sNum) {
	if (sNum >= start.size())return;
	int x = start[sNum].first, y = start[sNum].second;
	bool flag = 0;
	for (int i = 0; x + i < n && y - i >= 0; i++) {
		int xx = x + i;
		int yy = y - i;
		if (!visit[xx][yy])continue;
		if (!isPutX[n-1 + (yy-xx)]) {
			flag = 1;
			isPutX[n - 1 + (yy - xx)] = 1;
			maxShop = max(maxShop, ++now);
			putShop(sNum + 1);
			now--;
			isPutX[n - 1 + (yy - xx)] = 0;
		}
	}
	if(!flag)
		putShop(sNum + 1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	start.resize(n*2-1);
	isPutX.resize(n * 2);
	isPutY.resize(n * 2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> visit[i][j];
		}
	}
	for (int i = 0; i < n * 2-1; i++)start[i].first = min(max(0,i-n+1),n-1);
	for (int i = 0; i < n * 2-1; i++)start[i].second = min(i, n - 1);
	putShop(0);

	cout << maxShop;

	return 0;
}
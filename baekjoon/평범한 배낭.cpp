#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
using thing = pair<int, int>;//first is weight, second is value

int maxvalue[100001];
int temp[100001];
vector<thing>things;
int visit[100];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		thing a;
		cin >> a.first >> a.second;
		things.push_back(a);
	}

	for (auto t:things) {
		for (int w = t.first; w <= m; w++) {
			temp[w] = max(maxvalue[w], t.second + maxvalue[w - t.first]);
		}
		for (int i = 1; i <= m; i++) {
			maxvalue[i] = temp[i];
		}
	}
	
	cout << maxvalue[m];

	return 0;
}
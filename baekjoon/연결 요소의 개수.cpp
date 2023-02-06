#include <iostream>
#include <map>
#include <set>

using namespace std;

map<int, set<int>> nums;
bool visit[1001];

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n,m,c1=0;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		nums[a].insert(b);
		nums[b].insert(a);
	}
	int arr[1000];
	int temp[1000];
	int j, k = 0;

	for (int i = 1; i <= n; i++) {
		if (visit[i])
			continue;
		c1++;
		k = 1;
		arr[0] = i;
		while (k > 0) {
			j = k;
			k = 0;
			for (int q = 0; q < j; q++) {
				for (auto p : nums[arr[q]]) {
					if (!visit[p]) {
						temp[k++] = p;
						visit[p] = 1;
					}
				}
			}
			for (int q = 0; q < k; q++) {
				arr[q] = temp[q];
			}
		}
	}

	cout << c1;
	return 0;
}
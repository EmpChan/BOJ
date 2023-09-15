#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#define MAX 2000000000

using namespace std;
using lld = long long;

int n, m;
vector<int>tree;
vector<int>arr;

void insert(int s, int e, int i) {
	if (s > e)return;
	if (i >= tree.size())tree.resize((tree.size() + 1) * 2);
	if (s == e)tree[i] = arr[s-1];
	else {
		int mid = (s + e) / 2;
		insert(s, mid, i * 2); insert(mid + 1, e, i * 2 + 1);
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	}
}

int findmini(int s, int e, int l, int r, int i) {
	if (s > e || l > e || r < s)return MAX;
	if (s >= l && e <= r) {
		return tree[i];
	}
	else {
		int mid = (s + e) / 2;
		int a= findmini(s, mid, l, r, i * 2);
		int b= findmini(mid + 1, e, l, r, i * 2 + 1);
		return min(a, b);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b;

	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	insert(1, n, 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << findmini(1, n, a, b, 1) << '\n';
	}

	return 0;
}
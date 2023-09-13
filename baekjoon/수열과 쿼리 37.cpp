#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#define MAX 2000000000

using namespace std;
using lld = long long;

int arr[100001];
vector<int>tree;

void insert(int s, int e, int i) {
	if (s > e)return;
	if (tree.size() <= i)tree.resize((tree.size() + 1) * 2);
	if (s == e) {
		if (arr[s] % 2)tree[i] = 1;
		else tree[i] = 0;
		return;
	}
	int mid = (s + e) / 2;
	insert(s, mid, i * 2);
	insert(mid + 1, e, i * 2 + 1);
	tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void update(int s, int e, int i, int g) {
	if (s > e || s>g || e < g) return;
	if (s == e) {
		if (arr[g] % 2)tree[i] = 1;
		else tree[i] = 0;
		return;
	}
	int mid = (s + e) / 2;
	update(s, mid, i * 2, g);
	update(mid + 1, e, i * 2 + 1, g);
	tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

int findodd(int s, int e, int l, int r, int i) {
	if (s > e ||(e < l || r<s))return 0;
	if (s >= l && e <= r)return tree[i];
	int mid = (s + e) / 2;
	return findodd(s, mid, l, r, i*2) + findodd(mid + 1, e, l, r, i*2+1);
}

void sol(int n) {
	int t, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		if (a == 1) {
			arr[b] = c;
			update(1, n, 1, b);
		}
		else if (a == 2) {
			cout << (c - b + 1) - findodd(1, n, b, c, 1) << '\n';
		}
		else {
			cout << findodd(1, n, b, c, 1) << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i + 1];
	insert(1, n, 1);
	sol(n);

	return 0;
}
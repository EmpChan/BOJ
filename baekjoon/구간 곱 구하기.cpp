#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#define MAX 1000000007

using namespace std;
using lld = long long;

int n, m, k;
vector<lld>tree;
vector<int>arr;

void insert(int s, int e, int i) {
	if (s > e)return;
	if (i >= tree.size())tree.resize((tree.size() + 1) * 2);
	if (s == e)tree[i] = arr[s-1];
	else {
		int mid = (s + e) / 2;
		insert(s, mid, i * 2); insert(mid + 1, e, i * 2 + 1);
		tree[i] = (tree[i * 2] * tree[i * 2 + 1])%MAX;
	}
}

int getProduct(int s, int e, int l, int r, int i) {
	if (s > e || l > e || r < s)return 1;
	if (s >= l && e <= r) {
		return tree[i];
	}
	else {
		int mid = (s + e) / 2;
		lld a= getProduct(s, mid, l, r, i * 2);
		lld b= getProduct(mid + 1, e, l, r, i * 2 + 1);
		return (a*b)%MAX;
	}
}

void switchIt(int s, int e, int i, int g) {
	if (s > e || s > g || e < g)return;
	if (s == e) {
		tree[i] = arr[g - 1];
	}
	else {
		int mid = (s + e) / 2;
		switchIt(s, mid, i * 2, g);
		switchIt(mid + 1, e, i * 2 + 1, g);
		tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MAX;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b, c;

	cin >> n >> m >> k;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	insert(1, n, 1);
	for (int i = 0; i < m+k; i++) {
		cin >> a >> b >> c;
		if (a == 2) {
			cout << getProduct(1, n, b, c, 1) << '\n';
		}
		else {
			arr[b-1] = c;
			switchIt(1, n, 1, b);
		}
	}

	return 0;
}
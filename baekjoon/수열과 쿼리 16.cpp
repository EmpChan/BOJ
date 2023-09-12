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
int tree[600002];

void insert(int l, int r,int i) {
	if (l == r) {
		tree[i] = l;
	}
	else {
		int mid = (l + r) / 2;
		insert(l, mid, i * 2);
		insert(mid + 1, r, i * 2 + 1);
		if (arr[tree[i * 2]] <= arr[tree[i * 2 + 1]])tree[i] = tree[i * 2];
		else tree[i] = tree[i * 2 + 1];
	}
}

void update(int l, int r, int i, int g) {
	if (l == r)return;
	if (g < l || g > r)return;
	int mid = (l + r) / 2;
	update(mid + 1, r, i * 2 + 1, g);
	update(l, mid, i * 2, g);
	if (arr[tree[i * 2]] <= arr[tree[i * 2 + 1]])tree[i] = tree[i * 2];
	else tree[i] = tree[i * 2 + 1];
}

int findMini(int s, int e, int l, int r, int i) {
	if (s >= l && e <= r) {
		return tree[i];
	}
	if (s > r || e < l) return 0;
	int mid = (s + e) / 2;
	int a = findMini(s, mid, l, r,i*2);
	int b = findMini(mid + 1, e, l, r, i*2+1);
	if (arr[a] <= arr[b])return a;
	else return b;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,a,b,c;
	cin >> n;
	arr[0] = MAX;
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
	}
	insert(1, n, 1);
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			arr[b] = c;
			update(1, n, 1, b);
		}
		else {
			cout << findMini(1, n, b, c,1) << '\n';
		}
	}

	return 0;
}
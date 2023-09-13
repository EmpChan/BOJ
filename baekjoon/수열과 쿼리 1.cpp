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
vector<vector<int>>tree;

void merge(int s, int e, int now, int arr1, int arr2) {
	int i = 0, j = 0, k=0;
	tree[now].resize(tree[arr1].size() + tree[arr2].size());
	while (i < tree[arr1].size() && j < tree[arr2].size()) {
		if (tree[arr1][i] > tree[arr2][j])
			tree[now][k++] = tree[arr2][j++];
		else
			tree[now][k++] = tree[arr1][i++];
	}
	while(i<tree[arr1].size())tree[now][k++] = tree[arr1][i++];
	while(j<tree[arr2].size())tree[now][k++] = tree[arr2][j++];
}

void insert(int s, int e, int i) {
	if (tree.size() <= i) {
		tree.resize((tree.size()+1) * 2);
	}
	if (s == e)tree[i].push_back(arr[s]);
	else {
		int mid = (s + e) / 2;
		insert(s, mid, i * 2);
		insert(mid + 1, e, i * 2 + 1);
		merge(s, e, i, i * 2, i * 2 + 1);
	}
}

int bsearch(int arrn, int k) {
	int mid = (tree[arrn].size()-1)/2;
	int l = 0, r = tree[arrn].size() - 1;
	while (l < r) {
		if (tree[arrn][mid] == k) {
			while (mid < tree[arrn].size() && tree[arrn][mid] == k)mid++;
			return mid;
		}
		else if (tree[arrn][mid] > k) {
			r = mid;
			mid = (l + r) / 2;
		}
		else {
			l = mid+1;
			mid = (l + r) / 2;
		}
	}
	while (l < tree[arrn].size() && tree[arrn][l] <= k)l++;
	return l;
}

int findit(int s, int e, int l, int r, int i,int k) {
	if (s > r || e < l || s > e)return 0;
	if (s == e) {
		if (tree[i][0] > k)return 1;
		else return 0;
	}
	if (s >= l && e <= r) {
		return tree[i].size()- bsearch(i,k);
	}
	else {
		int mid = (s+e)/2;
		return findit(s, mid, l, r, i * 2, k) + findit(mid+1,e,l,r,i*2+1,k);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i+1];
	insert(1, n, 1);

	int t,l,r,k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> l >> r >> k;
		cout << findit(1, n, l, r, 1, k) << '\n';
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define MAX 3000000000

using namespace std;
using lld = long long;

int arr[1000];
set<int> fr;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	priority_queue<int, vector<int>, greater<int>>nmf;
	priority_queue<int>mf;

	int n, m,k;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> k;
		fr.insert(k);
	}
	for (int i = 0; i < n; i++) {
		if (fr.find(arr[i])!=fr.end()) {
			mf.push(i);
		}
		else {
			nmf.push(i);
		}
	}
	int r = 0;
	while (!nmf.empty() && !mf.empty() && nmf.top() < mf.top()) {
		r++;
		nmf.pop();
		mf.pop();
	}
	cout << r;
	return 0;
}
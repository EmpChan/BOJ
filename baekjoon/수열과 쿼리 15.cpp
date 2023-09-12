#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#define MAX 2000000000

using namespace std;
using lld = long long;

int arr[100000];
set<pair<int,int>>s;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		s.insert(make_pair(arr[i],i+1));
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t == 2) {
			cout << s.begin()->second << '\n';
		}
		else {
			int a, b;
			cin >> a >> b;
			s.erase(make_pair(arr[a - 1], a));
			arr[a-1] = b;
			s.insert(make_pair(arr[a-1],a));
		}
	}

	return 0;
}
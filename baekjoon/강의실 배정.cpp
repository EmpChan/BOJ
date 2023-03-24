#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, int>scount;
map<int, int>ecount;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		scount[a]++;
		ecount[b]++;
	}

	auto i = scount.begin();
	auto j = ecount.begin();

	int r = 0;
	int maxi = 0;
	while (i != scount.end()) {
		if (i->first >= j->first || i==scount.end()) {
			r -= j++->second;
		}
		else {
			r += i++->second;
		}
		maxi = max(r, maxi);
	}

	cout << maxi;
	return 0;
}
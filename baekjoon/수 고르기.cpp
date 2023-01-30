#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int nums[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums, nums + n);
	int p=0, q=1;
	long long t=2000000001;
	while (q<n) {
		if (nums[q] - nums[p] < m) {
			q++;
		}
		else {
			if (nums[q] - nums[p] < t)
				t = nums[q] - nums[p];
			p++;
		}
	}
	cout << t;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int absol(int n) {
	if (n < 0)
		return n * -1;
	else
		return n;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int key, n;
	cin >> n;

	priority_queue<int>left;
	priority_queue<int,vector<int>, greater<int>>right; 

	cin >> key;
	cout << key << '\n';
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		if (a >= key)right.push(a);
		else left.push(a);
		if (right.size() - left.size() >= 0 && right.size() - left.size() <=1) {
			cout << key << '\n';
		}
		else if (left.size() - right.size() <= 1 && (left.size() - right.size() >= 0 && (left.size() + right.size()) % 2 == 0)) {
			cout << key << '\n';
		}
		else {
			if (right.size() > left.size()) {
				left.push(key);
				key = right.top();
				right.pop();
			}
			else {
				right.push(key);
				key = left.top();
				left.pop();
			}
			cout << key << '\n';
		}
	}

	return 0;
}
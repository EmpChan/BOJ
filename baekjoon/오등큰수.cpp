#include <iostream>
#include <stack>

using namespace std;

int arr[1000000];
stack<int>p;
int counting[1000001];
int ans[1000000];

void solution(int n) {
	for (int i = 0; i < n; i++) {
		while (!p.empty() && counting[arr[p.top()]] < counting[arr[i]]) {
			ans[p.top()] = arr[i];
			p.pop();
		}
		p.push(i);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		counting[arr[i]]++;
	}

	solution(n);

	for (int i = 0; i < n; i++) {
		if (!ans[i])
			cout << -1 << ' ';
		else
			cout << ans[i] << ' ';
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <stack>
#define MAX 1000001

using namespace std;
using lld = long long;
using info = pair<int, int>;
using dvect = vector<vector<int>>;

stack<char> s;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n; string tmp,ans = "";
	cin >> n >> tmp;
	for (int i = n - 1; i >= 0; i--) {
		if (!s.empty()) {
			if (tmp[i] == s.top()) {
				ans += "N";
				s.pop();
				continue;
			}
		}
		if (tmp[i] == 'S') {
			ans += "UN";
			s.push('U');
		}
		else {
			ans += "SN";
			s.push('S');
		}
	}

	cout << ans.length() << '\n' << ans;

	return 0;
}
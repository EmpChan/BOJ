#include <iostream>

using namespace std;

bool ispalindrome(string a) {
	int p = 0, q = a.length()-1;
	while (p < q) {
		if (a[p++] == a[q--])
			continue;
		else
			return 0;
	}
	return 1;
}

bool issame(string a) {
	char cup = a[0];
	for (int i = 1; i < a.length(); i++) {
		if (cup != a[i])
			return 0;
	}
	return 1;
}

int main() {
	bool p = 0;
	string a;
	cin >> a;
	p = ispalindrome(a);
	if (!p) {
		cout << a.length();
	}
	else {
		if (issame(a)) { // 모든 문자열이 같은 경우
			cout << -1;
		}
		else {
			cout << a.length() - 1;
		}
	}
	return 0;
}
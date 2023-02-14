#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string a;
	cin >> a;
	int alp[26] = { 0 };
	for (auto i : a) {
		alp[i - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << alp[i] << ' ';
	}
	
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

string reverse(string a) {
	string cup = a;
	for (int i = 0; i < a.length() / 2; i++) {
		swap(cup[i], cup[a.length() - i - 1]);
	}
	return cup;
}

string funA(string a) {
	return a.erase(a.length() - 1);
}

string funB(string a) {
	return reverse(a.erase(a.length() - 1));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string a, b;
	cin >> a >> b;

	int j, k = 1;

	while (1) {
		if (b.length() < a.length())
			break;
		if (a == b) {
			cout << 1 << '\n';
			return 0;
		}
		if (b[b.length() - 1] == 'A') b = funA(b);
		else b = funB(b);
	}
	cout << 0 << '\n';

	return 0;
}
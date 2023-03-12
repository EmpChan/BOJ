#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	bool check[26] = { 0 };
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string a;
		int key = 999;
		getline(cin, a);
		for (int j = 0; j < a.length(); j++) {
			if (j == 0) {
				if (!check[tolower(a[j])-'a']) {
					check[tolower(a[j]) - 'a'] = 1;
					key = j;
					break;
				}
			}
			else if (a[j] == ' ') {
				j++;
				if (!check[tolower(a[j]) - 'a']) {
					check[tolower(a[j])-'a'] = 1;
					key = j;
					break;
				}
			}
		}
		if (key == 999) {
			for (int j = 0; j < a.length(); j++) {
				if (a[j] == ' ')
					continue;
				else {
					if (!check[tolower(a[j]) - 'a']) {
						check[tolower(a[j]) - 'a'] = 1;
						key = j;
						break;
					}
				}
			}
		}
		for (int j = 0; j < a.length(); j++) {
			if (j == key)
				cout << '[' << a[j] << ']';
			else
				cout << a[j];
		}
		cout << '\n';
	}

	return 0;
}
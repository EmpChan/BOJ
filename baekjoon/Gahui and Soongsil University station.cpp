#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);;

	int r = 0;
	for (int i = 0; i < 4; i++) {
		string a;
		int b;
		cin >> a >> b;
		if (a == "Es") r += b * 21;
		else r += b * 17;
	}
	cout << r << '\n';

	return 0;
}
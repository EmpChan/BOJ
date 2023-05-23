#include <iostream>

using namespace std;

bool bin[10];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b, r=0, k = 0;
	cin >> a >> b;
	int i = 1; 
	while (max(a, b) >= i) {
		i *= 2;
		k++;
	}
	while (i > 0) {
		if (a >= i && b >= i) {
			a -= i;
			b -= i;
			bin[k] = 0;
		}
		else if (a >= i || b >= i) {
			if (a >= i) a -= i;
			else b -= i;
			bin[k] = 1;
			r += i;
		}
		else
			bin[k] = 0;
		i /= 2;
		k--;
	}

	cout << r << '\n';

	return 0;
}
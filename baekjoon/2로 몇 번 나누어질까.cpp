#include <iostream>
#include <math.h>
#include <map>

using namespace std;

map<long long, long long>two;
map<long long, long long>mtwo;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long a,b,c;
	long long s = 0;
	long long k = 0;
	long long l = 0;
	cin >> a >> b;
	c = b;
	while (c > 0) {
		l++;
		c /= 2;
	}
	for (int i = l; i >= 0; i--) {
		long long cup = pow(2, i);
		two[cup] = b / cup;
		mtwo[cup] = (a-1) / cup;
		s += (two[cup] - mtwo[cup] - k) * cup;
		k += two[cup] - mtwo[cup] - k;
	}

	cout << s;

	return 0;
}
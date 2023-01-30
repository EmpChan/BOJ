#include <iostream>

using namespace std;

unsigned long long impowing(unsigned long long a, unsigned long long b, unsigned long long c) {
	if (a == 1 || b==0)
		return 1;
	if (b == 1)
		return a % c;
	if (b % 2 == 0)
		return (impowing(a, b / 2, c)%c) * (impowing(a, b / 2, c)%c)% c;
	else
		return ((impowing(a, b / 2+1, c)%c) * (impowing(a, b / 2, c)%c)) % c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	unsigned long long a, b, c;
	cin >> a >> b >> c;
	cout << impowing(a, b, c);
	

	return 0;
}
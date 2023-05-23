#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

bool bin[10];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long a;
	cin >> a;
	long long i = 1,j=1;
	if (a == 0) {
		cout << 0 << '\n';
		return 0;
	}
	while (a > i) {
		i*=2;
		j++;
	}

	cout << j << '\n';

	return 0;
}
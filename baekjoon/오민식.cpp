#include <iostream>
#include <math.h>
#define MAXV 987654321

using namespace std;

int primes[500000];
bool check[1000001];
int k;

void era() {
	for (int i = 2; i < 1000000; i++) {
		if (check[i])continue;
		else primes[k++] = i;
		for (int j = i + i; j < 1000001; j += i) {
			check[j] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	era();
	long long r = 1;
	for (int i = 0; i < k; i++) {
		if (primes[i] > n) break;
		int p = 0;
		int q = n;
		while (q >= primes[i]) {
			p++;
			q /= primes[i];
		}
		r *= pow(primes[i], p);
		r %= MAXV;
	}

	cout << r << '\n';

	return 0;
}
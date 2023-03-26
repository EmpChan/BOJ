#include <iostream>
#include <vector>

using namespace std;

int primes[1000000];
bool check[2000001];
int k;

bool pel(int n) {
	int s = 0;
	int c = n;
	int arr[7] = { 0 };
	while (c) {
		arr[s++] = c % 10;
		c /= 10;
	}
	int i=0, j=s-1;
	while (i < j) {
		if (arr[i++] != arr[j--])
			return 0;
	}
	return 1;
}

void era() {
	for (int i = 2; i < 20000; i++) {
		if (check[i])
			continue;
		for (int j = i + i; j <= 2000000; j+=i) {
			check[j] = 1;
		}
	}
	for (int i = 2; i <= 2000000; i++) {
		if (!check[i] && pel(i)) {
			primes[k++] = i;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,i=0;
	cin >> n;
	
	era();

	while (primes[i] < n)
		i++;

	cout << primes[i];

	return 0;
}
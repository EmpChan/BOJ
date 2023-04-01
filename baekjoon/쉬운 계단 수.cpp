#include <iostream>
#define MAX 1000000000

using namespace std;

long counting[10];
long temp[10];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i < 10; i++) counting[i] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < 9; j++) {
			temp[j] = (counting[j - 1] + counting[j + 1])%MAX;
		}
		temp[0] = counting[1];
		temp[9] = counting[8];
		for (int j = 0; j < 10; j++) counting[j] = temp[j];
	}
	long long r = 0;
	for (int i = 0; i < 10; i++) r = (r+counting[i])%MAX;
	cout << r % MAX << '\n';
	return 0;
}
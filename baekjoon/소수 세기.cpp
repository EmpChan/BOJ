#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#define INF 1000000000
#define MAX 1000000007

using namespace std;
using lld = long long;
using info = pair<int, int>;
using vect = vector<vector<info>>;

bool isprime[3000001];
int primes[220000];
int dp[3000001];
int c;

void era() {
	c = 0;
	for (int i = 2; i <= 3000; i++) {
		if (isprime[i])continue;
		for (int j = i + i; j <= 3000000; j += i) {
			isprime[j] = 1;
		}
	}
	primes[c++] = 2;
	for (int i = 3; i < 3000000; i+=2) {
		if (!isprime[i])primes[c++] = i;
	}
}

void sol() {
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 2; i < c; i++) {
		int tmp = primes[i] / 2;
		while (isprime[tmp] || isprime[primes[i] - 1 - tmp])tmp--;
		dp[primes[i]] = dp[tmp] + dp[primes[i] - 1 - tmp] +1;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	era();
	sol();

	cout << dp[n];

	return 0;
}
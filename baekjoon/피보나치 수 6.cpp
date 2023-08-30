#include<iostream>
#include<vector>
#include<queue>
#define INF 1000000000
#define MAX 1000000007

using namespace std;
using lld = long long;
using info = pair<int, int>;
using vect = vector<vector<lld>>;

lld n;
vect matrix;
vect ans;

vect sq(vect a, vect b) {
	vect c;
	c.resize(2);
	c[0].resize(2), c[1].resize(2);
	c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0])%MAX;
	c[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1])%MAX;
	c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0])%MAX;
	c[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1])%MAX;
	return c;
}

vect fibo(lld k) {
	if (k >= 2) {
		vect tmp;
		if (k % 2 == 0) {
			tmp = fibo(k / 2);
			return sq(tmp, tmp);
		}
		else {
			tmp = fibo(k / 2);
			return sq(sq(tmp, tmp), matrix);
		}
	}
	else return matrix;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	matrix.resize(2);
	matrix[0].resize(2), matrix[1].resize(2);
	matrix[0][0] = 1, matrix[0][1] = 1, matrix[1][0] = 1, matrix[1][1] = 0;
	cin >> n;
	ans = fibo(n);
	
	cout << ans[0][1];

	return 0;
}
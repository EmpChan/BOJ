#include <iostream>

using namespace std;

long long segment[4000000];
long long arr[1000001];
int place[1000001];

void input(int i, int l, int r) {
	if (l == r) {
		segment[i] = arr[l];
		place[l] = i;
		return;
	}
	int mid = (l + r) / 2;
	input(i * 2, l, mid);
	input(i * 2 + 1, mid + 1, r);
	segment[i] = segment[i * 2] + segment[i * 2 + 1];
}

long long getsum(int i, int s, int e, int l, int r) {
	if (s > r || e < l)
		return 0;
	if (s >= l && e <= r)
		return segment[i];
	int mid = (s + e) / 2;
	return getsum(i * 2, s, mid, l, r) + getsum(i * 2 + 1, mid + 1, e, l, r);
}

void changevalue(int i, long long v, bool check) { // k번째 값을 j로 변환
	if (i <= 0) return;
	if (check) {
		segment[i] = v;
		changevalue(i / 2, v, 0);
	}
	else {
		segment[i] = segment[i * 2] + segment[i * 2 + 1];
		changevalue(i / 2, v, 0);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) cin >> arr[i];
	input(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 2) {
			cout << getsum(1, 1, n, b, c) << '\n';
		}
		else {
			changevalue(place[b], c, 1);
		}
	}

	return 0;
}
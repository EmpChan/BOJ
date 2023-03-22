#include<iostream>
#include<algorithm>

using namespace std;

int u[250001]; // 종유석
int d[250001]; // 석순
int wall[500001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, h;
	cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			cin >> u[i / 2];
		}
		else {
			cin >> d[i / 2 + 1];
		}
	}
	
	sort(u, u + n / 2+1);
	if (n % 2 != 0) {
		sort(d, d + n / 2 + 2);
	}
	else {
		sort(d, d + n / 2 + 1);
	}
	int r = 0;
	for (int i = n / 2; i >= 1; i--) {
		r ++;
		for (int j = u[i]-1; j >= u[i - 1]; j--) {
			wall[h - j] += r;
		}
	}
	
	r = 0;
	for (int i = n / 2; i >= 1; i--) {
		wall[d[i]] -= r;
		r ++;
		for (int j = d[i]; j >= d[i - 1]; j--) {
			wall[j] += r;
		}
	}
	
	int mini = 500000, counting = 500000;
	for (int i = 1; i <= h; i++) {
		if (mini > wall[i]) {
			mini = wall[i];
			counting = 1;
		}
		else if (mini == wall[i]) counting++;
	}

	cout << mini << ' ' << counting << '\n';

	return 0;
}
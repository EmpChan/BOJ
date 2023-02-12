#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int a, b, c;
	int mini[2][3];
	int maxi[2][3];
	cin >> a >> b >> c;
	if (n == 1) {
		cout << max(a, max(b, c)) << ' ' << min(a,min(b,c));
		return 0;
	}
	mini[1][0] = a, mini[1][1] = b, mini[1][2] = c;
	maxi[1][0] = a, maxi[1][1] = b, maxi[1][2] = c;
	for (int i = 1; i < n; i++) {
		mini[0][0] = mini[1][0], mini[0][1] = mini[1][1], mini[0][2] = mini[1][2];
		maxi[0][0] = maxi[1][0], maxi[0][1] = maxi[1][1], maxi[0][2] = maxi[1][2];
		cin >> a >> b >> c;
		mini[1][0] = min(a + mini[0][0], a + mini[0][1]);
		mini[1][1] = min(b + mini[0][0], min(b + mini[0][1], b + mini[0][2]));
		mini[1][2] = min(c + mini[0][1], c + mini[0][2]);
		maxi[1][0] = max(a + maxi[0][0], a + maxi[0][1]);
		maxi[1][1] = max(b + maxi[0][0], max(b + maxi[0][1], b + maxi[0][2]));
		maxi[1][2] = max(c + maxi[0][1], c + maxi[0][2]);
	}

	cout << max(maxi[1][0], max(maxi[1][1], maxi[1][2])) << ' ' << min(mini[1][0], min(mini[1][1], mini[1][2]));

	return 0;
}
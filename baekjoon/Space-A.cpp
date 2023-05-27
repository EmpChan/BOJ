#include<iostream>
#include<vector>
#include<map>

using namespace std;

int uc = 0, rc = 0, xc = 0;

bool search(int x, int y) {
	int xx = x, yy = y;
	if (xx == 1 && yy == 1) return 1;
	int k = min(xc, min(xx - 1, yy - 1));
	xx -= k;
	yy -= k;
	xx -= min(rc, xx - 1);
	yy -= min(uc, yy - 1);
	if (xx == 1 && yy == 1) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,counts=0;
	cin >> n;
	
	string a;
	cin >> a;
	for (auto i : a) {
		if (i == 'R')rc++;
		else if (i == 'U')uc++;
		else xc++;
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		int b, c;
		cin >> b >> c;
		if (search(b, c))counts++;
	}

	cout << counts;

	return 0;
}
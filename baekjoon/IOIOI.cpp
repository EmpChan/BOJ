#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, c=0, q=0,base;
	cin >> n >> m;
	base = 1 + n * 2;
	string a,b="IOI",p="OI";
	cin >> a;
	bool flag = 0;
	for (int i = 0; i < a.length(); i++) {
		if (!flag) {
			if (i >= a.length() - 2) {
				break;
			}
			if (b[0] == a[i] &&(b[1] == a[i+1] && b[2] == a[i+2])) {
				flag = 1; c = 3;
				i += 2;
			}
		}
		else {
			if (p[0]==a[i] && p[1] == a[i+1]) {
				c += 2;
				i++;
			}
			else {
				flag = 0;
				i--;
				q += max(0, ((c - base) / 2)+1);
			}
		}
	}
	
	cout << q;

	return 0;
}
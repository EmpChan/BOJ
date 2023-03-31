#include <iostream>
#include <vector>
#define MAX 30

using namespace std;

int pel(string a,int p,int q) {
	if (p >= q)
		return 0;
	bool flag = 0;
	int i = p,j=q;
	while (i < j) {
		if (a[i] == a[j])
			i++, j--;
		else {
			if (flag)
				return 2;
			else
				flag = 1;
			if (a[i] == a[j - 1] && a[i + 1] == a[j]) {
				int c = pel(a, i + 1, j);
				int cc = pel(a, i, j - 1);
				c = min(c, cc);
				if (c >= 1) return 2;
				else return 1;
			}
			else if (a[i] == a[j - 1]) {
				j--;
			}
			else if (a[i + 1] == a[j]) {
				i++;
			}
			else
				return 2;
			i++;
			j--;
		}
	}

	if (flag)
		return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		cout << pel(a,0,a.length()-1) << '\n';
	}

	return 0;
}
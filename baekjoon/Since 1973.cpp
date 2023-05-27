#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,c=0;
	bool flag = 0;
	char* k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		flag = 0;
		int temp = i,t1=-1;
		while (temp > 0) {
			if (t1 == 0 && temp % 10 == 5)flag = 1;
			t1 = temp % 10;
			temp /= 10;
		}
		if (flag)c += 2;
		else c++;
	}

	cout << c << '\n';

	return 0;
}
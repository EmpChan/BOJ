#include <iostream>

#define MAX 9876543210

using namespace std;

long long arr[1000001];

void getdeclinenum() {
	long long l=1,temp=0,i1=0,i2=-1,j=0;
	while (temp <= MAX) {
		l = 1;
		i1 = temp;
		bool flag = 0;
		while (i1 > 9) {
			l *= 10;
			i2 = i1%10;
			i1 /= 10;
			if (i1%10 <= i2) {
				flag = 1;
				break;
			}
		}
		if (i1 <= i2) {
			flag = 1;
		}
		if (!flag) {
			arr[j++] = temp;
			temp++;
		}
		else {
			i1 = temp % l;
			temp -= i1;
			temp += l;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	getdeclinenum();
	if (arr[n] == 0 && n != 0)
		cout << -1;
	else
		cout << arr[n];
	
	return 0;
}
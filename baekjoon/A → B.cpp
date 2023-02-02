#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long a, b;
	cin >> a >> b;
	long arr[100000], temp[100000],j,k=1,counting=0;
	arr[0] = a;
	while (k > 0) {
		counting++;
		j = k;
		k = 0;
		for (int i = 0; i < j; i++) {
			if (arr[i] == b) {
				cout << counting;
				return 0;
			}
			if (arr[i] * 2 <= b)
				temp[k++] = arr[i] * 2;
			if (arr[i] * 10 + 1 <= b)
				temp[k++] = arr[i] * 10 + 1;
		}
		for (int i = 0; i < k; i++) {
			arr[i] = temp[i];
		}
	}
	cout << -1;
	return 0;
}
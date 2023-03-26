#include <iostream>
#include <vector>

using namespace std;

int arr[1000000];
int counting;

void bsort(int n) {
	int i = 0;
	int cup;
	while (counting > 0 && i<n) {
		cup = arr[i];
		int maxp = i,maxv = arr[i];
		//cout << i << ' ' << arr[i] << '\n';
		for (int p = i; p < n; p++) {
			if (maxv < arr[p]) {
				if (p-i <= counting) {
					maxp = p; 
					maxv = arr[p];
				}
			}
		}
		for (int p = maxp; p > i; p--) {
			swap(arr[p], arr[p - 1]);
			counting--;
		}
		if (cup == arr[i])
			i++;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> counting;

	bsort(n);

	for (int i = 0; i < n; i++) cout << arr[i] << ' ';

	return 0;
}
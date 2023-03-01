#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int absol(int a) {
	if (a > 0)
		return a;
	else
		return a * -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cout.tie(0);

	int mini = 2000000001;
	int n,p=0,q=0,ans[2];
	cin >> n;
	q = n - 1;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	while (p < q) {
		if (absol(arr[p] + arr[q]) < mini) {
			ans[0] = p;
			ans[1] = q;
			mini = absol(arr[p] + arr[q]);
		}
		else {
			if (absol(arr[p + 1] + arr[q]) < absol(arr[p] + arr[q - 1]))
				p++;
			else
				q--;
		}
	}
	cout << arr[ans[0]] << ' ' << arr[ans[1]];

	return 0;
}
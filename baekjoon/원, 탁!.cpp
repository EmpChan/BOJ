#include<iostream>
#include<vector>
#include<map>

using namespace std;

int arr[1000000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,c=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (arr[0] <= arr[n - 1]) c++;
	for (int i = 1; i < n; i++) if (arr[i] <= arr[i - 1])c++;

	cout << c;

	return 0;
}
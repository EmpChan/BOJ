#include <iostream>

using namespace std;

int arr[10000];
int key[10000];
int c, n;

void printarr() {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

bool insertion_sort() {
	for (int i = 1; i < n; i++) {
		int loc = i - 1;
		int newitem = arr[i];
		bool flag = 0;
		while (0 <= loc && newitem < arr[loc]) {
			if (arr[loc + 1] == key[loc + 1])flag = 1;
			arr[loc + 1] = arr[loc];
			if (arr[loc + 1] == key[loc + 1] && !flag)c++;
			else if (flag && arr[loc + 1] != key[loc + 1])c--;
			loc--;
			if (c == n)return 1;

		}
		if (loc + 1 != i) {
			if (arr[loc + 1] == key[loc + 1])flag = 1;
			arr[loc + 1] = newitem;
			if (arr[loc + 1] == key[loc + 1] && !flag)c++;
			else if (flag && arr[loc + 1] != key[loc + 1])c--;
			if (c == n) return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	for (int i = 0; i < n; i++) {
		cin >> key[i];
		if (key[i] == arr[i])c++;
	}
	cout << insertion_sort();


	return 0;
}
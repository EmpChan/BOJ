#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int>place;
int arr[26];
string key;
string re;

int sol() {
	for (int i = 0; i < key.length(); i++) {
		place[key[i]] = i+1;
	}
	for (int i = re.find(key[0]); i < re.length(); i++) {
		int cup = place[re[i]];
		if (cup == 0)continue;
		else {
			if (cup == 1) {
				arr[cup - 1]++;
			}
			else if (arr[cup - 2]) {
				arr[cup - 1]++;
				arr[cup - 2]--;
			}
		}
	}

	return arr[key.length()-1];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> re >> key;
	cout << sol();

	return 0;
}
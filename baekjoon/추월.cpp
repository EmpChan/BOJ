#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, bool>checkit;
int counting;
string cop1[1000];
string cop2[1000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> cop1[i];
	for (int i = 0; i < n; i++) cin >> cop2[i];
	for (int i = 0, j=0; i < n && j<n; i++,j++) {
		if (checkit[cop1[i]]) {
			j--;
			continue;
		}
		while (cop1[i] != cop2[j] && j<n) {
			checkit[cop2[j]] = 1;
			counting++; j++;
		}
	}
	cout << counting;
	return 0;
}
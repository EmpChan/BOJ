#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<char, int>dict;

long long alpha[26];
bool front[26];
string a[50];
int fc = 0;
bool visit[26];

void sortit() {
	long long maxi = 0,j=0;
	int k = 9;
	while (k > fc) {
		maxi = 0,j=0;
		while (visit[j])j++;
		for (int i = 0; i < 26; i++) {
			if (!visit[i] && alpha[i] > maxi) {
				maxi = alpha[i];
				j = i;
			}
		}
		dict[j + 'A'] = k--;
		visit[j] = 1;
		if (front[j]) {
			front[j] = 0;
			fc--;
		}
	}
	while (fc-- && k) {
		maxi = 0, j = 0;
		while (visit[j])j++;
		for (int i = 0; i < 26; i++) {
			if (front[i] && alpha[i] >= maxi) {
				maxi = alpha[i];
				j = i;
			}
		}
		dict[j + 'A'] = k--;
		front[j] = 0;
	}
}

long long strToInt(string a) {
	long long l = 1, r = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		r += dict[a[i]] * l;
		l *= 10;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	long long r = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		long long l = 1;
		if (!front[a[i][0] - 'A']) {
			front[a[i][0] - 'A'] = 1;
			fc++;
		}
		for (int j = a[i].length() - 1; j >= 0; j--) {
			alpha[a[i][j] - 'A'] += l;
			l *= 10;
		}
	}
	sortit();
	for (int i = 0; i < n; i++)r += strToInt(a[i]);
	cout << r << '\n';

	return 0;
}


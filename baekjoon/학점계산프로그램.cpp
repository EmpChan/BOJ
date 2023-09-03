#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 3000000000

using namespace std;
using lld = long long;


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string tmp;
	double score = 0;
	int n = 0;
	cin >> tmp;
	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] == 'A') {
			score += 4;
			n++;
		}
		else if (tmp[i] == 'B') {
			score += 3;
			n++;
		}
		else if (tmp[i] == 'C') {
			score += 2;
			n++;
		}
		else if (tmp[i] == 'D') {
			score += 1;
			n++;
		}
		else if (tmp[i] == 'F') {
			n++;
		}
		else if (tmp[i] == '+') {
			score += 0.5;
		}
	}

	cout << score / n;

	return 0;
}
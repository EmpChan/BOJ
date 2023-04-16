#include <iostream>
#include <map>

using namespace std;

map<string, double>score;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	score["A+"] = 4.5; score["A0"] = 4; score["B+"] = 3.5;
	score["B0"] = 3.0; score["C+"] = 2.5; score["C0"] = 2.0;
	score["D+"] = 1.5; score["D0"] = 1.0; score["F"] = 0;

	double s = 0,n =0;
	while (1) {
		string cup;
		cin >> cup;
		if (cin.eof()) {
			break;
		}
		double a;
		cin >> a >> cup;
		if (cup == "P")continue;
		s += score[cup]*a;
		n += a;
	}

	cout << s / n;

	return 0;
}
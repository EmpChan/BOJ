#include <iostream>
#include <string>

using namespace std;

string arr[1000000];
char check_list[] = { '<','>','(',')'};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string a;
	int k = 0;
	getline(cin, a);
	string cup = "";
	bool imspace = 0,an = 0 ,o = 0;
	for (int i = 0; i < a.length(); i++) {
		if (imspace && a[i] == ' ')
			continue;
		else
			imspace = 0;
		if (a[i] == ' ') {
			imspace = 1;
			if (cup != "") {
				arr[k++] = cup;
				cup = "";
			}
		}
		else {
			bool nomal = 0;
			for (auto j : check_list) if (a[i] == j) nomal = 1;
			if (nomal) {
				if (cup != "") {
					arr[k++] = cup;
					cup = "";
				}
				arr[k++] = a[i];
			}
			else {
				if (a[i] == '&') {
					if (cup != "") {
						arr[k++] = cup;
						cup = "";
					}
					arr[k++] = "&&";
					i++;
				}
				else if (a[i] == '|') {
					if (cup != "") {
						arr[k++] = cup;
						cup = "";
					}
					arr[k++] = "||";
					i++;
				}
				else
					cup += a[i];
			}
		}
	}
	if (cup != "") {
		arr[k++] = cup;
		cup = "";
	}
	for (int i = 0; i < k; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}
#include <iostream>

using namespace std;

bool pp[51];
int party[50][50];
int participate[51][50];
int pc[51];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k,p,q=0;
	int arr[50],temp[50];
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int cup;
		cin >> cup;
		pp[cup] = 1;
		arr[q++] = cup;
	}
	for (int i = 0; i < m; i++) {
		int cup;
		cin >> cup;
		for (int j = 0; j < cup; j++) {
			int cup2;
			cin >> cup2;
			party[i][j] = cup2;
			participate[cup2][pc[cup2]++] = i;
		}
	}
	while (q != 0) {
		p = q;
		q = 0;
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < pc[arr[i]]; j++) {
				for (auto i2 : party[participate[arr[i]][j]]) {
					if (i2 == 0)
						break;
					if (!pp[i2]) {
						temp[q++] = i2;
						pp[i2] = 1;
					}
				}
			}
		}
		for (int i = 0; i < q; i++) arr[i] = temp[i];
	}
	
	int counting = 0;
	for (int i = 0; i < m; i++) {
		bool flag = 0;
		for (int j = 0; party[i][j] != 0; j++) {
			if (pp[party[i][j]]) {
				flag = 1;
				break;
			}
		}
		if (!flag) { counting++;}
	}
	cout << counting; 

	return 0;
}
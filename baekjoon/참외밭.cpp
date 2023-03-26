#include <iostream>
#include <vector>

using namespace std;

int arr[6][2];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,width=0,height=0,result=0;
	int cup[2][2] = { 0 };
	bool flag = 0;
	cin >> n;
	for (int i = 0; i < 6; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 0; i < 12; i++) {
		if (cup[0][0] == arr[i % 6][0] && !flag) {
			if (cup[1][0] == arr[(i + 1) % 6][0]){
				result -= cup[1][1] * arr[i % 6][1];
				flag = 1;
			}
		}
		if ((i % 6) % 2 == 0) {
			width = max(width, arr[i % 6][1]);
		}
		else {
			height = max(height, arr[i % 6][1]);
		}
		cup[0][0] = cup[1][0];
		cup[0][1] = cup[1][1];
		cup[1][0] = arr[i%6][0];
		cup[1][1] = arr[i%6][1];
	}
	result += width * height;
	cout << result * n << '\n';

	return 0;
}
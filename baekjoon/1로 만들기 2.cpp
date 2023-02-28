#include <iostream>

using namespace std;

struct st {
	int v;
	string ans;
};

st arr[1000000];
st temp[1000000];
bool visit[1000001];

string makestr(int n) {
	string cup = "",cup2="";
	int j = n;
	while (j > 0) {
		cup += j % 10 + '0';
		j /= 10;
	}
	for (int i = cup.length()-1; i>=0; i--) {
		cup2 += cup[i];
	}
	return cup2+"_";
}

st sol(int n) {
	arr[0].v = n;
	arr[0].ans = makestr(n);
	int j, k = 1,counting=0;
	while (true) {
		j = k;
		k = 0;
		for (int i = 0; i < j; i++) {
			if (arr[i].v == 1) {
				cout << counting << '\n';
				return arr[i];
			}
			if (!visit[arr[i].v - 1]) {
				temp[k].v = arr[i].v - 1;
				temp[k++].ans = arr[i].ans + makestr(arr[i].v - 1);
				visit[arr[i].v - 1] = 1;
			}
			if (arr[i].v % 2 == 0 && !visit[arr[i].v/2]) {
				temp[k].v = arr[i].v / 2;
				temp[k++].ans = arr[i].ans + makestr(arr[i].v / 2);
				visit[arr[i].v / 2] = 1;
			}
			if (arr[i].v % 3 == 0 && !visit[arr[i].v / 3]) {
				temp[k].v = arr[i].v / 3;
				temp[k++].ans = arr[i].ans + makestr(arr[i].v / 3);
				visit[arr[i].v / 3] = 1;
			}
		}
		for (int i = 0; i < k; i++) {
			arr[i].v = temp[i].v;
			arr[i].ans = temp[i].ans;
		}

		counting++;
	}
}

void printans(st ans) {
	string cup = "";
	for (auto i : ans.ans) {
		if (i == '_') {
			cout << cup << ' ';
			cup = "";
		}
		else {
			cup += i;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	st ans = sol(n);
	printans(ans);

	return 0;
}
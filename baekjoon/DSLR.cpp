#include <iostream>

using namespace std;

struct st {
	int n;
	string ans;
};

st arr[40001];
st temp[40001];
bool visit[10001];

int funcD(int n) {
	return (n * 2) % 10000;
}

int funcS(int n) {
	if (n != 0)
		return n - 1;
	else
		return 9999;
}

int funcL(int n) {
	int a, b, c, d;
	a = (n % 10000) / 1000;
	b = (n % 1000) / 100;
	c = (n % 100) / 10;
	d = n % 10;
	return b*1000+c*100+d*10+a;
}

int funcR(int n) {
	int a, b, c, d;
	a = (n % 10000) / 1000;
	b = (n % 1000) / 100;
	c = (n % 100) / 10;
	d = n % 10;
	return d*1000+a*100+b*10+c;
}

void set0() {
	for (int i = 0; i <= 10000; i++) visit[i] = 0;
}

void find_answer(int origin,int answer) {
	set0();
	int j, k = 1;
	bool flag = 0;
	arr[0].n = origin;
	arr[0].ans = "";
	visit[arr[0].n] = 1;
	while (k!=0) {
		j = k;
		k = 0;
		for (int i = 0; i < j; i++) {
			if (arr[i].n == answer) {
				cout << arr[i].ans << '\n';
				return;
			}
			int a = funcD(arr[i].n);
			if (!visit[a]) {
				visit[a] = 1;
				temp[k].n = a;
				temp[k++].ans = arr[i].ans + "D";
			}
			a = funcS(arr[i].n);
			if (!visit[a]){
				visit[a] = 1;
				temp[k].n = a;
				temp[k++].ans = arr[i].ans + "S";
			}
			a = funcL(arr[i].n);
			if (!visit[a]) {
				visit[a] = 1;
				temp[k].n = a;
				temp[k++].ans = arr[i].ans + "L";
			}
			a = funcR(arr[i].n);
			if (!visit[a]) {
				visit[a] = 1;
				temp[k].n = a;
				temp[k++].ans = arr[i].ans + "R";
			}
		}
		for (int i = 0; i < k; i++) {
			arr[i] = temp[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int origin, answer;
		cin >> origin >> answer;
		find_answer(origin, answer);
	}

	return 0;
}

#include<iostream>
#include <queue>

using namespace std;

bool visit[1000001];

bool sol(int n,int k) {
	int c = 0;
	queue<int>p;
	p.push(0);
	visit[0] = 1;
	while (!p.empty()) {
		c++;
		if (c > k)return 0;
		queue<int>tmp;
		while (!p.empty()) {
			int me = p.front();
			p.pop();
			if (me + 1 == n) return 1;
			if (me+1 <= n && !visit[me + 1]) {
				visit[me + 1] = 1;
				tmp.push(me + 1);
			}
			if (me + me / 2 == n) return 1;
			if (me+me/2 <= n && !visit[me + me / 2]) {
				visit[me + me/2] = 1;
				tmp.push(me + me / 2);
			}
		}
		swap(tmp, p);
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	if (sol(n, k)) {
		cout << "minigimbob\n";
	}
	else {
		cout << "water";
	}

	return 0;
}
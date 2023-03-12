#include <iostream>
#include <vector>

using namespace std;

vector<int> links[1000001];
bool visit[1000001];
bool sns[1000001];

int search(int i) {
	int p = 0;
	for (auto k : links[i]) {
		if (!visit[k]) {
			visit[k] = 1;
			p+=search(k);
		}
	}
	if (p == 0) { //리프 노드인 경우
		return 1; 
	}
	else { // 리프가 아님
		int j = 0;
		for (auto k : links[i]) {
			if (sns[k])
				j++;
		}
		if (j >= links[i].size() - 1) {
			if (i == 1 && j == links[i].size()-1)
				sns[i] = 1;
			else
				return 1;
		}
		else {
			sns[i] = 1;
			return 1;
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		links[a].push_back(b);
		links[b].push_back(a);
	}
	visit[1] = 1;
	search(1);
	int c=0;
	for (int i = 1; i <= n; i++) {
		if (sns[i])
			c++;
	}
	cout << c << '\n';

	

	return 0;
}
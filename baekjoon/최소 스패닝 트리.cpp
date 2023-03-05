#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using edge = pair<int, int>;
using info = pair<int, edge>;

vector<info>lines;
int parent[10001]; // 만약 edge의 두 정점이 같은 집합이라면 사이클이 생기므로 체크 
long long s; // 답을 저장할 공간

void input(int m) {
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> b >> c >> a;
		lines.push_back(make_pair(a, make_pair(b, c)));
	
	}
	sort(lines.begin(), lines.end()); // 가중치에 따라 오름차순으로 정렬
	for (int i = 1; i <= 10000; i++) parent[i] = i; // 유니온 파인드를 위한 초기화
}

int find(int dot) { // 정점의 집합 속 가장 최상위 점 찾음
	vector<int>dots;
	int p = parent[dot], q = dot;
	while (p != q) {
		dots.push_back(q);
		q = p;
		p = parent[q];
	}
	for (auto i : dots) parent[i] = p; // set 최적화
	return p;
}

void unionset(int a, int b) { // a와 b가 속한 집합 union
	parent[find(b)] = parent[find(a)];
}

void mst() {
	for (auto i : lines) {
		int v = i.first;
		int start = i.second.first;
		int end = i.second.second;
		if (find(start) == find(end))
			continue;
		else {
			s += v;
			unionset(start, end);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	input(m);
	mst();
	
	cout << s;

	return 0;
}
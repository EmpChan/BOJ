#include<iostream>
#include<vector>
#include<utility>

#define MAX 99999999

using namespace std;

vector<pair<int, int>>chicken;
vector<pair<int, int>>house;
int map[50][50];
int minidistance = MAX;
int n, m, c;
int arr[13][2];
bool visit[13];

int absol(int a) {
	if (a < 0)
		return a * -1;
	else
		return a;
}

void search(int i,int j) {
	if (j >= m) {
		int r = 0;
		for (auto p : house) {
			int mini = MAX;
			for (int q = 0; q < j; q++) {
				int cup = absol(p.first - arr[q][0]) + absol(p.second - arr[q][1]);
				mini = min(cup, mini);
			}
			r += mini;
		}
		minidistance = min(r, minidistance);
		return;
	}
	for (int p = i; p < c; p++) {
		if (!visit[p]) { 
			visit[p] = 1;
			arr[j][0] = chicken[p].first;
			arr[j][1] = chicken[p].second;
			search(p + 1, j + 1);
			visit[p] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)house.push_back(make_pair(i, j));
			else if (map[i][j] == 2)chicken.push_back(make_pair(i, j));
		}
	}
	c = chicken.size();
	search(0, 0);

	cout << minidistance;

	return 0;
}
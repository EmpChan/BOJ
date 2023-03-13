#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

map<int, int>start;
vector<pair<int, int>>meeting;

int findbestmeeting(int i) {
	int key=i;
	int s = meeting[i].first;
	int e = meeting[i].second;
	for (int r = i; r < meeting.size(); r++) {
		if (meeting[r].first > e)
			return key;
		else {
			if (meeting[r].second < e) {
				key = r;
				e = meeting[key].second;
			}
		}
	}
	return key;
}

int findnextmeeting(int i) {
	for (int k = i+1; k < meeting.size(); k++) {
		if (meeting[k].first >= meeting[i].second)
			return k;
	}
	return meeting.size();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, counting = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		meeting.push_back(make_pair(s, e));
	}
	sort(meeting.begin(), meeting.end());
	int cup = meeting[0].first;
	start[cup] = 0;
	for (int i = 1; i < meeting.size(); i++) {
		if (meeting[i].first != cup) {
			cup = meeting[i].first;
			start[cup] = i;
		}
	}

	//for (int i = 0; i < meeting.size(); i++) {
	//	cout << meeting[i].first << ' ' << meeting[i].second << '\n';
	//}

	for (int i = 0; i < n;) {
		i=findbestmeeting(i);
		counting++;
		i = findnextmeeting(i);
	}

	cout << counting << '\n';

	return 0;
}
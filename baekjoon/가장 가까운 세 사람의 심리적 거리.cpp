#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int diff(string a, string b) {
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i] == b[i])continue;
		ans++;
	}
	return ans;
}

int sol(vector<string>arr) {
	int ans = 9876543210;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			int t = diff(arr[i], arr[j]);
			for (int k = j + 1; k < arr.size(); k++) {
				ans = min(ans,t + diff(arr[i], arr[k]) + diff(arr[j], arr[k]));
			}
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<string, int>mbti;
		vector<string>tmp;
		for (int i = 0; i < n; i++) {
			string a;
			cin >> a;
			mbti[a]++;
		}
		for (auto i : mbti) {
			if (i.second > 3)i.second = 3;
			for (int j = 0; j < i.second; j++)tmp.push_back(i.first);
		}
		cout << sol(tmp) << '\n';
	}

	return 0;
}
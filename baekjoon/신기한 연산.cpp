#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define MAX 3000000000

using namespace std;
using lld = long long;
using info = pair<pair<int,int>, int>;
using dvect = vector<vector<int>>;



int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	int k = 0,t=0;
	for (int i = 0; i < b; i++) {
		cout << (char)((k%a)+'a');
		if ((++t) % 2 == 0)k++;
	}

	return 0;
}
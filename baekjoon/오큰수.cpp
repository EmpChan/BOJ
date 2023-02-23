#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

queue<int>arr;
stack<int>place;
stack<int>temp;
int answer[1000000];


void sol() {
	int i = 0;
	temp.push(arr.front());
	arr.pop();
	place.push(i);
	while (!arr.empty()) {
		i++;
		if (!temp.empty()) {
			while (!temp.empty() && temp.top() < arr.front()) {
				temp.pop();
				answer[place.top()] = arr.front();
				place.pop();
			}
		}
		temp.push(arr.front());
		arr.pop();
		place.push(i);
	}
	while (!temp.empty()) {
		temp.pop();
		answer[place.top()] = -1;
		place.pop();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cup;
		cin >> cup;
		arr.push(cup);
	}
	
	sol();
	for (int i = 0; i < n; i++) {
		cout << answer[i] << ' ';
	}

	return 0;
}
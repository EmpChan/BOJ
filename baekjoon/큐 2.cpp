#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int front=0, rear=0,n;
	vector<int>queue(2000000);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string ans;
		cin >> ans;
		if (ans == "push") {
			cin >> queue[rear++];
		}
		else if (ans == "pop") {
			if (front == rear) cout << -1;
			else cout << queue[front++];
			cout << '\n';
		}
		else if (ans == "front") {
			if (front == rear) cout << -1;
			else cout << queue[front];
			cout << '\n';
		}
		else if (ans == "back") {
			if (front == rear) cout << -1;
			else cout << queue[rear-1];
			cout << '\n';
		}
		else if (ans == "size") {
			cout << rear - front << '\n';
		}
		else if (ans == "empty") {
			if (front == rear) cout << 1;
			else cout << 0;
			cout << '\n';
		}
	}
	
	return 0;
}
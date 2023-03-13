#include <iostream>
#define MAXI 1000000000

using namespace std;

int arr[100000];
int minitree[400001];
int maxitree[400001];

void base() {
	for (int i = 1; i <= 400000; i++) {
		minitree[i] = MAXI;
	}
}

void input_minitree(int i,int s,int e) {
	if (s == e)
		minitree[i] = arr[s];
	else {
		int mid = (s + e) / 2;
		input_minitree(i * 2, s, mid);
		input_minitree(i * 2 + 1, mid + 1, e);
		minitree[i] = min(minitree[i * 2], minitree[i * 2 + 1]);
	}
}

void input_maxitree(int i, int s, int e) {
	if (s == e)
		maxitree[i] = arr[s];
	else {
		int mid = (s + e) / 2;
		input_maxitree(i * 2, s, mid);
		input_maxitree(i * 2 + 1, mid + 1, e);
		maxitree[i] = max(maxitree[i * 2], maxitree[i * 2 + 1]);
	}
}

int find_max(int i, int s, int e, int l, int r) {
	if (s > r || e < l) // 구간을 벗어나는 경우
		return 0;
	if (s >= l && r >= e) // 구간을 벗어나지 않고 안에 있는 경우 
		return maxitree[i];
	else {
		int mid = (s + e) / 2;
		return max(find_max(i * 2, s, mid, l, r), find_max(i * 2 + 1, mid + 1, e, l, r));
	}
}

int find_min(int i, int s, int e, int l, int r) {
	if (s > r || e < l)
		return MAXI;
	if (s >= l && r >= e)
		return minitree[i];
	else {
		int mid = (s + e) / 2;
		return min(find_min(i * 2, s, mid, l, r), find_min(i * 2 + 1, mid + 1, e, l, r));
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	int maxi, mini;
	cin >> n >> m;
	base();
	for (int i = 1; i <= n; i++) cin >> arr[i];
	input_maxitree(1, 1, n);
	input_minitree(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		maxi = find_max(1, 1, n, a, b);
		mini = find_min(1, 1, n, a, b);

		cout << mini << ' ' << maxi << '\n';
	}

	return 0;
}
#include<iostream>
#include<queue>

using namespace std;
using place = pair<int, int>;

int n;
int a, b;
int parents[101];
int visit[101];
int ans;

void sol() {
	int c = 1;
	while (a != parents[a]) {
		visit[a] = c++;
		a = parents[a];
	}
	visit[a] = c;
	while (!visit[b] && b != parents[b]) {
		ans++;
		b = parents[b];
	}

	if (visit[b])ans += visit[b]-1;
	else ans = -1;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int k, c, d;
	cin >> n;
	cin >> a >> b >> k;
	for (int i = 1; i <= n; i++) parents[i] = i;
	for (int i = 0; i < k; i++) {
		cin >> c >> d;
		parents[d] = c;
	}
	sol();
	cout << ans << '\n';
	return 0;
}
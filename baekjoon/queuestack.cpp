#include <iostream>
#include <vector>
using namespace std;

vector<int> queuestack;
int st[100000];
int arr[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> st[i];
	}
	for (int i = 0; i < n; i++)
	{
		int cup;
		cin >> cup;
		if (st[i] == 1)
			continue;
		queuestack.insert(queuestack.begin(), cup);
		
	}
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int cup;
		cin >> cup;
		queuestack.push_back(cup);
		cup = queuestack[i];
		cout << cup << ' ';
	}

	return 0;
}
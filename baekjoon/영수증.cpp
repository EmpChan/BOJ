#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, n, r=0;
	int a, b;
	cin >> x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cin >> b;
		r += a * b;
	}
	if (r == x)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
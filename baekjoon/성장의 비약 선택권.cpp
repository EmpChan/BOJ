#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	if (n < 206)
		cout << 1;
	else if (n <= 217)
		cout << 2;
	else if (n <= 228)
		cout << 3;
	else
		cout << 4;
	return 0;
}
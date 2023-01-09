#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,r=0;
	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		int cup;
		cin >> cup;
		if (cup > n)
		{
			r += n;
		}
		else
		{
			r += cup;
		}
	}
	cout << r;
	return 0;
}
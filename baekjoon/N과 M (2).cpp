#include <iostream>

using namespace std;

int arr[8];

void outit(int s, int e, int r, int c)
{
	if (r == c)
	{
		for (int i = 0; i < r; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else
	{
		for (int i = s; i <= e-r+1+c; i++)
		{
			arr[c] = i;
			outit(i + 1, e, r, c + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;
	outit(1, n, m, 0);

	return 0;
}
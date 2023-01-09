#include <iostream>

using namespace std;

bool man[200001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,c=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (b == 0 && !man[a])
		{
			c++;
		}
		else if (b == 1 && man[a])
		{
			c++;
		}
		man[a] = b;
	}
	for (int i = 0; i <= 200000; i++)
	{
		if (man[i])
			c++;
	}

	cout << c;

	return 0;
}
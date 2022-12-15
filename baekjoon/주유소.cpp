#include <iostream>

using namespace std;

long howmuch[100000];
long howlong[100000];

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	cin >> n;
	unsigned long long price = 0;


	for (int i = 1; i < n; i++)
	{
		cin >> howlong[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> howmuch[i];
	}
	int mini = howmuch[0];
	for (int i = 1; i < n; i++)
	{
		if (howmuch[i] < mini)
		{
			mini = howmuch[i];
		}
		else
		{
			howmuch[i] = mini;
		}
	}
	for (int i = 1; i < n; i++)
	{
		price += howlong[i] * howmuch[i-1];
	}
	cout << price << '\n';
	return 0;
}
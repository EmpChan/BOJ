#include <iostream>

using namespace std;

int looks[150];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int bo,countit=0,pointer;
	cin >> bo;
	for (int i = 0; i < n; i++)
	{
		cin >> looks[i];
	}
	pointer = 0;
	while (countit <= 1000000)
	{
		countit++;
		if (looks[pointer] == bo)
			break;
		else
			pointer = looks[pointer];
		
	}
	if (countit > 1000000)
		cout << -1;
	else
		cout << countit;

	return 0;
}
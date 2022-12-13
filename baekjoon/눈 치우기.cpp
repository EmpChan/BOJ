#include <iostream>

using namespace std;

int arr[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int countit = 0;
	while (countit <= 1440)
	{
		int m1=0, m2=1;
		for (int i = 2; i < n; i++)
		{
			if (arr[m1] < arr[i])
			{
				m1 = i;
				continue;
			}
			if (arr[m2] < arr[i])
			{
				m2 = i;
				continue;
			}
		}
		if (arr[m1] <= 0 && arr[m2] <= 0)
			break;
		arr[m1]--;
		arr[m2]--;
		countit++;
	}
	if (countit > 1440)
		cout << -1 << '\n';
	else
		cout << countit << '\n';
	return 0;
}
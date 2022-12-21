#include <iostream>

using namespace std;

long long arr[100000];

int findminilength(int n, long long s)
{
	int mpoint=0;
	int minilength = n;
	for (int i = 0; i < n; i++)
	{
		if (s <= arr[i])
		{
			minilength = i;
			break;
		}
	}
	mpoint = minilength;
	int cup = 0;
	
	while (minilength != cup)
	{
		cup = minilength;
		for (int i = mpoint; i < n; i ++)
		{
			if (s <= arr[i] - arr[i - minilength])
			{
				minilength -= 1;
				mpoint = i;
				break;
			}
		}
	}
	return minilength+1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long s;
	cin >> n;
	cin >> s;
	int length;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < n; i++)
	{
		arr[i] += arr[i - 1];
	}
	if (arr[n - 1] < s)
		cout << 0;
	else
	{
		length = findminilength(n,s);
		cout << length;
	}

	return 0;
}
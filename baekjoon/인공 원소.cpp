#include <iostream>

using namespace std;

bool n[200];

void era()
{
	n[0] = 1; n[1] = 1;
	for (int i = 2; i < 200; i++)
	{
		for (int k = i + i; k < 200; k += i)
		{
			n[k] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	era();
	int t,nums[118];
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> nums[i];
	}
	for (int i = 0; i < t; i++)
	{
		bool a=false;
		for (int j = nums[i]; j >= 2; j--)
		{
			if (!n[j] && !n[nums[i] - j])
			{
				a = true;
				cout << "Yes" << '\n';
				break;
			}
		}
		if (!a)
			cout << "No" << '\n';
	}
	return 0;
}
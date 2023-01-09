#include <iostream>

using namespace std;

int arr[9];

void printit(int n,int m,int c)
{
	if (c >= m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			bool flag = 0;
			for(int j=0; j<c; j++)
			{
				if (arr[j] == i)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				continue;
			else
			{
				arr[c] = i;
				printit(n, m, c + 1);
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin >> n >> m;
	printit(n, m, 0);

	return 0;
}
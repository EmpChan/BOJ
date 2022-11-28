#include <iostream>

using namespace std;

int stack[100000];
int temp[100000] = {1,};
char stackop[200001] { '+',};
int next_in = 2;
int last = 0;
int opcount = 1;
bool get_stackop(int g)
{
	while (1)
	{
		if (temp[last] == stack[g])
		{
			stackop[opcount++] = '-';
			last--;
			break;
		}
		else if (temp[last] < stack[g])
		{
			temp[++last] = next_in++;
			stackop[opcount++] = '+';
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> stack[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (get_stackop(i))
		{
			continue;
		}
		else
		{
			cout << "NO" << '\n';
			return 0;
		}
	}
	for (int i = 0; i < opcount; i++) cout << stackop[i] << '\n';
	return 0;
}
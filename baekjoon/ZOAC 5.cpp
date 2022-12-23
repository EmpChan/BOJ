#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string q;
	cin >> q;
	int mini = 1000000,countit=0;
	char cup=q[0];
	for (auto i : q)
	{
		if (cup == i)
			countit++;
		else
		{
			if (mini > countit)
				mini = countit;
			countit = 1;
		}
		cup = i;
	}
	if (mini > countit)
		mini = countit;
	cout << mini;

	return  0;
}
#include <iostream>
#include <map>

using namespace std;

map<string, int>recipe;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a;
		int cup;
		cin >> a;
		cin >> cup;
		if (recipe.find(a) == recipe.end())
		{
			recipe[a] = cup;
		}
		else
		{
			recipe[a] += cup;
		}
	}
	for (auto i : recipe)
	{
		for (auto j : recipe)
		{
			if (i.first == j.first)
				continue;
			
			if (max(i.second,j.second)==int(min(i.second,j.second)*1.618))
			{
				cout << "Delicious!";
				return 0;
			}
		}
	}
	cout << "Not Delicious...";

	return 0;
}
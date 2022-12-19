#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a;
	string m = "aeiouAEIOU";
	getline(cin, a);
	while (a != "#")
	{
		int countit = 0;
		for (auto i : a)
		{
			for (auto j : m)
			{
				if (i == j)
					countit++;
			}
		}
		cout << countit << '\n';
		getline(cin, a);
	}
	return 0;
}
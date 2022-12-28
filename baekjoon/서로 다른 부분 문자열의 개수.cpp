#include <iostream>
#include <set>

using namespace std;

set<string>ground;

int main()
{
	string a;
	cin >> a;
	string cup = "";
	int c = 0;
	while (c < a.length())
	{
		c++;
		for (int i = 0; i <= a.length() - c; i++)
		{
			ground.insert(a.substr(i,c));
		}
	}
	cout << ground.size();

	return 0;
}
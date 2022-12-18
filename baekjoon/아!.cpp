#include <iostream>

using namespace std;

int main()
{
	string a;
	string b;
	cin >> a;
	cin >> b;
	if (a.length() >= b.length())
		cout << "go";
	else
		cout << "no";
	return 0;
}
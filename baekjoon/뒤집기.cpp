#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string inp;
	cin >> inp;
	int count=0;
	char a=inp[0];
	for (auto i : inp)
	{
		if (a != i)
			count++;
		a = i;
	}
	if (count == 0)
		cout << 0;
	else
	{
		if (count % 2 == 0)
			cout << (count)/2;
		else
			cout << (count+1)/2;
	}

	return 0;
}
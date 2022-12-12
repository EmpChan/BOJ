#include <iostream>

using namespace std;

int c1=0;
int c2=0;
int codeone(int n)
{
	if (n == 1 || n == 2)
	{
		c1++;
		return 1;
	}
	else
		return (codeone(n - 1) + codeone(n - 2));
}
int codetwo(int n)
{
	c2++;
	int f1 = 1;
	int f2 = 1;
	for (int i = 3; i < n; i++)
	{
		c2++;
		int cup = f2;
		f2 = f2 + f1;
		f1 = cup;
	}
	return f2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	codeone(n);
	codetwo(n);
	cout << c1 << ' ' << c2;

	return 0;
}
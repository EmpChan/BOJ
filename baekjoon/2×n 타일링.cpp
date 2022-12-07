#include <iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int one=1, two=1;
	int cup;
	for (int i = 1; i < n; i++)
	{
		cup = two%10007;
		two += one;
		one = cup%10007;
	}
	

	cout << two%10007;
	return 0;
}
#include <iostream>

using namespace std;

int alpha[26] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,mini=999999;
	cin >> n;
	string s;
	cin >> s;
	int arr[5] = { 'H' - 'A','I' - 'A','R' - 'A','A' - 'A','C' - 'A' };
	for (auto i : s)
	{
		alpha[ i - 'A']++;
	}
	for (auto i : arr)
	{
		if (alpha[i] < mini)
			mini = alpha[i];
	}
	cout << mini;
	return 0;

}
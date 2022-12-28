#include <iostream>
#include <map>

using namespace std;

string arr[10];
map<char, int>alpha;
map<char, int>weight;

int stringtoint(string a)
{
	int cup = 0,w=1;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		cup += weight[a[i]]*w;
		w *= 10;
	}
	return cup;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long r=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (char i = 'A'; i <= 'Z'; i++)
	{
		alpha[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		int w = 1;
		for (int j = arr[i].length() - 1; j >= 0; j--)
		{
			alpha[arr[i][j]] += w;
			w *= 10;
		}
	}
	int mw = 9999999999, num = 9;
	for (int i = 0; i < 10; i++)
	{
		int most = 0,cup = -1;
		for (int j = 0; j < 26; j++)
		{
			if (alpha[j + 'A'] > most && (mw >= alpha[j+'A'] && weight.find(j+'A')==weight.end()))
			{
				most = alpha[j + 'A'];
				cup = j;
			}
		}
		mw = most;
		if (cup == -1)
			break;
		weight[cup + 'A'] = num--;
	}
	for (int i = 0; i < n; i++)
	{
		r += stringtoint(arr[i]);
	}
	cout << r;

	return 0;
}
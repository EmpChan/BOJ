#include <iostream>
#include <algorithm>

using namespace std;

struct a {
	string s;
	int i;
	int d;
};

a pro[100];
int se[100001] = { 0 };
int compare(a one, a two)
{
	if (one.i < two.i)
		return 1;
	else if (one.i > two.i)
		return -1;
	else
		return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	string ans="";
	for (int i = 0; i < n; i++)
	{
		cin >> pro[i].s;
		cin >> pro[i].i;
		se[pro[i].i] = i+1;
		cin >> pro[i].d;
	}
	for (int i = 0; i <= 100000; i++)
	{
		if (se[i])
		{
			char j = pro[se[i]-1].s[pro[se[i]-1].d-1];
			if (j >= 'a' && j <= 'z')
			{
				j -= 'a';
				j += 'A';
			}
			ans += j;
		}
	}
	cout << ans;
	return 0;
}
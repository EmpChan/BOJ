#include <iostream>
#include <map>

#define MAXPLAYER 100000

using namespace std;

map<int, int>s;

struct play {
	int num;
};

play player[MAXPLAYER];
play temp[MAXPLAYER];
bool nums[1000001];

void check(int n)
{
	for (int i=0; i<n; i++)
	{
		for (int j = player[i].num + player[i].num; j <= 1000000; j += player[i].num)
		{
			if (nums[j])
			{
				s[player[i].num]++;
				s[j]--;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> player[i].num;
		nums[player[i].num] = true;
	}
	for (int i = 0; i < n; i++)
	{
		s[player[i].num] = 0;
	}
	check(n);
	for (int i=0; i<n; i++)
	{
		cout << s[player[i].num] << ' ';
	}

	return 0;
}
#include <iostream>

using namespace std;
int time_record[257];
int ground[250000] = { 0 };
int b;
void get_time(int n, int m)
{
	int mini;
	for (int h = 0; h < 257; h++)
	{
		int cup = b;
		int t = 0;
		for (int i = 0; i < n * m; i++)
		{
			if (ground[i] < h)
			{
				cup -= h - ground[i];
				t += (h - ground[i]);
			}
			else if (ground[i] > h)
			{
				cup += ground[i] - h;
				t += (ground[i] - h) * 2;
			}
		}
		if (cup < 0)
		{
			time_record[h] = 2100000000;
		}
		else
			time_record[h] = t;
	}
	mini = time_record[0];
	int h = 0;
	for (int i = 1; i < 257; i++)
	{
		if (mini >= time_record[i])
		{
			mini = time_record[i];
			h = i;
		}
	}
	cout << mini << ' ' << h << '\n';


}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;
	cin >> b;

	for (int i = 0; i < n * m; i++) cin >> ground[i];
	get_time(n, m);
	

	return 0;
}


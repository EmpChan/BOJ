#include <iostream>

using namespace std;

int minheap[100001];
int last = 0;

void insertheap(int a)
{
	minheap[++last] = a;
	int p = last;
	while (p > 1)
	{
		if (minheap[p] >= minheap[p / 2])
		{
			swap(minheap[p], minheap[p / 2]);
			p = p / 2;
		}
		else
			break;
	}
}

int popheap()
{
	int c = minheap[1];
	if (last <= 0)
		return 0;
	minheap[1] = minheap[last--];
	minheap[last + 1] = 0;
	int p = 1;
	while (p <= last)
	{
		if (minheap[p * 2] > minheap[p * 2 + 1])
		{
			if (minheap[p] < minheap[p * 2] && p * 2 <= last)
			{
				swap(minheap[p], minheap[p * 2]);
				p = p * 2;
			}
			else if (minheap[p] < minheap[p * 2 + 1] && p * 2 + 1 <= last)
			{
				swap(minheap[p], minheap[p * 2 + 1]);
				p = p * 2 + 1;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (minheap[p] < minheap[p * 2 + 1] && p * 2 +1 <= last)
			{
				swap(minheap[p], minheap[p * 2+1]);
				p = p * 2 +1;
			}
			else if (minheap[p] < minheap[p * 2] && p * 2<= last)
			{
				swap(minheap[p], minheap[p * 2]);
				p = p * 2;
			}
			else
			{
				break;
			}
		}
	}
	return c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int cup;
		cin >> cup;
		if (cup != 0)
		{
			insertheap(cup);
		}
		else
		{
			cup=popheap();
			cout << cup << '\n';
		}
	}

	return 0;
}
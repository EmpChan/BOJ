#include <iostream>

using namespace std;

int heap[200001];
int last = 0;

int absol(int a)
{
	if (a < 0)
		return a * -1;
	else
		return a;
}

bool compare(int a,int b)
{
	if (absol(a) > absol(b))
		return 1;
	else if (absol(a) == absol(b) && a > b)
		return 1;
	else
		return 0;
}


void insert(int a)
{
	last++;
	heap[last] = a;
	int p = last;
	while (p > 1)
	{
		if (compare(heap[p/2],heap[p]))
		{
			swap(heap[p], heap[p / 2]);
			p = p / 2;
		}
		else
		{
			break;
		}
	}
}

void printheap()
{
	for (int i = 1; i <= last; i++)
		cout << heap[i] << ' ';
	cout << '\n' << '\n';
}

int pop()
{
	int c = heap[1];
	if (last < 1)
		return 0;
	heap[1] = heap[last];
	heap[last--] = 0;
	int p = 1;
	while (p < last)
	{
		if (compare(heap[p*2+1],heap[p*2]))
		{
			if (compare(heap[p],heap[p*2]) && p * 2 <= last)
			{
				swap(heap[p], heap[p * 2]);
				p = p * 2;
			}
			else if (compare(heap[p], heap[p * 2+1]) && p*2+1 <= last)
			{
				swap(heap[p], heap[p * 2 + 1]);
				p = p * 2 + 1;
			}
			else
				break;
		}
		else
		{
			if (compare(heap[p], heap[p * 2+1]) && p * 2 + 1 <= last)
			{
				swap(heap[p], heap[p * 2 + 1]);
				p = p * 2 + 1;
			}
			else if (compare(heap[p], heap[p * 2]) && p * 2 <= last)
			{
				swap(heap[p], heap[p * 2]);
				p = p * 2;
			}
			else
				break;
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
			insert(cup);
		else
		{
			cup = pop();
			cout << cup << '\n';
		}
	}
	return 0;
}
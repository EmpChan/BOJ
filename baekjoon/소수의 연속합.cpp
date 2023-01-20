#include <iostream>

using namespace std;

bool era[4000001];
long long prime[300000];
long long arr[300000];
int c;

void get_prime()
{
	for (int i = 2; i <= 200000; i++)
	{
		for (int j = i + i; j <= 4000000; j += i)
			era[j] = 1;
	}
	for (int i = 2; i <= 4000000; i++)
	{
		if (!era[i])
			prime[c++] = i;
	}
	arr[0] = 0;
	for (int i = 0; i < c; i++)
	{
		arr[i+1] = arr[i] + prime[i];
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	get_prime();
	int n;
	cin >> n;
	int p=0, q=1;
	int counting = 0;
	while (true)
	{
		if (arr[q] - arr[p] < n)
			q++;
		else if (arr[q] - arr[p] > n)
			p++;
		else {
			counting++;
			q++;
		}
		if (q > c || p > c)
			break;
	}

	cout << counting;
	
	return 0;
}
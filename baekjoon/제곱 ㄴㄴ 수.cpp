#include <iostream>

using namespace std;

long long arr[100000]; // 아님
bool sosu[1100001];
bool ans[1000011];
long long c;  // 아님

void base()
{
	c = 0;
	for (int i = 0; i < 1100000; i++) sosu[i] = 0;
	for (int i = 2; i < 1100000; i++)
	{
		for (int j = i+i; j <1100000; j+=i)
		{
			sosu[j] = 1;
		}
	}
	for (long long i = 2; i < 1100000; i++)
	{
		if (!sosu[i]) {
			arr[c++] = i * i;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m, countit=0;
	cin >> n >> m;
	base(); 
	for (long long i = 0; i < c; i++)
	{
		if (arr[i] > m)
			break;
		long long cup = n / arr[i];
		if (n % arr[i] != 0)
			cup+= 1;
		for (long long j = (cup * arr[i]) - n; j <= m - n; j+=arr[i])
		{
			ans[j] = 1;
		}
	}

	for(long long i = 0; i <= m - n; i++)
	{
		if (!ans[i]) countit++;
	}
	cout << countit;
	return 0;
}
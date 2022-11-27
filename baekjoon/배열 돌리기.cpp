#include <iostream>

using namespace std;

void turnit(int* arr,int n,int d,int a,int b,int c)
{
	if (a == b || b == c)
		return;
	int k[8] = { a * n + a, a * n + b, a * n + c, b * n + c,c * n + c, c * n + b, c * n + a,  b * n + a };
	int q=0,p[8];
	
	for (int i = 0; i < 8; i++) p[i] = arr[k[i]];
	if (d > 0)
	{
		for (int i = 0; i < 8; i++)
		{
			arr[k[(i + d) % 8]] = p[i];
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
				arr[k[(8 + ((i + d)%-8))%8]]= p[i];
		}
	}
	turnit(arr, n, d, a + 1, b, c - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int arr[250000];
		int n, d;
		int a = 0, b, c;
		cin >> n;
		cin >> d;
		d /= 45;
		b = n / 2;
		c = n - 1;
		for (int j = 0; j < n * n; j++) cin >> arr[j];
		turnit(arr ,n, d, a, b, c);
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cout << arr[j * n + k] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}
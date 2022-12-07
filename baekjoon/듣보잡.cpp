#include <iostream>

using namespace std;

string cantsee[500000];
string canthear[500000];
string temp[500000];

void merge(string* arr, int s, int e)
{
	int mid = (s + e) / 2;
	int i = s, j = mid + 1, k = s;
	while (i <= mid && j <= e)
	{
		if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= e) temp[k++] = arr[j++];

	for (int i = s; i <= e; i++) arr[i] = temp[i];
}

void partition(string* arr,int s, int e)
{
	if (s >= e)
		return;
	int mid = (s + e) / 2;
	partition(arr, s, mid);
	partition(arr, mid + 1, e);
	merge(arr, s, e);
}

void find_no_see_no_hear(int n, int m)
{
	int i = 0, j = 0;
	int s = 0;
	while (i < n && j < m)
	{
		if (cantsee[i] == canthear[j])
		{
			temp[s++] = cantsee[i];
			i++;
			j++;
		}
		else
		{
			if (cantsee[i] > canthear[j])
				j++;
			else
				i++;
		}
	}
	while (i < n)
	{
		if (cantsee[i++] == canthear[j])
			temp[s++] = cantsee[i];
	}
	while (j < m)
	{
		if (cantsee[i] == canthear[j++])
			temp[s++] = cantsee[i];
	}
	cout << s << '\n';
	for (int i = 0; i < s; i++)
	{
		cout << temp[i] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> cantsee[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> canthear[i];
	}
	partition(cantsee, 0, n-1);
	partition(canthear, 0, m-1);
	find_no_see_no_hear(n, m);
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 20001;

string temp[MAX_SIZE];
string str[MAX_SIZE];

int compare(string a, string b)
{
	if (a.length() < b.length())
		return 1;
	else if (a.length() == b.length())
	{
		if (a <= b)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

void merge(int s, int e)
{
	int mid = (s + e) / 2;
	int i = s, j = mid + 1, k = s;
	while (i <= mid && j <= e)
	{
		if (compare(str[i], str[j]))
			temp[k++] = str[i++];
		else
			temp[k++] = str[j++];
	}
	while (i <= mid) temp[k++] = str[i++];
	while (j <= e) temp[k++] = str[j++];
	for (int m = s; m <= e; m++) str[m] = temp[m];

}

void partition(int s, int e)
{
	if (s >= e)
		return;
	int mid = (s + e) / 2;
	partition(s, mid);
	partition(mid + 1, e);
	merge(s, e);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	partition(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		if (i == 0) cout << str[i] << '\n';
		else if (str[i] == str[i - 1])
			continue;
		else
			cout << str[i] << '\n';
	}
	return 0;
}
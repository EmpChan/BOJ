#include <iostream>

using namespace std;

struct u {
	int age;
	string name;
};

u user[100000];
u temp[100000];

void merge(int s, int e)
{
	int mid = (s + e) / 2;
	int i = s, j = mid + 1, k = s;
	while (i <= mid && j <= e)
	{
		if (user[i].age <= user[j].age)
			temp[k++] = user[i++];
		else
			temp[k++] = user[j++];
	}
	while (i <= mid)temp[k++] = user[i++];
	while (j <= e)temp[k++] = user[j++];
	for (int m = s; m <= e; m++) user[m] = temp[m];
}

void sort(int s, int e)
{
	if (s < e)
	{
		int mid = (s + e) / 2;
		sort(s, mid);
		sort(mid+1, e);
		merge(s, e);
	}
	return;
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
		cin >> user[i].age;
		cin >> user[i].name;
	}
	sort(0, n-1);
	for (int i = 0; i < n; i++)
		cout << user[i].age << ' ' << user[i].name << '\n';
	return 0;
}
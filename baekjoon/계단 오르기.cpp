#include <iostream>

using namespace std;

int arr[301];

int score[301];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> score[i];

	arr[0] = 0;
	arr[1] = score[1];
	arr[2] = score[1] + score[2];
	for (int i = 3; i <= n; i++)
	{
		arr[i] = max(arr[i - 2] + score[i], score[i - 1] + score[i] + arr[i - 3]);
	}

	cout << arr[n] << '\n';

	return 0;
}
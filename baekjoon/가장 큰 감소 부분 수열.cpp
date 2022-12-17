#include <iostream>

using namespace std;

int nums[1000];
int arr[1000];



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,c=1,ans = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> nums[i];
	arr[0] = nums[0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[j] > nums[i])
				arr[i] = max(arr[i], nums[i] + arr[j]);
			else
				arr[i] = max(nums[i], arr[i]);
			if (arr[i] > ans)
				ans = arr[i];
		}
	}
	
	cout << ans;

	return 0;
}
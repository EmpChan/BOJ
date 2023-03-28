#include <stdio.h>
#define MAX 1001

int arr[MAX];

void selectsort(int size) {
	for (int i = 0; i < size; i++) {
		int key=i;
		for (int j = i; j < size; j++) {
			if (arr[key] > arr[j]) key = j;
		}
		int temp = arr[i];
		arr[i] = arr[key];
		arr[key] = temp;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	selectsort(n);
	
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}

/* 머지? 머지는 합병입니다.*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int weight;
	int height;
	int rank;
}stu;

int main() {
	
	int x, y, n; //x는 몸무게, y는 키, n은 사람 수
	int num = 1;//num = 순위
	stu student[50];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &student[i].weight, &student[i].height);
	}
	for (int i = 0; i < n; i++)
	{
		for (int p = 0; p < n; p++)
		{
			if (student[i].weight < student[p].weight && student[i].height < student[p].height)
			{
				num++;
			}
		}
		student[i].rank = num;
		num = 1;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", student[i].rank);
	}
	return 0;
}
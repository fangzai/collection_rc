/*
time   :  2015-5-14
author :  ht
comment:  ex54�ı���
*/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
void show(int **matrix, int m, int n)
{
	int i, j;
	printf("========================================\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int** generateMatrix(int n) {
	if (n <= 0)
		return NULL;
	int i, j, k, p;

	int len;
	if (n % 2 == 0)  //ȷ���ж��ٲ�ѭ��
	{
		len = (n) / 2;
	}
	else
	{
		len = (n) / 2;
		len++; 
	}

	int index = 1;   //��1��ʼ

	int **matrix = (int**)malloc(n*sizeof(int*));
	for (i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc(n*sizeof(int));
	}

	int start, end;
	for (k = 0; k <len; k++)
	{
		i = k;
		//��һ��������(i,i)
		start = i;
		end = n - 1 - i;
		for (j = i; j < n - 1 - i; j++)
		{
			matrix[i][j] = index;
			index++;
		}
		if (index >= n*n)
		{
			//���������������������ͽ�����
			matrix[i][n - 1 - i] = index;
			index++;
			break;
		}

		//�ڶ���������(i,n-1-i)

		start = i;
		end = n - 1 - i;
		j = n - 1 - i;
		for (p = i; p < n - 1 - i; p++)
		{
			matrix[p][j] = index;
			index++;
		}

		//������������(n-1-i,n-1-i)
		start = n - 1 - i;
		end = i;
		p =n - 1 - i;
		for (j = n - 1 - i; j > i; j--)
		{
			matrix[p][j] = index;
			index++;
		}
		//���ĸ�������(n-1-i,i)
		start = n - 1 - i;
		end = i;
		j = i;
		for (p = n - 1 - i; p > i; p--)
		{
			matrix[p][j] = index;
			index++;
		}
		if (index > n*n)
			break;
	}
	//printf("total number is ================%d \n", index);
	return matrix;
}

int main()
{
	int n = 6;
	int **matrix = generateMatrix(n);

	show(matrix, n, n);
	return 0;
}
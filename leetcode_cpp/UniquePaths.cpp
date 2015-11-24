/*
time   :  2015-5-18
author :  ht
comment:  ������·������������ʵ�������������
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

long long int combination(int m, int n)
{
	int i, j;
	int num = m;
	long long int result = 1;
	int index = 1;
	for (i = 0; i < n; i++)
	{
		result = result*num/index;
		index++;
		num = num - 1;
	}
	return result;
}
int uniquePaths1(int m, int n) {
	if (m <= 1)
	{
		return 1;
	}
	if (n <= 1)
	{
		return 1;
	}
	int totalStep = m + n - 2;
	int down = n - 1;

	if (down > totalStep / 2)
	{
		down = totalStep - down;
	}

	long long int result = combination(totalStep,down);
	return result;
}
int uniquePaths(int m, int n) {
	//���Ͽ���һ���������ù�������ķ������
	int i, j;
	int **matrix = (int**)malloc(m*sizeof(int*));
	for (i = 0; i < m; i++)
	{
		matrix[i] = (int*)malloc(n*sizeof(int));
	}
	for (i = 0; i < m; i++)
		matrix[i][0] = 1;  //��һ�и�ֵΪ1
	for (i = 0; i < n; i++)
		matrix[0][i] = 1;  //��һ�и�ֵΪ1

	for (i = 1; i < m; i++)
	{
		for (j = 1; j < n; j++)
		{
			matrix[i][j] = matrix[i-1][j]+matrix[i][j-1];
		}
	}
	int result = matrix[m - 1][n - 1];
	for (i = 0; i < m; i++)
		free(matrix[i]);
	free(matrix);

	return result;
}
int main()
{
	int m = 51;
	int n = 9;
	printf("%d \n",uniquePaths(m,n));
	return 0;
}
/*
time   :  2015-5-16
author :  ht
comment:  ���һ����������0�Ļ����Ͱ����е�Ԫ�ض���Ϊ0
 
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
void show(int **matrix,int m,int n)
{
	int i, j;
	printf("========================================\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}
//����������õ���o(mn)���㷨��ֱ�ӱ�����������0�Ļ�
//����һ�ξ������е�Ԫ�ض�Ϊ0

//��һ�ַ�����o(m+n)  ��������������Ǹ��и����Ƿ�Ӧ����Ϊ0
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
	if (matrix == NULL||matrix[0]==NULL)
		return;
	int m = matrixRowSize;
	int n = matrixColSize;
	int*row = (int*)malloc(m*sizeof(int));
	int*col = (int*)malloc(n*sizeof(int));
	int i, j;
	for (i = 0; i < m; i++)  //�����⣬����Ҫ����Ϊ0 oj���ù�
	{
		row[i] = 0;
	}
	for (j = 0; j < n; j++)
	{
		col[j] = 0;
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (row[i] == 1 || col[j] == 1)
				matrix[i][j] = 0;
		}
	}

}

//�ڶ��ַ����ǳ����ռ������
void setZeroes1(int** matrix, int matrixRowSize, int matrixColSize)
{
	//�õ�һ�к͵�һ������ʾĳһ�к�ĳһ���Ƿ�Ӧ����Ϊ0
	if (matrix == NULL || matrix[0] == NULL)
		return;
	int m = matrixRowSize;
	int n = matrixColSize;
	int i, j;
	bool firstRow = false;  //��һ�еı��
	bool firstCol = false;
	for (i = 0; i < m; i++)
	{
		if (matrix[i][0] == 0)
		{
			firstCol = true;  //���һ����û��0
			break;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (matrix[0][i] == 0)
		{
			firstRow = true; //���һ����û��0
			break;
		}
	}

	for (i = 1; i < m; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;  
				//�ӵڶ��� �ڶ��п�ʼ�������������0,
				//�ͽ����еĵ�һ��Ԫ�ػ��߸��еĵ�һ��Ԫ����Ϊ0
				matrix[0][j] = 0;
			}
		}
	}


	for (i = 1; i < m; i++)
	{
		if (matrix[i][0] == 0)
		{
			for (j = 1; j < n; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	for (i = 1; i < n; i++)
	{
		if (matrix[0][i] == 0)
		{
			for (j = 1; j < m; j++)
			{
				matrix[j][i] = 0;
			}
		}

	}
	//��������һ�� �͵�һ��
	if (firstRow)
	{
		for (i = 0; i < n; i++)
		{
			matrix[0][i] = 0;
		}
	}
	if (firstCol)
	{
		for (i = 0; i < m; i++)
		{
			matrix[i][0] = 0;
		}
	}

}

int main()
{
	int m, n,i,j;
	m = 5;
	n = 6;
	int ** matrix;
	matrix = (int**)malloc(m*sizeof(int*));
	for (i = 0; i < m; i++)
	{
		matrix[i] = (int*)malloc(n*sizeof(int));
		for (j = 0; j < n; j++)
		{
			matrix[i][j] = 1;
		}
	}
	matrix[1][3] = 0;
	//int**matrix; 
	//matrix = (int**)malloc(m*sizeof(int*)); 
	//for (int i = 0; i < m; i++)
	//{
	//	matrix[i] = (int*)malloc(n*sizeof(int));
	//}
	//matrix[0][0] = INT_MIN;
	//matrix[1][0] = 2;
	//matrix[2][0] = 3;
	show(matrix,m,n);
	setZeroes1(matrix, m, n);
	show(matrix, m, n);
	return 0;
}
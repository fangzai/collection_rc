/*
time   :  2015-5-15
author :  ht
comment:  ������ת 90��
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

void show(int** matrix, int m, int n)
{
	int i, j;
	printf("the matrix is ===========================================\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
/*
 *
 * ��ʼ���������������
 * 1 2 3 4 
 * 5 6 7 8
 * 9 10 11 12
 * 13 14 15 16
 *�������
 * 13 9 5 1
 *14 10 6 2
 * 15 11 7 3
 * 16 12 8 4
 * ���Կ������±��Ǵ����ұ߿�ʼ��
 */

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
	int i, j,k;
	int len = matrixRowSize / 2;
	int temp1,temp2;
	int n = matrixRowSize;
	for (k = n - 1; k >= len; k--)
	{
		// ����k�Ϳ������i��
		i = n - 1 - k;
		//����Χ������
		for (j = i; j < k; j++)
		{
			temp1 = matrix[i][j];  
			//��ô��i,j������һ���ڵ��ǣ�n-j,i��
			matrix[i][j] = matrix[n-1 - j][i];

			// ��i,j������һ���ڵ��ǣ�j,n-i��
			temp2 = matrix[j][n-1 - i];
			matrix[j][n-1 - i] = temp1;

			//��j,n-i������һ���ڵ���(n-i,n-j)

			temp1 = matrix[n-1 - i][n-1 - j];
			matrix[n-1 - i][n-1 - j] = temp2;

			// (n-i,n-j)��һ���ڵ��� ��n-j,i��
			matrix[n-1 - j][i] = temp1;
		}
		//show(matrix, n, n);
	}

}

int main()
{
	int n = 4;
	int **matrix = (int**)malloc(n*sizeof(int*));
	int i, j, index = 1;;
	for (i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc(n*sizeof(int));
		for (j = 0; j < n; j++)
		{
			matrix[i][j] = index;
			index++;
		}
	}
	show(matrix, n, n);
	rotate(matrix, n, n);
	show(matrix, n, n);
	return 0;
}
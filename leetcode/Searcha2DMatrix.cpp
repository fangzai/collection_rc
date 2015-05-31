/*
time   :  2015-5-18
author :  ht
comment:  �Ծ�����ж��ֲ���
*/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

void show(int**matrix, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	int m, n;
	m = matrixRowSize;
	n = matrixColSize;

	int up = 0, down = m - 1;
	int mid;
	while (up < down)
	{
		if (up == down || (up == (down - 1)))
			break;  //�˳�������������һ����up == down,����һ����up == down-1
		mid = (up + down) / 2;
		if (matrix[mid][0] >target)
		{
			down = mid - 1;  //��������mid��һ��
		}
		else
		{
			if (matrix[mid][0] < target)
			{
				up = mid;  //������mid��һ��
			}
			else
			{
				return true;
			}
		}
	}
	int line;//ȷ����������һ��
	if (up == down)
	{
		line = up;  //������һ�У������ö��ֲ���
	}
	else
	{
		if (matrix[down][0] > target)
		{
			line = up;
		}
		else
		{
			line = down;
		}
	}

	
	int left = 0, right = n - 1;
	while (left <= right)
	{
		mid = (left + right) / 2; // left + (right-left)/2
		if (matrix[line][mid] > target)
		{
			right = mid-1;  //ȥ��mid 
		}
		else if (matrix[line][mid] < target)
		{
			left = mid+1;  //��ȥmid
		}
		else
		{
			return true;
		}
	}

	return false;
}
int main()
{
	int m = 2;
	int n = 1;
	int nums1[5] = { 1, 3, 5, 7 };
	int nums2[5] = { 10, 11, 16, 20 };
	int nums3[5] = { 23, 30, 34, 50 };
	int nums4[5] = { 53, 63, 64, 65 };
	int **matrix = (int**)malloc(m*sizeof(int**));
	int i, j;
	matrix[0] = nums1;
	matrix[1] = nums2;
	//matrix[2] = nums3;
	//matrix[3] = nums4;
	int target = 10;
	if (searchMatrix(matrix, m, n, target))
	{
		printf("Find the number %d \n",target);
	}
	else
	{
		printf("Didn't find the number %d \n", target);
	}
	return 0;
}
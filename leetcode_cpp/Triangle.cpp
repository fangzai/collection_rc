/*
time   :  2015-5-13
author :  ht
comment:  ����ת��Ϊ�ַ������
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
void traverse(int**triangle, int i,int j,int current,int numRows,int*index,int*data)
{
	//�����������ͱ������ǲ���  �ռ临�Ӷ��� 2^n
	if ((i+1) == numRows)
	{
		index[0]++;
		//printf("%d ===  %d \n",index[0], current);
		data[index[0] - 1] = current;
		//return current;
	}
	else
	{
		int temp1 = current +triangle[i+1][j];
		traverse(triangle, i + 1, j, temp1, numRows, index, data);

		int temp2 = current + triangle[i+1][j+1];
		traverse(triangle, i + 1, j + 1, temp2, numRows, index, data);
	}
}
int minimumTotal(int **triangle, int numRows) {
	int i = 0, j;
	if (numRows <= 0)
		return 0;
	int numSize = pow(2, numRows - 1);
	int *data = (int*)malloc(numSize*sizeof(int));
	for (i = 0; i < numSize; i++)
	{
		data[i] = 0;
	}

	int index = 0;
	traverse(triangle, 0, 0, triangle[0][0], numRows, &index, data);
	int min = data[0];

	for (i = 1; i < numSize; i++)
	{
		if (min > data[i])
		{
			min = data[i];
		}
		printf("%d ==========%d  \n", i, data[i]);
	}

	return min;
}
void reTraverse(int**triangle,int numRows, int index, int*data)
{
	// ����������ռ临�Ӷ��� n
	// ��Ϊǰ��ö����ظ���  �������ֻ��Ҫ�Ƚϵ�ǰ�Ľ�Сֵ�Ϳ�����
	int i;
	if ((index+1) == numRows)
	{

		for (i = 0; i <= index; i++)
		{
			data[i] = triangle[index][i];
			//���һ���ϸ�data��ֵ�����ϱ���
			//printf("%d ", data[i]);
		}
		//printf("\n");
	}
	else
	{
		index++;
		reTraverse(triangle, numRows, index, data);
		//����ط��ı����߽�Ҫ����1  ��Ϊǰ�� +1��
		for (i = 0; i <= index-1; i++)
		{
			data[i] = data[i] < data[i + 1] ? data[i] : data[i + 1];
			data[i] += triangle[index-1][i];
			//printf("%d ", data[i]);
		}
		//printf("\n");
	}
	
}
int minimumTotal1(int **triangle, int numRows) {
	int i = 0, j;
	if (numRows <= 0)
		return 0;
	int numSize = numRows;
	int *data = (int*)malloc(numSize*sizeof(int));
	for (i = 0; i < numSize; i++)
	{
		data[i] = 0;
	}
	int min = data[0];
	int index = 0;
	reTraverse(triangle, numRows, index, data);
	i = 0;
	return data[0];
}


int main()
{
	int num1[1] = {2};
	int num2[2] = { 3,4 };
	int num3[3] = { 6, 5 ,7};
	int num4[4] = { 4, 1, 8,3 };
	int num5[5] = { 4, 1, 8, 3 ,10};
	int *nums[5];
	nums[0] = num1;
	nums[1] = num2;
	nums[2] = num3;
	nums[3] = num4;
	nums[4] = num5;
	printf("%d \n", minimumTotal1(nums, 4));
	return 0;
}
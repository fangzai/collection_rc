/*
time   :  2015-5-9
author :  ht
comment:  ����piscal ������
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** generate(int numRows, int** columnSizes, int* returnSize) {
	
	returnSize[0] = numRows;  //����Ȼ�ĺðɣ�
	//columnSizes[0] = (int*)malloc(numRows*sizeof(int));  
	//�Ǻ�  �����leetcode�ϱ���Ҫ�������ù������� runtime error
	int i = 0,j;
	int **result = (int**)malloc(numRows*sizeof(int*));
	for (i = 0; i < numRows; i++)
	{
		columnSizes[0][i] = i+1;
		result[i] = (int*)malloc((i+1)*sizeof(int));
		result[i][0] = 1;  //��һ��ֵΪ 1
		result[i][i] = 1;  //���һ��ֵҲ��1
	}
	for (i = 1; i < numRows; i++)
	{
		for (j = 1; j < i; j++)
		{
			result[i][j] = result[i - 1][j] + result[i - 1][j-1];
		}
	}
	return result;

}

int main()
{
	int num = 5;
	int *columnSizes = (int*)malloc(num*sizeof(int));
	int returnSize;
	int **result = generate(num,&columnSizes,&returnSize);

	int i, j;
	//printf("%d  \n",returnSize);
	for (i = 0; i < returnSize; i++)
	{
		for (j = 0; j < columnSizes[i]; j++)
		{
			printf("%d  ", result[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < returnSize; i++)
	{
		free(result[i]);
	}
	free(result);
	return 0;
}
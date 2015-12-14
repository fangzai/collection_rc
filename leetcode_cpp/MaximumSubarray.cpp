/*
time   :  2015-5-14
author :  ht
comment:  �������ڵ�����
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int travser1(int* prices, int pricesSize) {
	// ��������  ���Ӷ���o(��n^2)
	int i, j;
	int ps, pe;
	int max = INT_MIN;  //��ʼ����Сֵ

	int sum = 0;
	for (i = 0; i < pricesSize; i++)
	{
		sum = 0;
		for (j = i; j < pricesSize; j++)
		{
			sum += prices[j];
			if (sum > max)
			{
				max = sum;
				ps = i;  //����λ��
				pe = j;
			}
		}
	}
	printf("from %d  to from %d  == %d\n", ps, pe, max);
	return max;
}
int maxSubArray(int* nums, int numsSize) {
	// ��̬�滮  ���Ӷ���o(n)
	// ���ƹ�ʽ�� dp[i] = max(dp[i-1]+nums[i],nums[i])

	/*
	*���㷨���ڵ�˼��Ҳ�ܼ򵥣�������������к͵ĵ�һ��Ԫ�ز������Ǹ�����
	*���ܺ�֤������֤��������a[i��j]Ϊ����������������a[i]Ϊ��������
	*a[i+1��j]�ĺͽ������a[i��j]�ĺͣ�������ԭ����ì�ܣ�������Ƴ������
	*���к͵ĵ�һ��Ԫ�ز������Ǹ������õ�����������ǾͿ��Խ�һ�������ƹ㣬
	*�Ǿ������һ�������еĺ�Ϊ��������ô������в����������������������
	*�Ŀ�ʼ��һ�����У������ڵ�һ��Ԫ�صķ����ɵõ�֤��������κͿ�����һ��Ԫ�أ�
	*/
	if (numsSize <= 0)
		return 0;

	int i, j;
	int ps, pe;
	int ts, te;
	int sum = 0;
	int max = INT_MIN;

	for (i = 0; i < numsSize; i++)
	{
		if (sum <= 0)
		{
			//����sum
			//������ʱ��¼�±��ts��te
			sum = nums[i];
			ts = i;
			te = i;
		}
		else
		{
			sum += nums[i];
			te = i;
		}
		if (sum > max)
		{
			max = sum;
			ps = ts;
			pe = te;
		}
	}
	return max;
}
// �ڶ��ַ������ǵݹ�� �����黮�ֳ����룬Ȼ������������
// 1 �������ұ�  
// 2 ���������
// 3 �����Խ��  д�����ʱ���ⲿ�ֵ���д��ʣ��Ĳ��ֵݹ�
// ���Ӷ��� nlogn �����ҹ�����д���������ݹ�Ҫ���ر��
int* crossSubArray(int*nums, int low, int mid, int high)
{
	int leftSum = INT_MIN,rightSum = INT_MIN;
	int leftStart = 0, rightEnd = 0;
	int sum = 0;
	int i, j;
	for (i = mid; i >= 0; i--)
	{
		sum += nums[i];
		if (sum > leftSum)
		{
			leftSum = sum;
			leftStart = i;
		}
	}
	sum = 0;
	for (j = mid + 1; j <= high; j++)
	{
		sum += nums[j];
		if (sum > rightSum)
		{
			rightSum = sum;
			rightEnd = j;
		}
	}
	int label[3] = { 0 };
	label[0] = leftStart;
	label[1] = rightEnd;
	label[2] = leftSum + rightSum;
	return label;
}
int* findMaxSubArray(int*nums,int low,int high)
{
	if (high == low)
	{
		int label[3] = {0};
		label[0] = low;
		label[1] = high;
		label[2] = nums[low];
		return label;//�ݹ鵽������ĵط���
	}
	else
	{
		int mid = (low + high) / 2;
		int *leftResult = NULL,*crossResult=NULL,*rightResult=NULL;
		leftResult = findMaxSubArray(nums, low, mid);
		rightResult = findMaxSubArray(nums, mid+1, high);
		crossResult = crossSubArray(nums, low, mid, high);
		if (leftResult[2] >= rightResult[2] && leftResult[2] >= crossResult[2])
		{
			return leftResult;
		}
		else
		{
			if (rightResult[2] >= leftResult[2] && rightResult[2] >= crossResult[2])
			{
				return rightResult;
			}
			else
			{
				return crossResult;
			}
		}

	}
}
int maxSubArray1(int* nums, int numsSize)
{
	if (numsSize <= 0)
		return 0;
	int *result = findMaxSubArray(nums, 0, numsSize - 1);
	return result[2];
}
int main()
{
	int nums[10] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	//int nums[10] = { -2, 11, -4, 13, -5, -2 };
	int numSize = 3;
	printf("%d \n", maxSubArray1(nums, numSize));
	return 0;
}
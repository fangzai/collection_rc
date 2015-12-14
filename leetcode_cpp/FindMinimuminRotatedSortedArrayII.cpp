/*
time   :  2015-5-26
author :  ht
comment:  ����ת����sorted���������ҵ���Сֵ,��������������ظ�ֵ
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int findMin(int* nums, int numsSize) {
	//���������ʱ�临�Ӷȣ�������Ҫ����һ��
	if (numsSize <= 0)
		return 0;
	if (numsSize == 1)
		return nums[0];
	int i;
	int max = 0;
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i - 1] > nums[i])
		{
			max = nums[i];
			break;
		}
	}
	if (i == numsSize)
	{
		max = nums[0];  //����������û���ҵ��Ļ������ǵ�һ����С
	}
	return max;
}
int binarySearch(int* nums, int numsSize)
{
	//����һ�����Ӷ�Ϊlogn���㷨  ��������
	//���ڶ��������Ļ������nums��sorted���Ļ�û��ʲô����
	//��������һ��С�����������ת�˵�
	int target = 10;
	int i;
	int left, mid, right;
	left = 0;
	right = numsSize - 1;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] > target)
		{
			//
			right = mid - 1;  //Ҳ�޳�mid��
		}
		else if (nums[mid]<target)
		{
			left = mid + 1;  //�Ѿ��޳�mid��
		}
		else
		{
			return mid;
		}
	}
	return -2;
}
int findMin1(int* nums, int numsSize)
{
	if (numsSize <= 0)
		return 0;
	int i, j;
	int min = nums[0];
	int low = 0, high = numsSize - 1, mid;
	//����ѡ����Ǳ�����
	while (low<high)
	{
		if (nums[low] < nums[high])
			return nums[low];
		mid = low + (high - low) / 2;
		if (nums[mid]>nums[high])
		{
			low = mid + 1;  //���� ��Сֵ��������mid�±�ģ�
		}
		else if (nums[mid]<nums[high])
		{
			high = mid;
		}
		else
		{
			low++; //���nums[mid]��nums[high]һ���Ļ�
			//�Ͳ����������ˣ����ǿ϶���Сֵ������low��ߣ�ֻ����high�Ǳ�
		}
	}
	return nums[low]; //�˳���ʱ��϶�nums[low]<=mid[high]
}

int main()
{
	//int nums[10] = { 4, 5, 6, 7, 0, 3, 3, 3 };
	int nums[10] = { 3,3,1,3};
	int numSize = 4;
	printf("%d \n", findMin1(nums, numSize));
	//printf("%d \n", binarySearch(nums, numSize)+1);
	return 0;
}
/*
time   :  2015-5-16
author :  ht
comment:  �ҵ�ĳ��Ԫ�صĲ����λ��,���ö�������

*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int searchInsert1(int* nums, int numsSize, int target) {
	//������ͨ�ķ�����Ӧ�û��бȽϺõĶ�����������
	if (numsSize <= 0)
		return 0;

	int i = 0, j;
	while (i < numsSize&&target>nums[i])
	{
		i++;
	}
	return i;

}
int searchInsert(int* nums, int numsSize, int target) {
	//������������
	if (numsSize <= 0)
		return 0;
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
	return right+1; //���صĽ��left > right������nums[left]�϶���target��

}

int main()
{
	int nums[10] = {1,3,5,6};
	int numSize = 4;

	int target = 5;
	//printf("%d\n", searchInsert(nums, numSize, target));
	target = 2;
	printf("%d\n", searchInsert(nums, numSize, target));

	target = 7;
	printf("%d\n", searchInsert(nums, numSize, target));

	target = 0;
	printf("%d\n", searchInsert(nums, numSize, target));

	return 0;
}
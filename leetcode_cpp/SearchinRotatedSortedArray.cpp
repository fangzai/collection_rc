/*
time   :  2015-5-16
author :  ht
comment:  ��ת������飬���ö�������ĳ��target

*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;


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
	return right + 1; //���صĽ��left > right������nums[left]�϶���target��

}
// http://www.cnblogs.com/lichen782/p/leetcode_Search_in_Rotated_Sorted_Array.html
int search(int* nums, int numsSize, int target){
	int left, right,mid;
	left = 0;
	right = numsSize - 1;
	//��һ��Ķ��������±�����ж�̫���ˣ���Ҫ��ϸ����
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (target == nums[mid])
			return mid;
		if (nums[left]<nums[mid])
		{
			// ˵�����ڵ�һ����������
			if (nums[left]<=target&&target < nums[mid])
			{
				//��left ��mid-1����������
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		else if (nums[left]>nums[mid])
		{
			//˵�����ڵڶ�����������
			if (nums[mid]<target&&target <= nums[right])
			{
				//��left ��mid-1����������
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		else  //�������� left��mid�غϵ����
		{
			left = mid + 1;
		}
	}

	return -1;

}

int main()
{
	int nums[10] = { 4,5,6 ,7 ,0 ,1 ,2,3 };
	int numSize = 8;

	int target = 1;
	for (int i = 0; i < numSize; i++)
	{
		target = nums[i];
		printf("%d  ==== %d\n",target ,search(nums, numSize, target));
	}

	return 0;
}
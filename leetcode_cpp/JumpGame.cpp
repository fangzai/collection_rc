/*
time   :  2015-5-18
author :  ht
comment:  ������Ϸ
*/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

bool traverse(int* nums, int numsSize, int index)
{
	//д��һ���ݹ���� ��ʱ��
	int maxStep = nums[index];
	if ((index + maxStep) >= (numsSize - 1))
	{
		return true;
	}
	else
	{
		bool mark = false;
		int nextIndex = index;

		for (int i = maxStep; i >= 1; i--)
		{
			//nextIndex= nums[index];
			//nextIndex += i;
			mark = traverse(nums, numsSize, nextIndex + i);
			if (mark)
				return true;
		}
		return false;
	}
}

bool canJump1(int* nums, int numsSize) {

	int nextIndex = 0;
	int i = 0, j;
	bool mark = traverse(nums, numsSize, 0);

	return mark;
}
bool canJump(int* nums, int numsSize)
{
	/*
	 * ��̰�Ĳ��ԣ��տ�ʼstep = A[0]������һ��step--,
	 * ����ȡstep = max(step, A[1])������stepһֱ�Ǳ����������ƶ��������ֲ�����Ҳ��ȫ�����š�
	 */

	if (numsSize == 0)
		return false;
	int step = nums[0];

	for (int i = 1; i < numsSize; i++)
	{
		if (step > 0)
		{
			step--;
			step = step> nums[i]?step:nums[i];
		}
		else
			return false;
	}
	return true;
}
int main()
{
	int nums[10] = { 1, 0, 1, 1, 4 };
	//int nums[10] = {3,2,1,0,4};
	//int nums[10] = { 1,2,3 };
	int numSize = 1;
	if (canJump(nums, numSize))
	{
		printf("Ok, can finish the jump! \n");
	}
	else
	{
		printf("NO, can't finish the jump! \n");
	}
	return 0;
}
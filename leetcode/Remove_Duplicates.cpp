#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

int removeDuplicates(int* nums, int numsSize) {
	int i;
	int pointer = 0;  //��ǰָ���λ��
	//int step = 0;
	if (numsSize <= 0)   //��ֹ��������Ϊ�յ�����»���������Ĳ���
	{
		return 0;
	}
	int current;
	for (i = 1; i < numsSize; i++)
	{
		//current = nums[i];

		
		while ((nums[i] == nums[pointer]) && (i<numsSize))
		{
			i++;
		}
		if (i < numsSize)  //��ֹ�Ѿ�����������˻��ڽ���pointer�Ĳ���
		{
			pointer++;  //ָ����һ��δ�ظ�������
			nums[pointer] = nums[i];
		}

	}
	for (i = 0; i <= pointer; i++)
	{
		printf("%d  ", nums[i]);
	}
	printf("\n");
	return pointer+1;
}

int main()
{
	int nums[10] = {1,1,1,2,2,3,3,4,4,9};
	int numSize = 2;
	printf("%d \n", removeDuplicates(nums,numSize));
	return 0;
}
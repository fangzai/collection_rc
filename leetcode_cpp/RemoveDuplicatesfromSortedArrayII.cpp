/*
time   :  2015-5-12
author :  ht
comment:  ÿ��Ԫ���������2�Σ�ȥ�������
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int removeDuplicates(int* nums, int numsSize) {
	int i;
	int pointer = 0;
	//int step = 0;
	if (numsSize <= 0)
	{
		return 0;
	}
	int current;
	int count = 0;
	
	for (i = 0; i < numsSize; )
	{
		current = nums[pointer]; //pointer���ǵ�ǰָ���жϵĵط�
		count = 0;
		while ((current == nums[i]) && (i<numsSize))
		{
			//�±�ѭ����Ҫ�ٵ�һ��
			if (count <= 1)   //�����1+1���������ֳ��ִ���
			{
				nums[pointer] = nums[i];  //ÿ�γ��ֶ�����
				pointer++;
			}
			i++;
			count++;
		}
		if (count == 0)
		{
			i++;//���ֻ������һ�ξ�ֱ�ӹ�ȥ��
		}
		nums[pointer] = nums[i];  //i ����pointer
	}
	for (i = 0; i < pointer; i++)
	{
		printf("%d  ", nums[i]);
	}
	printf("\n");
	return pointer;
}

int main()
{
	int nums[] = { 1, 1, 1, 1,1,2,2 ,2,3,3};
	//int nums[] = { 1, 2, 2, 2, 3, 3 };
	int numSize = 1;
	printf("%d \n", removeDuplicates(nums, numSize));
	return 0;
}
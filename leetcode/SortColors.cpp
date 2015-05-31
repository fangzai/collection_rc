/*
time   :  2015-5-18
author :  ht
comment:  ��������ɫ��������ò���õ��Ǽ�������
*/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

void sortColors(int* nums, int numsSize) {
	//�൱�ڱ��������飬��ʵ����Ŀ��Ҫ��̫һ������ĿҪ��ֻ����һ��
	//������Ҫ�����ռ����
	int num1, num2, num3, i;
	num1 = num2 = num3 = 0;
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] == 0) num1++;
		if (nums[i] == 1) num2++;
		if (nums[i] == 2) num3++;
	}
	int k = 0;
	while (num1--) nums[k++] = 0;
	while (num2--) nums[k++] = 1;
	while (num3--) nums[k++] = 2;
}

//http://www.cnblogs.com/felixfang/p/3680047.html
void sortColors1(int* nums, int numsSize)
{
	int i = -1, j = -1, k = -1;

	//�Ҳ� ���������ը��
	//i  j  k�ֱ�����ָ�� 0 1 2������е�λ��
	for (int p = 0; p < numsSize; p++)
	{
		if (nums[p] == 0)
		{
			//�����0�Ļ���������Ѿ�������1��2��
			//����1 2�ļ���pointer��Ҫ����Ųһ��λ��
			//������Ų2 ��Ų1
			//����0 ����i+1ָ���λ��
			nums[++k] = 2;
			nums[++j] = 1;
			nums[++i] = 0;
		}
		else if (nums[p] == 1)
		{
			//�����1�Ļ���0�Ͳ����ˣ������ֲ���
			//ֱ��Ų����һ��2�Ϳ�����
			nums[++k] = 2;
			nums[++j] = 1;

		}
		else if (nums[p] == 2)
		{
			//�����2�Ļ���û��ʲô˵����ֱ�Ӹ��ӵ�k+1��λ����
			nums[++k] = 2;
		}
	}
}

int main()
{
	return 0;
}
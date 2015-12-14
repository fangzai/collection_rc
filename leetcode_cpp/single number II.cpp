/*
time   :  2015-5-12
author :  ht
comment:  һ����������������ĳ�����֣������������ֳ��ֵ�3��,
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int singleNumber(int* nums, int numsSize) {
	/* ͳ��ÿ��bit���ֵĴ������ĳ���ط����ֵĴ�������3�ı����������δ֪Ϊ1
	* ����λ�������������ε�����ÿ��λ���ϵ�1������mod3�϶�����0
	* a^0 = a
	* a^a = 0
	* a^b = b^a
	*/
	int number[32] = { 0 };
	int i, j;
	for (i = 0; i < numsSize; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (nums[i] & (1<<j)) 
			{ 
				//����jλ��ȡ����jλ
				number[j]++;
			}
		}
	}
	int result = 0;
	
	for (i = 31; i >=0; i--)
	{
		result *= 2;
		if (number[i] % 3 != 0)
		{
			//result += (1 << i);
			result += number[i]%3;
		}
	}
	//for (int i = 0; i < 32; ++i)
	//{
	//	if (number[i] % 3 != 0)
	//	{
	//		result += (1 << i);
	//	}
	//}
	return result;
}
int singleNumber1(int* nums, int numsSize) {
	// �ұ�ʾ�����ַ������Ĳ��Ǻ�����~~~~
	//�ܵ���˵������ͳ�Ƹ���������λ1���ֵĴ�����  
	//������one,two��ÿ��������λ�ֱ�����Ӧλ1���ֵĴ�������ȡģΪ1��2��  
	//����one,two��ĳ��������λ��Ϊ0ʱ�����ʾ��λ1���ֵĴ���ȡģ����Ϊ0��  
	int one = 0, two = 0; //�տ�ʼ��ÿλ��1��û���֣����Զ���0��  
	int three = 0; //��one,two��ĳ��������λ��Ϊ1ʱ�������Ѿ����������Σ�����ȡģ��  

	for (int i = 0; i < numsSize; ++i)
	{
		two |= one&nums[i];
		one ^= nums[i];
		three = one&two;
		//���������κ�one,two��0���൱��ȡģ  
		one &= ~three;
		two &= ~three;
	}

	return one | two; //��Ϊ��֪���Ǹ����ǳ���һ�λ������Σ����Խ�����һ�λ����εĶ�����
}

int main()
{
	int nums[7] = { 2, 2, 3, 2 };
	//cout << (1 << 7) << endl;
	int numSize = 4;
	printf("%d \n", singleNumber1(nums, numSize));
	return 0;
}
/*
time   :  2015-5-12
author :  ht
comment:  һ������������ֻ��һ��������һ�Σ������������ֳ��ֵ�����
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int singleNumber(int* nums, int numsSize) {
	/* ��������ľ��Ǳ����������϶��ᳬ��ʱ�����Ƶ�
	 * �������ϵ�˼·��������
	 * a^0 = a
	 * a^a = 0
	 * a^b = b^a
	 */

	int i = 0;
	int target = nums[0];
	for (i = 1; i < numsSize; i++)
	{
		target = target^(nums[i]);
	}
	return target;
}

int main()
{
	int nums[5] = { 1, 2, 3, 3, 2 };
	int numSize = 5;
	printf("%d \n", singleNumber(nums, numSize));
	return 0;
}
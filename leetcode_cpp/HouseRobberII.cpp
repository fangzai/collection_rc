/*
time   :  2015-5-20
author :  ht
comment:  house robber�������汾
          ��һ�������ڷ�����Ԫ�ص�����
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

//��̬�滮��˼��
/*ά��һ������dp��dp[i]��ʾ����i��������Ԫ�ص�����
*�����Ŀ��Եõ�dp{i] = max(num[i]+dp[i-2],dp[i-1))
*/

int max(int a, int b)
{
	return a > b ? a : b;
}
/*
 * ����ԭ����house robber,�ٹ���һ��
 * ����dp[i]��͵��i��ʱ������ֵ
 * dp[0] = nums[0]  ��Ϊֻ��һ��
 * dp[1] = max(nums[0],num[1])
 * ��͵�������ҵ�ʱ��dp[2] = max(dp[1],dp[0]+nums[2])  ��Ϊ͵�˵ڶ��Ҳ�������͵������
 * ����͵�˵�һ�Һ����͵������
 */
int traverse(int* nums, int numsSize)
{
	int i = 0;
	int *dp = (int*)malloc(numsSize*sizeof(int));
	if (numsSize <= 0)
		return 0;

	dp[0] = nums[0];
	dp[1] = max(nums[1], nums[0]);

	int pre1, pre2;
	for (i = 2; i < numsSize; i++)
	{
		dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
	}
	int result = dp[numsSize - 1];
	//free(dp);
	//dp = NULL;
	return result;
}
int rob(int* nums, int numsSize) {
	if (numsSize <= 0)
		return 0;
	if (numsSize == 1)
		return nums[0];
	int result1, result2;
	result1 = traverse(nums + 1, numsSize - 1);//�ӵڶ��ҵ����
	result2 = traverse(nums, numsSize - 1);   //�ӵ�һ�ҵ������ڶ���
	return max(result1, result2);
}

int main()
{
	int a[10] = { 2, 1, 1, 1, 5, 6, 7, 8, 9, 10 };
	int numsize = 4;
	printf("%d \n", rob(a, numsize));
	return 0;
}
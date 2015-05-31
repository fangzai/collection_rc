/*
time   :  2015-5-10
author :  ht
comment:  ��һ�������ڷ�����Ԫ�ص�����
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
int rob(int* nums, int numsSize) {
	int i = 0;
	int *dp = (int*)malloc(numsSize*sizeof(int));
	if (numsSize <= 0)
		return 0;

	dp[0] = nums[0];
	dp[1] = max(nums[1],nums[0]);
	/*
	 * ����ط��õ�ѭ������ȫ�����õݹ�ķ�ʽ��
	 * �����ݹ�ķ�ʽ����ջ��Ȼ��Ҳ����ֻά��������
	 * û�б�Ҫ�ٿ��ڴ�ռ�
	 */
	for (i = 2; i < numsSize; i++)
	{
		dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
	}
	return dp[numsSize-1];
}

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int numsize = 1;
	printf("%d \n", rob(a, numsize));
	return 0;
}
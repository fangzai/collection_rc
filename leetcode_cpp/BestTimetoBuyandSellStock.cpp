/*
time   :  2015-5-14
author :  ht
comment:  �������ڵ�����
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int maxProfit(int* prices, int pricesSize) {
	// ��������  ���Ӷ���o(��n^2)
	int i, j;
	int ps, pe;
	int max = INT_MIN;  //��ʼ����Сֵ

	int sum = 0;
	for (i = 0; i < pricesSize; i++)
	{
		sum = 0;
		for (j = i; j < pricesSize; j++)
		{
			sum += prices[j];
			if (sum > max)
			{
				max = sum;
				ps = i;  //����λ��
				pe = j;
			}
		}
	}
	printf("from %d  to from %d  == %d\n", ps, pe, max);
	return max;
}
// �ڶ��ַ������ǵݹ�� �����黮�ֳ����룬Ȼ������������
// 1 �������ұ�  
// 2 ���������
// 3 �����Խ��  д�����ʱ���ⲿ�ֵ���д��ʣ��Ĳ��ֵݹ�
// ���Ӷ��� nlogn �����ҹ�����д���������ݹ�Ҫ���ر��
int maxProfit1(int* prices, int pricesSize) {
	// ��̬�滮  ���Ӷ���o(n)
	// ���ƹ�ʽ�� dp[i] = max(dp[i-1]+nums[i],nums[i])

	/*
	 *���㷨���ڵ�˼��Ҳ�ܼ򵥣�������������к͵ĵ�һ��Ԫ�ز������Ǹ�����
	 *���ܺ�֤������֤��������a[i��j]Ϊ����������������a[i]Ϊ��������
	 *a[i+1��j]�ĺͽ������a[i��j]�ĺͣ�������ԭ����ì�ܣ�������Ƴ������
	 *���к͵ĵ�һ��Ԫ�ز������Ǹ������õ�����������ǾͿ��Խ�һ�������ƹ㣬
	 *�Ǿ������һ�������еĺ�Ϊ��������ô������в����������������������
	 *�Ŀ�ʼ��һ�����У������ڵ�һ��Ԫ�صķ����ɵõ�֤��������κͿ�����һ��Ԫ�أ�
	 */
	int i, j;
	int ps, pe;
	int ts, te;  //��¼��ʱ�����յ�
	int max = INT_MIN;  //��ʼ����Сֵ
	if (pricesSize <= 0)
		return 0;
	int sum = 0;
	for (i = 0; i < pricesSize; i++)
	{
		if (sum <= 0)
		{
			sum = prices[i]; //�ѵ�ǰֵ����sum
			ts = i;  // ��ʱ�±��������
			te = i;
		}
		else
		{
			sum += prices[i];  
			// ���sumΪ�������Ѻ�������Ž�ȥ
			te = i;
		}

		if (sum > max)
		{
			//��¼������еĺ��Լ������յ�
			max = sum;
			ps = ts;
			pe = te;
		}
	}
	printf("from %d  to from %d  == %d\n", ps, pe, max);
	return max;
}
int maxProfit2(int* prices, int pricesSize)
{
	//��Ŀ�����ˣ�Ӧ����j>i  Ȼ��max(price[j]-prices[i]) 
	// ����ת��Ϊ��̬�滮
	int i, j;
	int ps, pe;
	int max = INT_MIN;  //��ʼ����Сֵ

	int sum = 0;
	for (i = 0; i < pricesSize-1; i++)
	{
		prices[i] = prices[i+1] - prices[i];
	}
	
	int profit = maxProfit1(prices, pricesSize - 1);
	if (profit < 0)
	{
		profit = 0;
	}
	return profit ;
	
}

int main()
{
	int nums[10] = { 1,0, 6,5 , 5, 0 };
	//int nums[10] = {2,1};// { -2, 11, -4, 13, -5, -2 }
	int numSize = 6;
	printf("%d \n", maxProfit2(nums, numSize));
	return 0;
}
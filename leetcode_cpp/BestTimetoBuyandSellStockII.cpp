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

/*
 *  �ϸ���˵����ɱ�exe121�򵥶��ˣ���ʾ�������������ľ���
 */
int maxProfit2(int* prices, int pricesSize)
{
	int i, j;
	int ps, pe;
	int max = INT_MIN;  //��ʼ����Сֵ

	int sum = 0;
	int profit = 0;
	if (pricesSize <= 1)
		return 0;
	for (i = 0; i < pricesSize - 1; i++)
	{
		prices[i] = prices[i + 1] - prices[i];
		if (prices[i] > 0)
		{
			profit += prices[i];
		}
	}

	if (profit < 0)
	{
		profit = 0;
	}
	return profit;
}

int main()
{
	int nums[10] = { 1, 0, 6, 7, 9, 0 };
	//int nums[10] = {2,1};// { -2, 11, -4, 13, -5, -2 }
	int numSize = 6;
	printf("%d \n", maxProfit2(nums, numSize));
	return 0;
}
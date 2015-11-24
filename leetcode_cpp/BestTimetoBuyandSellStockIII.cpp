/*
time   :  2015-5-25
author :  ht
comment:  ���Ľ��״�����2������������
*/
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

/*
 * ���ڿ������ҵ�ʱ��һ����������ò�ƻ��븴����
 * ��һ�ָ����ò����Ǹ�����������

 * ����������ص�˼�������i��һ��ֽ磬��߽��������ұ߽�����������
 * Ȼ�����ɨһ��Ϳ�����
 * �������Ӷ�ò�ƻ�ܸ�
 * ����ö�̬�滮�Ļ������߶�ά��һ������Ϳ�����
 */
class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int len = prices.size();
		if (len <= 0)
			return 0;
		vector<int>dpLeft(len,0);
		vector<int>dpRight(len,0);

		int i, j;
		int minPrice = prices[0];
		dpLeft[0] = 0;
		for (i = 1; i < len; i++)
		{
			minPrice = myMin(minPrice,prices[i]);
			dpLeft[i] = myMax(dpLeft[i-1],prices[i]-minPrice);
		}

		dpRight[len - 1] = 0;
		int maxPrice = prices[len-1];  //�����Ƶ�ʱ���Ӧ�������price ��ȥ��ǰprices��
		for (i = len-2; i >=0; i--)
		{
			maxPrice = myMax(maxPrice, prices[i]);
			dpRight[i] = myMax(dpRight[i+1], maxPrice-prices[i]);
		}

		int profit = 0;
		for (i = 0; i<len; i++)
		{
			int tmp = dpLeft[i] + dpRight[i];
			if (tmp > profit)
				profit = tmp;
		}

		return profit;
	}
	int myMin(int a,int b)
	{
		return a > b ? b : a;
	}
	int myMax(int a, int b)
	{
		return a > b ? a : b;
	}
};


int main()
{
	//vector<int>prices = { -2, 11, -4, 13, -5, -2 };
	vector<int>prices = { 1,2,4 };
	Solution mine;
	int result;
	result = mine.maxProfit(prices);
	cout << result << endl;
	return 0;
}
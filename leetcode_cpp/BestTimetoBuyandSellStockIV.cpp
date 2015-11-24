/*
time   :  2015-5-30
author :  ht
comment:  ��k��������������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<unordered_set>
#include<set>
using namespace std;


class Solution1 {
	//��̬�滮�ķ���
public:
	/*
	 *��ʵ����������k�ν��׵��������
	 *���Ƕ���local[i][j]Ϊ�ڵ����i��ʱ���ɽ���j�ν��ײ������һ�ν���
	 *�����һ��������������󣬴�Ϊ�ֲ����š�
	 *
	 *Ȼ�����Ƕ���global[i][j]Ϊ�ڵ����i��ʱ���ɽ���j�ν��׵�������󣬴�Ϊȫ������

	 *
	 * local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)

     * global[i][j] = max(local[i][j], global[i - 1][j])��

     * ���оֲ�����ֵ�ǱȽ�ǰһ�첢�ٽ���һ�ε�ȫ�����ż��ϴ���0�Ĳ�ֵ��
	 * ��ǰһ��ľֲ����ż��ϲ�ֵ����ȣ�����֮��ȡ�ϴ�ֵ����ȫ�����űȽϾֲ����ź�ǰһ���ȫ�����š�
	 */
	int maxProfit(int k, vector<int> &prices) 
	{
		if (prices.empty() || k == 0)
			return 0;

		if (k >= prices.size())  //�����ܶ������
			return solveMaxProfit(prices);

		vector<int> global(k + 1, 0);
		vector<int> local(k + 1, 0);

		for (int i = 1; i < prices.size(); i++) 
		{
			int diff = prices[i] - prices[i - 1];
			for (int j = k; j >= 1; j--)
			{
				local[j] = myMax(local[j] + diff, global[j - 1] + myMax(diff, 0));
				global[j] = myMax(global[j], local[j]);
			}
		}

		return global[k];
	}
	int myMin(int a, int b)
	{
		return a > b ? b : a;
	}
	int myMax(int a, int b)
	{
		return a > b ? a : b;
	}
private:
	int solveMaxProfit(vector<int> &prices)
	{
		//����ǽ���Խ�������εģ�Ҳ����II��һ�����
		int res = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			int diff = prices[i] - prices[i - 1];
			if (diff > 0)
				res += diff;
		}
		return res;
	}
};

class Solution {
public:
	int result = INT_MIN;

	//��������㷨�Ƚϱ������ݹ飬��ʱ�����������~~~
	int maxProfit(int k, vector<int>& prices) {
		if (k <= 0)
			return 0;
		int currentProfit = 0;
		int depth = 0;
		int start = 0;
		recursive(prices, k, start, depth, currentProfit);
		return result;
	}
	void recursive(vector<int> prices,int k,int start,int depth,int accumulation)
	{
		int len = prices.size();
		if (k == (depth+1))
		{
			//�˳�����
			int currentProfit = profit(prices,start, len - 1);
			currentProfit += accumulation;
			result = myMax(currentProfit,result);
		}
		else
		{
			int i;
			int currentProfit;
			for (i = start; i < len-(k - depth); i++)
			{
				currentProfit = profit(prices, start, i);
				currentProfit += accumulation;
				recursive(prices, k, i + 1, depth + 1, currentProfit);
			}
		}
	}
	int profit(vector<int> prices,int start,int end)
	{
		int maxPrice, minPrice;
		maxPrice = prices[start];
		minPrice = prices[start];
		int currentProfit = 0;
		for (int i = start; i <= end; i++)
		{
			maxPrice = myMax(maxPrice, prices[i]);
			minPrice = myMin(minPrice, prices[i]);
		}
		currentProfit = maxPrice - minPrice;
		return currentProfit;
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
	return 0;
}
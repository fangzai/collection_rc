/*
time   :  2015-5-30
author :  ht
comment:  Dungeon Game �ػ�����Ϸ
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

/*
 * ��̬�滮���㷨���Ӻ���ǰ����
 * ���м��ʱ���������߷���һ��right,һ����down
 * ��һ����ά���� dp[i][j]����ʾ����һ��״̬����������Ҫ����СȨֵ
 * �������right�� 
           right = myMax(dp[i][j + 1] - dungeon[i][j], 1);
 * �������down��
           down = myMax(dp[i + 1][j] - dungeon[i][j], 1);
 * ���ȳ�ʼ��dp[m-1][n-1] ������Ǹ���������Ҫ1-dungeon[m-1][n-1]��������
 *                        �������������ֻ��Ҫ1
 * Ȼ���ʼ�����һ�к����һ�У�Ȼ�����ϵ��ƣ���������ʱ�򣬾�����Ҫ��
 * ��С������
 */
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.size() <= 0 || dungeon[0].size() <= 0)
			return 0;

		int result;
		result = minimum(dungeon);
		return result;
	}
	int minimum(vector<vector<int>>& dungeon)
	{
		int m = dungeon.size();
		int n = dungeon[0].size();
		vector<vector<int>>dp(m,vector<int>(n,0)); //��һ����ά���飬��ʾ��һ��״̬����i,j�������СȨֵ
		if (dungeon[m - 1][n - 1] >= 0)
			dp[m - 1][n - 1] = 1;
		else
			dp[m - 1][n - 1] = 1-dungeon[m - 1][n - 1];
		int i = 0,j=0;
		for (i = m - 2; i >= 0; i--)
			dp[i][n - 1] = myMax(dp[i+1][n - 1] - dungeon[i][n - 1],1);
		for (j = n - 2; j >= 0; j--)
			dp[m-1][j] = myMax(dp[m-1][j+1] - dungeon[m-1][j], 1);
		int right, down;
		for (i = m - 2; i >= 0; i--)
		{
			for (j = n - 2; j >= 0; j--)
			{
				down = myMax(dp[i + 1][j] - dungeon[i][j], 1);
				right = myMax(dp[i][j + 1] - dungeon[i][j], 1);
				dp[i][j] = myMin(down,right);
			}
		}
		
		return dp[0][0];

	}
	int myMin(int a, int b)
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
	vector<vector<int>> board = { {-2,-3,3}, {-5,-10,1}, {10,30,-5} };
	Solution mine;
	int result;
	result = mine.calculateMinimumHP(board);
	cout << result << endl;
	return 0;
}
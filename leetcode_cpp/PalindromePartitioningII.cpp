/*
time   :  2015-5-22
author :  ht
comment:  ���ַ����ֽ��Ϊ���Ĵ��Ӽ�,��������С�ü�
		  ex131��������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

int myMin(int a, int b)
{
	return a > b ? b : a;
}
class Solution {
public:
	vector<vector<bool>> matrix;
	vector<vector<string>>result;
	int minCut(string s) {
		
		matrixPalindrome(s);//���Ƚ�matrix�����
		vector<int>cut(s.size()+1,0); //ȫ����ʼ��Ϊ0
		//cut[i]��ʾ����i��string��ĩβ��Ҫ�и�ĵ���

		int i, j;
		int len = s.size();
		for (i = len - 1; i >= 0; i--)
		{
			cut[i] = len - i;  //��ʼ��ʱ����趼��ÿһ����ĸ���ָ�
			//��ѭ���Ӻ���ǰ����
			for (j = i; j < len; j++)
			{
				if (matrix[i][j])
				{
					//i->j�ǿ����и�ģ���ô cut[i] �͵���ԭ���ĺ� cut[j+1]+1�Ľ�Сֵ
					cut[i] = myMin(cut[j + 1] + 1,cut[i]);
					//��ѭ����ǰ�������
				}
			}
		}
		//���һ���ַ�����Ҫ�и���Լ�ȥ1

		return cut[0]-1;
	}
	vector<vector<bool>> matrixPalindrome(string s) {

		int	 n = s.length();
		vector<vector<bool>> dp;
		//Ϊ��׼�����ֵ
		int i, j;
		vector<bool> temp(n,false);
		for (i = 0; i < n; i++)
		{
			dp.push_back(temp);
			//��ò�Ҫ��������ѭ�����׳�ʱ
		}

		int startPos = 0;
		int max = 1;
		for (i = 0; i < n; ++i)
		{
			dp[i][i] = true;
			if (i + 1 < n)
			{
				if (s[i] == s[i + 1])
				{
					dp[i][i + 1] = true;
					startPos = i;
					max = 2;
				}
				else dp[i][i + 1] = false;
			}
		}

		//�������,ǰ������len = 1, len = 2�����
		int len;
		for (len = 3; len <= n; ++len)
		{
			for (i = 0; i < n - len + 1; ++i)
			{
				j = i + len - 1;

				if (dp[i + 1][j - 1] && s[i] == s[j])
				{
					dp[i][j] = true;
					int curLen = j - i + 1;
					if (curLen > max)
					{
						startPos = i;
						max = curLen;
					}
				}
				else dp[i][j] = false;

			}
		}
		matrix = dp;

		return dp;
	}
};

int main()
{
	Solution mine;
	string str = "aacb";
	int result;
	result = mine.minCut(str);

	cout << result <<endl;
	return 0;
}
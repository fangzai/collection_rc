/*
time   :  2015-5-27
author :  ht
comment:  ����S�����Ӵ�T����T��S���еĴ���
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<stack>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	int result = 0;
	int numDistinct(string s, string t) {
		//traverse(s,0,t,0);
		int len1 = s.length();
		int len2 = t.length();
		if (len1 == 0 || len2 == 0)
			return 0;
		if (len1 < len2)
			return 0;
		return traverse1(s,t);
	}
	int traverse1(string s, string t)
	{
		//��̬�滮�㷨
		//��һ������dp[i][j]��ʾ  s����ǰi������t����ǰj��ƥ�������
		//����ת�Ʒ���
		//���s[i]==t[j]��ôdp[i][j]������ѡ�񷽷���һ����s[i]��s[j]ƥ�䣬ѡ�񷽷���dp[i-1][j-1]
		//                      ����һ���� s[i]��s[j]��ƥ�䣬ѡ�񷽷���dp[i-1]dp[j] Ҳ���ǲ�Ҫs[i]
		//���s[i]!=t[j] ��ôֻ��һ�ַ�����dp[i-1][j]������
		// dp[0][0] =1, dp[i][0] =1  //�κ�һ���ַ�����ɿմ� ֻ��һ�ַ���
		int len1 = s.length();
		int len2 = t.length();
		vector<int>tmp(len2+1,0);
		vector<vector<int>>dp(len1+1,tmp);
		int i, j;
		dp[0][0] = 1;
		//�κ�һ���ַ�����ɿմ� ֻ��һ�ַ���
		for (i = 1; i <= len1; i++)
			dp[i][0] = 1;

		for (i = 1; i <= len1; i++)
		{
			for (j = 1; j <= len2; j++)
			{
				if (s[i-1] == t[j-1])//if (s[i] == t[j] ���� ��Ϊ������չ��һ��λ
				{
					dp[i][j] = dp[i-1][j-1]+ dp[i-1][j];
					//dp[i-1][j-1]��s[i]==t[j]
					//dp[i-1][j] ����s[i]==t[j]
				}
				else
				{
					//dp[i-1][j] ����s[i]==t[j]
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[len1][len2];

	}
	void traverse(string s,int index1, string t,int index2)
	{
		//�����������ϵͳ�ʱ��
		int len1 = s.length();
		int len2 = t.length();
		if ((index2 + 1) == len2)
		{
			result++;return;
		}
		if ((index1 + 1) == len1)
			return;
		//�������˳�����
		int j = index2;
		for (int i = index1; i < len1; i++)
		{
			if (s[i] == t[j])
			{
				traverse(s, i + 1, t, j + 1);
			}
		}
	}
};

int main()
{
	string str1, str2;
	str1 = "b";
	str2 = "a";
	Solution mine;
	int result;
	result = mine.numDistinct(str1,str2);
	cout << result << endl;
	return 0;
}
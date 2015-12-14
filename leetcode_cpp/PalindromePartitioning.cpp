/*
time   :  2015-5-22
author :  ht
comment:  ���ַ����ֽ��Ϊ���Ĵ��Ӽ�
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
	vector<vector<bool>> matrix;
	vector<bool>sign;
	vector<vector<string>>result;
	vector<vector<string>> partition(string s) {
		
		matrixPalindrome(s);//���Ƚ�matrix�����

		int i = 0;
		for (i = 0; i < s.size(); i++)
		{
			sign.push_back(false);
		}

		traverse(s,0);  //�ӵ�һ���ַ���ʼ
		return result;
	}
	void traverse(string s,int start)
	{
		if (start == s.size())
		{
			int i;
			//�Ѿ����������  ��ʼ�ָ� �ַ�
			string str;
			vector<string>temp;
			for (i = 0; i < s.size(); i++)
			{
				str += s[i];
				if (sign[i])
				{
					temp.push_back(str);
					str = "";//���ã���¼��һ�μ���
				}
			}
			result.push_back(temp);
		}
		else
		{
			//����Ļ������ݹ�
			int index = 0;
			for (index = start; index < s.size(); index++)
			{
				// start ->index  start֮��Ļ��Ķ��ҳ���
				if (matrix[start][index] == true)
				{
					sign[index] = 1;
					traverse(s, index + 1);
					sign[index] = 0;//����֮��Ҫ����  �����Ӱ����һ�ε���
				}
				else
				{
					//do nothing������sign���
				}
			}
		}

	}
	vector<vector<bool>> matrixPalindrome(string s) {

		int	 n = s.length();
		vector<vector<bool>> dp;
		//Ϊ��׼�����ֵ
		int i, j;
		for (i = 0; i < n; i++)
		{
			vector<bool> temp;
			for (j = 0; j < n; j++)
			{
				temp.push_back(false);
			}
			dp.push_back(temp);
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
	string str= "aab";
	vector<vector<string>> result;
	result = mine.partition(str);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
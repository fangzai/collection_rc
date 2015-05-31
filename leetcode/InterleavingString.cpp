/*
time   :  2015-5-27
author :  ht
comment:  ��������string,�ж�ĳ��string�Ƿ���������string�����γɵ�
*/
#include<iostream>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();
		if ((len1 + len2) != len3)
			return false;
		bool result = traverse(s1, s2, s3);
		return result;
		
	}
	bool recursive(string s1,int index1 ,string s2,int index2, string s3,int index3)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();
		if (len1 == index1&&len2 == index2&&index3 == len3)
		{
			//�����ַ�����ĩβ��
			return true;
		}
		else
		{
			bool result = false;
			char a, b;
			if (index1 < len1 && index2 < len2)
			{
				a = s1[index1];
				b = s2[index2];
				if (a != b)
				{
					if (s1[index1] == s3[index3])
					{
						result = recursive(s1, index1 + 1, s2, index2, s3, index3 + 1);
						return result;
					}
					else if (s2[index2] == s3[index3])
					{
						result = recursive(s1, index1, s2, index2 + 1, s3, index3 + 1);
						return result;
					}
					return false;
				}
				else
				{
					bool mark1, mark2;
					mark1 = false;
					mark2 = false;
					if (s2[index2] == s3[index3])
					{
						mark1 = recursive(s1, index1 + 1, s2, index2, s3, index3 + 1);
						mark2 = recursive(s1, index1, s2, index2 + 1, s3, index3 + 1);
						return mark1 || mark2;
					}
					else
						return false;
				}
			}
			else if (index1 < len1)
			{
				if (s1[index1] == s3[index3])
				{
					result = recursive(s1, index1 + 1, s2, index2, s3, index3 + 1);
					return result;
				}
				else
					return false;
				
			}
			else if (index2 < len2)
			{
				if (s2[index2] == s3[index3])
				{
					result = recursive(s1, index1, s2, index2+1, s3, index3 + 1);
					return result;
				}
				else
					return false;
			}
		}
	}
	
	bool traverse(string s1, string s2, string s3)
	{
		//��̬�滮���б��� ��һ�����飬dp[i][j]��ʾ 
		//��һ�������ǰi�����ڶ���string��ǰj����interleave��
		//���Ծ���ת�Ʒ���
		// if(s1[i]==s3[k-1])   dp[i][j] = dp[i-1][j]
		// if(s2[j]==s3[k-1])   dp[i][j] = dp[i][j-1]  k��s3�ĵ�ǰ�±�
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();
		if ((len1 + len2) != len3)
			return false;
		vector<bool>tmp(len2+1,false);
		vector<vector<bool>> dp(len1+1,tmp);  //s1�����е�λ�ã�s2�����е�λ��
		
		//Ϊ�˷��㣬�±�ͳһ��1��ʼ����
		dp[0][0] = true;
		int i, j;
		for (i = 1; i <= len1; i++)  //��һ��
		{			
			if (s1[i - 1] == s3[i - 1])
				dp[i][0] = true;
			else
				break;
		}
		for (j = 1; j <= len2; j++)
		{
			if (s2[j - 1] == s3[j - 1])
				dp[0][j] = true;
			else
				break;
		}
		
		int k = 0; //���ڼ�¼s3���±�
		for (i = 1; i <=len1; i++)
		{
			for (j = 1; j <= len2; j++)
			{
				k = i + j;
				if (s1[i - 1] == s3[k - 1])
					dp[i][j] = dp[i - 1][j] || dp[i][j];
				if (s2[j - 1] == s3[k - 1])
					dp[i][j] = dp[i][j - 1] || dp[i][j];
			}
		}
		return dp[len1][len2];

	}
};

int main()
{
	string str1, str2,pattern;
	str1 = "aabc";
	str2 = "abad";
	pattern = "aabcabad";
	//pattern = "aadbbbaccc";
	Solution mine;
	bool result;
	result = mine.isInterleave(str1,str2,pattern);
	if (result)
		cout << "Is interleave!	" << endl;
	else
		cout << "Not interleave!" << endl;
	return 0;
}

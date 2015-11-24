/*
time   :  2015-5-21
author :  ht
comment:  �������ַ��ĳ���
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		//http://blog.csdn.net/hopeztm/article/details/7932245
		int len = s.size();
		if (len <= 1)
			return s;

		string T = preProcess(s);
		//cout << T << endl;

		len = T.size();
		int C = 0, R = 0; //�����Ǽ������ĵ�ֵ
		vector<int>	P(len,0);


		int i_mirror = 0;
		int i, j;
		for (i = 0; i < len; i++)
			cout << P[i] << " ";
		for (i = 1; i < len - 1; i++)
		{
			i_mirror = 2 * C - i;//����i'�������
			
			if (R > i)
			{
				P[i] = myMin(R-i,P[i_mirror]);
			}
			else
			{
				P[i] = 0;
			}
			//������iλ�ú����P[i]

			while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
			{
				P[i] =P[i] +1;  //��Ϊ�ǶԳƵ�
				//cout << P[i] << endl;
			}
			if (i + P[i] > R)  //������R������Ҫ����C��R
			{
				C = i;
				R = i + P[i];
			}
		}
		int maxLen = 0;
		int centerIndex = 0;
		for (i = 0; i < len; i++)
		{
			if (P[i]>maxLen)
			{
				maxLen = P[i];
				centerIndex = i;
			}
		}
		string  result = s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
		return result;
	}
	int myMin(int a,int b)
	{
		return a > b ? b : a;
	}
	string preProcess(string s)
	{
		int n = s.length();
		if (n == 0) return "";
		string ret="^";  //�����Ͳ��ý��б߽�����
		for (int i = 0; i < n; i++)
		{
			ret.append("#" + s.substr(i, 1));
		}

		ret.append("#$"); //�����Ͳ��ý��б߽�����
		return ret;
	}
	string LCS(string s1, string s2)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		vector<int>mark(len2 + 1, 0);
		int i, j;
		//for (i = 0; i < mark.size(); i++)
		//	cout << mark[i] << " ";
		//cout << endl;

		int max = 0;
		int pe = 0;
		for (i = 0; i < len1; i++)
		{
			for (j = len2; j > 0; j--)
			{
				if (s1[i] == s2[j - 1])
				{
					mark[j] = mark[j - 1] + 1;
				}
				else
				{
					mark[j] = 0;
				}
				if (mark[j] > max)
				{
					max = mark[j];
					pe = i;
				}
			}
		}
		string result;
		i = 0;
		j = pe - max + 1;
		result = s1.substr(j,max);
		return result;
	}
	string longestPalindrome1(string s)
	{
		string s1 = s;
		reverse(s.begin(), s.end());
		string test = LCS(s1,s);
		return test;
	}
};

int main()
{
	string str = "a";
	//string str = "h";
	Solution mine;
	//string result = mine.longestPalindrome(str);
	//cout << result << endl;

	string str2 = str;

	string test = mine.longestPalindrome1(str);
	cout << test << endl;
	return 0;
}
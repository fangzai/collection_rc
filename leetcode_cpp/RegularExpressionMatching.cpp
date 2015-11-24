/*
time   :  2015-5-26
author :  ht
comment:  �ַ���ƥ�������
		  .  ����ƥ�����ⵥ���ַ�
		  *  ����ƥ��0�����߶��ǰһ���ַ�
*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

#include <stdio.h>


class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		//http://blog.csdn.net/hopeztm/article/details/7992253
		//http://www.cnblogs.com/codingmylife/archive/2012/10/05/2712561.html
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    

		if (0 == *p) return 0 == *s;

		//�ж�pָ��ĵڶ����ַ��Ƿ�*��
		if (*(p + 1) != '*')
		{
			if (*p == *s || (*p) == '.' && (*s) != 0)
			{
				return isMatch(s + 1, p + 1);
			}
			return false;
		}
		else
		{
			//pָ��ĵڶ����ַ���*��
			while (*p == *s || ((*p) == '.' && (*s) != 0))
			{
				//��������ַ���ȣ�����pָ�����.��
				if (isMatch(s, p + 2))
				{
					return true;
				}
				s++;
			}
			//�������ȵĻ�  ֱ�Ӱ�ǰ���ȥ������Ϊ��*�ţ�����ǰ��Ŀ��Գ���0��
			return isMatch(s, p + 2);

		}

	}
	bool isMatch(string s, string p)
	{
		bool result = traverse(s,0,p,0);
		return result;
	}
	bool traverse(string s,int s_index,string p,int p_index)
	{
		if (p_index == p.length())
			return s_index == s.length();
		if (p[p_index + 1] != '*')
		{
			if (s[s_index] == p[p_index] || (p[p_index] == '.'&&s.length() != s_index))
			{
				return traverse(s, s_index+1,p, p_index+1);
			}
			return false;
		}
		else
		{
			while (s[s_index] == p[p_index] || (p[p_index] == '.' && s.length() != s_index))
			{
				//��������ַ���ȣ�����pָ�����.��
				if (traverse(s, s_index, p, p_index + 2))
				{
					return true;
				}
				s_index++;
			}
			//�������ȵĻ�  ֱ�Ӱ�ǰ���ȥ������Ϊ��*�ţ�����ǰ��Ŀ��Գ���0��
			return traverse(s,s_index, p,p_index+2);
		}
	}
};



int main()
{
	string str1 = "aaac";
	//string str2 = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
	string str2 = "a*c";
	Solution mine;
	bool result;
	result = mine.isMatch(str1, str2);
	if (result)
		cout << "Is matched!" << endl;
	else
		cout << "Not matched!" << endl;
	return 0;
}
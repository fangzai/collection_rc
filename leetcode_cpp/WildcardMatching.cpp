/*
time   :  2015-5-26
author :  ht
comment:  �ַ���ƥ�������
          ?  ����ƥ�����ⵥ���ַ�
          *  ����ƥ���������е��ַ���������                
*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int len1 = s.length();
		int len2 = p.length();
		if (len1 == 0 && len2 != 0)
			return false;
		if (len2 == 0 && len1 != 0)
			return false;
		if (len1 == len2&&len1 == 0)
			return true;

		bool result;
		string newP = removeRepeat(p);
		result = traverse(s,0,newP,0);
		return result;
	}
	string removeRepeat(string &str)
	{
		int ps = 0;
		int len = str.length();
		string res;
		int i = 0;
		while (i < len)
		{
			if (str[i] != '*')
			{
				res.push_back(str[i]);
				i++;
			}
			else
			{
				res.push_back(str[i]);
				while ((i+1)<len&&str[i + 1] == '*')
					i++;
				i++;
				
			}
		}
		return res;
	}
	bool traverse(string a,int index,string b,int bIndex)
	{
		//Ӧ�����������������ƥ��
		//��ջ��ֱ�Ӹ���ʱ��
		int len1 = a.length();
		int len2 = b.length();
		if (len1 == index)
		{
			if (len2 == bIndex)
			{
				return true;
			}
			return false;
		}
		if (len2 == bIndex)
		{
			if (len1 == index)
			{
				return true;
			}
			return false;
		}
			
		if (b[bIndex] == '?')
		{
			return traverse(a, index + 1, b, bIndex + 1);
		}
		else if (b[bIndex] == '*')
		{
			if (bIndex == (len2 - 1))
			{
				return true;
			}
			else
			{
				bool result = false;
				for (int i = index; i < len1; i++)
				{
					result = traverse(a, i, b, bIndex + 1);
					if (result)
						return true;
				}
				return result;
			}
		}
		else
		{
			bool result = false;
			if (a[index] == b[bIndex])
			{
				result = traverse(a,index+1,b,bIndex+1);
				return result;
			}
			else
			{
				return false;
			}
		}
	}
};

class Solution1 {
	/*
	 * �������ϵ����汾�ĵ�
	 * http://www.acmerblog.com/leetcode-solution-wildcard-matching-6318.html
	 * http://blog.csdn.net/tingmei/article/details/8049926
	 */
public:
	bool isMatch(string s, string p)
	{
		int i, j;
		int len1 = s.length();
		int len2 = p.length();

		bool star = false;
		int tmpi=0, tmpj=0;
		for (i = 0, j = 0; i < len1; i++, j++)
		{
			switch (p[j])
			{
			case '?': break;  //���ܹ�ƥ���κ��ַ�
			case '*': 
				star = true;  //���� *��
				tmpi = i;
				tmpj = j;
				do
				{
					tmpj++;//�����ظ��� *��
				} while (p[tmpj]=='*');
				if (j == len2 )
					return true;  //�������û���ַ��˵Ļ���ֱ��ȫ��ƥ��
				i = tmpi - 1; //��¼�ϸ�ʱ�̵�λ�ã�Ҳ���ǣ���һ�̿�ʼ������λ��
				j = tmpj - 1; //�������1��Ϊ�˵�������һ��ѭ��������1
				break;
			default:
				if (s[i] != p[j])
				{
					if (!star)
						return false;  //ǰ�����û��*�ŵĻ�ֱ�Ӿ��˳���
					tmpi++;
					i = tmpi - 1;   //�������1��Ϊ�˵�������һ��ѭ��������1
					j = tmpj - 1;
				}
				break;
			}
		}
		while (p[j] == '*')
			j++;
		if (j == len2)
			return true;  //������������ַ��˵Ļ���ֱ��ȫ��ƥ��
		else
		{
			return false;
		}
	}
};

// LeetCode, Wildcard Matching
// �����棬ʱ�临�Ӷ�O(n*m)���ռ临�Ӷ�O(1)
class Solution2 {
public:
	bool isMatch(const char *s, const char *p) {
		bool star = false;
		const char *str, *ptr;
		for (str = s, ptr = p; *str != '\0'; str++, ptr++) {
			switch (*ptr) {
			case '?':
				break;
			case '*':
				star = true;
				s = str, p = ptr;
				while (*p == '*') p++;  //skip continuous '*'
				if (*p == '\0') return true;
				str = s - 1;
				ptr = p - 1;
				break;
			default:
				if (*str != *ptr) {
					// ���ǰ��û��'*'����ƥ�䲻�ɹ�
					if (!star) return false;
					s++;
					str = s - 1;
					ptr = p - 1;
				}
			}
		}
		while (*ptr == '*') ptr++;
		return (*ptr == '\0');
	}
};


int main()
{
	string str1 = "abc";
	//string str2 = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
	string str2 = "a*c";
	Solution1 mine;
	bool result;
	result = mine.isMatch(str1,str2);
	if (result)
		cout << "Is matched!" << endl;
	else
		cout << "Not matched!" << endl;
	return 0;
}
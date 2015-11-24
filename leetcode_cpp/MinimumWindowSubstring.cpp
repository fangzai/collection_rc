/*
time   :  2015-5-26
author :  ht
comment:  ĸ��S����ƥ����Ӵ�T�����S�е���С�����ܹ�����T�������ַ�
*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

/*
 * ���ڻ��������⣬��ex209  ��Ϊ����
 * �������Ϊһ���õ��˵�ǰƥ����ַ�������ߵ�ָ������
 * �����ж��Ƿ����ҵ���������ҵ�����startָ�뻬��
 * ��������ҵ�endָ�����
 * 
 * ��ex209��Ҳ�Ǵ��ڻ�����window֮�䲻����ͣ�һ�����ڸ���ֵ��start��ʼ����
 */
class Solution {
public:
	int range = 128;
	string minWindow(string s, string t) {

		vector<int>pattern(range,0);  //����������t������ֵ�Ƶ��
		vector<int>text(range, 0);

		int i;
		for (i = 0; i < t.size(); i++)
			pattern[t[i]]++;
		int start = 0, end = 0;
		int minStart = 0, minEnd = 0;
		int minLength = s.length();
		
		bool mark = false;  //��ʾ�Ƿ��������������Ĵ���

		text[s[end]]++;  //��һ��Ԫ�ؼӽ�ȥ
		while (end < s.size())
		{
			if (compare(text, pattern))
			{
				//�ҵ�һ��������
				int currentLen = end - start + 1;
				if (minLength >= currentLen)
				{
					mark = true;
					minLength = currentLen;
					minEnd = end;
					minStart = start;
				}
				if (start < end)
				{
					//�ڱ�֤startָ������endָ��֮ǰ����������
					//�����Ҫend������չ
					start++;
					text[s[start - 1]]--; //����  ��ߵĴ��ں���
				}
				else
				{
					end++;  //�ϸ���˵�������ߵ���һ��
					if (end<s.size())
						text[s[end]]++;  //�ұߵĴ��ں���
				}

			}
			else
			{
				end++;   //�ұߵĴ��ں���
				if (end<s.size())
					text[s[end]]++;
			}
		}
		string res;
		if (mark)
		{
			res= s.substr(minStart,minEnd-minStart+1);
			return res;
		}
		else
		{
			return res;//û���ҵ����ؿ�
		}
	}
	bool compare(vector<int>text,vector<int>pattern)
	{
		//��С�������õ�128
		int i;
		for (i = 0; i < range; i++)
		{
			if (text[i] < pattern[i])
				return false;
		}
		return true;
	}
};

int main()
{
	string S = "ADOBECODEBANC";
	string T = "ABC";
	Solution mine;
	string result;
	result = mine.minWindow(S,T);
	cout << result << endl;
	return 0;
}
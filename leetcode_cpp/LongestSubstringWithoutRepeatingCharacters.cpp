/*
time   :  2015-5-20
author :  ht
comment:  ��һ���ַ����ڳ������������Ӵ��ĳ���
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
			return 0;
		string str = s.substr(0,1);
		int i = 0,index;
		string temp;
		int len = 1,maxlen = 1;
		for (i = 1; i < s.size(); i++)
		{
			temp = s.substr(i,1);//��ȡ��ǰ���ַ�
			index = str.find(temp); 
			//�����Ƿ��ٵ�ǰstr�����ˣ�һ�����־ͰѸô�������ַ��س���
			len = str.size();
			if (index >= 0)
			{
				//�ظ���
				str = str.substr(index+1,len-index-1);
				str.append(temp);
				len = str.size();
			}
			else
			{
				str.append(temp); //����͸�����ȥ
				len = str.size();
			}
			if (len > maxlen)
			{
				maxlen = len;
			}
		}
		return maxlen;
	}
};

int lengthOfLongestSubstring(char* s) {

	int ps, pe;
	int ts, te;
	char*tempStr;
	return 0;
}

int main()
{
	//string str = "abcabcbb";
	string str = "b";
	Solution mine;
	int result = mine.lengthOfLongestSubstring(str);
	cout << result << endl;
	return 0;
}
/*
time   :  2015-5-20
author :  ht
comment:  ʵ��word break
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		/*
		 * �����Ƽ��Ķ����õ�dp�滮���㷨��������ϸ����Ҳ��
		 * �ȿ���һ���ַ���û�б�ƥ�䣬Ȼ��鿴0-1�ַ��Ƿ�ƥ�䣬Ȼ��һֱ����s�����
		 * ����������
		 */
		unordered_set<string>::iterator it;
		string str;
		int i,index = 0;
		int nsize = s.size();
		bool *dp = new bool[nsize];
		
		for (i = 0; i < nsize; i++)
		{
			dp[i] = false;  //��ʼ��һ��
			
			dp[i] =(wordDict.find(s.substr(0, i + 1))==wordDict.end())?false:true;
			if (!dp[i])
			{
				//ûƥ���ϣ��ٷָ�0->i���ַ��������Ƿ��ܹ�ƥ����
				for (int j = 0; j < i; j++)
				{
					//��j���ָ�
					if (dp[j])
					{
						//ƥ��j+1�±꿪ʼ���ܹ�i-j���ַ�
						dp[i] = (wordDict.find(s.substr(j+1, i - j)) == wordDict.end()) ? false : true;
						if (dp[i])
						{
							break;
						}
					}
				}
			}
			else
			{
				//do nothing ��Ϊ����Ѿ�ƥ������
			}
		}
		bool result = dp[nsize - 1];
		delete[] dp;
		return result;

	}
	bool wordBreak1(string s, unordered_set<string>& wordDict) {

		unordered_set<string>::iterator it;
		string temp,str,pre_str;
		int index = 0;
		str = s;
		//��������Ƚϱ�������s�ĵ�һ���ַ���ʼƥ�䣬����s[0]��wordDict��ƥ��
		//Ȼ��������������û��ƥ��Ļ�������str�����������ʵ�Ƕ�������ǰƥ���������Ϣ
		do
		{
			pre_str = str;
			for (it = wordDict.begin(); it != wordDict.end(); it++)
			{
				temp = *it;
				if (temp[0] == str[0])
				{
					index = str.find(*it);
					while (index >= 0)
					{
						str.erase(index,temp.size());
						if (str.empty())
						{
							return true;
						}
						index = s.find(temp);
					}
				}
			}
			if (pre_str == str)
				break;
		} while (!str.empty());
		return false;

	}
	bool find(string str1,string str2)
	{
		int index = str1.find(str2);
		cout << index << endl;
		return true;
	}
};

int main()
{
	//unordered_set<string>Dict = { "leet", "code" };
    unordered_set<string>Dict = { "gs", "s","dog"};
	string str = "dogs";
	string str1 = "teet";
	Solution me ;
	//me.find(str,str1);
	if (me.wordBreak(str, Dict))
	{
		cout << "Is empty now!"<<endl;
	}
	else
	{
		cout << "Not empty now!" << endl;
	}
	return 0;
}
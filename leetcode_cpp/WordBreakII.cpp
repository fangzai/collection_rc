/*
time   :  2015-5-29
author :  ht
comment:  word break�������棬��Ҫ�����еķָ�����������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
	vector<string> result;
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		/*
		* �����Ƽ��Ķ����õ�dp�滮���㷨��������ϸ����Ҳ��
		* �ȿ���һ���ַ���û�б�ƥ�䣬Ȼ��鿴0-1�ַ��Ƿ�ƥ�䣬Ȼ��һֱ����s�����
		* ����������
		*/
		unordered_set<string>::iterator it;
		string str;
		int i, index = 0;
		int nsize = s.size();
		vector < bool>dp(nsize, false);
		vector<vector<bool>> mark(nsize, dp); //mark[i][j]��ʾ i->j�±���ַ����ܷ�ָ�
		for (i = 0; i < nsize; i++)
		{
			dp[i] = false;  //��ʼ��һ��

			dp[i] = (wordDict.find(s.substr(0, i + 1)) == wordDict.end()) ? false : true;
			if (dp[i])
				mark[0][i] = true;
			//�൱�ڰ�ǰ����������ڲ�һ�飬����ż��j+1->i�ָ�
			for (int j = 0; j < i; j++)
			{
				//��j���ָ�
				if (dp[j])
				{
					//ƥ��j+1�±꿪ʼ���ܹ�i-j���ַ�
					bool part = (wordDict.find(s.substr(j + 1, i - j)) == wordDict.end()) ? false : true;
					if (part)
					{
						dp[i] = part;
						mark[j + 1][i] = true;
						//break;
					}
				}
			}
		}
		if (!dp[nsize - 1])
			return result; //���ү�� ���Լ��Ͼ�Ȼ�����ַָ�ģ�����������û���ж����������ѭ����
		traverse(mark, s);
		return result;
	}
	void traverse(vector<vector<bool>>mark, string str)
	{
		int i = 0, j = 0;
		int index = 0;
		string res;
		recursive(mark, str, 0, res); //�ݹ����������ȱ����õ����

	}
	void recursive(vector<vector<bool>>mark, string str, int start, string res)
	{
		int i;
		int len = mark.size();
		if (len == start)
		{
			if (res[res.size() - 1] == ' ')
				res.erase(res.end() - 1);
			result.push_back(res);
			return;
		}
		for (i = start; i < len; i++)
		{
			if (mark[start][i])
			{
				string tmp = res;
				tmp.append(str.substr(start, i - start + 1));
				tmp.append(" ");
				recursive(mark, str, i + 1, tmp);
			}
		}
	}
};

int main()
{
	Solution mine;
	string str = "aaaaaaa";
	unordered_set<string> wordDict = { "aaaa", "aa", "a" };
	vector<string> result;
	result = mine.wordBreak(str,wordDict);
	for (int i= 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}
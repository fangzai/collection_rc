/*
time   :  2015-5-29
author :  ht
comment:  ���ڸ���string������Ϻ���ĸ���г���λ�õ�����
*/
#include<iostream>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

/*
 * ����һ��ĸ�ַ�����һ��words��vector,����ĵ��ʵĳ��ȶ���һ����
 * ����һ���������к�����������sĸ���е�λ��
 * �Ҿ����������ĺ�ԩ��  ���ү�ģ���Ȼ�Ǳ�������  ������������
 */
class Solution {
public:
	vector<int>result;
	vector<int> findSubstring1(string S, vector<string> &L) {
		// Note: The Solution object is instantiated only once.  
		map<string, int> words;
		map<string, int> cur;
		int wordNum = L.size();
		for (int i = 0; i < wordNum; i++)
			words[L[i]]++;
		int wordLen = L[0].size();
		vector<int> res;
		//if(S.size() < wordLen*wordNum)return res;  
		for (int i = 0; i <= (int)S.size() - wordLen*wordNum; i++)
		{
			cur.clear();
			int j;
			for (j = 0; j < wordNum; j++)
			{
				string word = S.substr(i + j*wordLen, wordLen);
				if (words.find(word) == words.end())
					break;
				cur[word]++;
				if (cur[word]>words[word])
					break; //��Ϊ���и�ĸ���ϵ��ַ���������dict������ֵĴ��������ֵ����ظ��Ĵ�����
			}
			if (j == wordNum)
				res.push_back(i);
		}
		return res;
	}

	vector<int> findSubstring(string s, vector<string>& words) {
		//words = remvoveRepeat(words);
		traverse(s,words);
		return result;
	}
	vector<string>remvoveRepeat(vector<string> words)
	{
		set<string> mySet;
		vector<string> newWords;
		for (int i = 0; i < words.size(); i++)
			mySet.insert(words[i]);
		for (auto &word : mySet)
			newWords.push_back(word);
		int num;

		for (int i = 0; i < newWords.size(); i++)
		{
			string tmp = newWords[i];
			newWords[i].clear();
			for (int j = 0; j < words.size(); j++)
			{
				if (tmp == words[j])
					newWords[i].append(words[j]);
			}
		}
		return newWords;
	}
	bool in(vector<int>index, int location)
	{
		for (int i = 0; i < index.size(); i++)
		{
			if (location == index[i])
				return true;
		}
		return false;
	}
	void traverse(string s, vector<string>& words)
	{
		/*
		 * �������������s�в��ϲ���words��Ԫ��
		 * �ڴ�Ĳ��Լ��ϳ�ʱ������ȥ�����ַ�����������˵ȷʵ����bug��
		 */
		int len = words.size();
		int wordLen = words[0].size();
		bool mark = false;
		int breakPoint = 0;
		vector<int> index;
		int i = 0;
		int start = 0;
		while (true)
		{
			index.clear();
			mark = false;
			//�ֵ�����һ��
			for (i = 0; i < len; i++)
			{
				int location = s.find(words[i], start);
				int tmpStart = location;
				while (in(index,location))
				{
					tmpStart = location + wordLen;
					location = s.find(words[i], tmpStart);
					if (location == string::npos)
					{						
						break;
					}
				}
				if ( location!= string::npos)
				{
					index.push_back(location);
				}
				else
				{
					break;
				}
			}

			if (index.size() == len)
			{
				sort(index.begin(), index.end());
				//�����鿴�ҵ����±�
				//����������Լ�����ô���ӵ��߼��Ҿ�Ȼ�����˳���
				for (i = 1; i < len; i++)
				{
					if ((index[i] - index[i - 1]) != wordLen)
					{
						mark = true;
						breakPoint = i;
						break;
					}
				}
				if (mark)
				{
					//�ҵ��Ĳ���
					start = index[breakPoint-1]+wordLen;
				}
				else
				{
					start = index[len-1] +wordLen;
					result.push_back(index[0]);
				}
			}
			else
			{
				break; //while ���˳�����
			}

		}

		//��������
	}
};

int main()
{
	string str = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
	vector<string>words = { "fooo", "barr", "wing", "ding", "wing" };
	Solution mine;
	vector<int> result;
	result = mine.findSubstring(str,words);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;

	return 0;
}
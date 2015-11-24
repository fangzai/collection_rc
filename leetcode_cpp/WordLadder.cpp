/*
time   :  2015-5-28
author :  ht
comment:  ���ʱ任������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		int len1 = beginWord.size();
		int len2 = endWord.size();
		if (len1 != len2) return 0;
		if (len1 == 0 || len2 == 0) return 0;
		int result = traverse1(beginWord,endWord,wordDict);
		return result;
	}
	int traverse1(string beginWord, string endWord, unordered_set<string>& wordDict)
	{
		//����������� ÿ�ν�beginWord���һ���ַ���ɷ��Լ��ĵ�a-z��һ�����鿴�ֵ�������û��
		queue < string> que;
		que.push(beginWord);
		int currentSteps = 1;  //��ʼ��Ϊ1
		int currentNum = 1;   //��ʼ��ʱ��ֻ��һ��
		wordDict.erase(beginWord);  //�ѵ�һ������ȥ�� ����еĻ�
		while (!que.empty())
		{
			string current = que.front();
			que.pop();
			currentNum--;
			for (int i = 0; i < current.size(); i++)
			{
				string tmp = current;
				for (char j = 'a'; j <= 'z'; j++)
				{
					tmp[i] = j; //����Ļ�����dict������û��
					if (tmp == current)
						continue;//�����ñ任
					if (tmp == endWord) return currentSteps + 1;
					if (wordDict.find(tmp) != wordDict.end())
						que.push(tmp);
					//����������������Ҵ��ֵ���ɾ��
					wordDict.erase(tmp);  //�����Ϳ����ж��Ƿ���ʹ��˵�
				}
			}
			if (currentNum == 0)
			{
				currentNum = que.size(); 
				//�����һ��������ˣ���һ��ĸ����պ��Ƕ��еĴ�С
				currentSteps++;
			}
		}
		return 0;//����ߵ�����Ļ���˵��û��·��
	}
	int traverse(string beginWord, string endWord, unordered_set<string>& wordDict)
	{
		//��һ��˼·��ɨ�������ֵ䣬�����һ�α任����ǰû��ɨ����ͼ����ֵ�
		//�൱�������������
		unordered_set<string>visited;
		visited.insert(beginWord);  //��ʼ�ĵ��ʼӽ�ȥ
		queue<string> que;

		int currentSteps = 1;     //��¼�任�˶��ٲ�,��ʼֵΪ1����Ϊ�ѵ�ǰ��startҲ���ȥ��
		int currentLevelNum = 1;  //��ǰ���м���Ԫ�أ���һ��ֻ��beginWordһ��Ԫ��
		int nextLevelNum = 0;       //���ڼ�¼��һ���Ԫ��
		
		que.push(beginWord);

		while (!que.empty())
		{
			string current = que.front(); //ȡ����ǰ��string
			que.pop(); 

			unordered_set<string>::iterator it;
			//�����ֵ�
			currentLevelNum--;//pop��ǰ���Ԫ�ؼ���һ��
			for (it = wordDict.begin(); it != wordDict.end(); it++)
			{
				string tmp = *it;
				if ((stringDiff(current, tmp) == 1) && (visited.find(tmp) == visited.end()))
				{
					//�����ǰcurrent->tmpֻ��һ�����룬��tmpû�б����ʹ�
					que.push(tmp);
					visited.insert(tmp);
					nextLevelNum++;  //��һ���Ԫ������һ��
				}
			}
			if (stringDiff(current, endWord) == 1)	return currentSteps + 1;

			if (currentLevelNum == 0)
			{
				//��ǰ��������ˣ���ʼ��һ��
				currentSteps++; //������ 1
				currentLevelNum = nextLevelNum;
				nextLevelNum = 0;  //��һ������
			}

		}

	}
	int  stringDiff(string a,string b)
	{
		int len1 = a.size();
		int len2 = b.size();
		int count = 0;
		for (int i = 0; i < len1; i++)
		{
			if (a[i] != b[i])count++;
		}
		return count;
	}
};

int main()
{
	string start = "hit";
	string end = "cog";
	unordered_set<string>dict = { "hot", "dot", "dog", "lot", "log" };
	Solution mine;
	int result;
	result = mine.ladderLength(start,end,dict);
	cout << result << endl;
	return 0;
}
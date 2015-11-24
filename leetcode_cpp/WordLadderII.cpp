/*
time   :  2015-5-28
author :  ht
comment:  ���ʱ任������  �Ǻǣ��� ���ܰ�����·������һ���㶼�ҳ���������ȫ�����ж�~~~
*/
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<unordered_set>
#include<unordered_map>
using namespace std;


class Solution {
public:
	//�ⷽ����ʱ�� ���ү��
	vector<vector<string>> result;
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		int len1 = start.size();
		int len2 = end.size();
		if (len1 != len2) return result;
		if (len1 == 0 || len2 == 0) return result;
		traverse1( start,end, dict);
		return result;
	}
	int traverse1(string beginWord, string endWord, unordered_set<string>& wordDict)
	{
		//����������� ÿ�ν�beginWord���һ���ַ���ɷ��Լ��ĵ�a-z��һ�����鿴�ֵ�������û��
		queue < string> que;

		//��¼ÿ�����ʵ�ǰ��
		map<string, vector<string>> trace;
		map<string,int> last;
		bool mark = false;
		que.push(beginWord);
		int currentSteps = 1;  //��ʼ��Ϊ1
		int currentNum = 1;   //��ʼ��ʱ��ֻ��һ��
		wordDict.erase(beginWord);  //�ѵ�һ������ȥ�� ����еĻ�
		queue < string> delQue;
		while (!que.empty())
		{
			string current = que.front();
			que.pop();
			currentNum--;
			delQue.push(current);
			for (int i = 0; i < current.size(); i++)
			{
				string tmp = current;

				for (char j = 'a'; j <= 'z'; j++)
				{
					tmp[i] = j; //����Ļ�����dict������û��
					if (tmp == current) 
						continue;//�����ñ任
					
					if (tmp == endWord)
					{
						mark = true;
						last.insert(pair<string, int>(current,0));
					}
					if (wordDict.find(tmp) != wordDict.end())
					{
						que.push(tmp);
						vector<string>mean;
						if (trace.find(tmp) == trace.end())
						{
							mean.push_back(current);
							trace.insert(pair<string, vector<string>>(tmp, mean));
						}
						else
						{
							mean = trace[tmp];
							vector<string>::iterator it = find(mean.begin(),mean.end(),current);
							if (it == mean.end())
							{	
								//û���ҵ�
								mean.push_back(current);
								trace.erase(tmp);
								trace.insert(pair<string, vector<string>>(tmp, mean));
							}

						}
					}
				}
			}
			if (mark&&currentNum==0)
				break;
			if (currentNum == 0)
			{
				while (!delQue.empty())
				{
					wordDict.erase(delQue.front());  //����һ����ֹ��Ķ�ɾ��
					delQue.pop();
				}
				currentNum = que.size();  //�����һ��������ˣ���һ��ĸ����պ��Ƕ��еĴ�С
				currentSteps++;
			}
		}
		vector<string>res;
		map<string, int>::iterator it;
		for (it = last.begin(); it != last.end(); it++)
		{
			res.push_back((*it).first);
		}
		getRes(res, trace, endWord, beginWord, currentSteps);
		return 0;//����ߵ�����Ļ���˵��û��·��
	}
	void getRes(vector<string>last, map<string, vector<string>> trace, string endWord, string beginWord,int depth)
	{
		
		for (int i= 0; i < last.size(); i++)
		{
			vector<string>res;
			res.push_back(endWord);
			traverse(last[i], trace, beginWord, res,depth,0);
		}
		for (int i = 0; i < result.size(); i++)
		{
			reverse(result[i].begin(),result[i].end());
		}
	}
	void traverse(string current, map<string, vector<string>> trace, string beginWord, vector<string> res,int depth,int index)
	{
		if (index >= depth)
			return;
		if (current == beginWord)
		{
			res.push_back(current);
			result.push_back(res);
		}
		else
		{
			vector<string>tmp = trace[current];
			for (int i = 0; i < trace[current].size(); i++)
			{
				vector<string>me = res;
				me.push_back(current);
				traverse(tmp[i], trace, beginWord, me,depth,index+1);
			}
		}
	}
};

class Solution0 {
public:
	/*
	 * ��ݴ����˼·Ӧ��˵���������˼·����һģһ����������ǰ׺�õ����ݽṹ���ҵĲ�ͬ
	 * http://www.tuicool.com/articles/eaQNNr
	 */
	vector<string> temp_path;
	vector<vector<string>> result_path;

	void GeneratePath(unordered_map<string, unordered_set<string>> &path, const string &start, const string &end)
	{
		//�ؽ�·���Ĺ��̣���dfs
		temp_path.push_back(start);
		if (start == end)
		{
			vector<string> ret = temp_path;
			reverse(ret.begin(), ret.end());
			result_path.push_back(ret);
			return;
		}

		for (auto it = path[start].begin(); it != path[start].end(); ++it)
		{
			GeneratePath(path, *it, end);
			temp_path.pop_back();
		}
	}
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
	{
		temp_path.clear();
		result_path.clear();

		unordered_set<string> current_step; //��ǰ����Ҫ�����Ľڵ�
		unordered_set<string> next_step;    //��һ����Ҫ�����Ľڵ�

		unordered_map<string, unordered_set<string>> path;  
		//�������set�������ݽṹ���ҵ����濪ʼ��ʱ��ͳ����˺ö��ظ���Ԫ��

		unordered_set<string> unvisited = dict; //δ���ʹ���Ԫ��set

		if (unvisited.count(start) > 0)
			unvisited.erase(start); //�Ȱ�start��ɾ��

		current_step.insert(start);  //��ǰ��ֻ��Ҫ����start

		while (current_step.count(end) == 0 && unvisited.size() > 0)
		{
			//�����ǰ��û��end�ڵ㣬����˵�ֵ��л���Ԫ��û�б�����
			for (auto pcur = current_step.begin(); pcur != current_step.end(); ++pcur)
			{
				//ǰ׺
				string word = *pcur;

				for (int i = 0; i < start.length(); ++i)
				{
					for (int j = 0; j < 26; j++)
					{
						string tmp = word;
						if (tmp[i] == 'a' + j)
							continue;
						tmp[i] = 'a' + j;
						if (unvisited.count(tmp) > 0)
						{
							//�����δ���ʵļ��������ҵ�tmp����tmp�ŵ���һ����
							//���� tmp��ǰ׺����word�������
							next_step.insert(tmp);
							path[tmp].insert(word);
						}
					}
				}
			}

			if (next_step.empty()) break;  //�����һ��û��Ҫ���ʵ��ˣ�ֱ��break�˳���
			for (auto it = next_step.begin(); it != next_step.end(); ++it)
			{
				unvisited.erase(*it); //��unvisited������ɾ����һ����Ҫ���ʵ�Ԫ��
				//��Ϊ�ڵ�����һ���ʱ�򣬿϶��������ɺͱ���һ�����ʵĺ��ӣ�����Ͳ������·����
				//��һ�����Ҫ�������ؽ�·����ʱ���������ѭ����
			}

			current_step = next_step; //current_step��Ϊ��һ��Ҫ���ʵģ���һ������
			next_step.clear();
		}

		if (current_step.count(end) > 0)
			GeneratePath(path, end, start);

		return result_path;
	}
};

class Solution1 {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		pathes.clear();
		dict.insert(start);
		dict.insert(end);
		vector<string> prev;
		unordered_map<string, vector<string> > traces;
		for (unordered_set<string>::const_iterator citr = dict.begin();citr != dict.end(); citr++)
		{
			traces[*citr] = prev;
		}

		vector<unordered_set<string> > layers(2);
		int cur = 0;
		int pre = 1;
		layers[cur].insert(start);
		while (true) 
		{
			cur = !cur;
			pre = !pre;
			for (unordered_set<string>::const_iterator citr = layers[pre].begin();citr != layers[pre].end(); citr++)
				dict.erase(*citr);
			
			layers[cur].clear();
			for (unordered_set<string>::const_iterator citr = layers[pre].begin();citr != layers[pre].end(); citr++)
			{
				for (int n = 0; n<(*citr).size(); n++)
				{
					string word = *citr;
					int stop = word[n] - 'a';
					for (int i = (stop + 1) % 26; i != stop; i = (i + 1) % 26) 
					{
						word[n] = 'a' + i;
						if (dict.find(word) != dict.end())
						{
							traces[word].push_back(*citr);
							layers[cur].insert(word);
						}
					}
				}
			}
			if (layers[cur].size() == 0)
				return pathes;
			if (layers[cur].count(end))
				break;
		}
		vector<string> path;
		buildPath(traces, path, end);

		return pathes;
	}

private:
	void buildPath(unordered_map<string, vector<string> > &traces,vector<string> &path, const string &word)
	{
		if (traces[word].size() == 0) 
		{
			path.push_back(word);
			vector<string> curPath = path;
			reverse(curPath.begin(), curPath.end());
			pathes.push_back(curPath);
			path.pop_back();
			return;
		}

		const vector<string> &prevs = traces[word];
		path.push_back(word);
		for (vector<string>::const_iterator citr = prevs.begin();citr != prevs.end(); citr++) 
		{
			buildPath(traces, path, *citr);
		}
		path.pop_back();
	}

	vector<vector<string> > pathes;
};


int main()
{
	string start = "qa";
	string end = "sq";
	unordered_set<string>dict = { "si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye" };
	Solution mine;
	vector<vector<string>> result;
	result = mine.findLadders(start, end, dict);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j]<<"->";
		}
		cout << endl;
	}
	
	return 0;
}
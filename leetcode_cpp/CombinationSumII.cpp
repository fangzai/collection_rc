/*
time   :  2015-5-24
author :  ht
comment:  �ҵ������������ֺ�Ϊtarget��������,����һ��Ԫ��ֻ����һ��
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> result;
	vector<bool>sign;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		int len = candidates.size();
		if (len <= 0)
			return result;

		sort(candidates.begin(), candidates.end());
		vector<bool>tmp(candidates.size(),false);
		sign = tmp;
		//preProcess(candidates); //ȥ���ظ�Ԫ��
		vector<int> index;
		traverse(candidates, target, 0, 0, index, 1000, 0);
		return result;
	}
	void traverse(vector<int> candidates, int target, int sum, int depth, vector<int>index, int maxDepth, int n)
	{
		//n��ʾ���ǵ�ǰ���������
		//���� 2 3 6 7 
		//�����ǰ��������3 ��ô�´�Ҳ�Ǵ�3��ʼ  Ϊ�˷�ֹ�ظ�  �����ܵ�2����ȥ
		//��ȱ������㷨����̫����
		if (sum > target)
		{
			return;//���������ˣ���Ϊ�Ѿ�̫����
		}
		if (sum == target)
		{
			vector<int>res;
			res = index;
			result.push_back(index);
			return;
		}
		int i, len = candidates.size();
		for (i = n; i < len; i++)
		{
			vector<int> temp = index;
			temp.push_back(candidates[i]);
			//��һ������sign��ǣ����ǰ��һ���͵�ǰ����ȣ�����ǰ����Ǹ�sign��true
			//Ҳ����ǰ����ù���,���������
			//Ҳ�������ù�����󣬰Ѻ������ȵ�Ԫ�ض�����ȥ
			if (i > 0 && candidates[i] == candidates[i - 1] && sign[i-1] == false)
				continue;
			sign[i] = true;
			traverse(candidates, target, sum + candidates[i], depth + 1, temp, maxDepth, i+1);
			sign[i] = false;
		}
	}
	void preProcess(vector<int>& candidates)
	{
		vector<int>::iterator ps = candidates.begin(), pe = ps;
		while (ps < candidates.end())
		{
			while ((pe + 1) < candidates.end() && *(pe + 1) == *(ps))
			{
				candidates.erase(pe + 1);
			}

			pe++;
			ps = pe;
		}
	}
};

int main()
{
	vector<int> candidate = { 10,1, 1, 2, 7, 6, 1, 5 };
	Solution mine;
	int target = 8;
	vector<vector<int>> result;
	result = mine.combinationSum2(candidate, target);
	int i, j;
	for (i = 0; i < result.size(); i++)
	{
		for (j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}
/*
time   :  2015-5-30
author :  ht
comment:  �鿴�������Ƿ����ظ���Ԫ��,�����ظ�Ԫ�ص��±겻���� k
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k){
		int i = 0;
		map<int, vector<int>>myMap;
		vector<int>tmp;
		bool part = false;
		for (i = 0; i < nums.size(); i++)
		{
			myMap[nums[i]].push_back(i);
		}
		map<int, vector<int>>::iterator it;
		for (it = myMap.begin(); it != myMap.end(); it++)
		{
			tmp = (*it).second;
			sort(tmp.begin(), tmp.end()); //��ʵû�б�Ҫ����һ���������
			if (tmp.size() >= 2 && valid(tmp,k))
				return true;
		}
		return false;
	}
	bool valid(vector<int> nums, int k)
	{
		int i, j;
		for (i = 1; i < nums.size(); i++)
		{
			if ((nums[i] - nums[i - 1] <= k))
				return true;
		}
		return false;
	}
};

int main()
{
	vector<int> nums = { 1, 0, 1,1 };
	Solution mine;
	bool result;
	int k = 0;
	result = mine.containsNearbyDuplicate(nums,1);
	if (result)
		cout << "Duplicate!" << endl;
	else
		cout << "No" << endl;
	return 0;
}
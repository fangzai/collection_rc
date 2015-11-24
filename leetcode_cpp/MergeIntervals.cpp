/*
time   :  2015-5-25
author :  ht
comment:  �����еĽ��������ں�����
*/
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;


//Definition for an interval.
struct Interval {
	int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval a, Interval b)
{
	if (a.start == b.start)
	{
		return a.end > b.end;
	}
	else
	{
		return a.start < b.start;
	}
	
}
class Solution {
public:
	vector<Interval> result;
	vector<Interval> merge(vector<Interval>& intervals) {
		int len = intervals.size();
		result.clear();
		if (len <= 0)
			return result;
		sort(intervals.begin(), intervals.end(), cmp); //�ȿ�����

		traverse(intervals);
		return result;
	}
	void traverse(vector<Interval> intervals)
	{
		int len = intervals.size();
		int ps, pe;
		ps = 0;
		pe = 0;
		Interval current,node;
		//ѭ���ں�
		while (ps<len)
		{
			current = intervals[ps];
			//pointer = intervals[pe + 1];
			while ((pe + 1)<len&&current.end >= intervals[pe + 1].start)
			{
				//�����ǰ��end����һ��start���ص��Ļ������ںϣ���Ϊ�����Ѿ��Ź�������
				//С����ǰ��
				current.end = myMax(current.end, intervals[pe + 1].end);
				pe++;
			}
			result.push_back(current);
			pe++;
			ps = pe;
		}
	}
	int myMin(int a,int b)
	{
		return a>b ? b : a;
	}
	int myMax(int a, int b)
	{
		return a > b ? a : b;
	}
};

int main()
{
	vector <Interval> nums;
	Interval p[4];
	p[0] = Interval(1, 3);
	p[1] = Interval(1, 6);
	p[2] = Interval(8, 10);
	p[3] = Interval(9, 18);
	int i = 0;
	int len = 4;
	for (i = 0; i < len; i++)
		nums.push_back(p[i]);
	Solution mine;
	vector<Interval> result;
	result = mine.merge(nums);
	for (i = 0; i < result.size(); i++)
	{
		cout << "[" <<result[i].start<<","<<result[i].end<<"]"<< endl;
	}
	return 0;
}
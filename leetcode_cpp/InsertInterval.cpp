/*
time   :  2015-5-25
author :  ht
comment:  ����һ��interval,�ϲ������ص���
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
/*
 *��һ����±�������������
 */
class Solution {
public:
	vector<Interval> result;
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)  {
		int len = intervals.size();
		result.clear();
		if (len <= 0)
		{
			result.push_back(newInterval);
			return result;
		}
			
		sort(intervals.begin(), intervals.end(), cmp); //�ȿ�����

		traverse(intervals, newInterval);
		return result;
	}
	void traverse(vector<Interval> intervals, Interval newInterval)
	{
		Interval head(INT_MIN, INT_MIN), tail(INT_MAX, INT_MAX);
		//��һ��ͷ  ��  һ��β��  ��������Խ��
		intervals.insert(intervals.begin(), head);
		intervals.insert(intervals.end(), tail);
		int len = intervals.size();
		int ps, pe;
		ps = 0;
		pe = 0;
		Interval current;
		//ѭ���ں�
		int i, j;
		for (i = 0; i<len; i++)
		{
			if (intervals[i].start < newInterval.start)
			{
				ps++;
			}
			if (intervals[i].end < newInterval.end)
			{
				pe++;
			}
		}
		//�Ȱ����Ǹò����λ�ò��ҳ���  һ����ps����һ����pe
		for (i = 0; i< ps - 1; i++)
		{
			result.push_back(intervals[i]);
		}

		////�м佻��������ж�
		//if (newInterval.start>intervals[ps-1].end)
		//{
		//	result.push_back(intervals[ps-1]);
		//	//newInterval��ps-1�±�����û�н���
		//	
		//	//�����ж�newInterval.end�Ƿ�ͺ���������н���
		//	current.start = newInterval.start;
		//	if (newInterval.end >= intervals[pe].start)
		//	{
		//		current.end = intervals[pe].end;
		//		result.push_back(current);
		//		//�н��棬�����ںϳ�һ����
		//	}
		//	else
		//	{
		//		//û�н��һ��current������һ�����±�Ϊpe��interval
		//		current.end = newInterval.end;
		//		result.push_back(current);
		//		result.push_back(intervals[pe]);
		//	}

		//}
		//else
		//{
		//	//��ǰ��һ�������н���
		//	current.start = intervals[ps-1].start;
		//	//�ж���pe�Ƿ��н���
		//	if (newInterval.end >= intervals[pe].start)
		//	{
		//		current.end = intervals[pe].end;
		//		result.push_back(current);
		//		//�н��棬�����ںϳ�һ����
		//	}
		//	else
		//	{
		//		//û�нϲһ��current������һ�����±�Ϊpe��interval
		//		current.end = newInterval.end;
		//		result.push_back(current);
		//		result.push_back(intervals[pe]);
		//	}
		//}


		//�ж�ps-1�±������Ƿ񽻲�
		if (newInterval.start>intervals[ps-1].end)
		{
			//newInterval��ps-1�±�����û�н���
			result.push_back(intervals[ps-1]);
			
			current.start = newInterval.start;
			//��ǰ���������newInterval��start
		}
		else
		{
			//��ǰ��һ�������н���
			current.start = intervals[ps-1].start;
		}

		//�ж���pe�Ƿ��н���
		if (newInterval.end >= intervals[pe].start)
		{
			current.end = intervals[pe].end;
			result.push_back(current);
			//�н��棬�����ںϳ�һ����
		}
		else
		{
			//û�н��棬һ��current������һ�����±�Ϊpe��interval
			current.end = newInterval.end;
			result.push_back(current);
			result.push_back(intervals[pe]);
		}



		//����û�н�������Ĵ���
		pe++;
		while (pe<len)
		{
			result.push_back(intervals[pe]);
			pe++;
		}
		//ȥ����һ��Ԫ�� �����һ������
		result.erase(result.begin());
		result.erase(result.end()-1);

	}
	int myMin(int a, int b)
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
	Interval p[5];
	p[0] = Interval(1, 2);
	p[1] = Interval(3, 5);
	p[2] = Interval(6 , 7);
	p[3] = Interval(8, 10);
	p[4] = Interval(12, 16);
	int i = 0;
	int len = 5;
	for (i = 0; i < len; i++)
		nums.push_back(p[i]);

	Interval point(3,17);
	Solution mine;
	vector<Interval> result;
	result = mine.insert(nums,point);
	for (i = 0; i < result.size(); i++)
	{
		cout << "[" << result[i].start << "," << result[i].end << "]" << endl;
	}
	return 0;
}
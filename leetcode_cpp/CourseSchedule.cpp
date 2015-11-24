/*
time   :  2015-5-24
author :  ht
comment:  ���һ��ͼ�����Ƿ��л�
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
using namespace std;

struct Node{
	int in;  //��һ��ά�ȱ�ʾ�������
	vector<int>request;  //�ڶ�ά�ȴ���Ҫ���ҡ��Ľڵ�
};

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<Node>nodes(numCourses);  //�ж����ſγ̾��ж��ٸ��ڵ�
		int len = 0;
		len = prerequisites.size();
		int i;
		for (i = 0; i < numCourses; i++)
			nodes[i].in = 0;
		pair<int,int> current;
		for (i = 0; i < len; i++)
		{
			//prerequisites��ά����ʵ�Ƕ�ά��
			current = prerequisites[i];
			nodes[current.second].request.push_back(current.first);
			//nodes[i]��req��������������Ҫi�Ľڵ㣬��Ҫ�㷴��
			nodes[current.first].in++;//��� +1
		}
		queue<int> myQ;
		for (i = 0; i < numCourses; i++)
		{
			if (nodes[i].in == 0)
			{
				myQ.push(i);
			}
		}
		int index;
		while (!myQ.empty())
		{
			index = myQ.front();
			myQ.pop();
			len = nodes[index].request.size();  //��Ҫindex�ڵ�Ŀγ̶����������request����
			for (i = 0; i < len; i++)
			{
				//���ﰤ������Ҫindex�ڵ�γ̵���ȶ� -1
				nodes[nodes[index].request[i]].in--;
				if (nodes[nodes[index].request[i]].in == 0)
					myQ.push(nodes[index].request[i]);
			}
		}
		for (i = 0; i < numCourses; i++)
		{
			//�����ʱ������ȴ���0�Ŀγ�
			if (nodes[i].in > 0)
				return false;
		}
		return true;
	}
};

int main()
{
	pair<int, int> p1,p2;
	p1 = make_pair<int,int>(0,1);
	p2 = make_pair<int, int>(1, 0);
	vector<pair<int, int>> pre = {p1,p2};
	int nums = 2;
	Solution mine;
	bool result;
	result = mine.canFinish(nums,pre);
	if (result)
	{
		cout << "Can finsh!" << endl;
	}
	else
	{
		cout << "Can't finish!" << endl;
	}
	return 0;
}
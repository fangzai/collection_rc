/*
time   :  2015-5-30
author :  ht
comment:  ��ƽ������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
/*
 * �Ҿ��ã���һ��Ҫ�ǲ��ø߼������ݽṹ�϶��ö�����
 * merge interval ��һ�����������ӣ��Լ�ȷ���±���Ե�����Ҫ���������ж�
 * �ο����ϵ�˼·
 */
class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> height;
		for (auto &b : buildings) 
		{
			height.push_back({ b[0], -b[2] }); 
			//��ڵ��Ϊ��ֵ�������ں���Ͳ���Ҫ�ж��������ұ߽绹����߽���
			height.push_back({ b[1], b[2] });
		}
		//�Ȱ���x�������򣬸߶Ȳ�����
		sort(height.begin(), height.end());
		multiset<int> heap;
		heap.insert(0);
		
		vector<pair<int, int>> res;
		int pre = 0, cur = 0;
		for (auto &h : height) 
		{
			//�������еĸ߶�
			if (h.second < 0) 
			{
				//������߽�Ͳ���߶�
				heap.insert(-h.second);
			}
			else 
			{
				//�����ұ߽��ɾ���߶�
				heap.erase(heap.find(h.second));
			}
			/*
			 * �������һ������ [0,3] [2,2] [3,3 [5,2] 
			 * ʵ��height��������ô���  [0,-3] [2,-2] [3,3] [5,2]
			 * ������һ���߶� ����cur =0, heap �����{0 3},  ����������һ��[0,3]��
			 * �����ڶ����߶� ��2��-2�����룬heap �����{ 0,2��3}��cur =3,pre =3; ��ȣ���� [0,3]
			 * �����������߶ȣ�ɾ���߶�3 ,heap�����{0,2},cur = 2��pre=3,���Ƚ����[0,3] [3��2]
			 * �������ĸ���ɾ���߶�2 ,cur =0,pre =2 ���ȣ������[0,3] [3��2][0,0]
			 */
			cur = *heap.rbegin();
			if (cur != pre)
			{
				res.push_back({ h.first, cur });
				pre = cur;
			}
		}
		return res;
	}
};
int main()
{
	vector<vector<int>> buildings = { {0,3,3}, {2,5,2} };
	vector<pair<int, int>> result;
	Solution mine;
	result = mine.getSkyline(buildings);
	return 0;
}
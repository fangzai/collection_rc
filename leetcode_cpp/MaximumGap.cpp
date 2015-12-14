/*
time   :  2015-5-28
author :  ht
comment:  ����������max gap������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
using namespace std;

/*
 * �ұ�ʾ��ʼ��ʱ��û���������
 * ��Ŀ����˼�Ƿ��������������max gap
 * Ҫ������ʱ��ռ�
 * �����Ͳ�����һ��ıȽ������� ��Ϊ��ͨ�ıȽ�������һ���½��� nlogn
 * ����ֻ�������������򷽷�
 */
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int len = nums.size();
		if (len < 2) return 0;
		return buckerOrder(nums);

	}
	int buckerOrder(vector<int> nums)
	{
		//ʹ��Ͱ�����ж��ٸ�Ԫ�ؾ��ж��ٸ�Ͱ��  �� �ⶼ�У�ǰ���������ȷֲ��ģ�
		//��Ȼ��ռ�ʱ�临�ӶȾ������Ե���
		// ��һ������ÿ��Ͱ��������Ԫ�غ���СԪ��
		//�����֮����ǰһ��Ͱ�ͺ�һ��Ͱ����Ĵ�gap,ȡ���ֵ
		
		//����ύ��ò��������
		int maxVal = *max_element(nums.begin(),nums.end());
		int minVal = *min_element(nums.begin(), nums.end());

		int avergeGap = ceil((double)(maxVal - minVal) / (nums.size() - 1)); //����Ͱ������
		int bucketNum = ceil((double)(maxVal - minVal) / avergeGap);
		vector<int> bucketMin(bucketNum, INT_MAX);
		vector<int> bucketMax(bucketNum, INT_MIN);
		int i;
		int bucketId;
		for (i = 0; i < bucketNum; i++)
		{
			if (nums[i] != maxVal&&nums[i] != minVal)
			{
				bucketId = (nums[i] - minVal) / avergeGap;
				bucketMin[bucketId] = myMin(bucketMin[bucketId],nums[i]);
				bucketMax[bucketId] = myMax(bucketMax[bucketId], nums[i]);
			}
		}
		int maxGap = INT_MIN;
		int previous = minVal;
		for (i = 0; i < bucketNum; i++)
		{
			//����һ��Ͱ�ǿյ����
			if (bucketMin[i] == INT_MAX || bucketMax[i] == INT_MIN)
				continue;
			maxGap = myMax(maxGap,bucketMin[i]-previous);
			previous = bucketMax[i];
		}
		maxGap = myMax(maxGap,maxVal-previous);
		return maxGap;
	}
	int common(vector<int> nums)
	{
		sort(nums.begin(),nums.end()); //nlogn�ĸ��Ӷ� �������ǲ��е�
		int len = nums.size(); 
			int maxGap = INT_MIN;
		for (int i = 1; i < len; i++)
		{
			maxGap = myMax(maxGap, nums[i] - nums[i - 1]);
		}
		return maxGap;
	}
	int myMax(int a,int b)
	{
		return a > b ? a : b;
	}
	int myMin(int a, int b)
	{
		return a > b ? b : a;
	}

	int maximumGap1(vector<int> &num) {
		//����Ǻõ�
		if (num.size() < 2) return 0;
		// 1. ����õ�Ͱ����ȡƽ��������������ֵ����Сֵ֮����Լ�����õ�Ͱ��
		// ��Ϊ��������ֵ����ƽ���ֲ���ʱ�����ȡͰ���ɵ�ʱ�临�Ӷ���0(n)
		auto maxVal = *max_element(num.begin(), num.end());
		auto minVal = *min_element(num.begin(), num.end());
		int agGap = ceil((double)(maxVal - minVal) / (num.size() - 1)); // ƽ�����
		int bucketCount = ceil((double)(maxVal - minVal) / agGap);
		// 2. ��¼ÿ��Ͱ�����ֵ����Сֵ
		vector<pair<int, int> > buckets(bucketCount, make_pair(INT_MIN, INT_MAX)); // ��ʼ��Ͱ
		for (auto val : num){
			if (val == maxVal || val == minVal) continue;
			int bucketNum = (val - minVal) / agGap;
			if (val > buckets[bucketNum].first)
				buckets[bucketNum].first = val; // �洢���ֵ
			if (val < buckets[bucketNum].second) buckets[bucketNum].second = val; // �洢��Сֵ
		}
		// 3. ��������
		int maxGap(0), lastMax(minVal);
		for (auto bucket : buckets){
			if (bucket.first == INT_MIN) continue; // ��Ͱ
			int curMax(bucket.first), curMin(bucket.second);
			maxGap = max(maxGap, curMin - lastMax);
			lastMax = curMax;
		}
		maxGap = max(maxGap, maxVal - lastMax);
		return maxGap;
	}
};

int main()
{
	vector<int> nums = { 13684, 13701, 15157, 2344, 28728, 16001, 9900, 7367, 30607, 5408, 17186, 13230, 1598, 9766, 13083, 27618, 29065, 9171, 2470, 20163, 5530, 20665, 14818, 4743, 24871, 27852, 8129, 4071, 17488, 30904, 1548, 16408, 1734, 17271, 19880, 22269, 18738, 30242, 6679, 19867, 13781, 4615, 10049, 28877, 9323, 5373, 11381, 18489, 13654, 14324, 28843, 27010, 10232, 31696, 29708, 3008, 28769, 30840, 21172, 28461, 20522, 8745, 17590, 27936, 30368, 30993, 24416, 17472 };
	Solution mine;
	int result;
	result = mine.maximumGap(nums);
	cout << result << endl;
	return 0;
}
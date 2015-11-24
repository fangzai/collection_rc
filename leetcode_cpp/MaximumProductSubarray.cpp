/*
time   :  2015-5-22
author :  ht
comment:  ���������в���ĳ��Ԫ�ص�range
Ҫ��nlogn��ʱ�临�Ӷ������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//ά����������
	//max[i]��ʾ��a[i]��β����������˻�
	//min[i]��ʾ��a[i]��β���������С�˻�

	//�����Ļ�max[i] = max(a[i],max[i-1]*a[i],min[i-1]*a[i])
	//�����Ļ�min[i] = min(a[i],max[i-1]*a[i],min[i-1]*a[i])
	int maxProduct(vector<int>& nums) {
		
		int len = nums.size();
		if (len < 1)
			return 0;
		vector<int>Max(len, 0);
		vector<int>Min(len, 0);
		Max[0] = nums[0];
		Min[0] = nums[0];
		int i;
		vector<int> array(3,0);
		int maxValue = nums[0];
		int maxPro,minPro;
		for (i = 1; i < len; i++)
		{
			array[0] = nums[i];
			array[1] = Max[i - 1] * nums[i];
			array[2] = Min[i - 1] * nums[i];
			Max[i] = myMax(array);
			Min[i] = myMin(array);
			if (maxValue < Max[i])
				maxValue = Max[i];
		}
		return maxValue;
	}
	int myMin(vector<int> array)
	{
		int i = 0;
		int len = array.size();
		int min = array[0];
		for (i = 1; i < len; i++)
			if (array[i] < min)
				min = array[i];
		return min;
	}
	int myMax(vector<int> array)
	{
		int i = 0;
		int len = array.size();
		int max = array[0];
		for (i = 1; i < len; i++)
			if (array[i] > max)
				max = array[i];
		return max;
	}
};

int main()
{
	vector<int> nums = { 2, 3, -2, 4 };
	int result;
	Solution mine;
	result = mine.maxProduct(nums);
	cout << result << endl;
	return 0;
}




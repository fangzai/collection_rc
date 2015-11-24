/*
time   :  2015-5-23
author :  ht
comment:  �ҵ�һ�������е�k�������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}
/*
 * ���ÿ��� ����nums��ǰk����������������α��������nums[index]���ڵ�k�����ֵĻ���
 * ������־�Ҫ����ԭ���������У��ö��ֲ��ҵķ����������㷨�ĸ��Ӷ�Ӧ��С��nlogn
 */
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int len = nums.size();
		if (len<=0||len < k)
		{
			return 0;
		}
		vector<int>array;
		int i = 0;
		for (i = 0; i < k; i++)
			array.push_back(nums[i]);
		int result;
		int index = k;
		result = taverse(array, nums, index, k);
		return result;
	}
	int taverse(vector<int> array,vector<int>nums,int index,int k)
	{
		//index��ʾnums���±����
		sort(array.begin(), array.end(),cmp);
		int i = 0;
		int lower = 0;
		for (i = index; i < nums.size(); i++)
		{
			if (nums[i]>array[k - 1])
			{
				lower = binarySearch(array, 0, k - 1,nums[i]);
				array.insert(array.begin()+lower,nums[i]);
			}
		}
		return array[k-1];
	}
	int binarySearch(vector<int>nums,int left,int right,int key)
	{
		int mid;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (nums[mid] == key)
				return mid;
			if (nums[mid] < key)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		return left;
	}
};

int main()
{
	vector<int>nums = { 3, 2, 1, 5, 6, 4 ,4};
	Solution mine;
	int k = 4;
	int result;
	result = mine.findKthLargest(nums,k);
	cout << result << endl;
	return 0;
}
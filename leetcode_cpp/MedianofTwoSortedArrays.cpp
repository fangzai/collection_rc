/*
time   :  2015-5-29
author :  ht
comment:  ������������ ��ϲ����������ֵ��Ҫ��ʱ�临�Ӷ���O(m+n)
*/
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double result; 
		result = traverse(nums1,nums2);
		return result;
	}
	double traverse(vector<int> nums1, vector<int> nums2)
	{
		int len1 = nums1.size();
		int len2 = nums2.size();
		int i, j;
		int index = 0;
		i = 0; //��һ��������±�
		j = 0; //�ڶ���������±�
		//����������Ļ�����ôindex�±����  (len1+len2)/2
		//�����ż���Ļ���index���±����  (len1+len2-1)/2  (len1+len2+1)/2
		int bound;
		bool flag = (len1 + len2) % 2 == 0;
		if (flag)
			bound = (len1 + len2 - 1) / 2;
		else
			bound = (len1 + len2) / 2;

		int median1, median2;
		while (i<len1||j<len2)
		{
			if (i < len1&&j < len2)
			{
				if (nums1[i] <= nums2[j])
				{
					median1 = nums1[i];
					i++;
				}
				else
				{
					median1 = nums2[j];
					j++;
				}
			}
			else if (i<len1)
			{
				median1 = nums1[i];
				i++;
			}
			else
			{
				median1 = nums2[j];
				j++;
			}

			if (index == bound)
				break;

			index++;	
		}
		if (flag)
		{
			//ż�������� �Ƚ���һ��
			if (i < len1&&j < len2)
			{
				median2 = (nums1[i] > nums2[j]) ? nums2[j] : nums1[i];
			}
			else if (i<len1)
			{
				median2 = nums1[i];
			}
			else
			{
				median2 = nums2[j];
			}
			return ((double)median1 + (double)median2) / 2;
		}
		else
		{
			return (double)median1;
		}
	}
};
int main()
{
	//vector<int> nums1 = {0,1,4};
	//vector<int>nums2 = {2,3,5};
	vector<int> nums1 = {0};
	vector<int>nums2 = {-1,2,3};
	Solution mine;
	double result;
	result = mine.findMedianSortedArrays(nums1,nums2);
	cout << result << endl;
	return 0;
}
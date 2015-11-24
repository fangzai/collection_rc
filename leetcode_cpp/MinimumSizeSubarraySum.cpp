/*
time   :  2015-5-22
author :  ht
comment:  ������ ��ĳ����С����ʹ����ض�����
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		
		//sort(nums.begin(), nums.end());  //�Ƚ�������
		int ps, pe;
		int i, j;
		ps = 0; pe = 0;
		int sum = 0;
		int len = nums.size();
		int result = len + 1;
		while (pe < len)
		{
			sum += nums[pe]; //�����ұߵ�ֵ
			while (sum >= s)
			{
				if ((pe - ps+1) == 1)
					return 1;

				//��ǰ�ĳ�����pe-ps +1
				result = myMin(result, pe - ps + 1);
				sum -= nums[ps];
				ps++;//��ʼֵ�±��1
			}
			pe++; //���ʱ��sum<s��
		}
		if (result == (len+1))
		{
			return 0;  //ѹ����û���ҵ�
		}
		else
		{
			return result;
		}
	}
	int myMin(int a, int b)
	{
		return a>b ? b : a;
	}
	int minSubArrayLen1(int s, vector<int>& nums)
	{
		if (nums.size() <= 0)
			return 0;
		// ����㷨�ĸ��Ӷ���nlogn��Ҫ�õ���������
		int len = nums.size();
		vector<int>sums(len+1,0);  //����һ��len + 1���������  ����sum[i]��ʾ 0->i-1�ĺ�
		int i;
		for (i = 1; i < len+1; i++)
			sums[i] = (sums[i-1] + nums[i-1]);
		int right, result=len+1;
		for (i = 0; i < len+1; i++)
		{
			right = binarySearch(i+1,len,sums[i]+s,sums);
			// start�±�Ӧ�ô� i����һ������ʼ
			//��keyֵ�պ���sums[i]Ҳ���Ǵ�0��i-1������s��ʼ
			//�ٸ�����  nums ={1,4,4}
			//sums = {0,1,5,9}  ��i =1��ʱ��Ӧ�ô�sum��2�±꿪ʼ����
			//����key�Ļ���Ӧ����  1 + s = 5 Ҳ����sum[1]+s
			if (right == (len + 1))
				break;
			result = myMin(result,right-i);
		}
		return result == (len + 1) ? 0:result;
	}
	int binarySearch(int left,int right,int key,vector<int> nums)
	{
		//���������ǿ��Բ��ҵ���ԭ�����Բ����λ��
		int mid;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (nums[mid] >= key)
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
	//vector<int> nums = { 2, 3, 1, 2, 4, 3 };
	vector<int> nums = { 1,4,4 };
	int s = 4;
	Solution mine;
	int result;
	result = mine.minSubArrayLen1(s, nums);
	cout << result << endl;

	//vector<int>nums1 = {1,4,5,8,9,10};
	//int target = 5;
	//result = mine.binarySearch(0,5,target,nums1);
	//cout << result << endl;
	return 0;
}

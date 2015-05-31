/*
time   :  2015-5-21
author :  ht
comment:  ����sum������
		  ������3sum����������棬������3sum����һ����ֻ���ڲ���twosum��
		  ����������Ҫ��һЩ�䶯
*/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

/*
 *������3sum����������棬������3sum����һ����ֻ���ڲ���twosum��
 * ����������Ҫ��һЩ�䶯
 */
class Solution {
public:
	int min = INT_MAX;
	int res;
	bool flag;
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3)
			return  0;
		sort(nums.begin(), nums.end());  //���ÿ�������

		int len = nums.size();
		for (int i = 0; i < len - 2; i++)
		{
			//��Ϊֻ���ܱ����������ڶ���
			if (i>0 && nums[i] == nums[i - 1])
				continue;  //��������ظ��Ľ��
			findTwoSum(nums, i + 1, len - 1, nums[i],target);
		}
		return res;
		
	}
	void findTwoSum(vector<int>nums, int begin, int end, int current,int target)
	{
		int left = begin;
		int right = end;
		int temp,result;
		while (left < right)
		{
			temp = current + nums[left] + nums[right];
			result = temp;  //������
			temp = temp - target;
			
			if (temp < 0)  //�����ֵ
			{
				temp = -1 * temp;
				flag = false;
				left++;
			}
			else
			{
				right--;
				flag = true;
			}
			if (temp < min)
			{
				min = temp;
				res = result;
			}
		}
	}
};

int main()
{
	
	int target = 1;
	Solution mine;
	vector<int>nums1 = { -1,2,1,-4 };
	int res = mine.threeSumClosest(nums1,target);

	cout <<res<< endl;
	return 0;
}
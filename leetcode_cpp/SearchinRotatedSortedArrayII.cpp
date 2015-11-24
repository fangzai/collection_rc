/*
time   :  2015-5-24
author :  ht
comment:  ex33�������棬����һ��Ԫ�ؿ����ظ�������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
 *  �ټ����ظ�Ԫ��֮�󣬶��������һ������Ҳ����left++�Ǹ�����
 *  ����ƽ���������Ǳ����Բ���Ҫ��
 */
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int numsSize = nums.size();
		int left, right, mid;
		left = 0;
		right = numsSize - 1;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (target == nums[mid])
				return true;
			if (nums[left]<nums[mid])
			{
				// ˵�����ڵ�һ����������
				if (nums[left] <= target&&target < nums[mid])
				{
					//��left ��mid-1����������
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			else if (nums[left]>nums[mid])
			{
				//˵�����ڵڶ�����������
				if (nums[mid]<target&&target <= nums[right])
				{
					//��left ��mid-1����������
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}

			}
			else
			{
				left = left + 1;  //ֻ��Ҫ���ҵ���һ��������leftֱֵ�Ӹ�Ϊ
				//left++ �Ϳ�����
			}
		}

		return false;
	}
};

int main()
{
	vector<int> nums = { 1, 3, 1, 1, 1 };
	Solution mine;
	int target = 3;
	int result;
	result = mine.search(nums,target);
	cout <<  result << endl;
	return 0;
}
/*
time   :  2015-5-25
author :  ht
comment:  �ҵ���һ����ʧ������
*/
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

/*
 * ��ĿҪ������ʱ������ɣ�Ȼ��ֻ�ܿ������ռ�
 * �����ͱȽ϶�����
 */
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		if (len <= 0) return 1;

		//��Ԫ�طŵ����ǹ̶���λ�� Ԫ��2���� nums[1]  Ԫ��3 ����num[2]
		int i;
		for (i = 0; i < len; i++)
		{
			while (nums[i] != (i + 1))
			{
				if (nums[i] <= 0 || nums[i] >= len || nums[i] == nums[nums[i] - 1])
					break;
				//��һ�������Ǹ����Ļ����ùܣ��ڶ���������nums[i]̫���ˣ��϶����ڷ�Χ��Ҳ���ù�
				//��������Ҫ�����������ط���Ԫ��һ�������ý�����Ҫ�ǽ����ˣ���������ѭ����
				//����
				
				//nums[i]Ӧ�÷ŵ�λ�õ��±���  nums[i]-1
				int tmp = nums[i];
				nums[i] = nums[tmp - 1];
				nums[tmp - 1] = tmp;
			}
		}
		for (i = 0; i < len; i++)
		{
			if (nums[i] != i + 1)
				return i + 1;
		}
		//�Ѿ�ѭ���������
		return len + 1;

	}
};

int main()
{
	vector<int>nums = { 3, 4, 2, 1 };
	Solution mine;
	int result;
	result = mine.firstMissingPositive(nums);
	cout << result << endl;
	return 0;
}
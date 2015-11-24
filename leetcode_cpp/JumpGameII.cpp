/*
time   :  2015-5-25
author :  ht
comment:  ����jump����С����
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int jump1(vector<int>& nums) {
		//����dp����  dp[i]ά������i����Ҫ����С����
		//��̬�滮�ĳ�ʱ�ˣ�ֻ�����Ǹ����Ե���
		int len = nums.size();
		vector<int>dp(len,INT_MAX);

		dp[0] = 0;  //��һ������Ҫ��������
		int i, j;
		for (i = 1; i < len; i++)
		{
			for (j = 0; j < i; j++)
			{
				if ((j + nums[j]) >= i)
				{
					//˵���ܴ�j����i;��������Сֵ�Ϳ�����
					int tmp = dp[j] + 1;//����˵��0-j����һ���Ϳ�����
					if (tmp < dp[i])
					{
						dp[i] = tmp;   //����Сֵ����dp[i]
						break;//����ط�break����Ϊ dp��һ���ǵݼ��ģ�����Ŀ϶�>=ǰ���
						//����û�б�Ҫ��j��������ѭ����
					}
				}
			}
		}

		return dp[len - 1];
	}
	/*
	 * �㷨������ô��⣬�ϴ���������Զ������last
	 * ���ߵ�i��ʱ�����last��i��ģ���������������
	 * ���ǻ���Ҫά��һ�µ�ǰ�ܵ����������
	 * ��last<i��֮��Ϳ�ʼ����last  Ȼ�����Ĳ���ҲҪ  +1
	 */
	int jump(vector<int>& nums) {
		//http://blog.csdn.net/loverooney/article/details/38455475
		//�㷨��̫�ö�
		int count = 0;    //��ǰ����  
		int last = 0;     //��һ���ɴ���Զ����  
		int current = 0;      //��ǰһ���ɴ���Զ��  
		int len = nums.size();
		for (int i = 0; i < len; ++i) 
		{
			//�޷���ǰ����ֱ�ӷ���  
			if (i>current)
			{
				return -1;
			}
			//��Ҫ�����´���Ծ�������last�͵�ִ�е�����ret  
			if (i > last)
			{
				last = current;
				count++;
			}
			//��¼��ǰ�ɴ����Զ��  
			current = myMax(current, i + nums[i]);
		}
		return count;
	}
	int myMax(int a,int b)
	{
		return a > b ? a : b;
	}
};

int main()
{
	vector<int>nums = { 2, 3, 1, 1, 4 };
	Solution mine;
	int result;
	result = mine.jump(nums);
	cout << result << endl;
	return 0;
}
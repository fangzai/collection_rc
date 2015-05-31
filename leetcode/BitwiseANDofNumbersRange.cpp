/*
time   :  2015-5-22
author :  ht
comment:  ������������������������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * �������Ŀ��Ҫ�ȹ۲�һ��m->n��Щ���ֵĹ���
 * ���ǿ��Կ������2^n�Ļ���ֻ�е�n+1λ����1��
 * ���m->n֮����һ���պ���2�����Ļ���ȫ����and֮��϶���0
 * ���� 4 100 �� 8 1000,���ǵĶ���ֵ��1����һ����Χ��
 * �����Ļ������Ǿ���Ҫ��һ��ѭ�� ��m,nһֱ��������������ǵ�k1��k2�Ƿ�����ȵģ������ȵĻ�
 * ��������push ����2^k1���������Ҫ��������
 * ����һ������m����n���0�˵Ļ����������ˣ��϶�����0��
 * �������Լ�д��һ������������һ��ָ����������ʵ��û�б�Ҫ��
 * Ҫ���Լ�д�Ļ������ٶȸ��죬�䵽c�������������ȥ�ˡ�
 */
class Solution {
public:
	vector<int>array;
	int rangeBitwiseAnd(int m, int n) {
		int k1,k2;
		if (m == 0 || n == 0)
			return 0;
		k1 = myLog(m);
		k2 = myLog(n);
		
		int low = m,high = n;
		// ��k1 == k2��ʱ����н��
		while (k2 == k1)
		{
			array.push_back(k1);
			int tmp = myExp(k1);
			low -= tmp;
			high -= tmp;

			//����һ����Ϊ0�Ļ���ֱ���˳��ˣ���������
			if (low == 0 || high == 0)
				break;

			k1 = myLog(low);
			k2 = myLog(high);
		}
		int len = array.size();
		if (len <= 0)
		{
			return 0;
		}
		else
		{
			int sum = 0;
			for (int i = 0; i < len; i++)
			{
				sum += myExp(array[i]);
			}
			return sum;
		}
	}
	int myLog(int n)
	{
		int i = 0;
		while (n >= 2)
		{
			n = n / 2;
			i++;
		}
		return i;
	}
	int myExp(int n)
	{
		int i = 0;
		int num = 1;
		for (i = 0; i < n; i++)
		{
			num *= 2;
		}
		
		return num;
	}
};

int main()
{
	//int m = 5,n =8;
	int m = 4, n = 8;
	Solution mine;
	int result;
	//result = mine.myLog(8);
	result = mine.rangeBitwiseAnd(m,n);
	cout << result << endl;
	return 0;
}
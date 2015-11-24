/*
time   :  2015-5-23
author :  ht
comment:  �����������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

/*
 * �㷨��˼�����ȶ�dividendȥ�������õ�N,Ȼ��
 * dividend -2^n������ȡ�����Ĺ��̲����ó˷��ͳ�������ֻ���üӷ���
 * ÿ��ѭ��һ�飬ֱ���ҵ����������Լ���������һ��ֵ���ظ�����
 */
class Solution {
public:
	long long internalDivide(unsigned long long dividend, unsigned long long divisor) {
		if (dividend < divisor) {
			return 0;
		}

		long long result = 1;
		unsigned long long tmp = divisor, left;

		while (tmp <= dividend) {
			left = dividend - tmp; 
			//��¼��4��ĳ��ָ������֮��ʣ���
			tmp <<= 1;

			if (tmp > dividend) {
				break;
			}
			else {
				result <<= 1;
			}
		}

		return result + internalDivide(left, divisor);
	}
	int divide(int dividend, int divisor) {
		unsigned long long _dividend = abs((long long)dividend),
			_divisor = abs((long long)divisor);
		bool positive = ((dividend >= 0) && (divisor > 0)) || ((dividend <= 0) && (divisor < 0));

		return positive ? internalDivide(_dividend, _divisor) : (-1) * internalDivide(_dividend, _divisor);
	}
	int divide1(int dividend, int divisor) {
		//������ĳ�����ߵĵݹ���ʽ��Ҳ���Ըĳɷǵݹ���ʽ
		//�����Ŀ��ʵ��������Ǹ���m n���е����� and�Ľ��������
		if (dividend == 0 || divisor == 0)
			return 0;  //���������ͳ���Ϊ0���������
		//��������Խ������

		long long int newDividen = dividend;
		long long int newDivisor = divisor;
		bool flag = false;
		if (newDividen*newDivisor < 0)
			flag = true;
		if (newDividen < 0)
			newDividen = 0- newDividen;
		if (newDivisor < 0)
			newDivisor = 0- newDivisor;
		
		if (newDivisor > newDividen)
			return 0;
		long long int sum = 0;
		int tmp;
		long long int count = 1;
		long long int last = 0;
		while (newDividen >= newDivisor)
		{
			sum = newDivisor;
			count = 1;
			while ((sum +sum) <= newDividen)
			{
				sum = sum +sum;
				count = count << 1;
			}
			newDividen -= sum;
			last += count;
		}
		if (flag)
			last = 0 - last;
		if (last >= INT_MAX)
			return INT_MAX;
		return last;
	}
};

int main()
{
	int dividend = INT_MIN;
	int divisor = -1;
	Solution mine;
	int result;
	result = mine.divide1(dividend,divisor);
	cout << result << endl;
	return 0;
}
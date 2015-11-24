/*
time   :  2015-5-12
author :  ht
comment:  ��x��n�η�
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
double myPow(double x, int n) {
	int i = 0;
	double result = 1;
	for (i = 0; i < n; i++)
	{
		result = result*x;
	}
	return result;
}
double myPow1(double x, int n)
{
	//ʹ���˶��ַ�����ʵ�ҵ��뷨��ֱ�ӳ���10
	//����Ч�ʻ����
	if (n == 0)
		return 1.0;
	if (n < 0)
	{
		if (n == INT_MIN)
			return 1.0 / (myPow(x, INT_MAX)*x);
		return 1.0 / myPow(x, -n);
	}
		
	double half = myPow(x, n >> 1);
	if (n % 2 == 0)   
		return half*half;
	else
		return half*half*x;
}
int main()
{
	double x = 3;
	int num = 3;
	printf("%f \n", myPow(x, num));
	return 0;
}
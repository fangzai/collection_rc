/*
time   :  2015-5-18
author :  ht
comment:  �Լ�д��������
		  ��ţ�ٷ�  ���ƹ�ʽΪ  m = (m + x/m)/2  x������ֵ��m���Լ�ȡ����һ����ʼ��
*/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int mySqrt(int x) {
	long double m = 1.0,tmp;
	tmp = m*m - x;
	if (tmp < 0)
		tmp = tmp*(-1.0);

	//�����Ժ�Ҫ����abs��������ˣ��ر𲻿��ף�����Խ��
	while (tmp > 1e-5)
	{
		m = (m+ x / m) / 2;
		tmp = m*m - x;
		if (tmp < 0)
			tmp = tmp*(-1.0);
	}
	return m;
}

int main()
{
	int n = 2147395599;
	printf("%d \n", mySqrt(n));
	return 0;
}
/*
time   :  2015-5-9
author :  ht
comment:  ����������ת��Ϊʮ��������

ע�ͣ����������� 7�����
I=1
V=5
X=10
L=50
C=100
D=500
M=1000
*/

#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int getInt(char s)
{
	switch (s)
	{
	case 'I':
		return 1;
		break;
	case 'V':
		return 5;
		break;
	case 'X':
		return 10;
		break;
	case 'L':
		return 50;
		break;
	case 'C':
		return 100;
		break;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		return -1;
		break;
	}
}
int romanToInt(char* s) {
	int len = strlen(s);
	int i = 0;
	int result = 0;
	int temp = 0;
	temp = getInt(s[i]);
	int num1, num2;
	//�ӵĹ�����������������˵����ķ�����������
	/*
	 * 1 �����ǰ������ַ���Ӧ��ֵ����һ���ַ�һ������ô��ʱ��
	 *   ����������ַ�������III = 3
	 *
	 * 2 �����ǰ��ǰһ����˵����һ�ε�ֵӦ���ǵ�ǰ���ֵ��ȥ
	 *   ǰ���¼�µ���ʱ�����е�ֵ������IIV = 5 �C 2
	 * 3 �����ǰ��ǰһ��С����ô�Ϳ����Ƚ���ʱ������ֵ�ӵ������
	 *  ��Ȼ��ʼ��һ�μ�¼������VI = 5 + 1
	 *  ����������ᣬ����current ��I��ʱ��ǰ�����ʱ�����ӵ�
	 *  ����У�Ȼ��ʼ��һ���ַ��ļ�¼
	 */
	
	for (i = 1; i < len; i++)
	{
		num1 = getInt(s[i]);
		num2 = getInt(s[i - 1]);
		if (num1 == num2)
		{
			temp = temp + num1; // temp ��ʵ���Ի���getInt(s[i])
		}
		else
		{
			if (num1 > num2)
			{
				temp = num1 - temp;
			}
			else
			{
				result += temp;
				temp = num1;
			}
		}

	}
	result += temp;
	return result;
}
int main()
{
	char* str = "MCMXCVI";
	printf("%d \n", romanToInt(str));
	return 0;
}
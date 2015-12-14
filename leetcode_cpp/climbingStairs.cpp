#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

int climbStairs(int n) {
	// ��Ŀԭ��˵  һ����ÿ�ο�����1������2��
	// ��n����¥���ж������߷�
	// �����Կ����õݹ�ķ�ʽ��Ҳ����˵
	// s[n]���Կ�����n-2��ֱ����һ��2��
	// n-1����һ�� ���� s[n] = s[n-2] +s[n-1]
	// �ܶ������õݹ飬�õݹ�Ļ����ڱȽϴ����������
	// ��ջ���  ֱ����ѭ���Ϳ�����

	int *count = (int*)malloc((n+1)*sizeof(int));
	count[1] = 1;  // һ��̨��ֻ��һ���߷�
	count[2] = 2;  // ����̨���������߷�
	int i;
	for (i = 3; i <= n; i++)
	{
		count[i] = count[i - 1] + count[i - 2];
	}
	return count[n];
}

int main()
{
	int n = 10;
	printf("%d \n",climbStairs(n));
	return 0;
}
/*
time   :  2015-5-14
author :  ht
comment:  ����n�����ŵ�ƥ����
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
//�϶����ö�ջ�ķ�������
char** traverse(int n,int m,int index,char**result,int *returnSize,char*temp)
{
	
	if (m == 0 && n == 0)
	{
		temp[index] = '\0';
		//printf("%s \n", temp);
		memcpy(result[returnSize[0]],temp,(index*2+1)*sizeof(char));
		returnSize[0]++;
		return result;
	}
	else
	{
		// n��ʾʣ�� n��ǰ����
		// m��ʾʣ�� m��������
		char current;
		if (n > 0)
		{
			current = '(';
			temp[index] = current;
			//index++;  //����������������㣬��Ϊ���ǻ��ۼƵ�
			traverse(n - 1, m, index + 1, result, returnSize, temp);
		}
		//ǰ���ŵĸ������ܱȺ�������
		if ((n < m)&(&m > 0))
		{
			current = ')';
			temp[index] = current;
			//index++;
			traverse(n, m - 1, index + 1, result, returnSize, temp);
		}
	}
	return result;  //һ��Ҫ�з���ֵ ��������˳�֮��result��û����
}


char** generateParenthesis(int n, int* returnSize) {
	int index = 0;
	int size = 10000;
	char**result = (char**)malloc((size)*sizeof(char*));
	char*temp = (char*)malloc((2 * n + 1)*sizeof(char));
	int i = 0;
	for (i = 0; i < size; i++)
	{
		result[i] = (char*)malloc((2 * n + 1)*sizeof(char));
	} 
	returnSize[0] = 0;
	result = traverse(n, n, index, result, returnSize,temp);
	return result;
}

int main()
{
	int n = 6;
	int reSize=0;
	char**result = generateParenthesis(n,&reSize);
	
	for (int i = 0; i < reSize; i++)
	{
		printf("%s  \n",result[i]);
	}
	printf("%d \n", reSize);
	return 0;
}
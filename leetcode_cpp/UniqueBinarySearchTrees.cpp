/*
time   :  2015-5-17
author :  ht
comment:  1.....n��������BST ����������������
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

/*
 * �ðɣ��ұ�ʾ�������û��ʲô˼·��ֻ֪���϶����е��ƹ�ʽ��
 * �ö�̬�滮���������������
 */


/*
 * �� n=1��ʱ����ڵ�ֻ��һ��ѡ��  1
 * �� n=2��ʱ����ڵ�������ѡ��
 * �� n=3��ʱ����ڵ���3��ѡ��
 * ֱ�۵ؿ������룬��n���ڵ��ʱ�򣬽ڵ�̶���ʱ��
 * ����������BST�˻����ǵ�ǰroot��BST������
 */

int numTrees(int n) {
	if (n <= 0)
		return 1;
	int i, j;
	int *result = (int*)malloc((n+1)*sizeof(int));
	result[0] = 1;
	result[1] = 1;
	result[2] = 2;
	for (i = 3; i <= n; i++)
	{
		//root�ڵ�̶�
		result[i] = 0;
		for (j = 0; j < i; j++)
		{
			//��������������i���ڵ㣬����������Ľڵ�����Ϊ n-j-1
			result[i] += result[j] * result[i - j - 1];
		}
	}

	int num = result[n];
	free(result);
	result = NULL;
	return num;
}
int main()
{
	printf("%d \n", numTrees(3));
	return 0;
}
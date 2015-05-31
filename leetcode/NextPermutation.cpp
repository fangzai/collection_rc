/*
time   :  2015-5-16
author :  ht
comment:  ����һ�����У�������һ������

�㷨���� ex47
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

void swap(int*a, int*b)
{
	int temp = a[0];
	a[0] = b[0];
	b[0] = temp;
}

void reverse(int* array, int len)
{
	int *str = (int*)malloc(len*sizeof(int));
	int i = 0, j = len - 1;
	memcpy(str, array, len*sizeof(int));
	while (i < len)
	{
		array[i] = str[j];
		j--;
		i++;
	}
}
//���öԸ������ַ����е��ַ��涨��һ���Ⱥ��ϵ���ڴ˻����ϰ���˳�����β���ÿ�����С�
/*�Ը������ַ����е��ַ��涨��һ���Ⱥ��ϵ���ڴ˻����ϰ���˳�����β���ÿ�����С�
*[��]�ַ���{1,2,3},��С�����ֽ���,�������ֵ������ɵ�ȫ������:123,132,213,231,312,321��
*���ɸ���ȫ���е���һ������ ��νһ������һ��������һ������һ��֮��û���ֵ�˳�������ڵ�
*�ַ��������Ҫ����һ������һ���о����ܳ��Ĺ�ͬǰ׺��Ҳ���仯�����ھ����̵ܶĺ�׺�ϡ�
*
* ��P��[1,n]��һ��ȫ���С�
* P=P1P2��Pn=P1P2��Pj-1PjPj+1��Pk-1PkPk+1��Pn , j=max{i|Pi<Pi+1}, k=max{i|Pi>Pj} ,
�Ի�Pj��Pk����Pj+1��Pk-1PjPk+1��Pn��ת�� P��= P1P2��Pj-1PkPn��Pk+1PjPk-1��Pj+1��P����һ��
����:839647521����һ������.
�����ҿ�ʼ,�ҵ���һ�����ұ�С������4(��Ϊ4<7����7>5>2>1),�ٴ����ҿ�ʼ,�ҵ�4�ұ߱�4���
����5(��Ϊ4>2>1��4<5),����4��5,��ʱ5�ұ�Ϊ7421,����Ϊ1247,������һ������:839651247.
�÷���֧�������ظ�������C++ STL�б����á�
*/
void nextPermutation(int* nums, int numsSize) {
	//���Ƿǵݹ�Ĳ���ȫ���е��㷨������֧��������ЩԪ�����
	int n = numsSize;
	int tail = n - 1;
	int i, j = tail;
	int len = 1, index1, index2, reverseLen = 0;
	for (i = 1; i <= n; i++)
	{
		len = len*i;
	}
	i = 1;
	j = tail;
	reverseLen = 0;
	while ((j >= 0) && (j - 1 >= 0) && (nums[j - 1] >= nums[j]))
	{
		j--;
		reverseLen++;
	}
	//�������� �ҵ���һ�����ұ�С�������±�  index1
	reverseLen++;
	index1 = j - 1;
	if (index1 <= -1)
	{
		//j=0��λ�������Ԫ��
		//break;  //�˳�����
	}
	else
	{
		//j = 0 λ�ò������Ԫ�أ���ô����ط��Ŀ϶������ҵ�index2��
		j = tail;
		while ((nums[j] <= nums[index1]) && (j >= 0))
		{
			j--;
		}
		index2 = j;
		//�ٴ������ң��ҵ���index1λ�ô������ �±� index2
		if (index2 <= -1)
		{
			//break;
		}
		swap(&nums[index1], &nums[index2]);
	}

	reverse(nums + index1 + 1, reverseLen);
}
int main()
{
	int list[8] = { 3, 2, 1, 1 };
	int numsSize = 0;
	int returnSize = 0;
	nextPermutation(list, numsSize);
	int i;

	for (i = 0; i < numsSize; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}
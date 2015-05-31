/*
time   :  2015-5-15
author :  ht
comment:  ��������ȫ���У������(��46��ȣ��������ظ�����)

		  �㷨���� ex60
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
int** traverse(int*list, int n, int**result, int* returnSize)
{
	//���Ƿǵݹ�Ĳ���ȫ���е��㷨������֧��������ЩԪ�����
	int tail = n - 1;
	int i, j = tail;
	int len = 1, index1, index2, reverseLen = 0;
	for (i = 1; i <= n; i++)
	{
		len = len*i;
	}
	i = 1;
	memcpy(result[0],list,n*sizeof(int));
	returnSize[0]++;
	//for (i = 0; i < n; i++)
	//{
	//	printf("%d ", list[i]);
	//}
	//printf("\n");
	for (i = 1; i < len; i++)
	{
		j = tail;
		reverseLen = 0;
		while ((j >= 0) && (j - 1 >= 0) && (list[j - 1] >= list[j]))
		{
			j--;   
			reverseLen++;
		}
		//�������� �ҵ���һ�����ұ�С�������±�  index1
		reverseLen++;
		index1 = j - 1;
		if (index1 <= -1)
		{
			break;  //�˳�����
		}
		j = tail;
		while ((list[j] <= list[index1]) && (j >= 0))
		{
			j--;
		}
		index2 = j;  
		//�ٴ������ң��ҵ���index1λ�ô������ �±� index2
		if (index2 <= -1)
		{
			break;
		}
		swap(&list[index1], &list[index2]);
		reverse(list + index1 + 1, reverseLen);
		memcpy(result[i], list, n*sizeof(int));
		//for (i = 0; i < n; i++)
		//{
		//	printf("%d ", list[i]);
		//}
		//printf("\n");
		returnSize[0]++;
	}
	return result;
}
int** permuteUnique(int* nums, int numsSize	, int* returnSize)  {
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
	int len = 1, i = 0,j;
	returnSize[0] = 0;
	for (i = 1; i <= numsSize; i++)
	{
		len = len*i;
	}
	
	int**result = (int**)malloc(len*sizeof(int*));
	for (i = 0; i < len; i++)
	{
		result[i] = (int*)malloc(numsSize*sizeof(int));
	}

	//����numsӦ��������
	for(i = 0; i < numsSize;i++)
	{
		int temp = nums[i];
		for (j = i; j < numsSize; j++)
		{
			if (nums[i]>nums[j])
			{
				swap(&nums[i],&nums[j]);
			}
		}
	}
	
	result = traverse(nums, numsSize,result, returnSize);
	return result;

}
int main()
{
	int list[8] = { 2,2,1,1 };
	int numsSize = 4;
	int returnSize = 0;
	int** result = permuteUnique(list, numsSize, &returnSize);

	int i, j;
	for (j = 0; j < returnSize; j++)
	{
		printf("%d  ===================================== ", j);
		for (i = 0; i < numsSize; i++)
		{
			printf("%d ", result[j][i]);
		}
		printf("\n");
	}
	return 0;
}
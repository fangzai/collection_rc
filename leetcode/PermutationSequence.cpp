/*
time   :  2015-5-13
author :  ht
comment: 1-n����������ȫ���У������
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//void swap(int&a, int&b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
void swap(char*a, char*b)
{
	char temp = a[0];
	a[0] = b[0];
	b[0] = temp;
}
void Perm(int *list, int k, int m)
{
	int i = 0;
	if (k == m)
	{	
		//�˳�����	
		printf("=====================================");
		for (i = 0; i <= k; i++)
		{
			printf("%d ", list[i]);
		}
		printf("\n");

	}
	else
	{
		for (i = k; i <= m; i++)
		{
			swap(&list[k], &list[i]);
			Perm(list, k + 1, m);
			swap(&list[k], &list[i]);
		}
	}
}
void traverse(char*list,int current,int m, int k, char*result, int*index)
{
	//������ͨ�ĵݹ��㷨�����ɵĲ������ֵ�����
	//������������ǲ��Ե�
	int i = 0;
	if (current == m)
	{
		index[0]++;
		printf("%d ====",index[0]);
		for (i = 0; i <= m; i++)
		{
			printf("%c ", list[i]);
		}
		printf("\n");
		if (index[0] == k)
		{
			memcpy(result, list, (m + 1)*sizeof(char)); 
			//ԭ�������������
			result[m+1] = '\0';
		}
		//if (index[0] == k)
			//return;
	}
	else
	{
		for (i = current; i <= m; i++)
		{
			if (index[0] <= k)
			{
				swap(list[current], list[i]);
				traverse(list, current + 1, m, k, result, index);
				swap(list[current], list[i]);
			}
		}
	}
}
char* getPermutation(int n, int k) {
	int len = 1, i = 0;
	for (i = 1; i <= n; i++)
	{
		len = len*i;
	}
	if (k > len)
	{
		return NULL;
	}
	char*list = (char*)malloc((n+1)*sizeof(char));
	char*result = (char*)malloc((n + 1)*sizeof(char));
	
	for (i = 0; i < n; i++)
	{
		list[i] = i + '0'+1;
	}
	list[i] = '\0';
	int index = 0;
	int current = 0;
	int m = n - 1;
	traverse(list, current, m, k, result, &index);
	result[n] = '\0';
	free(list);
	return result;
}
void reverse(char*array, int len)
{
	char*str = (char*)malloc(len*sizeof(char));
	int i = 0,j = len-1;
	memcpy(str, array, len);
	while (i < len)
	{
		array[i] = str[j];
		j--;
		i++;
	}
}
char* traverse1(char*list,int n,int k)
{
	int tail = n - 1;
	int i,j = tail;
	int len = 1,index1,index2,reverseLen=0;
	for (i = 1; i <= n; i++)
	{
		len = len*i;
	}
	i = 1;
	//printf("%d  =====%s \n",i, list);
	if (k == 1)
		return list;
	for (i = 2; i <= len; i++)
	{
		j = tail;
		reverseLen = 0;
		while ((j >= 0) && (j - 1 >= 0) && (list[j - 1] >= list[j]))
		{
			j--;
			reverseLen++;
		}
		reverseLen++;
		index1 = j-1;
		j = tail;
		while ((list[j] <= list[index1]))
		{
			j--;
		}
		index2 = j;
		swap(&list[index1],&list[index2]);
		reverse(list+index1+1,reverseLen);

		//printf("%d  =====%s \n", i, list);
		if (i == k)
		{
			//return list;
			break;
		}
	}
	return list;
}
char* getPermutation1(int n, int k) {
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
	int len = 1, i = 0;
	for (i = 1; i <= n; i++)
	{
		len = len*i;
	}
	if (k > len)
	{
		return NULL;
	}
	char*list = (char*)malloc((n + 1)*sizeof(char));

	for (i = 0; i < n; i++)
	{
		list[i] = i + '0' + 1;
	}
	list[i] = '\0';
	int m = n - 1;
	char* result = traverse1(list, n, k);
	//result[n] = '\0';
	return result;

}
char* getPermutation2(int n, int k) {
	//��lehmer��������
	//http://blog.csdn.net/chen895281773/article/details/12357703
	//http://www.cnblogs.com/friends-wf/p/3676848.html
	int *factor = (int*)malloc((n+1)*sizeof(int));
	int len = 1,j, i = 0;
	factor[0] = 1;
	for (i = 1; i <= n; i++)
	{
		factor[i] = factor[i - 1] * i;
	}
	bool* visited = (bool *)malloc(10 * sizeof(bool));
	for (i = 0; i < 10; i++)
		visited[i] = false;

	k--; //��Ϊ�±��Ǵ�0��ʼ��
	int code;
	char*list = (char*)malloc((n + 1)*sizeof(char));
	int current = 0;
	int resultIndex = 0;
	for (i = n-1; i >=0; i--)
	{
		code = k / factor[i];
		k = k%factor[i];
		// code �ǵ�ǰά���� 1-9����������±�
		current = 0;
		for (j = 0; j < 9; j++)
		{
			if (!visited[j])
			{
				current++;
			}
			if (current == (code+1))
			{
				visited[j] = true;
				break;
			}
		}
		list[resultIndex++] = j+'1';
	}
	list[n] = '\0';
	return list;
}
int main()
{
	int list[3] = {1,2,3};
	char* result=getPermutation2(4,6);
	//Perm(list, 0, 2);
	printf("%s \n", result);
	system("pause");
	return 0;
}
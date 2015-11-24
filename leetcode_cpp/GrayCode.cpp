/*
time   :  2015-5-15
author :  ht
comment:  ����һ��n���������ɵĶ��������
*/

#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

/*
 *��������ָ n��bit �������ֵ�����ֻ��һλ����ͬ
 *����  n =2;
 * 00 -> 01 -> 11 -> 10
 * http://baike.haosou.com/doc/3793519-3984486.html
 * һ��ģ���ͨ�����������������԰����·�������ת����

	��������->�����루���룩�������ұ�һλ�����ν�ÿһλ�����һλ���XOR����
	��Ϊ��Ӧ�������λ��ֵ�������һλ���䣨�൱�������0����

	������-���������루���룩������ߵڶ�λ�𣬽�ÿλ�����һλ������ֵ���
	��Ϊ��λ������ֵ�������һλ��Ȼ���䣩��
 */
int* grayCode(int n, int* returnSize) {
	//if (n <= 0)
		//return NULL;
	int len = pow(2, n);  //�������ɵ����еĳ���
	int* result = (int*)malloc(len*sizeof(int));
	int i, j;
	int index1, index2,mark1,mark2;
	//int standard = (len-1)>>1;
	int temp;
	//printf("%d \n", standard);
	for (i = 0; i < len; i++)
	{
		temp = 0;  //���ڴ洢���Ľ��
		index1 = 1;
		index2 = 2;
		for (j = 0; j < n; j++)
		{
			mark1 = index1&i; //ȡ��j��λ�� ���磬0101��ȡ�ڶ�λ���־��� 0100
			mark2 = index2&i; //ȡ��j+1��λ��
			mark2 = mark2 >> 1;//����һλ ��mark1����
			temp = temp|(mark1^mark2);  //mark1��mark2 ��һ��  �ӵ�temp��

			index2 = index2 << 1;  //index2 ����һλ
			index1 = index1 << 1;
		}
		//printf("%d \n",temp);
		result[i] = temp;
	}
	returnSize[0] = len;
	return result;
}

int main()
{
	int *result = NULL;
	int n = 3;
	int returnSize = 0;
	result = grayCode(n, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d\n",result[i]);
	}
	return 0;
}
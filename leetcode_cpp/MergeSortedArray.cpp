#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

void merge(int* nums1, int m, int* nums2, int n) {
	//�����ܿӣ�ԭ��û�и����е����ǵ������ǵݼ���
	//�����ύ��ʱ��ò���Զ�ȷ��Ϊ������
	//�����и���֧�Ͳ���д��
	int len = m + n;
	int * myNum = (int *)malloc(len*sizeof(int));
	int i = 0;
	int index1 = 0, come1 = nums1[0];
	int index2 = 0, come2 = nums2[0];
	bool flag = true;
	if (nums1[0] > nums1[1])
	{
		//flag = true;
	}
	if (flag)
	{    // ������
		while (index1<m && index2<n)
		{
			come1 = nums1[index1];
			come2 = nums2[index2];
			if (come1 > come2)
			{
				myNum[i] = come2;
				index2++;
			}
			else
			{
				myNum[i] = come1;
				index1++;
			}
			i++;
		}
	}
	else
	{
		//�ݼ���   ����ط�û�б�Ҫд
		/*
		while (index1<m && index2<n)
		{
			come1 = nums1[index1];
			come2 = nums2[index2];
			if (come1 > come2)
			{
				myNum[i] = come1;
				index1++;
			}
			else
			{
				myNum[i] = come2;
				index2++;
			}
			i++;
		}
		*/
	}
	//�����Ǹ����л�ʣ�࣬ʣ���ȫ������ȥ
	if (n != index2)
	{
		while (i < (m + n))
		{
			myNum[i] = nums2[index2];
			index2++;
			i++;
		}
	}
	if (m != index1)
	{
		while (i < (m + n))
		{
			myNum[i] = nums1[index1];
			index1++;
			i++;
		}
	}

	for (i = 0; i < len; i++)
	{
		printf("%d  ", myNum[i]);
	}
	printf("\n");
	//memcpy(nums1, myNum, (m + n)*sizeof(int));
}

int main()
{
	int nums1[5] = { 1,0,7,4,2 };
	int m = 5;
	int n = 4;
	int nums2[4] = {2, 1, 1, 9 };
	merge(nums1, 1, nums2, 1);
	return 0;
}
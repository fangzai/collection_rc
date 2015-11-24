/*
time   :  2015-5-18
author :  ht
comment:  ��һ������֮��������������Ƕ�̬�滮
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int maxArea(int* height, int heightSize) {
	int i, j;
	int width;
	int area = INT_MIN,min;
	int ps, pe;
	for (i = 0; i < heightSize; i++)
	{
		for (j = i + 1; j < heightSize; j++)
		{
			width = j - i;
			min = height[i]>height[j] ? height[j] : height[i];
			int tmp = width*min;
			if (area < tmp)
			{
				ps = i;
				pe = j;
				area = tmp;
			}

		}
	}
	printf("%d  ->   %d \n", ps,pe);
	return area;
}
int myMin(int a,int b)
{
	return a>b ? b : a;
}
int myMax(int a, int b)
{
	return a>b ? a : b;
}
/*
 * ���ȼ��������ҵ���ȡ����ݻ�������Ϊ i , j (�ٶ�i<j)����ô�õ�������ݻ� C = min( ai , aj ) * ( j- i) ��
 * �� j ���Ҷ�û��һ���߻�����ߣ� ������� k |( j<k && ak > aj) ����ô  �� ak> aj������ 
 * min( ai,aj, ak) =min(ai,aj) ��������i, k���ɵ��������ݻ�C' = min(ai,aj ) * ( k-i) > C����C����ֵì�ܣ����Ե�֤j�ĺ�߲����б������ߵ��ߣ�
 *
 * ͬ����i����˲�����һ���߱�����
 */
int maxArea1(int* height, int heightSize) {
	if (heightSize <= 1)
	{
		return 0;
	}
	int  result = 0;
	int ps = 0, pe = heightSize-1;
	while (ps < pe)
	{
		int temp = myMin(height[ps], height[pe])*(pe - ps);
		result = myMax(result,temp);
		//�ӽ�С�ı߿�ʼ����
		if (height[ps] < height[pe])
		{
			// ��ps���ұ߱���һ����  ps�ߵ���
			int k = ps;
			while ((k < pe) && (height[k] <= height[ps]))
			{
				k++;
			}
			ps = k;
		}
		else
		{
			// ��pe�������һ����  pe�ߵ���
			int k = pe;
			while ((k > ps) && (height[k] <= height[pe]))
			{
				k--;
			}
			pe = k;
		}
	}
	return result;

}

int main()
{
	//int nums[10] = { 2, 1, 2, 4, 2, 3, 5, 8, 4 };
	int nums[10] = {2,3,10,5,7,8,9};
	int numSize = 7;
	printf("%d \n", maxArea(nums, numSize));

	printf("%d \n", maxArea1(nums, numSize));
	return 0;
}
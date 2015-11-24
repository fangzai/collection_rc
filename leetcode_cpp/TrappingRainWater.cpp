/*
time   :  2015-5-18
author :  ht
comment:  ���ܹ���������ˮ��
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
 * ���⻹��һ��˼·������ѭ������ps�Ƿ�ֵ��ʱ����Ҳ�������С����
 * ���ʱ�����ó�������ɨһ�飬�����������������
 */
int trap(int* height, int heightSize) {

	if (heightSize <= 1)
	{
		return 0;
	}
	int ps, pe;
	int result = 0;
	int i, j;
	int min = 0,start,end;


	ps = 0;
	pe = 1;
	int te = 0, tmp = 0;

	bool mark = false;  //mark��ʾ���������ұ߱ȵ�ǰ��ֵ��ѭ��
	while (ps < heightSize&&pe < heightSize)
	{
		mark = false;
		while (pe<heightSize&&height[pe] < height[ps])
		{
			if (!mark)
			{
				mark = true;
				tmp = height[pe];  //��������ڼ�¼��ǰֵ�ұߵ�һ��ֵ��index�� ��С
				te = pe;
			}
			else
			{
				if (height[pe] > tmp)
				{
					// �ٴ�ѭ����ʱ�򣬰ѵ����ڶ�����ҵ�
					te = pe;
					tmp = height[pe];
				}
			}
			pe++;
		}
		if (pe == heightSize)
		{
			//û���ҵ���height[ps]��ģ��Ǿ��ҵ����ڶ����
			ps++;  //ps����Ųһλ����Ϊ��ǰ��peû������
			pe = te;
			
			start = ps;
			end = pe-1;   //����ط���end���԰���pe��Ҳ���Բ���pe����Ϊpe���Ǳ�׼ֵ
			min = height[pe]; //�����ڶ�����Ǳ�׼ֵ
			//���������֧  ��Ҫ�õĲ��Լ��� ��nums={4,2,3};
		}
		else
		{
			start = ps;
			end = pe - 1;
			min = height[ps]; //��ǰps�Ǳ�׼ֵ����Ϊ�ҵ��˱������ֵ
		} 

		//����ۼ�
		for (i = start; i <= end; i++)
		{
			result += min - height[i];
		}
		ps = pe;
		pe++;


		//����Ĵ�������滻�����if��䣬������������Ӿ���һЩ
		//if (pe == heightSize)
		//{
		//	//û���ҵ���height[ps]��ģ��Ǿ��ҵ����ڶ����
		//	ps++;  //ps����Ųһλ����Ϊ��ǰ��peû������
		//	pe = te;
		//	
		//	start = ps;
		//	end = pe-1;   //����ط���end���԰���pe��Ҳ���Բ���pe����Ϊpe���Ǳ�׼ֵ
		//	for (i = start; i <= end; i++)
		//	{
		//		result += height[pe] - height[i];
		//	}
		//	ps = pe;
		//	pe++;
		//}
		//else
		//{
		//	start = ps;
		//	end = pe - 1;
		//	for (i = start; i <= end; i++)
		//	{
		//		result += height[ps] - height[i];
		//	}
		//	ps = pe;
		//	pe++;
		//}

	}
	return result;
}

int main()
{
	//int nums[12] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int nums[12] = {4,2,3};
	int numSize = 2;
	printf("%d \n", trap(nums, numSize));
	return 0;
}
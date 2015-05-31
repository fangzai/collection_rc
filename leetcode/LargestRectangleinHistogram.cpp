/*
time   :  2015-5-26
author :  ht
comment:  ��histogramͼ���������������
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
 * �ðɣ��ұ�ʾ�����㷨�����벻������ֻ���ñ��������ķ���
 */
class Solution {
public:
	int largestRectangleArea(vector<int>& height) {

		return traverse(height);
	}
	int traverse(vector<int>& height)
	{
		//ʹ��ջ �����㷨
		height.push_back(0);//��height�������һ��0Ԫ�أ���Ϊ�߽��ж�
		stack<int> myStack;
		int i = 0;
		int maxArea = 0;
		int len = height.size();
		while (i < len)
		{
			if (myStack.empty() || (height[myStack.top()] <= height[i]))
			{
				//�����һ����ջ�����ߺ��浯ջ���topС�ڵ���iָ��Ԫ��
				//��ô�Ͳ����ٵ�ջ��
				myStack.push(i);
				i++;
			}
			else
			{
				//��ʼ�ѽϴ�Ԫ�ص�����
				int index = myStack.top();
				myStack.pop(); //ȡ��ջ��
				//�������
				int width = 0;
				if (myStack.empty())
				{
					width = i;
				}
				else
				{
					width = i - myStack.top()-1;
				}
				maxArea = myMax(maxArea,height[index]*width);
			}
		}
		return maxArea;

	}
	int myMax(int a,int b)
	{
		return a > b ? a : b;
	}
	int traverse1(vector<int>& height)
	{
		//���������ķ���
		//��ʱ
		int len = height.size();
		int i, j;
		int largestAera = 0;
		int area = 0;
		for (i = 0; i < len; i++)
		{
			area = 0;
			int low = height[i];
			for (j = i; j < len; j++)
			{
				if (height[j] < low) low = height[j];

				area = (j - i + 1)*low;
				if (area>largestAera) largestAera = area;
			}
		}
		return largestAera;
	}
};

int main()
{
	vector<int>height = { 2, 1, 5, 6, 2, 3 };
	Solution mine;
	int result;
	result = mine.largestRectangleArea(height);
	cout << result << endl;
	return 0;
}
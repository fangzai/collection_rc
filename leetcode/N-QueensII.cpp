/*
time   :  2015-5-25
author :  ht
comment:  N�ʺ����⣬�����ж���һ��board��
		 �κ������ʺ�����ͬһ�С�ͬһ�У�Ҳ������б�Խ���
		 
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


/*
 * �����ĸ�������ͱ���һ����ex51�򵥶���
 */
class Solution {
public:
	int result;
	int totalNQueens(int n) {
		result = 0;
		if (n <= 0)
			return result;
		vector<int>queen(n, -1);//���������е�Ԫ�ض���-1
		int index = 0;
		traverse(queen, index);
		return result;
	}
	void traverse(vector<int>&queen, int index)
	{
		//queen[i]��ʾ��i��  �ʺ��λ��
		int len = queen.size();
		int i = 0;
		//index��ʾ���ڸô�ڼ����ʺ���
		if ((index + 1) == len)
		{
			//�˳����������һ���ʺ��Ƿ��ܹ�����
			bool mark = false;
			for (i = 0; i < len; i++)
			{
				if (!conflict(queen, index, i))
				{
					//�ҵ�����
					queen[index] = i;
					result++;
					break;
				}
			}
		}
		else
		{
			bool mark = false;
			for (i = 0; i < len; i++)
			{
				mark = conflict(queen, index, i);
				if (!mark)
				{
					queen[index] = i; //��index�е�Q���� i����
					traverse(queen, index + 1); //������һ���ʺ��λ��
				}
			}
		}
	}
	bool conflict(vector<int>queen, int index, int col)
	{
		//index��ʾ����
		//col ��ʾ������
		//�ж������index�з��ڵ�col���Ƿ��ͻ
		int i = 0;
		int dis1, dis2, dis3, dis4;
		for (i = 0; i <index; i++)
		{
			//������ʼ��ʱ���ж�����д���ˣ�����������
			//ע�������һ��һ����ȷ�Ĺ���
			//dis1 = i - queen[i];
			//dis2 = index - col;
			//dis3 = i + queen[i];
			//dis4 = index + col;
			//if (dis2 == dis1||col==queen[i]||dis3==dis4)
			//	return true;
			dis1 = abs(i - index);
			dis2 = abs(queen[i] - col);

			if (dis2 == dis1 || col == queen[i])
				return true;
		}
		return false;
	}
};

int main()
{
	int n = 4;
	Solution mine;
	int result;
	result = mine.totalNQueens(n);
	//cout << result.size() << endl;
	
	cout << result<< endl;

	return 0;
}
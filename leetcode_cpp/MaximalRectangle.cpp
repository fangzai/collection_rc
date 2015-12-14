/*
time   :  2015-5-26
author :  ht
comment:  �������ܹ���Χ1�ַ��ľ���
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int result = traverse(matrix);
		return result;
	}
	int maximalRectangle2(vector<vector<char>>& matrix)
	{
		//�ڵڶ���˼·��һ������dp[i][j]����ʾ�ڵ�j�У�i���ǰ��������1�ĸ���
		//��ʵ�������Ǹ�n^3��˼·������һ����
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		int i, j;
		vector<int>tmp(n, 0);
		vector<vector<int>>dp(m, tmp);
		for (j = 0; j < n; j++)
			dp[0][j] = (matrix[0][j] == '1') ? 1 : 0; //�����һ��
		for (i = 1; i < m; i++)
			for (j = 0; j < n; j++)
				dp[i][j] = (matrix[i][j] == '1') ? dp[i-1][j] + 1 : 0;  //����Ĺ�ʽ����

		int maxRec = 0,tmpRec;
		for (i = 0; i < m; i++)
		{
			//����m��
			tmpRec = largestRec(dp[i]);
			maxRec = myMax(maxRec,tmpRec);
		}

		return maxRec;

	}
	int largestRec(vector<int>& height)
	{
		//ex84��histogram���������ĺ���
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
					width = i - myStack.top() - 1;
				}
				maxArea = myMax(maxArea, height[index] * width);
			}
		}
		return maxArea;

	}
	int maximalRectangle1(vector<vector<char>>& matrix)
	{
		//��һ��˼·��һ������dp[i][j]����ʾ�ڵ�i�У�j���ǰ��������1�ĸ���
		// ������i,jΪ���½ǵľ���
		//ò�Ƴ�ʱ��
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		int i, j;
		vector<int>tmp(n,0);
		vector<vector<int>>dp(m,tmp);
		for (i = 0; i < m; i++)
			dp[i][0] = (matrix[i][0] == '1') ? 1 : 0; //�����һ��
		for (i = 0; i < m; i++)
			for (j = 1; j < n; j++)
				dp[i][j] = (matrix[i][j] == '1') ? dp[i][j - 1] + 1:0;  //����Ĺ�ʽ����
		
		int result = 0;
		int k = 0;
		for (i = 0; i < m; i++)
		{
			for (j = 1; j < n; j++)
			{
				k = i;
				int width = INT_MAX;
				while (k>=0)
				{
					//�ӵ�i�����ϼ���
					if (dp[k][j] == 0) break;
					width = myMin(width,dp[k][j]);
					result = myMax(result,width*(i-k+1));
				}
			}
		}
		return result;
		
	}
	int myMin(int a,int b)
	{
		return a>b ? b : a;
	}
	int myMax(int a, int b)
	{
		return a>b ? a : b;
	}
	int traverse(vector<vector<char>> matrix)
	{
		//�Ҳ�����Ŀ�����ˣ���Ҫ��һ������ȫ��1��������
		//������������ǰ������е�1����С��������
		int m = matrix.size();
		int n = matrix[0].size();
		string tmp(n, '0');
		int i, j;
		int startY = 0,startX=0;
		int endY = 0, endX = 0;
		int count1 = 0;
		bool mark = false;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1')
				{
					startY = i;
					mark = true;
					break;
				}
			}
			if (mark)
				break;
		}
		if (!mark)
			startY = m;

		mark = false;
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < m; i++)
			{
				if (matrix[i][j] == '1')
				{
					startX = j;
					mark = true;
					break;
				}
			}
			if (mark)
				break;
		}
		if (!mark)
			startX = n;

		mark = false;
		for (i = m-1; i >=0; i--)
		{
			for (j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1')
				{
					endY = i;
					mark = true;
					break;
				}
			}
			if (mark)
				break;
		}
		if (!mark)
			endY = 0;

		mark = false;
		for (j = n-1; j >= 0; j--)
		{
			for (i = 0; i < m; i++)
			{
				if (matrix[i][j] == '1')
				{
					endX = j;
					mark = true;
					break;
				}
			}
			if (mark)
				break;
		}
		if (!mark)
			endX = 0;

		if (endY >= startY)
		{
			int width = endY - startY+1;
			int height = endX - startX+1;
			return width*height;
		}
		else
		{
			return 0;
		}
	}
};

int main()
{
	vector<string>str = { "000000",
		                  "000100",
						  "000100",
						 };
	vector<vector<char>> matrix(str.size());
	int len = str.size();
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < str[i].length(); j++)
		{
			matrix[i].push_back(str[i][j]);
		}
	}
	Solution mine;
	int result;
	result = mine.maximalRectangle(matrix);
	cout << result << endl;
	return 0;
}
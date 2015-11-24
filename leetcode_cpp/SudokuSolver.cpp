/*
time   :  2015-5-26
author :  ht
comment:  sodoku solver  ���������Ź���
*/
#include<iostream>
#include<vector>

using namespace std;
/*
*�հ׵Ĳ������Ǹ���.�����
*����
*	   1. ÿһ��1-9ÿ�����ֵĴ������ܳ���1��
*	   2. ÿһ��1-9ÿ�����ֵĴ������ܳ���1��
*	   3. ÿһ��3*3�ĸ���1-9ÿ�����ֵĴ������ܳ���1��
*����������������ȱ�������Ҫע��ľ�������˳���ʱ��һ��Ҫ�ѽ������Ҫ����
*/
class Solution {
public:
	char sep = '.';
	vector<vector<char>>result;
	void solveSudoku(vector<vector<char>>& board) {
		int startX = 0;
		int startY = 0;
		traverse(board,startX,startY);
		board = result;
	}
	void traverse(vector<vector<char>>& board,int x,int y)
	{
		int n = board.size();
		if (board[x][y] == sep)
		{
			for (int k = 0; k < n; k++)
			{
				if (isValidSudoku(board, x, y, k+1))
				{
					board[x][y] = k + '1';
					if ((y+1) < n)
					{
						traverse(board, x, y+1);
						board[x][y] = sep;
					}
					else
					{
						
						if (x == (n - 1) && y == (n - 1))
						{
							//һ��Ҫ��¼һ�½��������Ϳӵ���
							result = board;
							return;
						}
						else
						{
							int tmp = 0;
							traverse(board, x + 1, tmp);
							board[x][y] = sep;
						}

					}
					
				}
			}
		}
		else
		{
			if ((y + 1) < n)
			{
				traverse(board, x, y + 1);
			}
			else
			{
				if (x == (n - 1) && y == (n - 1))
				{
					//һ��Ҫ��¼һ�½��������Ϳӵ���
					result = board;
					return;
				}
				else
				{
					int tmp = 0;
					traverse(board, x + 1, tmp);
				}

			}
		}

	}
	bool isValidSudoku(vector<vector<char>>board,int x,int y,int label)
	{
		int m = board.size();
		int n = board[0].size();
		int i, j;

		vector<int>mem(10, 0);
		vector<int>hashDock(10, 0);
		int value = 0;

		//��֤��x��
		hashDock = mem;
		hashDock[label]++;
		for (i = 0; i < n; i++)
		{
			if (board[x][i] != sep)
			{
				value = board[x][i] - '0';
				hashDock[value]++;
				if (hashDock[value] >= 2)
					return false;
			}
		}
		//��֤��
		hashDock = mem;
		hashDock[label]++;
		for (i = 0; i < m; i++)
		{
			if (board[i][y] != sep)
			{
				value = board[i][y] - '0';
				hashDock[value]++;
				if (hashDock[value] >= 2)
					return false;
			}
		}
		
		//��֤�����ڵ�С��
		hashDock = mem;
		hashDock[label]++;
		int num = 3;
		int numX = x / 3;
		int numY = y / 3;
		int startX = numX * 3;
		int startY = numY * 3;
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
			{
				if (board[i + startX][j + startY] != sep)
				{
					value = board[i + startX][j + startY] - '0';
					hashDock[value]++;
					if (hashDock[value] >= 2)
						return false;
				}
			}
		}
		return true;
	}
};
int main()
{
	char * str[9] = {
	"53..7....",
	"6..195...",
	".98....6.",
	"8...6...3",
	"4..8.3..1",
	"7...2...6",
	".6....28.",
	"...419..5",
	"....8..79",
	};
	

	//char * str[9] = {
	//	"..4...63.",
	//	".........",
	//	"5......9.",
	//	"...56....",
	//	"4.3.....1",
	//	"...7.....",
	//	"...5.....",
	//	".........",
	//	"........."
	//};
	int n = 9;
	vector<char>tmp(n,'.');
	vector<vector<char>>board(n,tmp);
	
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			board[i][j] = str[i][j];

	Solution mine;
	mine.solveSudoku(board);
	return 0;
}
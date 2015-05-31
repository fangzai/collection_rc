/*
time   :  2015-5-10
author :  ht
comment:  valid sodoku ���ǿ��Ǹ�puzzle world�ǲ��ǶԵ�
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
/*
 *�հ׵Ĳ������Ǹ���.�����
 *����
 *	   1. ÿһ��1-9ÿ�����ֵĴ������ܳ���1��
 *	   2. ÿһ��1-9ÿ�����ֵĴ������ܳ���1��
 *	   3. ÿһ��3*3�ĸ���1-9ÿ�����ֵĴ������ܳ���1��
 */
bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
	
	int m = boardColSize;
	int n = boardRowSize;
	int num = 3;
	int i, j;
	char sep = '.';
	int mem[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int hashDock[10];
	int value = 0;
	for (i = 0; i < m; i++)
	{
		memcpy(hashDock, mem, 10 * sizeof(int));
		for (j = 0; j < n; j++)
		{
			//printf("%c ", board[i][j]);
			if (board[i][j] != sep)
			{
				value = board[i][j] - '0';
				hashDock[value]++;
				if (hashDock[value] >= 2)
				{
					return false;
				}
			}

		}
		//printf("\n");
	}
	for (i = 0; i < n; i++)
	{
		memcpy(hashDock, mem, 10 * sizeof(int));
		for (j = 0; j < m; j++)
		{
			//printf("%c ", board[i][j]);
			if (board[j][i] != sep)
			{
				value = board[j][i] - '0';
				hashDock[value]++;
				if (hashDock[value] >= 2)
				{
					return false;
				}
			}

		}
		//printf("\n");
	}
	int start,end,k = 0,f=0;
	for (i = 0; i < m; i+=num)
	{
		for (j = 0; j < n; j += num)
		{
			//start = 
			memcpy(hashDock, mem, 10 * sizeof(int));
			for (k = i; k < i + num; k++)
			{
				for (f = j; f < j + num; f++)
				{
					if (board[k][f] != sep)
					{
						value = board[k][f] - '0';
						hashDock[value]++;
						if (hashDock[value] >= 2)
						{
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}
int main()
{ 
	/*
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
	*/

	char * str[9] = {
					"..4...63.",
					".........", 
					"5......9.",
					"...56....",
					"4.3.....1",
					"...7.....", 
					"...5.....",
					".........",
					"........."
					};
	if (isValidSudoku(str, 9, 9))
	{
		printf("is Valid Sudoku\n");
	}
	else
	{
		printf("Not Valid Sudoku\n");
	}
	return 0;
}
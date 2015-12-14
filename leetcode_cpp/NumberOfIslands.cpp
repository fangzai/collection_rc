/*
time   :  2015-5-24
author :  ht
comment:  �����������ͨ����ĸ���
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*  
 * ��ǰû�����������⣬�����о��Ͽ�������ȱ�������
 * �ο����ϵ�ȷʵ���ֽⷨ��ÿ�α�������ͰѾ����ĵ�Ĩ��
 */
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size()<=0 || grid[0].size()<=0)
			return 0;
		int m = grid.size();
		int n = grid[0].size();
		int count = 0; //����������
		int i, j;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (grid[i][j] == '1')
				{
					traverse(grid,i,j);
					count++;
				}
			}
		}
		return count;
	}
	void traverse(vector<vector<char>>& grid,int x,int y)
	{
		if (x >= 0 && y >= 0  && x < grid.size()&& y < grid[0].size()&&grid[x][y]=='1')
		{
			grid[x][y] = '0';
			traverse(grid, x - 1, y);  //left
			traverse(grid, x + 1, y);  //right
			traverse(grid, x, y-1);  // up
			traverse(grid, x, y+1);  //down
		}
	}
};

int main()
{
	/*vector<vector<char>> grid = { { '1', '1', '1', '1', '0' }, 
								  { '1', '1', '0', '1', '0' },
								  { '1', '1', '0', '0', '0' },
								  { '0', '0', '0', '0', '0' } };
	*/
	vector<vector<char>> grid = { { '1', '1', '0', '0', '0' }, 
								  { '1', '1', '0', '1', '0' },
								  { '1', '1', '0', '0', '0' },
								  { '0', '0', '0', '1', '1' } };
	Solution mine;
	int result;
	result = mine.numIslands(grid);
	cout << result << endl;
	return 0;
}
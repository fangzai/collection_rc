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


class Solution {
public:
	vector<vector<string>> result;
	vector<vector<string> > solveNQueens(int n) {
		if (n <= 0)
			return result;
		vector<int>queen(n, -1);//���������е�Ԫ�ض���-1
		result.clear();
		int index = 0;
		traverse(queen,index);
		return result;
	}
	void traverse(vector<int>&queen,int index)
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
					mark = true;
					break;
				}
			}
			//�������ս��
			if (mark)
			{
				string str(len, '.');
				vector<string>res;
				for (i = 0; i < len; i++)
				{
					res.push_back(str);
					res[i][queen[i]] = 'Q';
				}
				result.push_back(res);
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
	bool conflict(vector<int>queen,int index,int col)
	{
		//index��ʾ����
		//col ��ʾ������
		//�ж������index�з��ڵ�col���Ƿ��ͻ
		int i = 0;
		int dis1, dis2,dis3,dis4;
		for (i = 0; i <index;i++)
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

			if (dis2 == dis1||col==queen[i])
				return true;
		}
		return false;
	}
};
/*
 * 
 *дһ��N�ʺ�����ķǵݹ��
 */
class Solution1 {
public:
	vector<vector<string>> result;
	vector<vector<string> > solveNQueens(int n) {
		if (n <= 0)
			return result;
		vector<int>queen(n,-1);
		traverse(queen);
		return result;
	}
	void traverse(vector<int>queen)
	{
		int i, j;
		i = 0; //��ʾ�ŵĻʺ���±�
		j = 0; //��ʾ�ŵ����±�
		int len = queen.size();
		bool mark = false;
		
		int k = 0;  //��һ���ʺ���n�ֿ���
		for (k = 0; k < len; k++)
		{
			mark = conflict(queen, 0, k);  //��һ���ʺ����(0,k)λ��
			if (!mark)
			{
				queen[0] = k;
				j = 0;
				i = 1;
				while (j < len&&i<len)
				{
					mark = conflict(queen, i, j);
					if (!mark)
					{
						//����ͻ   
						queen[i] = j;
						i++;
						j = 0;
						if (i == len)
						{
							//�ҵ���
							string str(len, '.');
							vector<string>res;
							for (int ii = 0; ii < len; ii++)
							{
								res.push_back(str);
								res[ii][queen[ii]] = 'Q';
							}
							result.push_back(res);
						}
						//break;
					}
					else
					{
						j++;
					}
				}
			}
			//��һ���ʺ��λ�ü�������Ų
		}

	
	}
	bool conflict(vector<int>queen, int index, int col)
	{
		//index��ʾ����
		//col ��ʾ������
		//�ж������index�з��ڵ�col���Ƿ��ͻ
		int i = 0;
		int dis1, dis2;
		for (i = 0; i <index; i++)
		{
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
	Solution1 mine;
	vector<vector<string>> result;
	result = mine.solveNQueens(n);
	//cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout <<"=========================="<<endl;
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << endl;
	}
	return 0;
}
/*
time   :  2015-5-28
author :  ht
comment:  ���������������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {

		bool result;
		result = traverse(s1, s2);
		return result;
	}

	bool traverse(string s1, string s2)
	{
		//��̬�滮Ҳ��һ���� ��һ������ dp[k][i][j]
		//�ڶ�ά i��ʾs1�������i,����άj��ʾ s2�����
		//�ڶ�ά�ȱ�ʾ����k����scramble��
		int len = s1.size();
		vector<vector<bool>>tmp(len, vector<bool>(len,false));
		vector<vector<vector<bool>>> dp(len,tmp);
		int i, j, k;
		for (i = 0; i < len; i++)
			for (j = 0; j < len; j++)
				dp[0][i][j] = (s1[i]==s2[j]); //�����ȵĻ������Զ�scramble��
		for (k = 2; k <= len; k++)
		{
			//ѭ������ĳ���
			for (i = len - k; i >= 0; i--)
			{
				for (j = len - k; j >= 0; j--)
				{
					bool res = false; 
					for (int m = 1; m < k&&!res; m++)
					{
						//ֻҪr��һ��Ϊtrue�ģ���ô����trueֱ���˳���
						//����Ҳ�ǽ��ַ��ֳ������֣�m����ǰ�벿�ֵĸ���
						bool part1 = dp[m - 1][i][j] && dp[k - m - 1][i + m][j+m];
						// i,j���� m-1ƥ�� ����i+m ����k-m-1��  �� j+m����k-m-1��ƥ��
						bool part2 = dp[m - 1][i][j + k - m] && dp[k - m - 1][i + m][j];
						// i,j+k-m���� m-1ƥ�� ����i+m ����k-m-1��  �� j����k-m-1��ƥ��

						//��һ���ֺ͵ݹ���һ����
						res = part1 || part2;
					}
					dp[k-1][i][j] = res; //����ط��ĵ�һά���±�Ӧ�� -1
				}
			}
		}
		return dp[len - 1][0][0];

	}

	//�ݹ�ķ�����˼·�ͱȽϼ���
	//��������س�ʱ�ˣ�ʱ�临�Ӷ�ò����3^n
	bool recursive(string s1, string s2)
	{
		/*
		 * ��s1���±� i�ֿ��� ǰ�벿����  0~i  ��벿����i ~len-i
		 * ������������� s11 0~i s21 0~i ���� s12 s22 scramble
		 * ���� s11 s22  ���� s12 s21 scramble
		 */
		if (s1.size() != s2.size()) return false;
		if (s1 == s2) return true;

		string tmp1 = s1;
		string tmp2 = s2;
		sort(tmp1.begin(),tmp1.end());  //����scramble��������s1��s2��������
		sort(tmp2.begin(), tmp2.end()); 

		if (tmp1 != tmp2)  //��������ȽϺ��Ȼ�͹���
			return false;
		for (int isep = 1; isep < s1.size(); ++isep) 
		{
			//seporate s1 as [0,isep - 1],[isep, s1.size() - 1]
			string seg11 = s1.substr(0, isep);
			string seg12 = s1.substr(isep);

			//see if forward order is ok
			string seg21 = s2.substr(0, isep);
			string seg22 = s2.substr(isep);
			if (isScramble(seg11, seg21) && isScramble(seg12, seg22)) 
				return true;
			
			//see if reverse order is ok
			seg21 = s2.substr(s2.size() - isep); //����ĳ���Ϊisep�ǲ���
			seg22 = s2.substr(0, s2.size() - isep); //
			if (isScramble(seg11, seg21) && isScramble(seg12, seg22)) return true;
			
		}
		return false;
	}
};

int main()
{
	string s1 ="rgtae" ;
	string s2 = "great";
	Solution mine;
	bool result;
	result = mine.isScramble(s1,s2);
	if (result)
		cout << "Is scramble!" << endl;
	else
		cout << "Not scramble!"<<endl;
	return 0;
}
/*
time   :  2015-5-28
author :  ht
comment:  ���ʱ任����̾�������
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
	/*
	 * ��Щ��Ŀ�����Ѱ�~~~~
	 *  DP Formulation: D[i,j]=min(D[i-1,j]+1,D[i,j-1]+1,D[i-1,j-1]+flag);//����if(s1[i]!=s2[j])��flag=2,else flag=0;
	 *  D[i,j]: the minimal edit distance for s1��ǰi���ַ��� s2��ǰj���ַ�
	 */
	int minDistance(string word1, string word2) {
		int len1 = word1.length();
		int len2 = word2.length();
		if (len1 == 0) return len2;
		if (len2 == 0) return len1;
		vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1));

		for (int i = 0; i <= len1; ++i) dp[i][0] = i;
		for (int j = 0; j <= len2; ++j) dp[0][j] = j;

		int cost;
		for (int i = 1; i <= len1; ++i) 
		{
			for (int j = 1; j <= len2; ++j)
			{
				cost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
				dp[i][j] = min(dp[i - 1][j - 1] + cost, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
			}
		}
		return dp[len1][len2];
	}
};
int main()
{
	string word1 = "a";
	string word2 = "a";
	Solution mine;
	int result = mine.minDistance(word1,word2);
	cout << result << endl;
	return 0;
}
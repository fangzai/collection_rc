/*
time   :  2015-5-21
author :  ht
comment:  �ֻ��������ֶ�Ӧ���ַ����
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.size() <= 0)
		{
			return result;
		}
		vector<string> myMap = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		
		result = traverse(digits,myMap);
		int len = result.size();
		for (int i = 0; i < len; i++)
		{
			reverse(result[i].begin(),result[i].end());
			//cout << i << "==========" << result[i] << endl;
		}
		return result;
	}
	vector<string>traverse(string digits,vector<string> myMap)
	{
		int len = digits.size();
		if (len <= 1)
		{
			//ֻʣһ����
			int num = digits[0] - '0';
			vector<string>result;
			string temp = myMap[num];
			int i;
			for (i = 0; i < temp.size(); i++)
			{
				result.push_back(temp.substr(i,1));
			}
			return result;
		}
		else
		{
			vector<string>result;
			vector<string>currentResult;
			int num = digits[0]-'0';  //ȡ����ǰ��һ������
			string temp = myMap[num];  //�浽temp����Ū
			int i;
			string sub = digits.substr(1,len-1);  //��ȡʣ�µ��ַ�
			currentResult = traverse(sub,myMap);
			if (temp.size() <= 0)
				return currentResult;  //���temp�ǿյĻ�,û�б�Ҫ�������ѭ����

			string mid;
			for (i = 0; i <temp.size(); i++)
			{
				for (int j = 0; j < currentResult.size(); j++)
				{
					mid = currentResult[j];
					mid.push_back(temp[i]);
					result.push_back(mid);  
					//����ط���ѹջ˳����ʵ���Ƿ��ģ��������ʱ��Ҫreverseһ��
				}	
			}
			return result;
		}
	}
};

int main()
{
	string digits = "0";
	Solution mine;
	vector<string> result =mine.letterCombinations(digits);
	//cout << result.size() << endl;
	int len = result.size();
	for (int i = 0; i < len; i++)
	{
		cout << i<<"=========="<<result[i] << endl;
	}
	return 0;
}
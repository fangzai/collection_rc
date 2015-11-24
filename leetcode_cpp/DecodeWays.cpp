/*
time   :  2015-5-23
author :  ht
comment:  ����������������ķ�������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	vector<bool>sign;  //���ڱ�Ǹõ��Ƿ�����и�
	int result;

	int numDecodings(string s) {
		/*
		 * �ö�̬�滮�ķ�ʽ��ps�ҵݹ�ķ�ʽҲ�������˼Ϊʲô�ᳬʱ�أ�����
		 * ways[i]��ʾ�Ե�ǰ�ַ���β�Ľ���ķ�ʽ
		 * �������  122
		 * ways[0] =1
		 * ways[1] = ways[0]+ways[-1] ,��ʵ����ط���way[-1]��ʾ�ľ��ǵ�ǰ�ַ���ǰһ���ַ���ϵõ�����
		 * ways[2] = ways[1]+ways[0]
		 * s[i-1]s[i]����ҪҪ��10~~26֮�䣬дһ��check�����Ϳ�����
		 * �����������Ļ�����
		 *  ways[i] = ways[i-1]+ways[i-2]  //��Ȼ��Ҫ���ǵ�ǰλ��ǡ����0�����
		 * �������101
		 * �ָʽֻ��1�־���10 ��1
		 */
		int len = s.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return check(s[0]);
		
		vector<int>ways(len,0);
		ways[0] = check(s[0]);
		ways[1] = (check(s[0]) & check(s[1])) + check(s[0], s[1]);
		int i = 0;
		for (i = 2; i < len; i++)
		{
			if (check(s[i]))
				ways[i] += ways[i - 1];//ֻ����һ���ַ�
			if (check(s[i-1], s[i]))  //if (check(s[i], s[i - 1]))  ��ʼ��ʱ��ߵ�λ�����
				ways[i] += ways[i - 2];
		}
		return ways[len - 1];
	}

	int check(char one)
	{
		return one == '0' ? 0 : 1;
	}
	int check(char one, char two)
	{
		return ((one == '1') || ((one == '2') && (two <= '6'))) ? 1 : 0;
	}
	int numDecodings1(string s) {
		//����ȵݹ�ķ�ʽ�ᳬʱ
		if (s.length() == 0)
			return 0;
		int start = 0;
		result = 0; 
		vector<bool>tmp(s.size(),false);
		sign = tmp;
		traverse(s,start);

		return result;
	}
	void traverse(string s,int index)
	{
		//��ʾ��ǰ�ָ��һ�����
		int len = s.size();
		if (index == len)
		{
			//�����ַ�������ĩ��λ����//Ҳ�����˳�����
			result++;
		}
		else
		{
			int i;
			string str;
			int num,range;
			for (i = index; i < len; i++)
			{
				range = i - index + 1;
				if (range >= 3)
					return;

				str = s.substr(index,range);
				if (str[0] == '0')
					return;
				if (range >= 2)
				{
					num = str[0] - '0';
					if (num >= 3)
						return;
				}
				num = str2int(str);
				if (num >= 1 && num <= 26)
				{
					sign[i] = true;
					traverse(s,i+1);
					sign[i] = false;
				}
			}
		}
	}
	int str2int(string s)
	{
		int len = s.size();
		int res = 0;
		for (int i = 0; i < len; i++)
		{
			res *= 10;
			res += s[i] - '0';
		}
		return res;
	}
};

int main()
{
	string code = "101";
	Solution mine;
	int result;
	result = mine.numDecodings(code);
	cout << result << endl;

	result = mine.numDecodings1(code);
	cout << result << endl;
	return 0;
}
/*
time   :  2015-5-22
author :  ht
comment:  ip��ַ�ַ��ķָ�
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<string> result;
	vector<bool>sign;
	vector<string> restoreIpAddresses(string s) {
		int len = s.size();
		if (len <= 3)
			return result;
		int start = 0,count =3;
		for (int i = 0; i < len; i++)
		{
			sign.push_back(false);
		}
		traverse(s,start,count);
		return result;
	}
	void traverse(string s, int index,int count)
	{
		// index ��ʾ��һ���и����ʼ��
		// count ��ʾ��ʣ����ٴ��и�
		// ������ȱ���
		int len = s.length();
		string temp;
		int num;
		if (count == 0)
		{
			//ʣ�µ��ַ�ȫ�������һ����
			temp = s.substr(index,len-index+1);
			if (temp[0] == '0'&&temp.size() > 1)
				return;  //�и��֮����ַ�����������0��ͷ�ҳ��ȴ���1�Ĵ�
			num = str2int(temp);
			string str;
			if (num >= 0 && num <= 255)
			{
				int start = 0;
				for (int i = 0; i < len; i++)
				{
					if (sign[i])
					{
						str.append(s.substr(start,i-start+1));
						str.append(".");
						start = i + 1;
					}
				}
				str.append(s.substr(start,len-start));
				result.push_back(str);
			}
			else
			{
				return;
			}
		}
		else
		{
			//len - count)����Ϊ������뱣�� count���и��
			for (int i = index; i < len - count; i++)
			{
				temp = s.substr(index,i-index+1);
				if (temp[0] == '0'&&temp.size() > 1)
					continue;
				num = str2int(temp);
				if (num >= 0 && num <= 255)
				{
					sign[i] = true;
					traverse(s,i+1,count-1);
					sign[i] = false;  //������֮���sign���ž�Ҫ����һ�£���������Ӱ����һ�α���
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
	//string str = "11112";
	//string str = "25525511135";
	string str = "010010";
	Solution mine;
	vector<string>result;
	result = mine.restoreIpAddresses(str);
	int i = 0;
	for (i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}
/*
time   :  2015-5-24
author :  ht
comment:  �ҳ����г��ֹ��������ϵ�10�����ַ���
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
	vector<string>result;
	map<string, int> myMap;
	map<unsigned int, int> textMap;
	vector<string> findRepeatedDnaSequences(string s) {
		traverse1(s);
		return result;
	}
	void traverse(string s)
	{
		//�������̫��������ʱ��
		//ò������Ϊ�ڴ治����ԭ��
		//���Ͼ���ţ�������ı任����
		//�Ǹ�map��key���治��string��ֱ�Ӵ�һ�����֣������ͺܽ�ʡ��
		int count = 10;
		int len;
		len = s.length();
		int i,index;
		string temp;
		for (i = 0; i < len - count; i++)
		{
			temp = s.substr(i,count);
			index = s.rfind(temp);
			if (index > i)
			{
				//˵�����ظ�
				if (!myMap.count(temp))
				{
					myMap.insert(pair<string,int>(temp,i));
					result.push_back(temp);
				}
			}
		}

	}
	unsigned int ten2Num(string str)
	{
		//A C G T  0 1 2 3
		int i = 0;
		int count = 10;
		unsigned int num = 0;
		unsigned int a;
		for (i = 0; i < count; i++)
		{
			switch (str[i])
			{
			case 'A': a = 0;
				break;
			case 'C': a = 1;
				break;
			case 'G': a = 2;
				break;
			case 'T': a = 3;
				break;
			default:
				break;
			}
			num *= 10;
			num += a;
		}

		return num;
	}
	void traverse1(string s)
	{
		//�ؼ�����ΰ�10���ַ���ѹ����һ�������أ�����
		//ͬ����˼�룬�Ұ�key���unsigned int���棬����ʱ���ϻ���̫����~~
		//�ѵ���ĵ���λ�������У�������
		int count = 10;
		int len;
		len = s.length();
		int i, index, exist;
		string temp;
		unsigned int mark = 0;
		for (i = 0; i < len - count+1; i++)
		{
			temp = s.substr(i, count);
			mark = ten2Num(temp);
			//û���������
			if (!textMap.count(mark))
			{
				textMap.insert(pair<unsigned int, int>(mark, i));
				textMap[mark]=1;
			}
			else
			{
				if(textMap[mark]==1)
					result.push_back(temp);
				textMap[mark]++;
				
			}
		}
	}
	unsigned int line(char s)
	{
		unsigned int a = 0;
		switch (s)
		{
		case 'A': a = 0;
			break;
		case 'C': a = 1;
			break;
		case 'G': a = 2;
			break;
		case 'T': a = 3;
			break;
		default:
			break;
		}
	}
	void traverse2(string s)
	{
		//�ؼ�����ΰ�10���ַ���ѹ����һ�������أ�����
		int count = 10;
		int len;
		len = s.length();
		int i, index, exist;
		string temp;
		unsigned int mark = 0, preMark = 0;;
		for (i = 0; i < len - count + 1; i++)
		{
			temp = s.substr(i, count);
			//index = s.rfind(temp);
			if (i == 0)
			{
				mark = ten2Num(temp);
			}
			else
			{
				unsigned int a = 0, b = 0;;
				a = line(s[i-1]);
				b = line(s[i+9]);
				mark = 10 * (preMark - a*pow(10, 9)) + b;
			}
			
			//û���������
			if (!textMap.count(mark))
			{
				textMap.insert(pair<unsigned int, int>(mark, i));
				textMap[mark] = 1;
			}
			else
			{
				if (textMap[mark] == 1)
					result.push_back(temp);
				textMap[mark]++;

			}
			preMark = mark;
		}
	}
};

int main()
{
	string DNApiece = "AAAAAAAAAAAA";
	vector<string>result;
	Solution mine;
	result = mine.findRepeatedDnaSequences(DNApiece);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}
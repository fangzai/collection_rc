/*
time   :  2015-5-29
author :  ht
comment:  ��һ�����������ƥ��
*/
#include<iostream>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
	/*
	 * �����ñ��������ķ���������������ɵ
	 * ˼����һ�£�һ�α����Ϳ�����ɣ���ջʵ�֣����û�б��������ľ��Ƿָ���
	 * ������һ�·ָ��ߵľ���Ϳ�����
	 * ��˵���⻹�����ö�̬�滮�����Ǹ�ȥ���ⶼ�У���
	 */
	int longestValidParentheses1(string s) {
		//��ջ��ʵ�֣�����һ�Σ�ÿ�ΰ��±�Ž�ȥ��һ��ƥ��Ͱ��±굯����
		//û�б��������ľ��Ƿָƥ����ַ����ŵ�
		int len = s.size();
		if (len < 2)
			return 0;
		int i;
		i = len - 1;
		stack<char>myStack;
		stack<int>indexStack;  //�洢�±������
		int count = 0;
		int maxLen = INT_MIN;
		while (i >= 0)
		{
			indexStack.push(i);
			if (s[i] == ')')
			{
				myStack.push(')');
			}
			else
			{
				//�����ǰ���ŵĻ�
				if (!myStack.empty())
				{
					myStack.pop();
					indexStack.pop();
					indexStack.pop();//һ��ƥ�䣬�Ͱ�������������
				}
				
			}
			i--;
		}
		maxLen = 0;
		len = indexStack.size();
		//�����±껹�ٱ�����������һ�����ַ���ĩβ��һ�����ַ�����ͷ
		if (indexStack.empty()) //���indexStackΪ�յĻ���˵��ȫ��ƥ��
		{
			return s.length();
		}

		int current;
		int previous = indexStack.top();
		if (previous != 0)
			maxLen = myMax(maxLen,previous); 
		//�����ͷ���Ƿָ��ߵĻ���˵����Ҫ�����0��ջ���±�ľ���


		for (i = 0; i < len; i++)
		{
			current = indexStack.top();
			indexStack.pop();
			maxLen = myMax(maxLen,current-previous-1);
			previous = current;
		}

		current = s.length();  //����һ�����һ�������index�� �ַ���ĩβ�ľ���
		maxLen = myMax(maxLen, current - previous - 1);


		return maxLen;
	}
	int myMax(int a,int b)
	{
		return a > b ? a : b;
	}
	int myMin(int a, int b)
	{
		return a > b ? b : a;
	}
	int longestValidParentheses(string s) {
		int len = s.size();
		if (len < 2)
			return 0;
		int i, j;
		bool mark;
		int maxLen = 0;
		int tmpLen = 0;
		for (i = 0; i < len; i++)
		{
			for (j = i + 1; j < len; j += 2)
			{
				string tmp = s.substr(i,j-i+1);
				tmpLen = tmp.size();
				mark = validParentheses(tmp);

				if (mark)
				{
					maxLen = maxLen>tmpLen ? maxLen : tmpLen;
				}

			}
		}
		return maxLen;
	}
	bool validParentheses(string s)
	{
		stack<char> myStack;
		int len = s.length();
		int i = len - 1;
		while (i >= 0)
		{
			if (s[i] == ')')
			{				
				i--;
				myStack.push(')');
			}
			else
			{
				if (myStack.empty())
					return false;
				else
				{
					myStack.pop();
					i--;
				}
					
			}
		}
		if (!myStack.empty())
			return false;
		else
			return true;
	}
};

int main()
{
	Solution mine;
	string s = "()(()(()";
	//bool mark = false;
	//mark = mine.validParentheses(s);
	//if (mark)
	//	cout << "Is valid parenttheses!" << endl;
	//else
	//	cout << "Not valid parenttheses!" << endl;

	int result;
	result = mine.longestValidParentheses1(s);
	cout << result << endl;
	return 0;
}
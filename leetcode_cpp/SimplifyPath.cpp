/*
time   :  2015-5-23
author :  ht
comment:  ��ָ����·��
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
	stack<string> myStack;
	string simplifyPath(string path) {
		string str;
		if (path.length() <= 0)
			return str;
		traverse(path);
		//��ջ�а����ݵ�����
		if (myStack.empty())
		{
			//���ջΪ�յĻ�����ô�Ͱѵ�ǰĿ¼�ŵ�str����ȥ
			str.append("/");
		}
		string temp;
		while (!myStack.empty())
		{
			temp = myStack.top();
			myStack.pop();
			str.insert(0,temp);
		}
		//������ظ��ж���ʵû�б�Ҫ
		int len = str.length();
		if (len>= 2&&str[0]==str[1])
		{
			str = str.substr(1,len-1);
		}

		return str;
		
	}
	void traverse(string path)
	{
		int len = path.size();
		int ps = 0,pe = ps;
		string str;

		int range;
		while (ps < len)
		{
			while (((pe+1)<len) && (path[pe+1] != '/'))
			{
				pe++;
			}
			//�и��ַ���
			
			range = pe - ps + 1;
			str = path.substr(ps, range);
			if (str == "/")
			{
				//ʲôҲ������Ϊ�������Ҫѹջ
			}
			else if (str == "/.")
			{
				//ʲôҲ������Ϊ�������Ҫѹջ
			}
			else if (str == "/..")
			{
				if (!myStack.empty())
				{
					myStack.pop();
				}
			}
			else
			{
				myStack.push(str);
			}
			//ps���õ�pe
			pe++;
			ps = pe;
			
		}

	}
};

int main()
{
	//string path = "/a/./b/../../c/";
	//string path = "//a/././/b/../../c/";
	string path = "/..";
	Solution mine;
	string result;
	result = mine.simplifyPath(path);
	cout << result << endl;
	return 0;
}
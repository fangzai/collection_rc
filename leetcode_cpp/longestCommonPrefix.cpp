/*
time   :  2015-5-10
author :  ht
comment:  ��һ��string�����������ͬǰ׺
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize <= 0)
	{
		// ��������ǿյĻ�����Ȼ���� ""
		// ��û�������˵
		return "";
	}

	if (strlen(strs[0]) <= 0)
	{
		return strs[0];
	}
	int i,j;
	char *result;
	int len = strlen(strs[0]);
	for (i = 1; i < strsSize; i++)
	{
		if (len >= strlen(strs[i]))
			len = strlen(strs[i]);
	}
	result = (char*)malloc((len + 1)*sizeof(char));
	bool mark = true;
	char first;
	j = 0;
	do
	{
		first = strs[0][j];
		for (i = 1; i < strsSize; i++)
		{
			if (strs[i][j] != first)
			{
				mark = false;
				break;
			}
		}
		if (mark)
		{
			result[j] = first;
			j++;
			if (j >= strlen(strs[0]))
			{
				break;
			}
		}
		//ѭ��������ʱ��С��Խ��
	} while (mark&&j<strlen(strs[0]));
	result[j] = '\0';

	return result;

}

int main()
{
	/*
	char*str[2] = {
	"",
	"wanitao",
	};
	*/
	char*str[1] = { "89" };
	int numSize = 1;
	printf("%s \n",longestCommonPrefix(str,numSize));
	return 0;
}
#include<iostream>
#include<cstring>
#include<cmath>
#include<cctype>
using namespace std;

char*dealStr(char*str)
{
	int i;
	int len = strlen(str);
	char*newStr = (char*)malloc(len*sizeof(char));
	int newLen = 0;
	for (i = 0; i < len; i++)
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
		{
			newStr[newLen] = str[i];
			newLen ++;
		}
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
		{	
			newStr[newLen] = str[i]+'a'-'A';
			newLen++;
		}
	}
	newStr[newLen] = '\0';
	return newStr;
}

bool isPalindrome(char* s) {
	int i;
	//printf("%s \n",dealStr(s));
	int emptyCount = 0;
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ')
		{
			emptyCount++;
		}
	}
	if (strlen(s) <= 0 || emptyCount==strlen(s))
	{
		return true;
	}
	char* result = dealStr(s);
	int len = strlen(result);
	if (len <= 0)
	{
		return false;
	}
	
	for (i = 0; i < len / 2; i++)
	{
		if (result[i] != result[len - i - 1])
		{
			return false;
		}
	}

	free(result);
	return true;
}

bool isIn(char s)
{
	if (((s >= 'a') && (s <= 'z')) || ((s >= 'A') && (s <= 'Z')) || ((s >= '0') && (s <= '9')))
		return true;
	else
		return false;
}
bool isPalindrome1(char* s) {
	int i;
	//printf("%s \n",dealStr(s));
	int emptyCount = 0;

	if (strlen(s) <= 0)  //һ���ַ�Ҳû��
	{
		return true;
	}
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ')     //���Ƕ��ǿմ������  
		{
			emptyCount++;
		}
		else
		{
			break;          //��Ҫ�����꣬��Ϊ�������˾�time exceeds
		}
	}
	if (emptyCount == strlen(s))
	{
		return true;
	}
	int len = strlen(s);
	int j = len - 1;  //�Ӻ�߱���
	char head, tail;
	int countArfa = 0;
	for (i = 0; i < len; )
	{
		while ((!isIn(s[i]))&&(i<len))  //����ط�һ��Ҫ��i<len ��ֹ������ĩβ��Խ��
		{
			i++;
		}
		if (i<len)
		{
			countArfa++;  //��¼��Ч�����ֺ��ַ�����һһ����û�еģ�ֱ�Ӿ�return true��
		}
		
		if (countArfa <= 0)
		{
			return true;
		}
		head = toupper(s[i]);   //����Ϊ��д�ַ�
		while ((!isIn(s[j]))&&(j>=0))
		{
			j--;
		}
		if (j>=0)
		{
			countArfa++;
		}
		tail = toupper(s[j]);
		
		//cout << s[i] << "  " << s[j]<< endl;
		//cout<<head<<"  "<<tail<<endl;
		//printf(tail);
		if (head != tail)
		{
			return false;
		}
		if (i >= j)
		{
			break;
		}
		i++;
		j--;
	}
	return true;
}

int main()
{
	//char*str = "A man, a plan, a canal: Panama";
	char*str = "1a2";
	if (isPalindrome1(str))
	{
		printf("Is palindrome.......... \n");
	}
	else
	{
		printf("Is not palindrome...... \n");
	}
	return 0;
}
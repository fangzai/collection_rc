#include<iostream>
#include<cstring>
using namespace std;

int strStr(char* haystack, char* needle) {
	// this is the  Brute force algorithm o(nm)
	// ���������ķ�����Ч���ǱȽ�����
	int i=0,j=0;
	while((haystack[i+j])!='\0'&&(needle[j]!='\0'))
	{
		if(haystack[i+j]==needle[j])
		{
			j++;
		}
		else
		{
			i++;  //haystack���±���ǰ�ƶ�1
			j=0;
		}
	}

	if(needle[j]=='\0')
	{
		return i;
	}
	else
	{
		return -1;
	}
}
void get_nextval(const char *T, int* next)
{
	// ��ģʽ��T��next����ֵ���������� next�� ��������Ǵ�����ο������г���
	int j = 0, k = -1;
	next[0] = -1;
	while ( T[j+1] != '\0' )
	{
		if (k == -1 || T[j] == T[k])
		{
			++j;
			++k;
			if (T[j]!=T[k])
			{
				next[j] = k;
			}
			else
			{
				next[j] = next[k];
			}
		}
		else
		{
			k = next[k];
		}
	}// while
	////�������Ҽӵ���ʾ����
	// for(int i=0;i<j;i++)
	//{
	//     cout<<next[i];
	//}
	//cout<<endl;
}
int strStr1(char* haystack, char* needle) 
{
	// ����ʵ��һ�¸���Ч��kmp�㷨  �������ò�ƥ���ַ���ǰ׺�������������ľ���
	if( !haystack||!needle|| needle[0]=='/0' || needle[0]=='/0' )
	{

		return -1;//��ָ���մ�������-1
	}
	int lenNeedle = strlen(needle);  //��ģʽneedle�ĳ���
	//cout<<lenNeedle<<endl;
	int *next = (int*)malloc(lenNeedle*sizeof(int));
	get_nextval(needle,next); //���ü���next�ĺ������ұ�ʾ������д�ģ������Ҳ���

	int i=0,j=0,index =0;
	while((haystack[i])!='\0'&&(needle[j]!='\0'))
	{
		if(haystack[i] == needle[j])
		{
			i++;  // �����ȵĻ���Ȼok
			j++;
		}
		else
		{
			//���ʱ���Ҫ�õ�next��
			index += j-next[j];  // j-next[j]���Ǳ�ʾǰ׺ǰ����Ǹ��ַ���λ��
			//index�������Ƶ�ǰhaystack���ƶ����±��
			if(next[j]!=-1)      //���ģʽ����-1��˵�����ص��Ĳ���
			{
				j=next[j];// ģʽ�������ƶ���Ҳ���Ǵ�ʱneedle�Ļ���Ҫ���±�j��ʼ
			}
			else
			{
				j=0;
				i++;     //�������-1�Ļ��Ǿ�û�а취�ˣ�ֻ��j���ã�i����
			}
		}
	}

	free(next);
	if(needle[j]=='\0')  // j����±�����Ƶ������Ļ�
	{
		return index;
	}
	else
	{
		return -1;
	}

}


int main()
{
	char *haystack ="abcabcabdabba";
	char *needle ="abcabd";
	cout<<strStr(haystack,needle)<<endl;
	cout<<strStr1(haystack,needle)<<endl;
	return 1;
}
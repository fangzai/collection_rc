#include<iostream>
#include<cstring>
using namespace std;


// ʵ��leetcode��20��
bool isValid(char* s) {
    int lenth = strlen(s);  //���������ַ��ĳ���
	int i =0;
	char head,tail;
	char *newS = (char*)malloc(lenth*sizeof(char));
	newS[0] = s[0];        //���׸��ַ�ѹ��ջ��
	int stackPoint = 0;    //��¼ջ����λ��
	char pop;              //pop�����ַ�
	char current;          //��ǰ��ƥ����ַ�
	bool isEmpty = false;  //�ж��Ƿ�ƥ�����
	for(i=1;i<lenth;i++)   //�ӵڶ����ַ���ʼƥ��
	{
		pop = newS[stackPoint];  //����ջ��
		current = s[i];          //��ƥ���ַ�
		if((pop == '{'&& current== '}')||(pop == '('&& current== ')')||(pop == '['&& current== ']'))//ƥ���ж�����
		{   
			//���ƥ�����
			if(stackPoint==0)
			{
				//��ջΪ�յ��������Ҫ��������
				if((i+1)<lenth)  //�����Ƿ�������
				{
					newS[stackPoint] = s[i+1];  
					i++;
				}
				else
				{
					isEmpty = true;  //����ط��ж��Ƿ�Ϊ��Ҳ���������Ƿ�ƥ�����
				}
			}
			else
			{
				//ջ��Ϊ�� ջ��Ҫ��һ��λ��
				stackPoint --;  //����һ��λ��
			}
		}
		else
		{
			//��ƥ��Ļ�����Ҫѹջ
			stackPoint++;  //ջ��   +1
			newS[stackPoint]=s[i];
		}
	}
	//cout<<lenth<<endl;
	return isEmpty;
}
int main()
{
	char * myString = "((";
	if(isValid(myString))
	{
		cout<<"��ƥ��ģ�"<<endl;
	}
	else
	{
		cout<<"��ƥ�䣡"<<endl;
	}
	return 1;
}
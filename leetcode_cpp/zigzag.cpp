/*
time   :  2015-5-9
author :  ht
comment:  ����zigzag���ַ�����ȡ��ʽ
˵���� �����ı߽��������������
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

char* convert(char* s, int numRows) {
	//�뷨�Ƚ�����
	//����ȷ����Ҫ����ĳ���
	char sep = ' ';
	int len = strlen(s);

	char*result = (char*)malloc((len + 1)*sizeof(char));
	if (numRows == 1)
	{
		memcpy(result, s, len + 1);   //ֻ��һ�У�����ת����
		return result;
	}
	int size = len / (2*numRows-2);  
	//���û��numRows���жϣ�������ܳ��ֳ���Ϊ0
	//�տ�ʼ��ô���ˣ�����ù�
	size = size*(numRows-1);
	int mode = len % (2 * numRows - 2);
	if (mode <= numRows)
	{
		size = size + 1;
	}
	else
	{
		size = size + 1 + mode - numRows;
	}
	char** str = (char**)malloc(numRows*sizeof(char*));
	int i, j;
	for (i = 0; i < numRows; i++)
	{
		str[i] = (char*)malloc(size*sizeof(char));
		for (j = 0; j < size; j++)
		{
			str[i][j] = sep;
		}
	}
	int current = 0;
	i = 0; //ȷ������һ��
	for (j = 0; j < size; j++)
	{
		if (current >= len)
			break;
		if (j % (numRows - 1)==0)
		{
			// ȷ��������Ҫ������
			while (i<numRows)
			{
				str[i][j] = s[current];
				current++;
				i++;
				if (current >= len)
				{
					break; // Խ����
				}
			}
			i = i - 2;;
		}
		else
		{
			//��������
			str[i][j] = s[current];
			current++;
			if (current >= len)
				break;
			i--;
		}
	}
	
	current = 0;
	for (i = 0; i < numRows; i++)
	{
		for (j = 0; j < size; j++)
		{
			//printf("%c", str[i][j]);
			if (str[i][j] != sep)
			{
				result[current] = str[i][j];
				current++;
			}
		}
		//printf("\n");
	}
	result[current] = '\0';
	for (i = 0; i < numRows; i++)
	{
		free(str[i]);
	}
	free(str);
	return result;
}

char* convert1(char* s, int numRows)
{
	/*  Ч�ʱȽϸߵķ���
	 *1 ��i�Ŵ�i��ʼ
	 *2 ��i���������ļ����2(m-i),2(i-1)����
	 */

	int len = strlen(s);
	if (numRows == 1)
	{
		return s;
	}
	char*result = (char*)malloc((len + 1)*sizeof(char));
	int index = 0,step1,step2;
	int i,current =0;
	for (i = 0; i < numRows; i++)
	{
		index = i;
		step1 = 2 * (numRows - i-1);
		step2 = 2 * i;
		result[current] = s[index];
		current++;
		while (index < len)
		{
			
			if (step1 > 0)
			{
				index += step1;
				if (index >= len)  // ���ܼ���֮���Խ����
				{
					break;
				}
				result[current] = s[index];
				current++;
			}
			if (step2 > 0)
			{
				index += step2;
				if (index >= len)
				{
					break;
				}
				result[current] = s[index];
				current++;
			}
		}

	}
	result[current] = '\0';
	//printf("%s\n",result);
	return result;
}


int main()
{
	//char * str = "PAYPALISHIRING";
	char * str = "P";
	int nums = 1;
	char *result = convert1(str, nums);
	printf("%s \n", result);
	return 0;
}
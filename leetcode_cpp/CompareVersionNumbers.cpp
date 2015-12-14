#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

int strsplit(char*src,char**dis)
{
	//����������ڷ�����sep������ַ����������ظ���
	int i = 0;
	int first = 0;
	int current = 0;
	char sep = '.';
	int len = 0;
	while (src[current] != '\0')
	{
		if (src[current] != sep)
		{
			current++;
		}
		else
		{
			len = (current - first);
			memcpy(dis[i],src+first,len*sizeof(char));
			dis[i][len] = '\0';
			//printf("%s \n",dis[i]);
			i++;
			first = current + 1;
			current++;
		}
	}
	len = (current - first);
	memcpy(dis[i], src + first, len*sizeof(char));
	dis[i][len] = '\0';
	//printf("%s \n", dis[i]);
	i++;
	return i;
}

int compareVersion(char* version1, char* version2) {
	//����뷨�Ƚ����أ��ȷ��룬�ٱȽ�
	int max_size = 10;
	int * ver2int1 = (int*)malloc(max_size*sizeof(int));
	int * ver2int2 = (int*)malloc(max_size*sizeof(int));
	int i = 0;
	for (i = 0; i < max_size; i++)
	{
		ver2int1[i] = 0;
		ver2int2[i] = 0;
	}

	char ** goal = (char**)malloc(max_size * sizeof(char**));
	for (i = 0; i < max_size; i++)
	{
		goal[i] = (char*)malloc(max_size * sizeof(char*));
	}
	int n1 = strsplit(version1, goal);
	
	//printf("Begin to output......  for str1\n");
	for (i = 0; i < n1; i++)
	{
		//printf("%s \n", goal[i]);
		ver2int1[i] = atoi(goal[i]);
		//printf("%d \n", ver2int1[i]);
		
	}
	//printf("End to output......\n");

	int n2 = strsplit(version2, goal);
	//printf("Begin to output......  for str2\n");
	for (i = 0; i < n2; i++)
	{
		//printf("%s \n", goal[i]);
		ver2int2[i] = atoi(goal[i]);
		//printf("%d \n", ver2int2[i]);

	}
	//printf("End to output......\n");

	int n = n1>n2?n1:n2;
	for (i = 0; i < n; i++)
	{
		if (ver2int1[i]>ver2int2[i])
		{
			return 1;
		}
		else
		{
			if (ver2int1[i] < ver2int2[i])
			{
				return -1;
			}
		}
	}
	free(ver2int1);
	free(ver2int2);
	for (i = 0; i < max_size; i++)
	{
		free(goal[i]);
	}
	free(goal);
	return 0;
}
int compareVersion2(char* version1, char* version2) {
	//�����и��ȽϺõ�˼·����ȡ��ʱ��ֱ�Ӿͼӵ�һ��ֵ����ȥ��
	//��������Ч��Ҳ�ߺܶ�

	int len1 = strlen(version1);
	int len2 = strlen(version2);

	int index1 = 0, index2 = 0;
	char sep = '.';
	int value1 = 0, value2 = 0;
	int temp;
	while (index1 < len1 || index2 < len2)
	{
		value1 = 0;  //��ȡ��һ���ַ��� sepǰ�������
		//while ((version1[index1] != sep)&&(version1[index1] != '\0'))  //��仰��bug  ����ojƽ̨�ͱ������еĲ�һ��
		while ((version1[index1] != sep) && (index1 < len1))
		{
			temp = version1[index1] - '0';
			value1 = value1 * 10 + temp;
			index1++;
		}

		//printf("%d  \n", value1);
		index1++;  //����sep


		value2 = 0;  //��ȡ��һ���ַ��� sepǰ�������
		while ((version2[index2] != sep)&&(index2 < len2))
		{
			temp = version2[index2] - '0';
			value2 = value2 * 10 + temp;
			index2++;
		}
		index2++;
		printf("%d vs %d  \n", value1,value2);
		if (value1 > value2)
		{
			return 1;
		}
		else
		{
			if (value1 < value2)
			{
				return -1;
			}
		}

	}
	
	//printf("%d \n", index1);
	return 0;
}  
int main()
{
	char* str1 = "1.0";
	char* str2 = "1";
	//testStrtol();
	printf("%d \n", compareVersion2(str1, str2));
	return 0;
}
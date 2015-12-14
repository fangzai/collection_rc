#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int titleToNumber(char* s) {
    int len = strlen(s);
	int i;
	int result = 0 ;
	int str2num =0;
	for(i=0;i<len;i++)
	{
		str2num = s[i]-'A'+1;
		//cout<<str2num<<endl;
		result *= 26;
		result += str2num;
	}
	return result;
}
void reverseString(char*mystr)
{
	//�ú���ʵ�ֵ����ַ�����ת
	int len = strlen(mystr);
	char*result = (char*)malloc(len*sizeof(char));
	int i;
	for(i=0;i<len;i++)
	{
		result[i]= mystr[len-i-1];
	}
	memcpy(mystr,result,len);
	free(result);
}
char* convertToTitle(int n) {
	int len = 0;
	int i=0;
	int num =n;
	int temp;
	char* result = (char*)malloc(100*sizeof(char));
	while(num>=26)
	{
		temp = num%26;
		
		num = num/26;
		if(temp ==0)   //��һ���ر���ģ���Ϊ����պó����Ļ����һ��������Z����ǰ���num����Ҫ  -1
		{
			temp = 26;
			num--;
		}
		result[len]=temp+'A'-1;
		printf("%d \n",temp);
		len++;
	}
	printf("%d \n",num);
	if(num>=1)    //��Ϊ���ܸպ���Z�����
	{
		result[len]=num+'A'-1;
		len++;
	}
	result[len] = '\0';
	reverseString(result);

	return result;
    
}

int main()
{
	char*mystr = "AB";
	//printf("%d \n",titleToNumber(mystr));

	int num = 28; 
	printf("%s \n", convertToTitle(num));
	return 0;
}
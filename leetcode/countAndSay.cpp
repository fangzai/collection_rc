#include<iostream>
#include<cstring>
using namespace std;
bool isIn(int*S,int len,int str)
{
	// �ж�ĳ�������Ƿ������������У����Ҳ�����ƹ㵽�ַ�ƥ����
	int i=0;
	//bool mark = false;
	for(i=0;i<len;i++)
	{
		if(S[i] == str)
			return true;
	}
	return false;
}
char* countAndSay1(int n) {
	int len = 0;
	int myNum = n;
	int temp;
	int*sequence=(int*)malloc(10*sizeof(int));
	int *intS = (int*)malloc(100*sizeof(int));
	while(myNum>=10)
	{
		temp = myNum%10;
		//cout<<temp<<"  ";
		myNum = myNum/10;
		intS[len]= temp;
		//sequence[len] = temp+'0';
		len++;
	}
	//cout<<myNum<<endl;
	//sequence[len]=myNum+'0';
	intS[len]=myNum;    //��ÿ��λ�õ����ִ浽intS��
	len++;				//��ʾintS�ĳ���
	//sequence[len+1]='\0';
	//��ȡ���ֵ�ÿ��λ�õ����ֽ���

	int i;
	int counts[10];
	for(i=0;i<10;i++)
	{
		counts[i]=0;  //������0
	}
	int current =0;
	//cout<<len<<endl;
	for(i=len-1;i>=0;i--)
	{
		if(isIn(sequence,current,intS[i]))
		{
			counts[intS[i]]++;   //��ʼͳ��
		}
		else
		{
			sequence[current]=intS[i];
			counts[intS[i]]++;
			current ++;
		}
	}

	char*myString=(char*)malloc(2*current*sizeof(char));
	//cout<<current<<endl;
	for(i=0;i<current;i++)
	{   //�ַ���ƴ��
		//cout<<counts[sequence[i]]<<" :"<<sequence[i]<<endl;
		myString[2*i]=counts[sequence[i]]+'0';
		myString[2*i+1]=sequence[i]+'0';
	}
	myString[2*current]='\0';
	return myString;
    
}

char* generate_next_num(char*str)
{
	int len=strlen(str);
	int i=0;
	char current_str = str[0];
	int *count=(int*)malloc(len*sizeof(int));   //ͳ�������ַ��ĸ���
	char*storage=(char*)malloc(len*sizeof(char));//�洢�����ַ���λ��
	int pointer=0;
	
	for(i=0;i<len;i++)
	{
		count[i]=0;    //ͳ����0
	}
	storage[pointer]=str[0];  //�Ȱѵ�һ���ַ�����0λ��
	count[pointer]++;         //���ַ�ͳ�� +1


	for(i=1;i<len;i++)
	{
		if(storage[pointer]!=str[i])  
		{
			//���the string coming ������ ��ǰpointer��ָ�ģ�����Ҫpointer����
			pointer++;
			storage[pointer]=str[i];
			count[pointer]++;  //ͳ��  +1
		}
		else
		{
			//���the string coming���� ��ǰpointer��ָ�ģ���pointer����
			count[pointer]++;  //ֻ��Ҫͳ��  +1
		}
	}
	storage[pointer+1]='\0';

	char*result=(char*)malloc(2*len*sizeof(char));

	//cout<<storage<<endl;
	for(i=0;i<pointer+1;i++)
	{
		result[2*i]=count[i]+'0';
		result[2*i+1]=storage[i];
		//cout<<count[i]<<" ";
	}
	result[2*(pointer+1)]='\0';
	//cout<<result<<endl;
	
	free(count);
	
	//free(storage);
	return result;
}
char* countAndSay(int n) {
	char*str_result="1";
	if(n<=1)
	{
		return str_result;
	}

	while(n>1)
	{
		str_result = generate_next_num(str_result);
		//cout<<n<<" : "<<str_result<<endl;
		n--;
	}
	return str_result;
}
int main()
{
	int num =5;
	cout<<countAndSay(num)<<endl;
	return 0;
}
#include<iostream>
#include<cstring>
using namespace std;

typedef unsigned long   uint32_t;    //�޷���32λ��

// �����Ŀ����ͳ�ƻ���2���ƺ�����1�ĸ�����
int hammingWeight(uint32_t n) {
	int len = 0;
	int num;
	while(n>1)
	{
		num = n%2;
		//cout<<num;
		if(num == 1)
		{
			len++;
		}
		n = n/2;
	}
	//cout<<n<<endl;
	if(n==1)
	{
		len++;
	}
	return len;
    
}
int main()
{
	uint32_t num = 10;
	cout<<hammingWeight(num)<<endl;
	return 0;
}
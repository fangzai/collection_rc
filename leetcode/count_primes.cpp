#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

// �ó�����С��ĳ���������ֵ����������ĸ���
//�����Ҷ�֪����������һ���� n ����Ǻ�������ô�������е����Ӳ�����<=sqrt(n)--n�Ŀ���,
//��ô���ǿ����������������ֱ�۵ķ���
bool isPrime()
{
	return true;
}
int countPrimes(int n) 
{
	int i =0, j =1;
	int num =0;
	bool mark =true;
	for(i=2;i<n;i++)
	{
		mark = true;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				mark = false;
				break;
			}
		}
		if(mark)
		{
			num++;
			//printf("%d  ",i);
		}
	}
    return num;
}
//��Ϊ����
// 1 ��һ���ܴ������prime[n+1]  �����������Ϊtrue ����ż�����Ϊfalse
// 2 ��3��ʼ������sqr(n)
int countPrimes1(int n) 
{
	int range = n-1;
	bool *prime = (bool*) malloc((n+1)*sizeof(bool));
	int i;
	prime[1]=false;
	prime[2]=true;
	for(i = 3; i<=range;i++)
	{
		if(i%2==0)
		{
			prime[i] = false;
		}
		else
		{
			prime[i] = true;
		}
	}
	int j =0;
	for(i = 3; i<=sqrt(range);i++)
	{
		if(prime[i])
		{
			for(j = i+i;j<=range;j+=i)  //�߽�һ��Ҫ���ǵ�  ����Ͷ�����
			{
				prime[j]= false;
			}
		}
	}
	int len = 0;
	for(i = 1; i<=range;i++)    //�еȺ�
	{
		if(prime[i])
		{
			len++;
			//printf("%d ",i);
		}
	}
	free(prime);
	return len;
}
int main()
{
	int num = 10;
	printf("\n%d \n",countPrimes1(num));
	return 0;
}


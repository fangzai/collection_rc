#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
int trailingZeroes(int n) {
	int factor[2] = {0,0};  //����2��5�ĸ���
	int i;
	int temp;
	for(i=2;i<=n;i++)
	{
		temp =i;
		while(temp%2==0)
		{
			factor[0]++;
			temp = temp/2;
		}
		while(temp%5==0)
		{
			factor[1]++;
			temp = temp/5;
		}
	}
	if(factor[0]>=factor[1])
	{
		return factor[1];
	}
	else
	{
		return factor[0];
	}
}
int trailingZeroes1(int n)
{
    //�������������ˣ����Ǽ���5�ĸ���
	//���Կ���ÿ�γ�5�õ��������Ǹô��ݵ�����5�ı���������ȥ��ֱ����Ҳ��������
	int num =n;
	int max_index =0;
	int single_five = num/5;
	int total_five =0;
	while(num>=5)
	{
		max_index++;
		num = num/5;
		total_five += num;  //������仰
	}
	//printf("single five is %d \n",single_five);
	//printf("complex five is %d \n",max_index);
	
	//printf("total five is %d \n",total_five);
	return total_five;
	
}
int main()
{
	printf("%d \n",trailingZeroes1(200));
	return 0;
}
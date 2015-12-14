/*
time   :  2015-5-20
author :  ht
comment:  gas station���⣬�ж����Ƿ��ܹ�����ȫ��
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>

using namespace std;

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {

	int i, j;
	int n = gasSize, sum = 0,sum1=0, index = 0;
	for (i = 0; i < n; i++)
	{
		sum += gas[i];
		sum1 += cost[i];
	}
	if (sum < sum1)
		return -1;
	sum = 0;
	srand((unsigned)time(NULL));
	int k = rand()%n;
	//�����ķ���������һ�����֮���ܹ�leetcode�ˣ��������ܲ�����
	//�ϸ���˵����n^2�������ʱ��
	for (i = 0; i < n; i++)
	{
		sum = 0;
		j = 0;
		while (j < n)
		{
			index = k + j;
			index = index%n;
			sum += gas[index];
			if (sum >= cost[index])
			{
				sum -= cost[index];
				//�ܹ�����i->i+1��һ��·��
			}
			else
			{
				break;
			}
			j++;
		}
		if (j == n)
			return k%n;
		k++;
	}

	return -1;
}
int canCompleteCircuit1(int* gas, int gasSize, int* cost, int costSize) {
	//���ϻ���һ��o(n�����㷨�������������step֮�� ͻȻ���ֲ�������
	//��㻹��ѡi+1���������ʱ��ﵽi+step������ʣ�����ֱ�Ӽ������
	int i, j;
	int n = gasSize, sum = 0, sum1 = 0, index = 0;
	for (i = 0; i < n; i++)
	{
		sum += gas[i];
		sum1 += cost[i];
	}
	if (sum < sum1)
		return -1;

	i = 0;
	sum = 0;
	j = 0;
	while (j < n&& i < n)
	{
		index = i + j;
		index = index%n;
		sum += gas[index];
		sum -= cost[index];
		if (sum >= 0)
		{
			
			//�ܹ�����i->i+1��һ��·��
		}
		else
		{
			int count = 0;
			while (sum < 0)
			{
				sum = sum + cost[i] - gas[i];
				//�ѵ�i->i+1��һ��·���ص�
				i++;
				count++;
			}
			j = j-count;  //������ȥ�Ĳ���

		}
		j++;
	}
	if (j == n)
	{
		return i;
	}

	return -1;
}
int main()
{ 
	int gas[5] = {4,3,3,7,3};
	int cost[5] = {5,2,4,6,3};
	//int gas[5] = { 1, 2, 3, 4, 5 };
	//int cost[5] = { 3, 4, 5, 1, 2 };
	int gasSize = 5;
	printf("%d \n", canCompleteCircuit1(gas, gasSize, cost, gasSize));
	return 0;
}
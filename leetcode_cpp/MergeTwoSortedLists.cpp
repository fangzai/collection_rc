/*
time   :  2015-5-9
author :  ht
comment:  �ں������Ѿ������������
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode {
	int val;
	struct ListNode *next;
};
ListNode* createNodeList(ListNode *head,int *array,int len)
{
	head = (ListNode*)malloc(sizeof(ListNode));
	//int len = 4;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	//int array[4] = { 1, 1, 0, 0 };
	int i;
	ListNode * p1 = NULL;  // p1 ���洴�����½ڵ�ĵ�ַ
	ListNode * p2 = NULL;  // p2 ������������һ���ڵ�ĵ�ַ
	p1 = (ListNode*)malloc(sizeof(ListNode));
	p2 = p1;
	if (len<=0)
	{
		head = NULL;   //�������  ����������
		return head;
	}
		
	for (i = 0; i < len; i++)
	{
		p1->val = array[i];

		if (i == 0)
		{
			head = p1;
			p2->next = NULL;  //��ʱ��p2����p1���״θ�ֵ��ʱ��p2ָ���

		}
		else
		{
			p2->next = p1;   //ָ���ϴ�����ոտ��ٵ��½ڵ�
		}

		p2 = p1;    //��p1�ĵ�ַ��p2������Ȼ��p1�����µĽڵ�

		p1 = (ListNode*)malloc(sizeof(ListNode));  // �����µĵ�ַ
	}
	p2->next = NULL;   // p2һֱ��ĩ�˽ڵ�


	free(p1);
	p1 = NULL;
	return head;
}
void Print(ListNode* head)
{
	ListNode *current;
	printf("Begin to output the node of this linklist\n");
	current = head;
	int i = 0;
	if (current != NULL)
	{
		do
		{
			printf("%d ", current->val);
			i++;
			current = current->next;
			if (current)
				printf(" -> ");
		} while (current != NULL);
		printf("\n");
	}
	else
	{
		printf("The link list is empty!");
	}
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	ListNode *head = NULL, *current1 = NULL, *current2 = NULL, *current = NULL;
	current1 = l1;
	current2 = l2;

	int value1, value2;
	int count = 0;

	//���������������������������
	if (l1 == NULL)
	{
		head = l2;
		return head;
		//current = current2;
	}
	if (l2 == NULL)
	{
		head = l1;
		return head;
		//current = current1;
	}

	//����whileѭ��  ����
	while (current1 != NULL&&current2 != NULL)
	{
		value1 = current1->val;
		value2 = current2->val;

		if (value1 < value2)
		{
			if (count == 0)
			{
				head = current1;  //��ȷ��ͷ
				current = current1;
			}
			else
			{
				current->next = current1;  
				//�������ͷ�Ļ�ֱ�Ӹ�ָ��
				current = current->next;
			}
			
			current1 = current1->next;
			
			count++;
		}
		else
		{
			if (count == 0)
			{
				head = current2;
				current = current2;
			}
			else
			{
				current->next = current2;
				current = current->next;
			}
			current2 = current2->next;
			
			count++;
		}
		
	}
	//������ѭ�����ж������и�������û�б�����ɵļ�������
	while (current1 != NULL)
	{
		current->next = current1;

		current1 = current1->next;
		current = current->next;
		count++;
	}
	while (current2 != NULL)
	{
		current->next = current2;

		current2 = current2->next;
		current = current->next;
		count++;
	}
	current->next = NULL;  // ĩ�˽ڵ�ָ�븳Ϊ0
	
	return head;
}


int main()
{
	ListNode *link1 = NULL, *link2 = NULL,*head = NULL;

	int array1[5] = {1,5,7,8,9};
	int num1 = 5;
	int *array2=NULL;
	int num2 = 0;
	link1 = createNodeList(link1,array1,num1);
	Print(link1);

	link2 = createNodeList(link2, array2, num2);
	Print(link2);

	head = mergeTwoLists(link1, link2);
	Print(head);
	return 0;
}
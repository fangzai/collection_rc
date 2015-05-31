/*
time   :  2015-5-9
author :  ht
comment:  ��ת����
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
ListNode* createNodeList(ListNode *head)
{
	head = (ListNode*)malloc(sizeof(ListNode));
	int len = 1;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int array[4] = { 1, 1, 0, 0 };
	int i;
	ListNode * p1 = NULL;  // p1 ���洴�����½ڵ�ĵ�ַ
	ListNode * p2 = NULL;  // p2 ������������һ���ڵ�ĵ�ַ
	p1 = (ListNode*)malloc(sizeof(ListNode));
	p2 = p1;

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

struct ListNode* reverseList(struct ListNode* head) {
	//��������
	ListNode *current;
	ListNode *p = NULL;
	ListNode *first = NULL;
	int len = sizeof(ListNode);
	if (head == NULL)
	{
		printf("The link list is empty!");
		return head;
	}

	current = head;

	while (current != NULL)
	{
		//�������
		if(current==head)  //��ʱ�����һ���ռ�
		{
			p = (ListNode*)malloc(len);
			p->val = current->val;
			p->next = NULL;
			first = p;
		}
		else
		{
			p = (ListNode*)malloc(len);
			p->val = current->val;
			p->next = first;
			first = p;
		}
		current = current->next;
	}
	return first;
}
int main()
{
	ListNode *head = NULL;
	head = createNodeList(head);
	Print(head);
	head = reverseList(head);
	Print(head);
	//head = removeElements(head, 1);
	//Print(head);
	return 0;
}
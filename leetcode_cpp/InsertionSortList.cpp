/*
time   :  2015-5-17
author :  ht
comment:  �ò�������ķ�����list��������
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
struct ListNode* createNodeList(struct ListNode *head, int *array, int len)
{
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	//int len = 2;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	//int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	if (len <= 0)
		return NULL;
	int i;
	struct ListNode * p1 = NULL;  // p1 ���洴�����½ڵ�ĵ�ַ
	struct ListNode * p2 = NULL;  // p2 ������������һ���ڵ�ĵ�ַ
	p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
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

		p1 = (struct ListNode*)malloc(sizeof(struct ListNode));  // �����µĵ�ַ
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

struct ListNode* insertionSortList(struct ListNode* head) {
	if (head == NULL)
		return NULL;
	struct ListNode*current = NULL, *p = NULL,*p1=NULL,*p2=NULL;
	p = (struct ListNode*)malloc(sizeof(struct ListNode*));
	p->val = INT_MIN;

	p->next = head;
	head = p;   //����һ�������ͷ

	current = head->next;
	head->next = NULL;
	while (current != NULL)
	{
		p = head;
		while (p->next != NULL&&p->next->val <= current->val)
		{
			p = p->next;
		}
		p1 = p->next;
		p2 = current;
		
		current = current->next;
		p->next = p2;
		p2->next = p1;	
	}
	

	p = head;
	head = head->next;
	//free(p);   //���������ͷ
	//p = NULL;  
	//��֪��Ϊʲô��oj�ϼ��������п���ͨ����������vs�ϾͲ���
	
	return head;
}

int main()
{
	ListNode *head = NULL, *tail = NULL, *first = NULL;

	int  nums[10] = { 10,8,4,7,6,5,4,9,1,2};
	int len = 0;
	head = createNodeList(head,nums,len);
	Print(head);
	head = insertionSortList(head);
	Print(head);
	return 0;
}
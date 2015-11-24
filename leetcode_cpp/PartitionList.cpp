/*
time   :  2015-5-17
author :  ht
comment:  ����һ������ָ�������Ὺʼ����
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

struct ListNode* insertionSortList(struct ListNode* head, struct ListNode*current) {
	struct ListNode *p = NULL, *p1 = NULL, *p2 = NULL;
	//����������  û����
	p = head;
	while (p->next != NULL&&p->next->val <= current->val)
	{
		p = p->next;
	}
	p1 = p->next;
	p2 = current;

	p->next = p2;
	p2->next = p1;

	return head;
}

struct ListNode* partition(struct ListNode* head, int x) {
	if (head == NULL)
		return NULL;
	struct ListNode*current = NULL, *tail = NULL, *head1 = NULL, *p = NULL,*p1=NULL,*p2=NULL;
	
	p = (struct ListNode*)malloc(sizeof(struct ListNode*));
	p->val = INT_MAX;
	p->next = head;
	head = p;   //����һ�������ͷ

	
	p1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	p1->val = INT_MIN;
	p1->next =NULL;
	head1 = p1;   //����һ�������ͷ

	current = head;
	
	tail = head1;
	while (current!=NULL&&current->next!=NULL)
	{
		if (current->next->val < x)
		{
			//��Ҫ���뵽��һ������֮��
			p1 = current->next;
			p2 = p1->next;    //��ҪŲ��ǰ��ĵ㶼�����
			current->next = p2;
			p1->next = NULL;  //��p1������

			tail->next = p1;
			tail = tail->next;  
			//��ΪҪ�������ǵ�ԭʼ˳�򲻱䣬����ط��Ͳ����ò���������
		}
		else
		{
			current = current->next;
		}
	}

	p1 = head1;
	head1 = head1->next;
	//free(p1);
	//p1 = NULL;

	p = head;
	head = head->next;
	//free(p);
	//p = NULL;//�ڴ����
	if (head1 == NULL)
	{
		return head;
	}
	tail->next = head;

	return head1;
	
}

int main()
{
	ListNode *head = NULL, *tail = NULL, *first = NULL;

	int  nums[10] = { 2,1,3};
	int len = 2;
	head = createNodeList(head, nums, len);
	Print(head);
	int pivot = 4;
	head = partition(head,pivot);
	Print(head);
	return 0;
}
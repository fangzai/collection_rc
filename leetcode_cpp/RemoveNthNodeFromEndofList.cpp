/*
time   :  2015-5-9
author :  ht
comment:  ��������ɾ��������N���ڵ�
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
ListNode* createNodeList(ListNode *head, int *array, int len)
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
	if (len <= 0)
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
int locate(struct ListNode *current, int n, struct ListNode* head)
{
	int num = 0; // ���ڼ�¼�����Ĵ��򣨵�����
	if (current->next == NULL)
	{
		num = 1;
		return num;
	}
	else
	{
		struct ListNode *p = NULL;
		p = current;
		current = current->next;
		num = 1 + locate(current, n,head);
		if ((num - 1) == n)  
		{
			// ��������޷��ݹ鵽ͷ���
			// ��Ҫ�ڵݹ������ɾ��
			p->next = current->next;
			free(current);	
			current = NULL;  
		}

		return num;
	}
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	
	struct ListNode *current = NULL;
	current = head;
	int num = locate(current, n, head); 
	// ɾ��ͷ�ڵ���Ҫ������ɾ��
	if (num == n)
	{
		head = head->next;
		free(current);
		current = NULL;
	}
		
	return head;
}


int main()
{
	ListNode *link1 = NULL, *link2 = NULL, *head = NULL;

	int array1[5] = { 1, 5, 7, 8, 9 };
	int num1 = 5;
	//int *array2 = NULL;
	//int num2 = 0;
	link1 = createNodeList(link1, array1, num1);
	Print(link1);

	head = removeNthFromEnd(link1, 5);
	Print(head);
	return 0;
}
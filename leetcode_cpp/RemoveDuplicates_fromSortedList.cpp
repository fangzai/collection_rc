/*
time   :  2015-5-9
author :  ht
comment:  ��������ɾ���ظ�������
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
	int len = 10;
	int array[10] = { 0, 0, 2, 2, 3, 4, 4, 5, 5, 5 };
	//int array[4] = { 1, 1, 0, 0 };
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

struct ListNode* removeElements(struct ListNode* head) {
	ListNode *current;
	ListNode *p = NULL;
	if (head == NULL)
	{
		printf("The link list is empty!");
		return head;
	}
	//��λҪɾ���Ľڵ�
	current = head->next;
	int count = 0;

	int val = head->val;

	p = head;  
	//������ɾ����һ��Ԫ�أ����Բ��ÿ��������������
	while (current != NULL)  
	//while (current != NULL &&current ->next= NULL)
	{
		//p = current;

		while (current != NULL&&current->val == val)  
		{
			//�ж�������˳���ܷ���
			p->next = current->next;
			free(current);
			current = p->next;

			count++;
		}
		if (current != NULL)   
		{
			// ���current�Ѿ��ǿյĻ�����û��current->next��
			p = current;   //���ĵ�ǰָ��
			val = p->val;  //���ĵ�ǰָ���Ҫɾ����ֵ
			current = current->next;
		}
	}

	if (count>0)
	{
		current = NULL;
		printf("\n%d is found for %d times!\n", val, count);
	}
	else
	{
		printf("\n%ld not been found!\n", val);
	}
	return head;

}

int main()
{
	ListNode *head = NULL;
	head = createNodeList(head);
	Print(head);
	head = removeElements(head);
	Print(head);
	//head = removeElements(head, 1);
	//Print(head);
	return 0;
}
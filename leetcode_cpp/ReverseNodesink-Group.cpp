/*
time   :  2015-5-27
author :  ht
comment:  ÿk��Ԫ����תһ��
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<stack>
#include<vector>
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
	int len = 3;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int i;
	if (len <= 0)
		return NULL;
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

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	//��ʵ��ջ�Ͷ�����ʵ���������ת����ʲô����ô��
	//��ǰ����ɵ�ˣ�ȫ�������Լ�д�ݹ�ʲô�ģ���������
	if (head == NULL||k<=1)
		return head;
	stack<struct ListNode*>myStack;
	struct ListNode* current=NULL,*tail=NULL,*start=NULL,*first=NULL;
	bool mark = false;
	current = head;
	while (current != NULL)
	{
		mark = false;
		start = current;
		for (int i = 0; i < k; i++)
		{
			//�ȱ���һ�£���������Ĺ�����
			if (current == NULL)
			{
				mark = true;
				current = start;
				break;
			}
			current = current->next;
		}
		if (mark) break;
		current = start;
		for (int i = 0; i < k; i++)
		{
			myStack.push(current);
			current = current->next;
		}
		for (int i = 0; i < k; i++)
		{
			if (tail == NULL)
			{
				tail = myStack.top();
				head = tail;
				tail->next = NULL;
				myStack.pop();
			}
			else
			{
				tail->next = myStack.top();
				myStack.pop();
				tail = tail->next;
				tail->next = NULL;
			}
		}
	}
	if (tail == NULL)
	{
		return head;
	}
	else
	{
		while (current != NULL)
		{
			tail->next = current;
			tail = tail->next;
			current = current->next;
			tail->next = NULL;
		}
		tail->next = NULL;
		return head;
	}
}
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) 
	{
		if (head == NULL || k <= 1)
			return head;
		stack<ListNode*>myStack;
		ListNode* current = NULL, *tail = NULL, *start = NULL, *first = NULL;
		bool mark = false;
		current = head;
		while (current != NULL)
		{
			mark = false;
			start = current;
			for (int i = 0; i < k; i++)
			{
				if (current == NULL)
				{
					mark = true;
					current = start;
					break;
				}
				current = current->next;
			}
			if (mark) break;
			current = start;
			for (int i = 0; i < k; i++)
			{
				myStack.push(current);
				current = current->next;
			}
			for (int i = 0; i < k; i++)
			{
				if (tail == NULL)
				{
					tail = myStack.top();
					head = tail;
					myStack.pop();
				}
				else
				{
					tail->next = myStack.top();
					myStack.pop();
					tail = tail->next;
				}
			}
		}
		if (tail == NULL)
		{
			return head;
		}
		else
		{
			while (current != NULL)
			{
				tail->next = current;
				tail = tail->next;
				current = current->next;
			}
			tail->next = NULL;
			return head;
		}
	}
};

int main()
{
	ListNode *head = NULL, *tail = NULL, *first = NULL;
	head = createNodeList(head);
	Print(head);
	int k = 4;
	first = reverseKGroup(head,k);
	Print(first);
	return 0;
}
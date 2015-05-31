/*
time   :  2015-5-15
author :  ht
comment:  ��תָ��λ�õ�����
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
	int len = 2;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int array[10] = { 1, 2, 3, 4,5,6,7,8 };
	int i;
	if(len<=0)
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

struct ListNode* reverseList(struct ListNode* current, struct ListNode**first) {
	//��������  z����ԭַ���ŵ��㷨
	struct ListNode*p1 = NULL, *p2 = NULL;
	if (current->next->next == NULL)
	{
		p1 = current->next;
		current->next = NULL;
		p1->next = NULL;
		first[0] = p1;
		return p1;
	}
	else
	{
		p1 = reverseList(current->next, first);
		p1->next = current->next;
		current->next = NULL;
		p1 = p1->next;
		p1->next = NULL;
		return p1;
	}
	//return first;
}
struct ListNode* reverseHead(struct ListNode* head)
{
	ListNode *tail = NULL, *first = NULL;
	//Print(head);
	tail = reverseList(head, &first);
	tail->next = head;
	//Print(first);
	return first;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {

	struct ListNode *current, *head1 = NULL, *tail = NULL, *tail1 = NULL, *head2=NULL, *first = NULL;
	current = head;
	int i;
	i = 0;
	while (current->next!=NULL)   
	{
		if ((i + 1) == (m - 1))
		{
			tail = current;  //�����һ�������tail
		}
		if ((i + 1) == n)
		{
			tail1 = current; //�ڶ��������tail
			break;
		}
		i++;
		current = current->next;
	}
	if (m == n)
	{
		return head; //m��n��ȵ����������ת
	}
	if (m != 1)  
	{
		//���ȵ�һ�������ǿ�
		head1 = tail->next;
		tail->next = NULL;//��һ������Ͽ�

		if (tail1 != NULL)  //�����������ǿ�
		{
			head2 = tail1->next;
			tail1->next = NULL; //�ڶ�������Ͽ�
		}
		
		if (head1->next != NULL)
		{
			//���ȵڶ��������ǿ�
			tail1 = reverseList(head1, &first);
			tail1->next = head1;
		}
		else
		{
			first = head1;
		}
		
		tail->next = first;  //��һ���͵ڶ�������ƴ��
		head1->next = head2; //�ڶ����͵���������ƴ��

		return head;
	}
	else
	{
		//���ȵ�һ�������ǿ�
		head1 = head;
		if (tail1 != NULL)  //tail1�Ѿ�������ĩ��
		{
			//�����������ǿ�
			head2 = tail1->next;
			tail1->next = NULL; //�ڶ�������Ͽ�
		}

		tail1 = reverseList(head1, &first);

		tail1->next = head1;   //��ʣ���һ��head1û�нӵ��ڶ���������
		head1->next = head2;  //�ڶ����͵���������ƴ��
		return first;
	}

}

int main()
{
	ListNode *head = NULL,*tail=NULL,*first=NULL;
	head = createNodeList(head);
	Print(head);
	head = reverseBetween(head, 1, 2);
	Print(head);
	//first = reverseHead(head);
	//Print(first);
	//head = reverseList(head);
	//Print(head);
	//head = removeElements(head, 1);
	//Print(head);
	return 0;
}
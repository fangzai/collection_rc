/*
time   :  2015-5-11
author :  ht
comment:  �ж������Ƿ��л�
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};
ListNode* createNodeList(ListNode *head, int*array, int len)
{
	head = (ListNode*)malloc(sizeof(ListNode));
	//int len = 4;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	//int array[4] = { 1, 1, 0, 0 };
	if (len <= 0)
		return NULL;
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
bool hasCycle(struct ListNode *head) {
	if (head == NULL)
		return false;
	struct ListNode *current = NULL, *current2 = NULL;

	current = head;   //���ÿ����һ��
	current2 = head;  //���������
	//������������ܹ������Ļ���˵���϶����л���
	int n = 0;
	while (true)
	{

		if (current == current2&&n>0)
		{
			printf("Circled��");
			return true;
		}
		if (current == NULL || current2 == NULL || current2->next == NULL)
			break;
		//if (n > 100)
		//{
		//	printf("There is bug!");
		//	break;
		//}

		n++;
		current = current->next;
		current2 = current2->next->next;
	}
	return false;
}

int main()
{
	ListNode *head = NULL,*current=NULL,*p=NULL, *link1 = NULL, *link2 = NULL;
	int nums1[4] = { 5, 9, 4, 9 };
	//int nums1[4];
	int size1 = 4;
	int nums2[2] = { 5, 1 };
	//int nums2[2];
	int size2 = 2;
	link1 = createNodeList(link1, nums1, size1);
	Print(link1);
	link2 = createNodeList(link2, nums2, size2);
	Print(link2);
	current = link1->next;
	while (current!=NULL)
	{
		if (current->next == NULL)
		{
			p = current;
		}

		current = current->next;
	}
	p->next = link1;
	hasCycle(link1);
	//head = addTwoNumbers1(link1, link2);
	//Print(head);
	//head = removeElements(head, 0);
	//Print(head);
	return 0;
}
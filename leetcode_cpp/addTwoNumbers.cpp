/*
time   :  2015-5-11
author :  ht
comment:  ��������ÿ������digit��������ʽ����洢��������ǵĺͣ��������洢
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
ListNode* createNodeList(ListNode *head,int*array,int len)
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
struct ListNode* traverse(struct ListNode*current, int *longLink, int len, int *index, int *mark, struct ListNode* head)
{
	if (current != NULL)
	{
		struct ListNode *p = NULL;
		traverse(current->next, longLink, len, index,mark,head);
		//current = current->next;
		
		int num1 = mark[0];
		int num2 = current->val;
		if (index[0] <= len)
		{
			num1 += longLink[len - index[0]];
		}
		
		num1 += num2;
		
		current->val = num1 % 10;
		mark[0] = num1 / 10;
		index[0]++;
		if (current == head&&(mark[0] >= 1))
		{
			struct ListNode* p = NULL;
			p = (struct ListNode*)malloc(sizeof(struct ListNode));
			p->val = mark[0];
			p->next = head;
			head = p;
			return head;
		}
		else
		{
			return current;
		}
			
	}
	else
	{
		index[0] = 1;
		mark[0] = 0;
		return NULL;
	}
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	//���������digitʱ��ĳ���
	struct ListNode *current, *shortLink = NULL, *longLink = NULL, *head = NULL;
	current = l1;
	int len1 = 0, len2 = 0;
	while (current != NULL)
	{
		len1++;
		current = current->next;
	}
	current = l2;
	while (current != NULL)
	{
		len2++;
		current = current->next;
	}
	int len = 0;
	if (len1 >= len2)
	{
		len = len2;
		//head = l1;
		longLink = l1;
		shortLink = l2;
	}
	else
	{
		len = len1;
		longLink = l2;
		shortLink = l1;
	}
	int *content = (int*)malloc(len*sizeof(int));
	int index = 0;
	current = shortLink;
	while (current != NULL)
	{
		content[index] = current->val;
		index++;
		current = current->next;
	}
	int mark = 0;
	index = 0;
	head = longLink;
	head = traverse(longLink, content,len, &index,&mark,head);
	return head;
}

struct ListNode* addTwoNumbers1(struct ListNode* l1, struct ListNode* l2) {
	//�����ʱ�������  �����ͺܼ��ˣ����ݹ鶼����Ҫ��
	//�������ʱ��򵥶���
	struct ListNode *current, *shortLink = NULL, *longLink = NULL, *head = NULL;
	current = l1;
	int len1 = 0, len2 = 0;
	while (current != NULL)
	{
		len1++;
		current = current->next;
	}
	current = l2;
	while (current != NULL)
	{
		len2++;
		current = current->next;
	}
	int len = 0;
	if (len1 >= len2)
	{
		len = len2;
		longLink = l1;
		shortLink = l2;
	}
	else
	{
		len = len1;
		longLink = l2;
		shortLink = l1;
	}

	int mark = 0;
	int num1;
	current = longLink;
	head = shortLink;
	while (current != NULL)
	{
		mark += current->val;
		if (head != NULL)
		{
			mark += head->val;
			head = head->next;
		}
		current->val = mark % 10;
		mark = mark / 10;
		if (current->next == NULL)
		{
			shortLink = current;
		}
		current = current->next;
	}
	if (mark >= 1)
	{
		current = (struct ListNode *)malloc(sizeof(struct ListNode));
		current->val = mark;
		current->next = NULL;
		shortLink->next = current;
	}
	return longLink;
}

int main()
{
	ListNode *head = NULL,*link1=NULL,*link2 =NULL;
	int nums1[4] = { 5, 9, 4, 9 };
	//int nums1[4];
	int size1 = 0;
	int nums2[2] = { 5, 1 };
	//int nums2[2];
	int size2 =0;
	link1 = createNodeList(link1,nums1,size1);
	Print(link1);
	link2 = createNodeList(link2, nums2, size2);
	Print(link2);
	head = addTwoNumbers1(link1, link2);
	Print(head);
	//head = removeElements(head, 0);
	//Print(head);
	return 0;
}
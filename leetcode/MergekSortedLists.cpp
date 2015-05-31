/*
time   :  2015-5-17
author :  ht
comment:  ʵ��k���Ѿ�����������ں�
//������õ��ĸ��Ӷ���nklogk��û�дﵽ�öѽ����õ�����ý��nlogk
//�����markһ���Ժ��ٷ���
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


struct ListNode* merge_list(struct ListNode*l1, struct ListNode*l2)
{
	//���������������ں�
	struct ListNode *head = NULL, *current1 = NULL, *current2 = NULL, *current = NULL;
	current1 = l1;
	current2 = l2;

	int value1, value2;
	int count = 0;
	if (l1 == NULL)
	{
		head = l2;
		return head;
	}
	if (l2 == NULL)
	{
		head = l1;
		return head;
	}
	while (current1 != NULL&&current2 != NULL)
	{
		value1 = current1->val;
		value2 = current2->val;

		if (value1 < value2)
		{
			if (count == 0)
			{
				head = current1;
				current = current1;
			}
			else
			{
				current->next = current1;
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
	if (current1 != NULL)
	{
		current->next = current1;
	}
	else if (current2 != NULL)
	{
		current->next = current2;
	}
	else
	{
		current->next = NULL;
	}

	return head;
}

struct ListNode* merge(struct ListNode** lists, int start,int end) {
	int mid = (start + end) / 2;
	struct ListNode *head = NULL;

	if (mid == start)
	{ 
		//�������������һ����start��end�غ�
		//��һ��start+1 == end���������ǻᵼ��start==mid==end
		if (end == start)
		{
			return lists[start];
		}
		else
		{
			head = merge_list(lists[start], lists[end]);
		}
	}
	else
	{
		struct ListNode *head1 = NULL, *head2 = NULL;
		head1 = merge(lists, start, mid);  // ���ַ� �鲢
		head2 = merge(lists, mid+1, end);
		head = merge_list(head1,head2);
	}

	return head;

}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	
	if (listsSize <= 0)
		return NULL;
	int start = 0,end = listsSize-1;
	struct ListNode *head = NULL;
	head = merge(lists, start, end);
	return head;
}

int main()
{
	ListNode *head1 = NULL, *head2 = NULL, *head3 = NULL, *head4 = NULL;

	//int  nums[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int  nums1[10] = { 1,4,9 };
	int len1 = 3;
	head1 = createNodeList(head1, nums1, len1);
	Print(head1);

	int  nums2[10] = { 0, 7, 8,8 };
	int len2 = 4;
	head2 = createNodeList(head2, nums2, len2);
	Print(head2);


	int  nums3[10] = { 2, 3, 3, 10,13 };
	int len3 = 5;
	head3 = createNodeList(head3, nums3, len3);
	Print(head3);

	int k = 1;
	struct ListNode** lists = (struct ListNode**)malloc(k*sizeof(struct ListNode*));
	lists[0] = head1;
	lists[1] = head2;
	lists[2] = head3;

	head1 = mergeKLists(lists, k);

	Print(head1);
	return 0;
}
/*
time   :  2015-5-14
author :  ht
comment:  ���Ѿ��Ź����е�������Ϊƽ�����������
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

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

struct ListNode* locate(struct ListNode* head,int n)
{
	// n��ʾλ��
	struct ListNode* current = NULL;
	current = head;
	int i = 0;
	while (i < n)
	{
		current = current->next;
		i++;
	}
	return current;
}


struct TreeNode* Node(struct TreeNode* current, struct ListNode *head, int len)
{
	// len��ʾ����ĳ���
	current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	int midIndex = len / 2;
	//��ȡ�Ͽ��ڵ����һ��ListNode

	if (len <= 2)
	{
		//�����������������һ����ֻʣһ��Ԫ����
		//����һ����ֻʣ����Ԫ����
		if (len == 1)
		{
			current->val = head->val;
			current->left = NULL;
			current->right = NULL;
			free(head);   
			head = NULL;
			//��֪��Ϊʲô  ��leetcode�ϱ���ȥ����Щָ�����ٲ���ͨ��
			//����ֵ�bug  ����vs����û���κ������
		}
		else
		{
			current->val = head->next->val;
			struct ListNode *p = head->next;
			head->next = NULL;

			current->left = Node(current->left, head, 1);
			//ֻʣ��һ����
			current->right = NULL;
			free(p);
			p = NULL;
		}

	}
	else
	{
		struct ListNode *p = NULL, *p1 = NULL, *head2 = NULL;  
		p = locate(head,midIndex-1);  //��¼Ҫ����ڵ����һ���ڵ�
		p1 = p->next;  //��¼�����ʱ�ڵ�
		head2 = p1->next;

		current->val = p1->val;
		p->next = NULL;

		free(p1);
		int len1 = midIndex;
		current->left = Node(current->left, head, midIndex);
		//left��ߵ��Ǵ�array�� 0��ʼ��midIndex-1
		int len2 = len - midIndex - 1;
		current->right = Node(current->right, head2, len2);
	}

	return current;

}

struct TreeNode* sortedListToBST(struct ListNode* head) {
	struct TreeNode* root = NULL;
	struct ListNode* current = NULL;
	if (head == NULL)
		return NULL;
	int len = 0;
	current = head;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	root = Node(root,head,len);
	return root;
}
int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	int value[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	//int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 2, 5, -1, -1, 2, -1, -1 };
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 2;
	for (int i = 0; i < nums; i++)
		value[i] -= 1;
	ListNode* head = NULL;

	head = createNodeList(head,value,nums);
	//head = locate(head, 3);
	//printf("%d \n",head->val);
	Print(head);

	root = sortedListToBST(head);
	//root = Node(root, value, nums);
	//root = sortedArrayToBST(value, nums);
	return 0;
}
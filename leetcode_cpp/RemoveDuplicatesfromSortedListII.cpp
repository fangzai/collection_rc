/*
time   :  2015-5-15
author :  ht
comment:  ɾ�������г����ظ���Ԫ��
          �������Ѷȱ�ex81��һЩ����Ϊ��Ҫ�ظ��Ķ�ɾ��
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
	int len = 1;
	int array[10] = { 0, 0, 2, 2, 3, 3, 4, 4, 5, 5 };
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

bool traverse(struct ListNode*head,int val)
{
	//�ж���ǰ�ڵ��Ƿ����ظ�
	//������ظ����ͰѺ�����ظ��ڵ�ɾ��
	//Ȼ�󷵻�true���˳�����ɾ��ǰ�ڵ�
	struct ListNode * current, *p = NULL;
	current = head;
	
	int deleteVal = val;
	bool del = false;
	while (current->next != NULL&&current->next->val == val)
	{
		del = true;
		p = current->next;

		current->next = p->next;
		free(p);
		p = NULL;
		
	}
	return del;
}

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode * current, *p = NULL;
	if (head == NULL)
		return NULL;

	// ��headǰ�����һ��INT_MIN��ֵ,�����Ϳ��Ա���һֱɾhead������
	p = (struct ListNode*)malloc(sizeof(struct ListNode));
	p->val = INT_MIN;
	p->next = head;
	head = p;

	current = head;
	int val = current->val;
	bool mark;

	while (current->next!=NULL&&current->next->next != NULL)
	{
		val = current->next->val;
		// ������һ�ڵ��ֵ
		//���� current->next֮��Ľڵ��Ƿ��current->next�ڵ�ֵһ��
		mark = traverse(current->next, val);
		//���һ���Ļ���Ҫɾ��current->next�ڵ�
		if (mark)  //ɾ��current->next�ڵ�
		{
			p = current->next;
			current->next = p->next;
			free(p);
			p = NULL;
		}
		else
		{
			//current->next�ǵ��ڵ㣬ֱ�ӹ�ȥ
			current = current->next;
		}

	}
	
	p = head;
	head = head->next;
	free(p);
	p = NULL;
	return head;
}

int main()
{
	ListNode *head = NULL;
	head = createNodeList(head);
	Print(head);
	head = deleteDuplicates(head);
	Print(head);
	//head = removeElements(head, 1);
	//Print(head);
	return 0;
}
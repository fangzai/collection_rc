/*
time   :  2015-5-10
author :  ht
comment:  ���������ҳ����ӵ�
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
ListNode* createNodeList(ListNode *head, ListNode **link,int label)  // i��ʾ��������ı��
{
	head = (ListNode*)malloc(sizeof(ListNode));
	int len1 = 5;
	int array1[5] = { 1, 3, 2, 5, 7};
	int array2[5] = { 1,3,4,5,6 };
	int len2 = 5;
	int i;
	ListNode * p1 = NULL;  // p1 ���洴�����½ڵ�ĵ�ַ
	ListNode * p2 = NULL;  // p2 ������������һ���ڵ�ĵ�ַ
	p1 = (ListNode*)malloc(sizeof(ListNode));
	p2 = p1;
	if (len1 <= 0)
	{
		head = NULL;   //�������  ����������
		return head;
	}

	for (i = 0; i < len1; i++)
	{
		p1->val = array1[i];

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

	link[0] = head;

	if (label == 2)
	{
		//array2����������ȥ
		ListNode* head1 = (ListNode*)malloc(sizeof(ListNode));
		p1 = (ListNode*)malloc(sizeof(ListNode));
		p2 = p1;
		ListNode * current = NULL;
		current = head;
		for (i = 0; i < len2; i++)
		{
			p1->val = array2[i];

			if (i == 0)
			{
				head1 = p1;
				p2->next = NULL;  //��ʱ��p2����p1���״θ�ֵ��ʱ��p2ָ���
				current = current->next;

			}
			else
			{
				p2->next = p1;   //ָ���ϴ�����ոտ��ٵ��½ڵ�
				current = current->next;
			}

			p2 = p1;    //��p1�ĵ�ַ��p2������Ȼ��p1�����µĽڵ�

			p1 = (ListNode*)malloc(sizeof(ListNode));  // �����µĵ�ַ
		}
		p2->next = current;

		free(p1);
		p1 = NULL;
		return head1;

	}

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
struct ListNode* location(struct ListNode*node, struct ListNode**addr, int*num, int len)
{
	if (node == NULL)
	{
		num[0] = 0;
		return NULL;
	}
	else
	{
		struct ListNode *temp = NULL;
		temp = location(node->next, addr, num,len); 
		//�����ºͽڵ�ĵ�ַ���õݹ����˼��Ҫ�Ӻ���ǰ�Ƚ�
		
		int index = len - num[0];//����ջ��index
		if (temp == addr[index])
		{
			//��֧1  
			// ���next��ͬ�����ص�ǰnode
			//��numҪ+1�������������
			num[0] += 1;
			return node;
		}
		else
		{
			//��֧2  
			//���򷵻�next��ָ��  num������
			//������������˳�
			return temp;
		}
		//printf("%d ",num[0]);
		//num[0] --;
		
	}
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL)
		return NULL;
	//if (headA == headB)
		//return headA;
	struct ListNode * current = NULL,* head=NULL;;
	current = headA;
	int size = 30000;
	struct ListNode** addr1 = (struct ListNode**)malloc(size*sizeof(struct ListNode*));
	// addr1�����൱��һ��ջ�����ں���һ������ݹ��ʱ��Ƚ�
	//int *addr2 = (int*)malloc(size*sizeof(int));
	int len = 0;
	while (current != NULL)
	{
		addr1[len] = current;
		len++;
		current = current->next;
	}
	addr1[len] = NULL;
	current = headB;
	int num;  //���ڼ�¼�����index
	
	head = location(current,addr1,&num,len);
	//��������⼸��  ��Ϊ������  A�������B��������
	//��[1,2] [2]  Ҳ����˵������head���ܴӵݹ麯����֧1������
	int index = len - num;
	if (head == addr1[index])
	{
		return head;
	}
	//num += 1;
	//printf("%d ", num);
	return head->next;
}

int main()
{
	ListNode *link1 = NULL, *link2 = NULL, *head = NULL;

	int array1[5] = { 1, 5, 7, 8, 9 };
	int num1 = 5;
	int *array2 = NULL;
	int num2 = 0;
	//link1 = createNodeList(link1,1);
	//Print(link1);

	link2 = createNodeList(link2,&link1, 2);
	Print(link1);
	Print(link2);
	
	head = getIntersectionNode(link1,link2);
	Print(head);
	return 0;
}
/*
time   :  2015-5-12
author :  ht
comment:  �ж������Ƿ��л�,���ػ���λ��
# ǰ�������������� intersect link list�Ľ��
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
		temp = location(node->next, addr, num, len);
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
	struct ListNode * current = NULL, *head = NULL;;
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

	head = location(current, addr1, &num, len);
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

struct ListNode *detectCycle(struct ListNode *head) {
	if (head == NULL)
		return false;
	struct ListNode *current = NULL, *current2 = NULL, *head2=NULL;

	current = head;   //���ÿ����һ��
	current2 = head;  //���������
	//������������ܹ������Ļ���˵���϶����л���
	bool mark = false;  //Ĭ��û�л�
	int n = 0;
	while (true)
	{


		if (current == NULL || current2 == NULL || current2->next == NULL)
			break;
		
		if (current->next == current2->next->next&&n>0)
		{
			printf("Circled��");

			head2 = current2->next->next; 
			//���ϻ�  һ��Ҫ��current2��
			//current2�ܹ���֤���ڻ����棬����current����
			current2->next->next = NULL;
			//return true;
			mark = true; //�л�  
			//����ط��Ͽ�֮�������������ͷ��
			// head �� head2
			break;

		}
		n++;
		current = current->next;
		current2 = current2->next->next;
		
	}

	//���ý���������ж�����
	if (mark)
	{
		head = getIntersectionNode(head,head2);
		return head;
	}

	return NULL;
}

int main()
{
	ListNode *head = NULL, *current = NULL, *p = NULL, *link1 = NULL, *link2 = NULL;
	int nums1[5] = { 1, 2, 3, 4,5 };
	//int nums1[4];
	int size1 = 5;
	int nums2[2] = { 5, 1 };
	//int nums2[2];
	int size2 = 2;
	link1 = createNodeList(link1, nums1, size1);
	Print(link1);
	link2 = createNodeList(link2, nums2, size2);
	Print(link2);
	current = link1->next;
	while (current != NULL)
	{
		if (current->next == NULL)
		{
			p = current;
		}

		current = current->next;
	}
	p->next = link1->next->next->next->next;
	head = detectCycle(link1);
	printf("%d \n", head->val);	
	//head = addTwoNumbers1(link1, link2);
	//Print(head);
	//head = removeElements(head, 0);
	//Print(head);
	return 0;
}
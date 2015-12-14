/*
time   :  2015-5-12
author :  ht
comment:  �������Ľ��浹��
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
struct ListNode* traverse(struct ListNode* current, struct ListNode *head, int frontIndex, int*tailIndex,struct ListNode **pointer)
{
	// pointer[0]�Ĺ�����ָ��ǰ�ڵ���Ҫ�ı��λ�ã�ǰ�棩
	// ����ÿ���ظ����������δ֪
	// current�Ǻ���Ҫ�ı��λ��
	struct ListNode*p1=NULL, *p2 = NULL,*temp=	NULL;
	if (current->next->next == NULL)
	{
		//index[0] = 0;
		pointer[0] = head->next;
		p1 = current->next;
		p2 = head->next;
		head->next = p1;
		p1->next = p2;
		current->next = NULL;
		tailIndex[0] = 0;
		
		return current;
	}
	else
	{
		int location = 0;
		frontIndex++;
		temp = traverse(current->next, head, frontIndex, tailIndex, pointer);
		tailIndex[0]++;
		
		int i=0;
		if (frontIndex > tailIndex[0])
		{	
			//��Ϊ�޶���frontIndex�ģ�����current�����ܵ�p1��ǰ��ȥ
			//ע������ط����ж�����
			p1 = current->next;
			p2 = pointer[0]->next;
			if (p1 != p2)
			{
				//�ݹ��˳�������
				pointer[0]->next = p1;
				p1->next = p2;
				pointer[0] = p2;
				//ÿ�εݹ������ʱ��pointer����ָ����һ��Ҫ�����ĵط�
				//�ñ�����ָ��
				current->next = NULL;
			}
			return current;
		}
		else
		{
			return head;
		}

	}
}
void reorderList(struct ListNode* head) {
	int frontIndex = 0,tailIndex,len=0;
	struct ListNode*current=NULL,*pointer=NULL;

	current = head;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	if (head == NULL)
	{
		head = NULL;
	}
	else
	{
		
		if (head->next == NULL||head->next->next==NULL)
		{
			//head = NULL;
			int n = 0;
		}
		else
		{
			head = traverse(head, head, frontIndex, &tailIndex,&pointer);
		}
	}
	
}

//�û�״������һ��
struct ListNode* traverse1(struct ListNode* current, struct ListNode *head)
{
	 // pointer����һ��ָ�����Ҫ��ӵ�λ�ã�pointer��������εݹ��б��ɵ�
	struct ListNode* virtualHead = NULL, *p1 = NULL, *p2 = NULL,*temp=NULL;
	
	if (current->next->next == NULL)
	{
		//ɾ����������һ��
		current->next->next = head;
		virtualHead = head;
		p1 = current->next;
		p2 = virtualHead->next;

		virtualHead->next = p1;
		p1->next = p2;

		virtualHead = virtualHead->next->next;
		//current->next = virtualHead;
		current->next = NULL;
		return virtualHead;
	}
	else
	{
		virtualHead = traverse1(current->next, head);
		if (virtualHead == head)
			return head;//�ݹ����
		p1 = current->next;
		p2 = virtualHead->next;
		if (p1 != p2&&p1->next!=virtualHead)
		{
			//�����������˳������һ����p1 �� p2�ص���
			//����һ������һ�εݹ��У�virtualHead�������current
			//����������֮����� current�� vhead������һ��λ��
			virtualHead->next = p1;
			p1->next = p2;
			virtualHead = virtualHead->next->next;
			//current->next = virtualHead;
			current->next = NULL;
			return virtualHead;
		}
		else
		{
			return head;
		}
		
	}
	
	return false;
}
void reorderList1(struct ListNode* head) {

	if (head == NULL)
	{
		head = NULL;
	}
	else
	{

		if (head->next == NULL || head->next->next == NULL)
		{
			//head = NULL;
			int n = 0;
		}
		else
		{
			head = traverse1(head, head);
		}
	}

	//head ����ݹ� head2��������

}
int main()
{
	ListNode *head = NULL, *current = NULL, *p = NULL, *link1 = NULL, *link2 = NULL;
	int nums1[5] = { 1, 2, 3, 4 ,5};
	//int nums1[4];
	int size1 = 4;
	int nums2[2] = { 5, 1 };
	//int nums2[2];
	int size2 = 2;
	link1 = createNodeList(link1, nums1, size1);
	Print(link1);
	link2 = createNodeList(link2, nums2, size2);
	Print(link2);
	//current = link1->next;
	reorderList1(link1);
	Print(link1);
	//head = addTwoNumbers1(link1, link2);
	//Print(head);
	//head = removeElements(head, 0);
	//Print(head);
	return 0;
}
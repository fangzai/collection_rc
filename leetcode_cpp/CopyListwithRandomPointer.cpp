/*
time   :  2015-5-27
author :  ht
comment:  ��ȸ������ָ��
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<stack>
#include<vector>
#include<map>
using namespace std;
// Definition for singly-linked list with a random pointer.
/*
 *struct RandomListNode {
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;
};
*/

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
};
struct RandomListNode* createNodeList(struct RandomListNode*head)
{
	head = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
	int len = 5;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	int i;
	if (len <= 0)
		return NULL;
	struct RandomListNode * p1 = NULL;  // p1 ���洴�����½ڵ�ĵ�ַ
	struct RandomListNode * p2 = NULL;  // p2 ������������һ���ڵ�ĵ�ַ
	p1 = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
	p1->random = NULL;
	p2 = p1;

	for (i = 0; i < len; i++)
	{
		p1->label = array[i];

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

		p1 = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));  // �����µĵ�ַ
		p1->random = NULL;
	}
	p2->next = NULL;   // p2һֱ��ĩ�˽ڵ�


	free(p1);
	p1 = NULL;
	return head;
}
void Print(struct RandomListNode* head)
{
	struct RandomListNode *current;
	printf("Begin to output the node of this linklist\n");
	current = head;
	int i = 0;
	if (current != NULL)
	{
		do
		{
			printf("%d ", current->label);
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

class Solution {
public:
	
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode * newHead = traverse(head);
		return newHead;
	}
	RandomListNode * traverse(RandomListNode *head)
	{
		map<RandomListNode *, RandomListNode *>map1,map2,map3;
		//map1 ӳ�� ���������ָ��֮��Ĺ�ϵ
		//map2 ӳ�� �¾�����ڵ�֮��Ĺ�ϵ
		//map3 ӳ�� ���������ָ��֮��Ĺ�ϵ

		RandomListNode *current = NULL, *newHead = NULL,*p=NULL,*randomPointer=NULL;
		current = head;
		while (current != NULL)
		{
			p = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
			p->next = NULL;
			p->random = NULL;
			p->label = current->label;
			if (current->random != NULL)
			{
				map1.insert(pair<RandomListNode *, RandomListNode *>(current, current->random));
			}
			map2.insert(pair<RandomListNode *, RandomListNode *>(current,p));  //���еĽڵ㶼map��
			if (current == head)
			{
				pre = p;
				newHead = p;
			}
			else
			{
				pre->next = p;
				pre = pre->next;
			}
			current = current->next;
		}

		current = head;
		p = newHead;
		while (current != NULL)
		{
			if (map1.find(current) != map1.end())
			{
				randomPointer = map1[current];  //ͨ��map1�ҵ�  current��random�ڵ�
				map3.insert(pair<RandomListNode *, RandomListNode *>(map2[current], map2[randomPointer]));
				map2[current]->random = map2[randomPointer]; //ͨ��map2�ҵ� ��Ӧcurrent�Ǹ��ڵ�� random�ڵ�
			}
			current = current->next;
			//p = p->next;
		}
		return newHead;
	}
};
int main()
{
	struct RandomListNode *head = NULL, *current = NULL,*result=NULL, *link[10];
	head = createNodeList(head);
	Print(head);
	int i = 0;
	current = head;
	while (current != NULL)
	{
		link[i] = current;
		current = current->next;
		i++;
	}
	link[0]->random = link[3];
	link[2]->random = link[3];
	Solution mine;
	result = mine.copyRandomList(head);
	return 0;
}
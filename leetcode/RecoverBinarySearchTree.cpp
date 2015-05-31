/*
time   :  2015-5-25
author :  ht
comment:  �����������Ļָ�������������Ԫ�ؽ�����
		  ��Ҫ���������ҳ��������һָ�ԭ����tree
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

TreeNode* Node(TreeNode* current, int *index, int*value, int nums)
{
	//����������������� ������ʽ���������
	current = (TreeNode*)malloc(sizeof(TreeNode));
	if (value[index[0]] != -1)
	{
		current->val = value[index[0]];
		current->left = NULL;
		index[0]++;
		if (index[0] < nums)
		{
			current->left = Node(current->left, index, value, nums);
		}
		current->right = NULL;
		if (index[0] < nums)
		{
			current->right = Node(current->right, index, value, nums);
		}
	}
	else
	{
		current = NULL;
		index[0]++;
	}
	return current;
}

/*
*ƽ���������� : root->key  ����  left->key
*               root->key  С��  right->key
*               ����������Ҳ��ƽ����
*/
//���뵽Ҫ������¼�����ڵ㣬���λ���������д��ʱ���Ȼû���Լ�д����������
void traverse(struct TreeNode* current,struct TreeNode **p1, struct TreeNode**p2, struct TreeNode**pre)
{
	//�������������������Υ������ľ�������mistake
	if (current == NULL) return;
	
	traverse(current->left,p1, p2,pre);
	//��������current,�ȸ�pre��ֵ
	if (pre[0] != NULL&&pre[0]->val > current->val)
	{
		//�ҵ�Υ���������  ǰ��Ľڵ�һ��Ҫ�Ⱥ����С
		//���Ի�һ��ͼ��������һ��Υ����ʱ��һ����һ�����壬Υ���Ľڵ��ǲ���
		//Ҳ����pre

		//�ڶ���Υ����ʱ����һ������
		//��Υ���Ľڵ����current,����else�������Ǹ�p2��ֵ
		
		//��Ϊʲô��if�ж������һ������p1��p2����ֵ�ˣ�
		//������Ϊ���������ĵ���������ڵģ���p1��pre��p2����current
		//�պ�������岨�ȵ���ʽ����������Υ������ķ�����һ�µ�
		if (p1[0] == NULL)
		{
			p1[0] = pre[0];
			p2[0] = current;
		}
		else
		{
			p2[0] = current;
		}
	}
	pre[0] = current;  //���ڻ�����current��pre
	traverse(current->right, p1, p2, pre);  //����������

}
void recoverTree(struct TreeNode* root) {
	struct TreeNode*p1, *p2, *pre;
	int tmp;
	p1 = NULL;
	p2 = NULL;
	pre = NULL;
	traverse(root, &p1, &p2, &pre);
	//��󽻻�������
	if (p1 != NULL&&p2 != NULL)
	{
		tmp = p1->val;
		p1->val = p2->val;
		p2->val = tmp;
	}
}
int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	//int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	int value[15] = { 6, 3, 1, -1, -1, 10, -1, -1, 5, 9, -1, -1, 12, -1, -1 };
	//int value[15] = {1,-1,2,-1,3,-1,-1};
	//int value[15] = { 3, 1, 0, -1, -1, 2, -1, 3, -1, -1, 5, -1, -1 };   //��ƽ���� ��Ϊ���ظ�Ԫ��
	//����һ������
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 15;
	root = Node(root, &index, value, nums);
	int returnSize = 0;
	recoverTree(root);
	return 0;
}
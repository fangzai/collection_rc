/*
time   :  2015-5-11
author :  ht
comment:  �ж����������Ƿ��ǶԳ���
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
bool traverse(struct TreeNode*current, struct TreeNode*mirror)
{
	//�����ǶԳƵ������ڵ�
	if (current != NULL&&mirror != NULL)
	{
		if (current->val == mirror->val)
		{
			bool mark1 = traverse(current->left, mirror->right);  
			// ��һ��
			bool mark2 = traverse(current->right, mirror->left);
			//��һ��
			return mark1&&mark2;
			
		}
		else
		{
			return false;  //���Գ�
		}
	}
	else
	{
		if (current == NULL&&mirror == NULL)
		{
			return true;
		}
		else
		{
			return false;  // mirror��current��һ�����ǿ�
		}
	}


}

bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;
	else
	{
		return traverse(root->left,root->right);
	}

	//return false;
}

int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	//int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 2, 5, -1, -1, 2, -1, -1 };
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 13;
	root = Node(root, &index, value, nums);
	if (isSymmetric(root))
	{
		printf("Is symmetric......\n");
	}
	else
	{
		printf("Not symmetric......\n");
	}
	return 0;
}
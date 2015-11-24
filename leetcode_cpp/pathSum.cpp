/*
time   :  2015-5-10
author :  ht
comment:  ��root��Ҷ�ӽڵ�·�����Ƿ���ڸ�����ֵ
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
*��һ��������ĸ߶Ȳ�һ������ΪҪȷ��Ҷ�ӽڵ�
*��Σ����ֻ��һ��root�Ļ�����ô����leaf�ľ����� 1 ��ȥ����ʲô�ƹ涨����
*������ʱ����������
* 1 �ڵ���Ҷ��
* 2 �ҽڵ�Ϊ�գ���ڵ㲻��
* 3 ��ڵ�Ϊ�գ��ҽڵ㲻��
* 4 ���ҽڵ������ݺͺ���
*/
bool traverse(struct TreeNode* current,int currentValue,int sum)
{
	int total = 0;
	total = current->val + currentValue;
	if ((current->left == NULL) && (current->right == NULL))
	{
		if (total == sum)
			return true;
		return false;
		//һ��Ҫȷ��Ҷ��
	}
	else
	{
		if (current->left == NULL)
		{
			return traverse(current->right, total, sum);
		}
		if (current->right == NULL)
		{
			return traverse(current->left, total, sum);
		}
		bool left = traverse(current->left, total, sum);
		bool right = traverse(current->right, total, sum);
		
		return left||right;

	}
}
bool hasPathSum(struct TreeNode* root, int sum) {
	
	if (root == NULL)
	{ 
		return false;
	}
	int value = 0;
	//int value = root->val;
	
	bool mark = traverse(root, value, sum);
	return mark;
}
int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	//int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1 };
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 0;
	root = Node(root, &index, value, nums);
	int sum = 0;

	if (hasPathSum(root, sum))
	{
		printf("in sum......");
	}
	else
	{
		printf("Not in sum......");
	}
	return 0;
}
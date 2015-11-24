/*
time   :  2015-5-15
author :  ht
comment:  �������������
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

bool traverse(struct TreeNode* current,int*index,int*result)
{
	if ((current->left == NULL) && (current->right == NULL))
	{
		result[index[0]] = current->val;
		index[0]++;  //����������
		return true;
	}
	else
	{
		if (current->left != NULL)
		{
			traverse(current->left, index, result);   //����������
		}
		result[index[0]] = current->val;
		index[0]++;  //���ڼ�����
		
		if (current->right != NULL)
		{
			//����������
			traverse(current->right, index, result);
		}
		return true;
	}
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	returnSize[0] = 0;
	if (root == NULL)
		return NULL;
	int size = 1000;
	int *result = (int*)malloc(size * sizeof(int));
	traverse(root,returnSize,result);
	return result;
}
int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	//int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1 };
	//����һ������
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 15;
	root = Node(root, &index, value, nums);
	int returnSize = 0;
	int *result = inorderTraversal(root,&returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}
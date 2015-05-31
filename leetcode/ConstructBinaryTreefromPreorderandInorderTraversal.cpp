/*
time   :  2015-5-19
author :  ht
comment:  ͨ��ǰ���������������ؽ�������
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
struct TreeNode* reConstruct(int* preorder, int *preStart, int preEnd, int* inorder, int inStart, int inEnd)
{
	if (inStart == inEnd)
	{
		struct TreeNode* current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		//ֻʣ��һ����
		current->val = preorder[preStart[0]];
		current->left = NULL;
		current->right = NULL;
		preStart[0]++;
		return current;
	}
	else
	{
		//��������ĵ�һ��Ԫ�ؿ϶��ǵ�ǰ�ĸ��ڵ� ���Ҹýڵ������������λ��
		int keyValue = preorder[preStart[0]];
		int i;
		int index = 0;
		for (i = inStart; i <= inEnd; i++)
		{
			if (keyValue == inorder[i])
			{
				index = i;
				break;
			}
		}
		//index����������������������index���ұ����������������б���

		struct TreeNode* current = NULL, *left = NULL, *right = NULL;
		current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		current->val = keyValue;
		preStart[0]++;
		//�ݹ�������
		if ((index - 1) >= inStart)
		{
			//�ж�����Ƿ���ֵ
			left = reConstruct(preorder, preStart, preEnd, inorder, inStart, index - 1);
		}
		else
		{
			//������û��ֵ�Ļ�����leftֱ�Ӿ͸�ֵΪ��
			left = NULL;
		}

		//�ݹ�������
		if ((index + 1) <= inEnd)
		{
			//�ж��ұ��Ƿ���ֵ
			right = reConstruct(preorder, preStart, preEnd, inorder, index + 1, inEnd);
		}
		else
		{
			//����ұ�û��ֵ�Ļ�����rightֱ�Ӿ͸�ֵΪ��
			right = NULL;
		}
		current->right = right;
		current->left = left;
		return current;
	}
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	//����reConstruct���еݹ�
	if (preorderSize <= 0)
	{
		return NULL;
	}
	struct TreeNode* root = NULL;
	int preStart = 0, preEnd = preorderSize - 1;
	int inStart = 0, inEnd = preorderSize - 1;
	root = reConstruct(preorder, &preStart,preEnd, inorder, inStart,inEnd);
	return root;
}

int main()
{
	//int preorder[7] = {1,2,4,5,3,6,7};
	//int inorder[7] = {4,2,5,1,6,3,7};
	//int preorder[6] = {1,2,5,3,6,7};
	//int inorder[6] = {2,5,1,6,3,7};
	int preorder[6] = {1,2,3,4};
	int inorder[6] = {1,3,4,2};
	int numsize = 4;
	TreeNode* root = NULL;

	root = buildTree(preorder,numsize,inorder,numsize);
	return 0;
}
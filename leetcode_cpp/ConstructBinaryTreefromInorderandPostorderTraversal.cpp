/*
time   :  2015-5-19
author :  ht
comment:  ͨ�������������������ؽ�������
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
struct TreeNode* reConstruct(int* postorder, int postStart, int *postEnd, int* inorder, int inStart, int inEnd)
{
	//postEnd���ָ���ڵݹ��������Ҫһֱ�ݼ�����ȫ����Ч
	if (inStart == inEnd)
	{
		struct TreeNode* current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		//ֻʣ��һ����
		current->val = postorder[postEnd[0]];
		current->left = NULL;
		current->right = NULL;
		postEnd[0]--;
		return current;
	}
	else
	{
		//��������ĵ����һ��Ԫ�ؿ϶��ǵ�ǰ�ĸ��ڵ� ���Ҹýڵ������������λ��
		int keyValue = postorder[postEnd[0]];
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
		postEnd[0]--;

		//����ط��ݹ�����������˳���ex105 ͨ������+���� �ع�����˳��һ��
		//���Լ���һ�£����ں������keyValue�ĺ���һ��ֵ�϶�����������keyValue
		//�ݹ�������
		if ((index + 1) <= inEnd)
		{
			//�ж��ұ��Ƿ���ֵ
			right = reConstruct(postorder, postStart, postEnd, inorder, index + 1, inEnd);
		}
		else
		{
			//����ұ�û��ֵ�Ļ�����rightֱ�Ӿ͸�ֵΪ��
			right = NULL;
		}

		//�ݹ�������
		if ((index - 1) >= inStart)
		{
			//�ж�����Ƿ���ֵ
			left = reConstruct(postorder, postStart, postEnd, inorder, inStart, index - 1);
		}
		else
		{
			//������û��ֵ�Ļ�����leftֱ�Ӿ͸�ֵΪ��
			left = NULL;
		}


		current->right = right;
		current->left = left;
		return current;
	}
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	//����reConstruct���еݹ�
	if (postorderSize <= 0)
	{
		return NULL;
	}
	struct TreeNode* root = NULL;
	int postStart = 0, postEnd = postorderSize - 1;
	int inStart = 0, inEnd = postorderSize - 1;
	root = reConstruct(postorder, postStart, &postEnd, inorder, inStart, inEnd);
	return root;
}

int main()
{
	//int preorder[7] = {1,2,4,5,3,6,7};
	//int inorder[7] = {4,2,5,1,6,3,7};
	//int postorder[7] = {4,5,2,6,7,3,1};
	//int preorder[6] = {1,2,5,3,6,7};
	//int inorder[6] = {2,5,1,6,3,7};
	//int postorder[6] = { 5,2,6,7,3,1 };
	//int preorder[6] = { 1, 2, 3, 4 };
	int inorder[6] = { 1, 3, 4, 2 };
	int postorder[6]={4,3,2,1};
	int numsize = 4;
	TreeNode* root = NULL;

	root = buildTree(inorder, numsize, postorder, numsize);
	return 0;
}
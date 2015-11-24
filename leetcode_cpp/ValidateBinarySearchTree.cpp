/*
time   :  2015-5-16
author :  ht
comment:  ��������������֤
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
                 root->key  С��  right->key
				 ����������Ҳ��ƽ����
 */
int* traverse(struct TreeNode* current)
{
	
	//��Ҫ����һ�����飬ÿ�η��ص����� BST���Ե��ж�  �Լ����������Ԫ�غ���СԪ��
	if ((current->left == NULL) && (current->right == NULL))
	{
		int *result = (int*)malloc(3*sizeof(int));
		result[0] = 1;
		result[1] = current->val;  //��Сֵ  left  
		result[2] = current->val;  //���ֵ  right
		return result;
	}
	else
	{
		int *result = (int*)malloc(3 * sizeof(int));
		int *leftResult=NULL,*rightResult=NULL;

		if (current->left != NULL)
		{
			if (current->right != NULL)
			{
				leftResult = traverse(current->left);
				rightResult = traverse(current->right);
				if (rightResult[0] && leftResult[0]&&current->val>leftResult[2]&&current->val<rightResult[1])
				{
					result[0] = 1;
					result[1] = leftResult[1]; //����������Сֵ
					result[2] = rightResult[2];//�����������ֵ
				}
				else
				{
					result[0] = 0;
				}
				free(leftResult);  //�ڴ����
				leftResult = NULL;
				free(rightResult);
				rightResult = NULL;

			}
			else
			{
				leftResult = traverse(current->left);
				if (leftResult[0] && current->val > leftResult[2])
				{
					result[0] = 1;
					result[1] = leftResult[1]; //��СԪ�ز���
					result[2] = current->val;  //���Ԫ�ظ���Ϊ��ǰroot��nodeֵ
				}
				else
				{
					result[0] = 0;
				}
				free(leftResult);     //�ڴ����
				leftResult = NULL;
			}
			
		}
		else
		{
			rightResult = traverse(current->right);
			if (rightResult[0] && current->val < rightResult[1])
			{
				result[0] = 1;
				result[1] = current->val;    //��СԪ�ظ���Ϊ��ǰroot��nodeֵ
				result[2] = rightResult[2];  //���Ԫ�ز���
			}
			else
			{
				result[0] = 0;
			}
			free(rightResult);   //�ڴ����
			rightResult = NULL;
			
		}
		return result;
	}
}
bool isValidBST(struct TreeNode* root) {
	if (root == NULL)
		return true;
	int *result = traverse(root);
	bool mark = result[0];
	
	
	free(result);     //�ڴ����
	result = NULL;  
	return  mark;
}
int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	//int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	//int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1 };
	//int value[15] = {1,-1,2,-1,3,-1,-1};
	int value[15] = { 3,1,0,-1,-1,2,-1,3,-1,-1,5,-1,-1 };   //��ƽ���� ��Ϊ���ظ�Ԫ��
	//����һ������
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 11;
	root = Node(root, &index, value, nums);
	int returnSize = 0;
	if (isValidBST(root))
	{
		printf("Is BST!\n");
	}
	else
	{
		printf("Not BST!\n");
	}
	return 0;
}
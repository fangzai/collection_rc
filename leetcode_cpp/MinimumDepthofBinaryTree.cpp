/*
time   :  2015-5-10
author :  ht
comment:  ��root��Ҷ�ӽڵ�����Ľڵ�
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
/*
 *��һ��������ĸ߶Ȳ�һ������ΪҪȷ��Ҷ�ӽڵ�
 *��Σ����ֻ��һ��root�Ļ�����ô����leaf�ľ����� 1 ��ȥ����ʲô�ƹ涨����
 *������ʱ���������� 
 * 1 �ڵ���Ҷ��
 * 2 �ҽڵ�Ϊ�գ���ڵ㲻��
 * 3 ��ڵ�Ϊ�գ��ҽڵ㲻��
 * 4 ���ҽڵ������ݺͺ���
 */
int traverse(struct TreeNode* current)
{
	int left = 0;
	int right = 0;
	int height = 0;
	if ((current->left == NULL)&&(current->right == NULL))
	{
		return 0;       
		//һ��Ҫȷ��Ҷ��
		//��ex104����벻һ��
	}
	else
	{
		if (current->left == NULL)
		{
			return 1 + traverse(current->right);
		}
		if (current->right == NULL)
		{
			return 1+ traverse(current->left);
		}
		right = traverse(current->right);
		left = traverse(current->left);
		height = left > right ? right : left;
		return height + 1;
			
	}
}
int minDepth(struct TreeNode* root) {
	int height = 0;
	if (root == NULL)
		return 0;
	height = traverse(root);
	return height+1;  //����ط�Ҫ+1
}

int main()
{
	return 0;
}
/*
time   :  2015-5-19
author :  ht
comment:  ��ʵ����������������뵽�˴ӵײ������ʱ��
		  ����Сֵ��ʼ��һ������һֱ�����������ʵ���Ƕ���

*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
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
	if (nums <= 0)
	{
		return NULL;
	}
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
 * Ҳ����дһ��c����ʵ�ֵĶ��У�����д��
 */
class BSTIterator {
	queue<TreeNode*> bst;
public:
	BSTIterator(TreeNode *root) {
		inOrder(root);

	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (bst.empty())
			return false;
		return true;
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *current = bst.front();
		bst.pop();
		return current->val;
	}
	void inOrder(TreeNode *root)
	{
		if (root != NULL)
		{
			inOrder(root->left);
			bst.push(root);
			inOrder(root->right);
		}
	}
};

int main()
{

	int value[15] = { 8, 4, 2, -1, -1, 7, -1, -1, 12, 11, -1, -1, 15, -1, -1 };
	struct TreeNode* root = NULL;
	int index = 0;
	int nums = 15;
	root = Node(root, &index, value, nums);

	BSTIterator *mine = new BSTIterator(root);

	while (mine->hasNext())
		cout << mine->next() << endl;
	cout << endl;
	return 0;
}
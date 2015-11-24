/*
time   :  2015-5-27
author :  ht
comment:  һ�����е����·��
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<stack>
#include<vector>
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

class Solution {
public:
	int maxValue = INT_MIN;
	int maxPathSum(TreeNode* root) {
		if (root == NULL)
			return 0;
		int result= traverse(root);
		return result > maxValue ? result : maxValue;
	}
	int myMax(int a,int b)
	{
		return a > b ? a : b;
	}
	int myMin(int a, int b)
	{
		return a > b ? b : a;
	}
	int  traverse(TreeNode* current)
	{
		//��ʼ��ʱ���Ҿ������˼·�������ڲ��ĺ������ⲿ��
		//����д�����ʱ���Զ��򿪣���Ȼ������current->val������ ���sum
		//Ȼ���2B�ˣ���ô�򵥵�һ����  ��������С��0�������������
		//����Ȼ2B��~~~~~
		if (current == NULL)
			return 0;
		int value = current->val;
		int leftMax = 0;
		int rightMax = 0;
		if (current->left != NULL)
		{
			leftMax = traverse(current->left);
			if (leftMax > 0)
			{
				value += leftMax; //ֻ����ߴ���0��ʱ��żӽ���
			}
		}
		//ͬ�����������һ��
		if (current->right != NULL)
		{
			rightMax = traverse(current->right);
			if (rightMax > 0)
			{
				value += rightMax;
			}
		}
		if (value > maxValue)
			maxValue = value;  //�����ʵ��ÿ�θ��������ڲ������ֵ

		//��Ϊ���ֻ��һ��·��
		//��󷵻ص�Ҫ�õ����������ĸ�������ȥ
		return myMax(current->val,myMax(leftMax+current->val,rightMax+current->val));

	}
};


int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	//int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	//int value[15] = { 6, 3, 1, -1, -1, 10, -1, -1, 5, 9, -1, -1, 12, -1, -1 };
	//int value[15] = {1,-1,2,-1,3,-1,-1};
	int value[15] = { 3, 1, 0, -1, -1, 2, -1, 3, -1, -1, 5, -1, -1 };   //��ƽ���� ��Ϊ���ظ�Ԫ��
	//����һ������
	//int value[15] = { 1,2,-1,-1,3,-1,-1};
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 15;
	root = Node(root, &index, value, nums);
	Solution mine;
	int result = 0;
	result = mine.maxPathSum(root);
	
	cout << result << endl;
	return 0;
}
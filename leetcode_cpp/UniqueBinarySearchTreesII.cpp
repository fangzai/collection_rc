/*
time   :  2015-5-16
author :  ht
comment:  1.....n��������BST ����������
		  �������еĶ���������
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// �����c����д̫�鷳��������ÿ�ζ����صĲ�ͬ���Ǹ�left��right��Ķ���
class Solution {
public:
	Solution(){};
	vector<TreeNode *> generateTrees(int n) {
		return createTree(1, n);
	}

	vector<TreeNode *> createTree(int start, int end)
	{
		vector<TreeNode *> results;
		if (start>end)
		{
			results.push_back(NULL);
			return results;
		}

		for (int k = start; k <= end; k++)
		{
			//ȷ��root�ڵ�
			vector<TreeNode *> left = createTree(start, k - 1);
			vector<TreeNode *> right = createTree(k + 1, end);
			for (int i = 0; i<left.size(); i++)
			{
				for (int j = 0; j<right.size(); j++)
				{
					TreeNode * root = new TreeNode();
					root->val = k;
					root->left = left[i];
					root->right = right[j];
					results.push_back(root);
				}
			}
		}
		return results;
	}
};

/*
 * c����ʵ�ְ汾 ��ʾ�����Լ�д��  5-19��
 */
struct TreeNode** reConstruct(int start, int end, int *size)
{
	struct TreeNode** result = NULL;
	if (start >= end)
	{
		result = (struct TreeNode**)malloc(1 * sizeof(struct TreeNode*));
		size[0]++;
		if (start > end)
		{
			result[0] = NULL;  //���һ������û����
		}
		else
		{
			result[0] = (struct TreeNode*)malloc(1 * sizeof(struct TreeNode));
			result[0]->val = start;//ֻʣһ��������
			result[0]->left = NULL;
			result[0]->right = NULL;
		}

		return result;
	}
	else
	{
		int k, i, j;

		//���ȣ�ѡһ��k��ΪkeyValue
		int leftSize = 0, rightSize = 0;

		result = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
		//û�а취����result�Ĵ�С��������ǰ����һ���
		int count = 0;
		for (k = start; k <= end; k++)
		{
			//�᷵��һ�ѿ��е�left��right;
			leftSize = 0;
			rightSize = 0;
			struct TreeNode** left = reConstruct(start, k - 1, &leftSize);
			//������ɵļ���

			struct TreeNode** right = reConstruct(k + 1, end, &rightSize);
			//�ұ����ɵļ���
			for (i = 0; i < leftSize; i++)
			{
				for (j = 0; j < rightSize; j++)
				{
					struct TreeNode*root = (struct TreeNode*)malloc(1 * sizeof(struct TreeNode*));
					root->val = k;  //kΪ��ǰroot
					root->left = left[i];
					root->right = right[j];
					result[count] = root;
					count++;
				}
			}
		}
		size[0] = count;  //��ʾ��ǰ���ϵĴ�С
		return result;
	}
}

struct TreeNode** generateTrees(int n, int* returnSize) {
	int count = 0;
	struct TreeNode** root = reConstruct(1, n, &count);
	returnSize[0] = count;
	return root;
}
int main()
{
	//Solution UBST;
	//int n = 3;
	//UBST.generateTrees(3);

	int returnSize = 0;
	int n = 3;
	struct TreeNode** root = generateTrees(n, &returnSize);
	return 0;
}

/*
time   :  2015-5-19
author :  ht
comment:  ��������c����ʵ�ֵģ������ڴ�Ĺ���û����ô�ϸ�

*/
/*

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

struct TreeNode** reConstruct(int start, int end, int *size)
{
	struct TreeNode** result = NULL;
	if (start >= end)
	{
		result = (struct TreeNode**)malloc(1 * sizeof(struct TreeNode*));
		size[0]++;
		if (start > end)
		{
			result[0] = NULL;  //���һ������û����
		}
		else
		{
			result[0] = (struct TreeNode*)malloc(1 * sizeof(struct TreeNode));
			result[0]->val = start;//ֻʣһ��������
			result[0]->left = NULL;
			result[0]->right = NULL;
		}

		return result;
	}
	else
	{
		int k, i, j;

		//���ȣ�ѡһ��k��ΪkeyValue
		int leftSize = 0, rightSize = 0;

		result = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
		//û�а취����result�Ĵ�С��������ǰ����һ���
		int count = 0;
		for (k = start; k <= end; k++)
		{
			//�᷵��һ�ѿ��е�left��right;
			leftSize = 0;
			rightSize = 0;
			struct TreeNode** left = reConstruct(start, k - 1, &leftSize);
			//������ɵļ���

			struct TreeNode** right = reConstruct(k + 1, end, &rightSize);
			//�ұ����ɵļ���
			for (i = 0; i < leftSize; i++)
			{
				for (j = 0; j < rightSize; j++)
				{
					struct TreeNode*root = (struct TreeNode*)malloc(1 * sizeof(struct TreeNode*));
					root->val = k;  //kΪ��ǰroot
					root->left = left[i];
					root->right = right[j];
					result[count] = root;
					count++;
				}
			}
		}
		size[0] = count;  //��ʾ��ǰ���ϵĴ�С
		return result;
	}
}

struct TreeNode** generateTrees(int n, int* returnSize) {
	int count = 0;
	struct TreeNode** root = reConstruct(1, n, &count);
	returnSize[0] = count;
	return root;
}

int main()
{
	int returnSize = 0;
	int n = 3;
	struct TreeNode** root = generateTrees(n, &returnSize);
	return 0;
}
*/
/*
time   :  2015-5-19
author :  ht
comment:  ����ʵ��ex95
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

struct TreeNode** reConstruct(int start,int end,int *size)
{
	struct TreeNode** result = NULL;
	if (start>= end)
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
		int leftSize = 0,rightSize=0;
		
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

			struct TreeNode** right = reConstruct(k + 1, end,&rightSize);
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
	struct TreeNode** root = reConstruct(1,n,&count);
	returnSize[0] = count;
	return root;
}

int main()
{
	int returnSize = 0;
	int n = 3;
	struct TreeNode** root = generateTrees(n,&returnSize);
	return 0;
}
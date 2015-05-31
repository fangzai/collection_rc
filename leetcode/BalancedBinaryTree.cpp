/*
time   :  2015-5-11
author :  ht
comment:  �ж��Ƿ���ƽ�������
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
 *  ƽ����������ֳ�AVL������������һ�ÿ����������Ǿ����������ʵĶ�������
 *  ����������������������ƽ��������������������������ĸ߶�֮��֮��ľ�
 *  ��ֵ������1��
 */
int Depth(struct TreeNode* current,bool*label)  
{
	//�����ĸ߶�  ����ͬʱ�Ѹ�������AVLƽ���������
	//����label����
	int left = 0;
	int right = 0;
	int height = 0;
	if (current != NULL)
	{
		bool mark1,mark2;
		left = Depth(current->left,&mark1);
		right = Depth(current->right,&mark2);
		
		int dist = abs(left - right);
		if (dist <= 1)
		{
			label[0] = mark1&& mark2;
		}
		else
		{
			label[0] = false;
		}
		
		height = left > right ? left : right;
		return height + 1;
	}
	else
	{
		label[0] = true;
		return 0;
	}

}
bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;
	//bool leftBalanced = isBalanced(root->left);
	bool label;

	int leftHeight = Depth(root,&label);
	return label;
}
int main()
{
	return 0;
}
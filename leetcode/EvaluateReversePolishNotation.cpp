/*
time   :  2015-5-19
author :  ht
comment:  ���ڷ��ű��ʽ�ؽ�Ϊ�������������
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


int str2num(char*str)
{
	int len = strlen(str);
	int num = 0,temp;
	bool flag = false;
	int i;
	i = 0;
	if (str[i] == '-')
	{
		flag = true;
		i = 1;
	}
	while (i < len)
	{
		num *= 10;
		temp = str[i] - '0';
		num += temp;
		i++;
	}
	if (flag)
	{
		return -1 * num;
	}
	else
	{
		return num;
	}

}
bool symbol2(char s)
{
	if (s == '+' || s == '-' || s == '/' || s == '*')
		return true;
	return false;
}
struct TreeNode* reConstruct(struct TreeNode* current, char**tokens, int numSize, int *index)
{
	int temp = 0;
	if (index[0] == 0)
	{
		//�˳�����
		int value = str2num(tokens[index[0]]);  //��һ��Ԫ�ز������Ƿ��� 
		
		current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		current->val = value;
		current->left = NULL;
		current->right = NULL;
		
		return current;
	}
	else
	{
		int value;
		
		struct TreeNode*left = NULL, *right = NULL, *root = NULL;
		if (symbol2(tokens[index[0]][0]) && tokens[index[0]][1]=='\0')
		{
			//��仰ԭ���� if (symbol2(tokens[index[0]]��ԭ����ֱ�����ַ�����ƥ���
			//����symbol2����Ҳ����ôд�ģ�����oj���ù�����Ȼvs�����ǶԵ�
			switch (tokens[index[0]][0])
			{
				//��root�ڵ�һ����ת��Ϊ 0 1 2 3��ʾ������Ҫ�����������
			case '+':
				value = 0;
				break;
			case '-':
				value = 1;
				break;
			case '*':
				value = 2;
				break;
			case '/':
				value = 3;
				break;
			default:
				return NULL;
			}
			index[0]--;
			right = reConstruct(right, tokens, numSize, index);
			if ((index - 1) == 0)
			{
				left = NULL;  //����ֻ��һ��������
			}
			else
			{
				//index[0]--;  //�����Ѿ�����һ���ˣ����ﲻ���ټ�һ��
				left = reConstruct(left, tokens, numSize, index);
			}
			
			current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
			current->val = value;
			current->left = left;
			current->right = right;
			root = current;
			return root;
		}
		else
		{
			value = str2num(tokens[index[0]]);
			index[0]--;
			current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
			current->val = value;
			current->left = NULL;
			current->right = NULL;
			root = current;
			//һ���������֣��϶���Ҷ�ڵ�
			return root;
		}
	}
}
int Depth(struct TreeNode*current,int depth)
{
	if ((current->left == NULL) && (current->right == NULL))
	{
		return depth;
	}
	else
	{
		int left = 0, right = 0;
		if (current->left != NULL)
		{
			left = Depth(current->left, depth+1);
		}

		if (current->right != NULL)
		{
			right = Depth(current->right, depth + 1);
		}

		return left>right ? left : right;  //��ʵ����ֵû�ж����
	}
}
int traverse(struct TreeNode*current)
{
	if (current->left == NULL&&current->right == NULL)
	{
		return current->val;
	}
	else
	{
		int leftValue = 0, rightValue = 0;
		if (current->left != NULL)
		{
			//leftValue = 0;
			leftValue = traverse(current->left);
		}
		if (current->right != NULL)
		{
			rightValue = traverse(current->right);
		}
		int temp = current->val;
		switch (temp)
		{
		case 0:
			current->val = leftValue + rightValue;
			break;
		case 1:
			current->val = leftValue - rightValue;
			break;
		case 2:
			current->val = leftValue * rightValue;
			break;
		case 3:
			current->val = leftValue / rightValue;
			break;
		default:
			break;
		}
		return current->val;
	}
}
int evalRPN(char** tokens, int tokensSize) {
	int i = tokensSize-1;
	int index = tokensSize - 1;
	struct TreeNode*left = NULL, *right = NULL,*root=NULL;
	int value = 0;
	int leftValue = 0, rightValue = 0;

	root = reConstruct(root, tokens, tokensSize, &index);
	//ͨ���������ؽ��������������������ȱ���

	int result = traverse(root);

	return result;
}

int main()
{

	TreeNode* root = NULL, *p = NULL;
	
	//char*str[5] = {"2", "1", "+", "3", "*"};
	//char*str[5] = { "4", "13", "5", "/", "+" };
	char*str[3] = { "-1", "3", "/"};
	int nums = 3;
	int result = evalRPN(str, nums);
	printf("%d \n",result);
	return 0;
}
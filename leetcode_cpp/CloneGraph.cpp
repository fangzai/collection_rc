/*
time   :  2015-5-24
author :  ht
comment:  ������ͼ����һ��
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;


// Definition for undirected graph.
 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		//��һ��˼·���Ȱ�ͼɨһ�飬����һ��map,ӳ��label���ھ�֮��Ĺ�ϵ
		if (node==NULL)
			return NULL;

		map<int, UndirectedGraphNode*> mapNode;
		map<int, bool> visited;
		queue<UndirectedGraphNode*> Q;

		Q.push(node); //����һ��nodeѹ����У�Ȼ��һ�α������еĽڵ㣬BFS����
		//���������������ȵĻ���ò�ƻ�ܿӵ�
		UndirectedGraphNode *current;
		while (!Q.empty())
		{
			current = Q.front(); //ȡ�������еĵ�һ���ڵ�
			Q.pop();//����
			//������map�в��� current,������ҵ��ľͲ���������
			if (mapNode.find(current->label) == mapNode.end())
			{
				//û���ҵ����Ͱ�����ŵ�map����ȥ
				UndirectedGraphNode * newNode = new UndirectedGraphNode(current->label);
				mapNode.insert(pair<int, UndirectedGraphNode*>(current->label,newNode));
				visited.insert(pair<int,bool>(current->label,false));
				//forѭ�����ھ�ѹ����������
				for (int i = 0; i < current->neighbors.size(); i++)
				{
					Q.push(current->neighbors[i]);
				}
			}

		}
		//���ʱ��Q�Ѿ��ǿյ���
		Q.push(node); //����һ��nodeѹ����У�Ȼ����һ�α������еĽڵ�
		visited[node->label] = true;  //����Ѿ�push���˾Ͳ��ܼ���push��
		while (!Q.empty())
		{
			current = Q.front();
			Q.pop();
			UndirectedGraphNode * newNode = mapNode[current->label];
			if (!current->neighbors.empty())
			{
				int len = current->neighbors.size();
				for (int i = 0; i < len; i++)
				{
					int label = current->neighbors[i]->label;
					newNode->neighbors.push_back(mapNode[label]);
					if (!visited[label])
					{
						//����Ѿ�push���˾Ͳ��ܼ���push��
						Q.push(current->neighbors[i]);
						visited[current->neighbors[i]->label] = true;
					}
						
				}
			}
		}
		return mapNode[node->label];
	}
	UndirectedGraphNode *cloneGraph1(UndirectedGraphNode *node)
	{
		//�ڶ���˼·���ǵݹ飬���ַ�ʽ�ݹ����һ�α���
		map<int, UndirectedGraphNode*> visited;
		return clone(node, visited);
	}
	UndirectedGraphNode *clone(UndirectedGraphNode *node, map<int, UndirectedGraphNode*> &table)
	{
		if (node == NULL) return NULL;
		if (table.find(node->label) != table.end()) 
			return table[node->label]; //�Ѿ���������

		//������������
		UndirectedGraphNode * newNode = new UndirectedGraphNode(node->label);
		table.insert(pair<int,UndirectedGraphNode*>(node->label,newNode));  //���ʹ���ǰ���˾�pass��
		int len = node->neighbors.size();
		for (int i = 0; i < len; i++)
		{
			UndirectedGraphNode * neighbors = clone(node->neighbors[i],table);
			//��neighbors�ŵ�newNode���ھ�����ȥ
			newNode->neighbors.push_back(neighbors);
			//table.insert(pair<int, UndirectedGraphNode*>(node->neighbors[i]->label, neighbors));
		}
		return  newNode;
	}

	UndirectedGraphNode *createGraph()
	{
		// ����һ�����ڵ��ͼ
		UndirectedGraphNode*node1=NULL, *node2=NULL, *node3=NULL;
		node1 = new UndirectedGraphNode(1);
		node2 = new UndirectedGraphNode(2);
		node3 = new UndirectedGraphNode(3);
		node1->neighbors.push_back(node2);
		node1->neighbors.push_back(node3);

		node2->neighbors.push_back(node1);
		node2->neighbors.push_back(node3);

		node3->neighbors.push_back(node1);
		node3->neighbors.push_back(node2);
		node3->neighbors.push_back(node3);
		return node1;
	}
};

int main()
{
	Solution mine;
	UndirectedGraphNode *Graph,*newGraph;
	Graph = mine.createGraph();
	newGraph = mine.cloneGraph1(Graph);
	return 0;
}

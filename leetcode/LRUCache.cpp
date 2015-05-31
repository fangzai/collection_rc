/*
time   :  2015-5-30
author :  ht
comment:  cache�ķ��ʰ���������ʴ洢�����ݽṹ���
          ����������ʵķ�����ǰ��
		  �����Ҫ�õ�˫�����������
		  http://www.cnblogs.com/x1957/p/3485053.html
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<unordered_map>
#include<algorithm>
using namespace std;

class LRUCache{
private:
	list<pair<int, int>> mlist;   //˫������
	unordered_map<int, list<pair<int, int>>::iterator> mmap;
	//ͨ��Ԫ��ӳ�䵽����
	int mcapacity;

public:
	LRUCache(int capacity) {
		mlist.clear();
		mmap.clear();
		mcapacity = capacity;
	}

	int get(int key) {
		if (mmap.find(key) != mmap.end()) 
		{
			pair<int, int> tmp = *(mmap[key]);
			mlist.splice(mlist.begin(), mlist, mmap[key]);
			mmap[key] = mlist.begin();
			
			return mlist.front().second;
		}
		else 
		{
			return -1;
		}
	}

	void set(int key, int value) 
	{
		
		if (mmap.find(key) != mmap.end()) 
		{
			//���õ�ʱ������ҵ���ԭ���ľ�ɾ����ֱ�Ӱ����ݷ��������ͷ
			//mlist.erase(mmap[key]);
			//mlist.push_front(make_pair(key, value));
			mlist.splice(mlist.begin(), mlist, mmap[key]);
			mmap[key] = mlist.begin();
			mlist.begin()->second = value;
		}
		else 
		{
			//���õ�ʱ�����û�ҵ�����Ҫ�ж�����������Ƿ񻹹�
			//������˵Ļ�����ɾ����һ����Ȼ���ٰ����key�ŵ�ͷ��
			//���û�����Ļ���ֱ�Ӱ����key����ͷ
			if (mlist.size() == mcapacity)
			{
				mmap.erase(mlist.back().first);
				mlist.pop_back();
			}
			mlist.push_front(make_pair(key, value));
			mmap[key] = mlist.begin();
		}
	}
};
int main()
{
	return 0;
}
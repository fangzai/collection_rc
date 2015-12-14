/*
time   :  2015-5-24
author :  ht
comment:  �����ֵ����prefix����������ӺͲ���
		  ����ex208��������ȱ���
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class TrieNode {
private:
	TrieNode *next[26];
	bool ed;
public:
	// Initialize your data structure here.
	TrieNode() {
		//ÿ����������26����֧
		memset(next, 0, sizeof(TrieNode *) * 26);
		ed = false;
	}
	TrieNode *insert(char ch) {
		int p = ch - 'a';
		return next[p] = new TrieNode();
	}
	TrieNode *get(char ch) {
		int p = ch - 'a';
		return next[p];
	}
	TrieNode *get(int index) {
		return next[index];
	}
	void seted(bool val) {
		ed = val;
	}
	bool geted() {
		return ed;
	}
};

class WordDictionary {
private:
	TrieNode* root;
public:

	// Adds a word into the data structure.
	void addWord(string word) {
		insert(word);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		TrieNode *r = root;
		int depth = 0;
		bool result = traverse(r, word, depth);
		return result;
	}
	WordDictionary() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string s) {
		TrieNode *r = root;
		for (int i = 0; i < s.length(); ++i) {
			TrieNode *p = r->get(s[i]);
			if (!p) {
				p = r->insert(s[i]);
			}
			r = p;
		}
		r->seted(true);
	}

	// Returns if the word is in the trie.
	bool search1(string key) {
		//��ȫƥ�����
		TrieNode *r = root;
		for (int i = 0; i < key.length(); ++i) {
			r = r->get(key[i]);
			if (!r) return false;
		}
		return r->geted();
	}
	bool traverse(TrieNode *r, string key, int depth)
	{
		//������ȱ���
		char s = key[depth];
		int index = 0;
		bool result = false;
		TrieNode *current = NULL;
		if (depth == (key.length() - 1))
		{
			//�˳�����  ���Ǳ�����key�����һ��Ԫ����
			if (s == '.')
			{
				for (int i = 0; i < 26; i++)
				{
					index = i;
					current = r->get(index);
					if (current&&current->geted())
						return true;
				}
				return false;
			}
			else
			{
				index = s - 'a';
				current = r->get(index);
				if (current&&current->geted())
					return true;
				return false;
			}
		}
		else
		{
			if (s == '.')
			{
				result = false;
				for (int i = 0; i < 26; i++)
				{
					index = i;
					current = r->get(index);
					if (!current)
						continue;  //�������ط�û�нڵ㣬�ͻ�˷
					result = result || traverse(current, key, depth + 1);
					//һ��һ��ƥ��ɹ�������ľͲ��ÿ�����
					if (result)
						break;
				}
				return result;
			}
			else
			{
				index = s - 'a';
				current = r->get(index);
				if (!current)
					return false;
				result = traverse(current, key, depth + 1);
				return result;
			}
		}


	}
	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode *r = root;
		for (int i = 0; i < prefix.length(); ++i) {
			r = r->get(prefix[i]);
			if (!r) return false;
		}
		return true;
	}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main()
{
	bool result;

	WordDictionary mine;
	mine.insert("hello");
	mine.insert("helloworld");
	result = mine.search("....world");
	if (result)
		cout << "In that WordDictionary!" << endl;
	return 0;
}

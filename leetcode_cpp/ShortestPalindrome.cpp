/*
time   :  2015-5-30
author :  ht
comment:  ��̻����ַ���������
		  �����Ҫ�����kmp�㷨��manacher�㷨������ϸ�ķ���
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

/*
 * ��һ�ַ���Ӧ������򵥴ֱ��ģ����ַ���ͷ��ʼ������Ļ����ַ���
 * ������string��ͷ��ʼ����ʣ�µ���ת�����Ϳ�����
 * ���Ӷ���n^2��
 */
//================================================================
bool isPalindrom(char* s, int start, int end) {
	while (start < end) {
		if (s[start] != s[end]) return false;
		++start; --end;
	}
	return true;
}

char* shortestPalindrome(char* s) {
	int pos = strlen(s) - 1;
	for (; pos > 0; --pos) {
		if (s[pos] == s[0] && isPalindrom(s, 0, pos)) break;
	}
	char* res = (char*)malloc(2 * strlen(s) - pos);
	int idx = 0;
	for (int i = strlen(s) - 1; i > pos; --i) res[idx++] = s[i];
	strcpy(res + idx, s);
	return res;
}
//================================================================

/*
* ���ǻ���manacher  �ұ�ʾ������㷨ȷʵ���Ǻ���
* http://www.cnblogs.com/easonliu/p/4522724.html
* ���Ӷ���O(n)��
*/
class Solution1 {
public:
	int longestPalindrom(string s) {
		string s1;
		s1.resize(2 * s.length() + 2);
		int idx = 0;
		s1[idx++] = '$';
		s1[idx++] = '#';
		for (char a : s) {
			s1[idx++] = a;
			s1[idx++] = '#';
		}
		vector<int> p(s1.length(), 0);
		int res = 0;
		for (int id = 0, i = 1; i < s1.length(); ++i) {
			if (i < id + p[id]) p[i] = min(p[2 * id - i], id + p[id] - i);
			else p[i] = 1;
			while (s1[i + p[i]] == s1[i - p[i]]) ++p[i];
			if (id + p[id] < i + p[i]) id = i;
			if (p[i] == i) res = max(res, i);
		}
		return res - 1;
	}

	string shortestPalindrome(string s) {
		int pos = longestPalindrom(s);
		string res;
		for (int i = s.length() - 1; i >= pos; --i) res.push_back(s[i]);
		return res + s;
	}
};
/*
* ���ǻ���kmp��  �ұ�ʾ������㷨Ҳ���Ǻ���
* https://leetcode.com/discuss/36807/c-8-ms-kmp-based-o-n-time-%26-o-n-memory-solution
* ���Ӷ���O(n)��  
*/
class Solution {
public:
	string shortestPalindrome(string s) {
		string rev_s = s;
		reverse(rev_s.begin(), rev_s.end());
		string l = s + "#" + rev_s;

		vector<int> p(l.size(), 0);
		for (int i = 1; i < l.size(); i++) {
			int j = p[i - 1];
			while (j > 0 && l[i] != l[j])
				j = p[j - 1];
			p[i] = (j += l[i] == l[j]);
		}

		return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
	}
};
int main()
{
	return 0;
}
/*
time   :  2015-5-21
author :  ht
comment:  �������������
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

void show(int **matrix,int m,int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
int LCS(char*s1,char*s2)
{
	/*
	 *�㷨�����ԸĽ������ǿ��Խ�������󳤶ȺͶ�Ӧ�ַ��Ĺ������ڹ������Ĺ�������ɣ�
	 *һ�߹���һ�߼�¼��ǰ����󳤶ȺͶ�Ӧλ�ã������ͽ�ʡ��n^2�Ĳ���ʱ�䡣

     *�ռ���Ҳ�������Ľ�������������ϵķ�ʽ���죬���Ƿ��֣�������ĵ�i+1�е�ֵ
	 *������ɺ󣬵�i�е�ֵ��û�����ˣ���������ĳ��ȳ����ڵ�i�У�����Ҳ�Ѿ���
	 *������¼�����ˡ���ˣ����Խ�����������һ�����������������ĵ�ǰֵ��Ӧ��i�У�
	 *��������һ��ѭ�����ֵ��Ӧ��i+1��
	 */
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int** mark = (int**)malloc(len1*sizeof(int*));

	int i, j;
	for (i = 0; i < len1; i++)
	{
		mark[i] = (int*)malloc(len2*sizeof(int));
		for (j = 0; j < len2; j++)
		{
			mark[i][j] = 0;
		}
	}
	for (i = 0; i < len1; i++)
		mark[i][0] = (s1[i] == s2[0]) ? 1 : 0;
	for (j = 0; j < len2; j++)
		mark[0][i] = (s1[0] == s2[j]) ? 1 : 0;

	int max = 0;
	int ps, pe = 0;
	for (i = 1; i < len1; i++)
	{
		for (j = 1; j < len2; j++)
		{
			if (s1[i] == s2[j])
			{
				mark[i][j] = mark[i - 1][j - 1]+1;
			}
			else
			{
				mark[i][j] = 0;
			}
			if (mark[i][j] > max)
			{
				max = mark[i][j];
				pe = i;
			}
		}
	}

	show(mark,len1,len2);
	i = 0;
	j = pe-max+1;
	while (i < max)
	{
		cout << s1[j];
		j++;
		i++;
	}
	cout <<endl<< max << endl;
	return max;
}

string LCS1(string s1, string s2)
{
	int len1 = s1.size();
	int len2 = s2.size();
	vector<int>mark(len2+1,0);
	int i, j;

	int max = 0;
	int ps, pe = 0;
	for (i = 0; i < len1; i++)
	{
		for (j = len2; j > 0; j--)
		{
			if (s1[i] == s2[j - 1])
			{
				mark[j] = mark[j - 1] + 1;
				if (mark[j] > max)
				{
					max = mark[j];
					pe = i;
				}
			}
			else
			{
				mark[j] = 0;
			}
		}
	}
	string result;
	i = 0;
	j = pe - max + 1;
	result = s1.substr(j, max);
	return result;
}
int main()
{
	char* str1 = "wanghaitao";
	char* str2 = "fhaitwhaitaowanggg";

	//int len = LCS(str1, str2);
	//string str = "h";
	string s1 = "esbtzjaaijqkgmtaajpsdfiqtvxsgfvijpxrvxgfumsuprzlyvhclgkhccmcnquukivlpnjlfteljvykbddtrpmxzcrdqinsnlsteonhcegtkoszzonkwjevlasgjlcquzuhdmmkhfniozhuphcfkeobturbuoefhmtgcvhlsezvkpgfebbdbhiuwdcftenihseorykdguoqotqyscwymtjejpdzqepjkadtftzwebxwyuqwyeegwxhroaaymusddwnjkvsvrwwsmolmidoybsotaqufhepinkkxicvzrgbgsarmizugbvtzfxghkhthzpuetufqvigmyhmlsgfaaqmmlblxbqxpluhaawqkdluwfirfngbhdkjjyfsxglsnakskcbsyafqpwmwmoxjwlhjduayqyzmpkmrjhbqyhongfdxmuwaqgjkcpatgbrqdllbzodnrifvhcfvgbixbwywanivsdjnbrgskyifgvksadvgzzzuogzcukskjxbohofdimkmyqypyuexypwnjlrfpbtkqyngvxjcwvngmilgwbpcsseoywetatfjijsbcekaixvqreelnlmdonknmxerjjhvmqiztsgjkijjtcyetuygqgsikxctvpxrqtuhxreidhwcklkkjayvqdzqqapgdqaapefzjfngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugphhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvyarvaxmchtyrtkgekkmhejwvsuumhcfcyncgeqtltfmhtlsfswaqpmwpjwgvksvazhwyrzwhyjjdbphhjcmurdcgtbvpkhbkpirhysrpcrntetacyfvgjivhaxgpqhbjahruuejdmaghoaquhiafjqaionbrjbjksxaezosxqmncejjptcksnoq";
	string s2 = s1;
	reverse(s1.begin(),s1.end());
	string result = LCS1(s1,s2);
	cout << result << endl;
	return 0;
}
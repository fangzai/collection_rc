/*
time   :  2015-5-30
author :  ht
comment:  ��һ�ѵ��ҳ���ĳ��ֱ�������������
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;


/*
 * �����Ľⷨ��ɵ����
 * ֱ�Ӽ���ÿ����ͱ�ĵ��б��Ȼ��ͳ���������
 * ���治֪��������Ϊʲô��ôС���ύ�ɹ���
 * http://www.cnblogs.com/easonliu/p/4527792.html
 */
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point>& points) {
		int res = 0, same_cnt, ver_cnt, cnt;
		unordered_map<double, int> mp;
		double k;
		for (int i = 0; i < points.size(); ++i)
		{
			same_cnt = 0;  //��i�ظ��ĵ�
			ver_cnt = 0;
			cnt = 0; //�����������
			mp.clear();
			for (int j = 0; j < points.size(); ++j) 
			{
				if (points[i].x == points[j].x)
				{
					//��Ҫ����x��ͬ��б�����������
					if (points[i].y == points[j].y)
					{
						++same_cnt; //�ظ��ĵ�
						continue;
					}
					else 
					{
						++ver_cnt;
						//б�����������
						cnt = max(cnt, ver_cnt);
					}
				}
				else 
				{
					//����б�ʣ�Ȼ��mapӳ����б�ʺ�����
					k = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
					++mp[k];
					cnt = max(cnt, mp[k]);
				}
			}
			//��Ϊ�����Ҫ�����ظ��ĵ�
			res = max(res, cnt + same_cnt);
		}
		return res;
	}
};
int main()
{
	return 0;
}
/*
time   :  2015-5-30
author :  ht
comment:  ��֤����������Ƿ�Ϸ�
*/
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

/*
 * ����д����ˣ��Ǹ����ַ�����������������~~~����˼·֪��
 * ������жϵķ�����̫low�ˣ������д�������һ������״̬������ը��
 *
 *
 *
 * ��������һ��״̬
 * ����״̬ 6��  0~5
 *	   ״̬  0 ����ʼ״̬�����ǲ��Ϸ�״̬��
				 1.���ܿո��ʱ��״̬��Ȼ��0
				 2.������ŵ�ʱ��״̬��Ϊ3��״̬3��0����һ�������޷��ٽ��ܷ��ţ�
				 3.�ʶ���0�Ļ����ϣ������ܷ�����Ϊ-1�����3��״̬
				 4.�������ֺ�״̬��Ϊ1��״̬1�޷��ڽ��ܷ��ţ����Խ��ܿո����֡��㡢ָ��
				 5.������Ϊ.��ʱ��״̬תΪ2���������������֣�������Ϊ�Ƿ�
				 6.����ָ����ʱ��Ƿ�
 
 *     ״̬  1 : ������Ϊ�ǿո�״̬
				 1.��������ʱ��תΪ״̬1
				 2.���ܵ�ʱ��תΪ״̬4�����Խ��ܿո����֣�ָ����״̬4Ϊ�Ϸ��Ľ���״̬
				 3.����ָ��ʱ��תΪ״̬5�����Խ��ܷ��ţ����֣������ٽ��ܵ㣬
				 ��Ϊָ������Ϊ���������ұ����ٽ�������

 *     ״̬  2 : ������Ϊ��.��״̬
		         1.�������ֺ�תΪ״̬4

 *     ״̬  3 : ������Ϊ�Ƿ���״̬

 *     ״̬  4 : ������Ϊ������״̬
				 1.���ܿո񣬺Ϸ�����
				 2.�������֣���Ȼ������
				 3.����ָ����תΪ״̬5
 
 *     ״̬  5 : ������Ϊ��ָ��״̬
				 1.���ܷ��ţ�תΪ״̬6��״̬6��5����һ����ֻ�ǲ����ٽ��ܷ���
				 2.�������֣�תΪ״̬7��7״ֻ̬�ܽ��ܿո�������֣�״̬7�ǺϷ�����״̬

 * ��չ��3��״̬
	   ״̬  6 : ������Ϊ��ָ��״̬��ķ���״̬
				 1.ֻ�ܽ������֣�ת��Ϊ״̬7

	   ״̬  7 : ������Ϊ��ָ��״̬�������״̬
				 1.���ܿո�״̬ת��Ϊ״̬8��״̬7�ǺϷ�����״̬
				 2.����������Ȼ��״̬7

	   ״̬  8 : ������Ϊ��ָ��״̬��Ŀո�״̬
			     1.ֻ�ܽ��ܿո񣬱���״̬8��״̬8Ϊ�Ϸ�״̬
 */
class Solution1
{
public:
	bool isNumber(string s)
	{
		enum InputType
		{
			INVALID,    // 0
			SPACE,      // 1
			SIGN,       // 2
			DIGIT,      // 3
			DOT,        // 4
			EXPONENT,   // 5
			NUM_INPUTS  // 6
		};

		int transitionTable[][NUM_INPUTS] =
		{
			-1, 0, 3, 1, 2, -1,     // next states for state 0
			-1, 8, -1, 1, 4, 5,     // next states for state 1
			-1, -1, -1, 4, -1, -1,     // next states for state 2
			-1, -1, -1, 1, 2, -1,     // next states for state 3
			-1, 8, -1, 4, -1, 5,     // next states for state 4
			-1, -1, 6, 7, -1, -1,     // next states for state 5
			-1, -1, -1, 7, -1, -1,     // next states for state 6
			-1, 8, -1, 7, -1, -1,     // next states for state 7
			-1, 8, -1, -1, -1, -1,     // next states for state 8
		};

		int state = 0;
		int len = s.length();
		int i = 0;
		while (i<len)
		{
			InputType inputType = INVALID;
			if (isspace(s[i]))
				inputType = SPACE;
			else if (s[i] == '+' || s[i] == '-')
				inputType = SIGN;
			else if (isdigit(s[i]))
				inputType = DIGIT;
			else if (s[i] == '.')
				inputType = DOT;
			else if (s[i] == 'e' || s[i] == 'E')
				inputType = EXPONENT;

			state = transitionTable[state][inputType];

			if (state == -1)
				return false;
			else
				i++;
		}
		//1��4��7��8��Ϊ�Ϸ�״̬
		return state == 1 || state == 4 || state == 7 || state == 8;
	}
};
int main()
{
	return 0;
}
#include<string>
#include<stack>
using namespace std;
namespace leetcode20 {
	class Solution {
	public:
		//ʹ��ջ
		//ʱ�临�Ӷ�O��n��
		//�ռ临�Ӷ�O��n��
		bool isValid(string s) {
			if (s.empty())return true;
			stack<char> stk;
			for (int i = 0; i < (int)s.size(); ++i)
			{
				if (s[i] == '(' || s[i] == '{' || s[i] == '[')
				{
					stk.push(s[i]);
				}
				else if (s[i] == ')')
				{
					//���û���κ������Ż��߲�ƥ�䣬����
					if (stk.empty() || stk.top() != '(')return false;
					else stk.pop();
				}
				else if (s[i] == '}')
				{
					//���û���κ������Ż��߲�ƥ�䣬����
					if (stk.empty() || stk.top() != '{')return false;
					else stk.pop();
				}
				else if (s[i] == ']')
				{
					//���û���κ������Ż��߲�ƥ�䣬����
					if (stk.empty() || stk.top() != '[')return false;
					else stk.pop();
				}
			}
			if (stk.empty())return true;//������Ƿ���δƥ���������
			else return false;

		}
	};
}
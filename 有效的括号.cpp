#include<string>
#include<stack>
using namespace std;
namespace leetcode20 {
	class Solution {
	public:
		//使用栈
		//时间复杂度O（n）
		//空间复杂度O（n）
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
					//如果没有任何左括号或者不匹配，返回
					if (stk.empty() || stk.top() != '(')return false;
					else stk.pop();
				}
				else if (s[i] == '}')
				{
					//如果没有任何左括号或者不匹配，返回
					if (stk.empty() || stk.top() != '{')return false;
					else stk.pop();
				}
				else if (s[i] == ']')
				{
					//如果没有任何左括号或者不匹配，返回
					if (stk.empty() || stk.top() != '[')return false;
					else stk.pop();
				}
			}
			if (stk.empty())return true;//最后检查是否还有未匹配的左括号
			else return false;

		}
	};
}
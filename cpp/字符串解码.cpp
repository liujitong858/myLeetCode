#include<vector>
#include<stack>
using namespace std;
namespace leetcode394 {
	class Solution {
	public:
		//栈的思想
		string decodeString(string s) {
			string res = "";
			string curString = "";
			int number = 0;
			stack<string> sta_string;
			stack<int> sta_int;
			for (int i = 0; i < (int)s.size(); ++i) {
				//一共有4种情况
				if (s[i] >= '0'&&s[i] <= '9') {//如果遇见数字
					number = number * 10 + s[i] - '0';//一定记住这个
				}
				else if (s[i] >= 'a'&&s[i] <= 'z' || s[i] >= 'A'&&s[i] <= 'Z') {
					curString += s[i];
				}
				else if (s[i] == '[') {
					sta_int.push(number);
					sta_string.push(curString);
					number = 0;
					curString = "";
				}
				else if (s[i] == ']') {
					int num = sta_int.top();
					sta_int.pop();
					for (int i = 0; i < num; ++i)
						sta_string.top() += curString;
					curString = sta_string.top();
					sta_string.pop();
				}

			}
			res += curString;
			return res;
		}
	};
}
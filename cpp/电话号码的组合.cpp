#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
namespace leetcode17 {
	class Solution {
	public:
		unordered_map<int, vector<string>> hashtable;
		vector<string> letterCombinations(string digits) {
			//组合问题
			if (digits.empty()) return vector<string>();
			int length = digits.size();
			vector<string> res;
			hashtable[2] = { "a","b","c" };
			hashtable[3] = { "d","e","f" };
			hashtable[4] = { "g","h","i" };
			hashtable[5] = { "j","k","l" };
			hashtable[6] = { "m","n","o" };
			hashtable[7] = { "p","q","r","s" };
			hashtable[8] = { "t","u","v" };
			hashtable[9] = { "w","x","y","z" };
			string curStr = "";
			letterCombinations_helper(res, curStr, digits, length, 0);
			return res;
		}
		void letterCombinations_helper(vector<string>& res, string curStr, string ori, int length, int index) {
			if (curStr.size() == length) {
				res.push_back(curStr);
				return;
			}
			vector<string> vec = hashtable[ori[index] - '0'];//当前索引所代表的字母们
			for (int i = 0; i < vec.size(); ++i) {
				letterCombinations_helper(res, curStr + vec[i], ori, length, index + 1);
			}
		}
	};
}
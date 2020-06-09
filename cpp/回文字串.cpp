#include<string>
#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode647 {
	class Solution {
	public:
		//中心扩展法
		int countSubstrings(string s) {
			if (s.size() <= 1) return s.size();
			int res = 0;
			int length = s.size();
			for (int i = 0; i < length; ++i) {
				countSubstrings_helper(s, i, i, res);
				countSubstrings_helper(s, i, i + 1, res);
			}
			return res;
		}
		void countSubstrings_helper(string& s, int left, int right, int& res) {
			while (left >= 0 && right < s.size() && s[left] == s[right]) {
				--left;
				++right;
				++res;
			}
		}

		//动态规划
		int countSubstrings2(string s) {
			if (s.size() <= 1) return s.size();
			int res = 0;
			int length = s.size();
			vector<vector<bool>> dp(length, vector<bool>(length));
			for (int i = length - 1; i >= 0; --i) {
				for (int j = i; j < length; ++j) {
					if ((s[i] == s[j]) && ((j - i < 2) || dp[i + 1][j - 1])) {
						dp[i][j] = true;
					}
					else dp[i][j] = false;
					if (dp[i][j]) ++res;
				}
			}
			return res;
		}
		//暴力遍历法
		int countSubstrings1(string s) {
			if (s.size() <= 1) return s.size();
			int res = s.size();//初始化的时候就把长度为1的加上
			int length = s.size();
			for (int i = 2; i <= length; ++i) {//长度
				for (int j = 0; j + i - 1 < length; ++j) {
					if (countSubstrings_helper(s, j, j + i - 1)) ++res;
				}
			}
			return res;
		}
		bool countSubstrings_helper(string& s, int left, int right) {
			while (left < right) {
				if (s[left] == s[right]) {
					++left;
					--right;
				}
				else return false;
			}
			return true;
		}
	};		
}